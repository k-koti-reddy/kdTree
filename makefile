TARGET	 = testkdTree.exe
CC	     = cl
CC	     = cl
LD	     = link -machine:X64
SL       = LIB.exe
PROJ_DIR = C:/Users/kotire/projects

INCLUDES	= -I. -I$(PROJ_DIR)/kdTree
OBJS		= testingkdTree.obj

CCFLAGS		 = /MDd -DSTD=std /Zi
CCFLAGS		+= -DWIN32
CCFLAGS		+= -DWINDOWS
CCFLAGS		+= /EHsc
LDFLAGS		 = 
APP_LIBS     = 
LIBS         = kdTree.lib

$(TARGET):$(OBJS)
	echo "$(LD) /OUT:$(TARGET) $(LDFLAGS) $(APP_LIBS) $(OBJS)"
	$(LD) /OUT:$(TARGET) $(LDFLAGS) $(APP_LIBS) $(OBJS) $(LIBS)
	
$(LIBS):kdTree.obj kdTreeTools.obj
	$(SL) /OUT:$(LIBS) kdTree.obj kdTreeTools.obj
	
kdTree.obj:kdTree.cxx kdTree.h
	$(CC) -c $(CCFLAGS) $(INCLUDES) kdTree.cxx
	
kdTreeTools.obj:kdTreeTools.cxx
	$(CC) -c $(CCFLAGS) $(INCLUDES) kdTreeTools.cxx
	
testingkdTree.obj:testingkdTree.cxx
	$(CC) -c $(CCFLAGS) $(INCLUDES) testingkdTree.cxx
	
clean:
	rm $(OBJS)
	rm $(TARGET)
	rm $(LIBS)