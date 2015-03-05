LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := libluajava
LOCAL_SRC_FILES := luajava.c
LOCAL_STATIC_LIBRARIES := liblua
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../lua/src
include $(BUILD_SHARED_LIBRARY)
