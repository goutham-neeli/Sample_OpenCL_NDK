LOCAL_PATH		:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := opencl
LOCAL_SRC_FILES := ../include/libOpenCL.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := prism
LOCAL_SHARED_LIBRARIES := opencl
LOCAL_C_INCLUDES := ../include/
LOCAL_SRC_FILES := main.cpp refNR.cpp openCLNR.cpp
include $(BUILD_EXECUTABLE)