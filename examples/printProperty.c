/**
 *  @file printProperty.c
 *  @author Sheng Di
 *  @date April, 2015
 *  @brief This is an example of using compression interface
 *  (C) 2015 by Mathematics and Computer Science (MCS), Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */


#include <stdio.h>
#include <stdlib.h>
#include "ByteToolkit.h"
#include "rw.h"
#include "qcat_dataAnalysis.h"

int main(int argc, char * argv[])
{
	int status = 0;
	char oriFilePath[640];

	if(argc < 2)
	{
		printf("Usage: printDataProperty [dataType] tgtFilePath]\n");
		printf("Example: printDataProperty -f testfloat_8_8_128.dat\n");
		exit(0);
	}

	int dataType = strcmp(argv[1],"-f") == 0 ? DA_FLOAT : DA_DOUBLE; //0: float , 1: double
	sprintf(oriFilePath, "%s", argv[2]);

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

	unsigned char* data  = NULL;
	size_t nbEle = 0;
	if(dataType == DA_FLOAT)
		data = (unsigned char*)readFloatData(oriFilePath, &nbEle, &status);
	else
		data = (unsigned char*)readDoubleData(oriFilePath, &nbEle, &status);

	int i = 0;
	printf("The first 10 values are: \n");
	if(dataType == DA_FLOAT)
		for(i=0;i<10;i++)
			printf("%f ", (float)data[i]);
	else
		for(i=0;i<10;i++)
			printf("%f ", (double)data[i]);		
	printf("....\n------------------------\n");
	if(status != DA_SCES)
	{
		printf("Error: data file %s cannot be read!\n", oriFilePath);
		exit(0);
	}
	
	QCAT_DataProperty* property = computeProperty(dataType, data, nbEle);
	
	printProperty(property);
	
	free(property);
	free(data);

	return 0;
}
