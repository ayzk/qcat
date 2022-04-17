/**
 *  @file calculateSSIM.c
 *  @author Sheng Di
 *  @date Sept, 2021
 *  @brief This is an example of using compression interface
 *  (C) 2020 by Mathematics and Computer Science (MCS), Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ByteToolkit.h"
#include "rw.h"
#include "qcat.h"
#include "qcat_gnuplot.h"

int main(int argc, char * argv[])
{
    int status = 0;
    char dataType[4];
    char oriFilePath[640];
    int intervals = 0;
    float min_threshold = 0, max_threshold = -1;
    
    if(argc < 3)
    {
		printf("Usage: computeDataPDF [datatype (-i/-f)] [data file] [# intervals] [min] [max]\n");
		printf("[# intervals] indicates the number of intervals that will be used to split the data value range.\n");
		printf("[min] means that all the values that are smaller than [min] will be overlooked.\n");		
		printf("[max] means that all the values that are greater than [min] will be overlooked. ([max] should be greater than [min])\n");
		printf("note: [min] and [max] are optional parameters. If you don't set them, then the algorithm will use the real min and max of the dataset to compute distribution.\n");
		printf("Example 1: computeDataPDF -i FREQSH_55_1e-3-lorenzo.q\n");
		printf("Example 2: computeDataPDF -f data.f32 10000 1.2 1.5\n");
		exit(0);
    }
   
    sprintf(dataType, "%s", argv[1]);
    sprintf(oriFilePath, "%s", argv[2]);
  
    if(argc>=4)
		intervals = atoi(argv[3]);
  
	if(argc>=6)
	{
		min_threshold = atof(argv[4]);
		max_threshold = atof(argv[5]);
	}	
  
    int x = 1;
    char *y = (char*)&x;

    if(*y==1)
    {     
		 sysEndianType = 0; //LITTLE_ENDIAN_SYSTEM;
		 printf("This is little-endian system.\n");
    }
    else //=0
    {
         sysEndianType = 1; //BIG_ENDIAN_SYSTEM;
         printf("This is big-endian system.\n");
    }
    
	double* pdf = NULL;
	float min = 0;
	
	int dtype = 0; 
	if(strcmp(dataType, "-i")==0)
		dtype = QCAT_INT32;
	else if(strcmp(dataType, "-f")==0)
		dtype = QCAT_FLOAT;
	
	double unit = 0;
    if(dtype==QCAT_INT32)
    {
		int* data;
		size_t nbEle = 0;
		printf("reading data from %s \n", oriFilePath);
		data = readInt32Data(oriFilePath, &nbEle, &status);
		printf("calcaulting....\n");
		int intMin = 0;
		pdf = computeDataPDF_int32(data, nbEle, &intMin, &intervals);
		min = intMin;	
		
		free(data);
	}
	else if(dtype==QCAT_FLOAT)
	{
		float* data;
		size_t nbEle = 0;
		if(intervals==0)
		{
			printf("Error: please set # intervals.\n");
			exit(0);
		}
		
		printf("reading data from %s \n", oriFilePath);
		data = readFloatData(oriFilePath, &nbEle, &status);
		printf("calcaulting....\n");
	
		pdf = computeDataPDF_float(data, nbEle, intervals, &min, &unit, min_threshold, max_threshold);
		
		free(data);		
	}
	
	//write pdf to a file
	char* tgtPDFDataPath = (char*)malloc(QCAT_BUFS_LONG);
	sprintf(tgtPDFDataPath, "%s.dis", oriFilePath);
	
	writePDFData_raw(dtype, tgtPDFDataPath, min, intervals, pdf, unit);
	free(tgtPDFDataPath);

	//generate gnuplot script file
	char* tgtPDFScriptPath = (char*)malloc(QCAT_BUFS_LONG);
	sprintf(tgtPDFScriptPath, "%s.p", oriFilePath);
	char** gnuplotScriptLines = genGnuplotScript_fillsteps(oriFilePath, "dis", 2, "Data", "Probability Density Function (PDF)");
	RW_writeStrings(19, gnuplotScriptLines, tgtPDFScriptPath);	
	
	printf("Done.\n");
	printf("You need to run following lines to generate distrituion img files:\n");
	char* dir = extractDirFromPath(tgtPDFScriptPath);
	if(dir==NULL)
		dir = "./";
	char* filename = extractFileNameFromPath(tgtPDFScriptPath);
	printf("cd %s; gnuplot %s\n", dir, filename);
	free(tgtPDFScriptPath);	
	free(pdf);	
	
    return 0;
}
