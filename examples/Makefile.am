AUTOMAKE_OPTIONS=foreign
AM_CPPFLAGS = -I../qcat/include -I../zstd
AM_CFLAGS = -I../qcat/include -I../zstd

bin_PROGRAMS=printProperty changeDataSize generateRandomData generateRandomData2 convertBytesToTxtFloat convertBytesToTxtDouble splitComplexData convertDataToLogFloat convertDataToLogDouble convertTxtToBytesDouble convertTxtToBytesFloat PlotSliceImage convertFloatToDouble convertDoubleToFloat compareData extractSliceFrom3D computeDataPDF computeErrPDF calculateSSIM predCR convertDataType simSZ convertEndianType computeDataAutoCorrelation computeErrAutoCorrelation compressQuantBins computeAccuracyGain computeLaplacian calculateSobolevNorm computeGradientLength splitDataFile lorenzoPredQuantCmpr lorenzoPredQuantDecmpr

printProperty_SOURCES=printProperty.c
printProperty_LDADD=../qcat/.libs/libqcat.a -lm
changeDataSize_SOURCES=changeDataSize.c
changeDataSize_LDADD=../qcat/.libs/libqcat.a -lm
generateRandomData_SOURCES=generateRandomData.c
generateRandomData_LDADD=../qcat/.libs/libqcat.a -lm
generateRandomData2_SOURCES=generateRandomData2.c
generateRandomData2_LDADD=../qcat/.libs/libqcat.a -lm
convertBytesToTxtFloat_SOURCES=convertBytesToTxtFloat.c
convertBytesToTxtFloat_LDADD=../qcat/.libs/libqcat.a -lm
convertBytesToTxtDouble_SOURCES=convertBytesToTxtDouble.c
convertBytesToTxtDouble_LDADD=../qcat/.libs/libqcat.a -lm
splitComplexData_SOURCES=splitComplexData.c
splitComplexData_LDADD=../qcat/.libs/libqcat.a -lm
convertDataToLogDouble_SOURCES=convertDataToLogDouble.c
convertDataToLogDouble_LDADD=../qcat/.libs/libqcat.a -lm
convertDataToLogFloat_SOURCES=convertDataToLogFloat.c
convertDataToLogFloat_LDADD=../qcat/.libs/libqcat.a -lm
convertTxtToBytesDouble_SOURCES=convertTxtToBytesDouble.c
convertTxtToBytesDouble_LDADD=../qcat/.libs/libqcat.a -lm
convertTxtToBytesFloat_SOURCES=convertTxtToBytesFloat.c
convertTxtToBytesFloat_LDADD=../qcat/.libs/libqcat.a -lm
PlotSliceImage_SOURCES=PlotSliceImage.c
PlotSliceImage_LDADD=../qcat/.libs/libqcat.a -lm
convertFloatToDouble_SOURCES=convertFloatToDouble.c
convertFloatToDouble_LDADD=../qcat/.libs/libqcat.a -lm
convertDoubleToFloat_SOURCES=convertDoubleToFloat.c
convertDoubleToFloat_LDADD=../qcat/.libs/libqcat.a -lm
compareData_SOURCES=compareData.c
compareData_LDADD=../qcat/.libs/libqcat.a -lm
extractSliceFrom3D_SOURCES=extractSliceFrom3D.c
extractSliceFrom3D_LDADD=../qcat/.libs/libqcat.a -lm
computeDataPDF_SOURCES=computeDataPDF.c
computeDataPDF_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a -lm
computeErrPDF_SOURCES=computeErrPDF.c
computeErrPDF_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a -lm
calculateSSIM_SOURCES=calculateSSIM.c
calculateSSIM_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a -lm
predCR_SOURCES=predCR.c
predCR_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a -lm
simSZ_SOURCES=simSZ.c
simSZ_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a -lm
convertDataType_SOURCES=convertDataType.c
convertDataType_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a -lm
convertEndianType_SOURCES=convertEndianType.c
convertEndianType_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a -lm
computeDataAutoCorrelation_SOURCES=computeDataAutoCorrelation.c
computeDataAutoCorrelation_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a -lm
computeErrAutoCorrelation_SOURCES=computeErrAutoCorrelation.c
computeErrAutoCorrelation_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a -lm
compressQuantBins_SOURCES=compressQuantBins.c
compressQuantBins_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a -lm
computeAccuracyGain_SOURCES=computeAccuracyGain.c
computeAccuracyGain_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a -lm
computeLaplacian_SOURCES=computeLaplacian.c
computeLaplacian_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a -lm
calculateSobolevNorm_SOURCES=calculateSobolevNorm.c
calculateSobolevNorm_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a -lm
computeGradientLength_SOURCES=computeGradientLength.c
computeGradientLength_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a -lm
splitDataFile_SOURCES=splitDataFile.c
splitDataFile_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a -lm
lorenzoPredQuantCmpr_SOURCES=lorenzoPredQuantCmpr.c
lorenzoPredQuantCmpr_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a -lm
lorenzoPredQuantDecmpr_SOURCES=lorenzoPredQuantDecmpr.c
lorenzoPredQuantDecmpr_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a -lm

if COMPILE_CUDA
SUFFIXES = .cu

AM_V_NVCC = $(AM_V_NVCC_@AM_V@)
AM_V_NVCC_ = $(AM_V_NVCC_@AM_DEFAULT_V@)
AM_V_NVCC_0 = @echo "  NVCC    " $@;
AM_V_NVCC_1 =

.cu.o:
	$(AM_V_NVCC)$(NVCC) $(AM_NVCCFLAGS) $(NVCCFLAGS) -o $@ -c $< -I../qcat/include -I../zstd

bin_PROGRAMS+=lorenzoPredQuantCmpr_GPU lorenzoPredQuantDecmpr_GPU
lorenzoPredQuantCmpr_GPU_SOURCES=lorenzoPredQuantCmpr_GPU.cu
lorenzoPredQuantCmpr_GPU_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a -lm
lorenzoPredQuantCmpr_GPU_LINK=$(NVCC) -o $@
lorenzoPredQuantDecmpr_GPU_SOURCES=lorenzoPredQuantDecmpr_GPU.cu
lorenzoPredQuantDecmpr_GPU_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a -lm
lorenzoPredQuantDecmpr_GPU_LINK=$(NVCC) -o $@
endif