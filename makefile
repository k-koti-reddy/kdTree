TARGET	= kdTree.exe
CC	= cl
CC	= cl
LD	= link -machine:X64

INCLUDES	= -I. -I$(HWCOMMON_DIR)/hwhdf
OBJS		= main.obj

CCFLAGS		= /MDd -DSTD=std /Zi
CCFLAGS		+= -DWIN32
CCFLAGS		+= -DWINDOWS
CCFLAGS		+= /EHsc