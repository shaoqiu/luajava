LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE    := liblua
LOCAL_SRC_FILES := ./src/lundump.c \
	./src/lutf8lib.c \
	./src/lzio.c \
	./src/lstate.c \
	./src/liolib.c \
	./src/loslib.c \
	./src/loadlib.c \
	./src/ldblib.c \
	./src/ldo.c \
	./src/linit.c \
	./src/lmem.c \
	./src/lcode.c \
	./src/lstrlib.c \
	./src/lctype.c \
	./src/lvm.c \
	./src/ltm.c \
	./src/ltablib.c \
	./src/lbaselib.c \
	./src/ldump.c \
	./src/ltable.c \
	./src/llex.c \
	./src/lcorolib.c \
	./src/lmathlib.c \
	./src/lgc.c \
	./src/lopcodes.c \
	./src/lbitlib.c \
	./src/ldebug.c \
	./src/lauxlib.c \
	./src/lfunc.c \
	./src/lparser.c \
	./src/lstring.c \
	./src/lobject.c \
	./src/lapi.c

include $(BUILD_STATIC_LIBRARY)
