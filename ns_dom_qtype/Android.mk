LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := ns_dom_qtype.out
LOCAL_C_INCLUDES += \
		../tools/
LOCAL_SRC_FILES := \
	    ns_dom_qtype.c \
#		../tools/tools.c
include $(BUILD_EXECUTABLE)
