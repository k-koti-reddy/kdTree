TARGET	 = testkdTree.exe
CC	     = cl
CC	     = cl
LD	     = link -machine:X64
SL       = LIB.exe
PROJ_DIR = C:/Users/kotire/projects
VC_DIR   = C:/"Program Files \(x86\)"/"Microsoft Visual Studio 14.0"/VC
INCLUDES	= -I$(VC_DIR)/include -I$(PROJ_DIR)/kdTree

OBJS		= testingkdTree.obj

CCFLAGS		 = -DSTD=std
CCFLAGS		+= -DWIN32
CCFLAGS		+= -DWINDOWS
LDFLAGS		 = 
APP_LIBS     = 
LIBS         = kdTree.lib -I$(VC_DIR)/lib

$(TARGET):$(OBJS)
	echo "$(LD) /OUT:$(TARGET) $(LDFLAGS) $(APP_LIBS) $(OBJS)"
	$(LD) /OUT:$(TARGET) $(LDFLAGS) $(APP_LIBS) $(OBJS) $(LIBS)
	
kdTree.lib:kdTree.obj kdTreeTools.obj
	echo "$(SL) /OUT:kdTree.lib kdTree.obj kdTreeTools.obj"
	$(SL) /OUT:kdTree.lib kdTree.obj kdTreeTools.obj
	
kdTree.obj:kdTree.cxx kdTree.h
	echo "$(CC) -c $(CCFLAGS) $(INCLUDES) kdTree.cxx"
	$(CC) -c $(CCFLAGS) $(INCLUDES) kdTree.cxx
	
kdTreeTools.obj:kdTreeTools.cxx
	echo "$(CC) -c $(CCFLAGS) $(INCLUDES) kdTreeTools.cxx"
	$(CC) -c $(CCFLAGS) $(INCLUDES) kdTreeTools.cxx
	
testingkdTree.obj:testingkdTree.cxx
	echo "$(CC) -c $(CCFLAGS) $(INCLUDES) testingkdTree.cxx"
	$(CC) -c $(CCFLAGS) $(INCLUDES) testingkdTree.cxx
	
clean:
	rm $(OBJS)
	rm $(TARGET)
	rm $(LIBS)