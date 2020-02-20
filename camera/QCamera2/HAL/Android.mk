LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CLANG_CFLAGS += \
        -Wno-error=unused-private-field \
        -Wno-error=strlcpy-strlcat-size \
        -Wno-error=gnu-designator \
        -Wno-error=unused-variable \
	-Wno-error=format

LOCAL_SRC_FILES := \
        QCamera2Factory.cpp \
        QCamera2Hal.cpp \
        QCamera2HWI.cpp \
        QCameraMem.cpp \
        QCameraQueue.cpp \
        QCameraCmdThread.cpp \
        QCameraStateMachine.cpp \
        QCameraChannel.cpp \
        QCameraStream.cpp \
	QCameraPostProc.cpp \
        QCamera2HWICallbacks.cpp \
        QCameraParameters.cpp \
        QCameraThermalAdapter.cpp \
        wrapper/QualcommCamera.cpp

LOCAL_CFLAGS = -Wall -Werror
#Debug logs are enabled
#LOCAL_CFLAGS += -DDISABLE_DEBUG_LOG

LOCAL_C_INCLUDES := \
        $(LOCAL_PATH)/../stack/common \
        frameworks/native/include/media/hardware \
        frameworks/native/include/media/openmax \
        hardware/qcom/display/libgralloc \
        hardware/qcom/media-caf-new/libstagefrighthw \
        $(LOCAL_PATH)/../../mm-image-codec/qexif \
        $(LOCAL_PATH)/../../mm-image-codec/qomx_core \
	$(LOCAL_PATH)/../util

ifneq ($(filter msm8974 msm8x74 msm8226,$(TARGET_BOARD_PLATFORM)),)
LOCAL_C_INCLUDES += \
        hardware/qcom/display-caf-new/libgralloc
else
LOCAL_C_INCLUDES += \
        hardware/qcom/display/msm8960/libgralloc
endif

LOCAL_C_INCLUDES += $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/include
LOCAL_C_INCLUDES += $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/include/media
LOCAL_ADDITIONAL_DEPENDENCIES := $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr

LOCAL_SHARED_LIBRARIES := libcamera_client liblog libhardware libutils libcutils libdl
LOCAL_SHARED_LIBRARIES += libmmcamera_interface libmmjpeg_interface

LOCAL_MODULE_PATH := $(TARGET_OUT_SHARED_LIBRARIES)/hw
LOCAL_MODULE := camera.$(TARGET_BOARD_PLATFORM)
LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)

#include $(LOCAL_PATH)/test/Android.mk

