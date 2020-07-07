TARGET	 = testkdTree.exe
CC	     = c++
PROJ_DIR = C:/Users/kotire/projects
INCLUDES	= -I$(PROJ_DIR)/kdTree

$(TARGET):testingkdTree.o kdTree.o kdTreeTools.o
	echo "$(CC) -o $(TARGET) testingkdTree.o kdTree.o kdTreeTools.o"
	$(CC) -o $(TARGET) testingkdTree.o kdTree.o kdTreeTools.o
	
testingkdTree.o:testingkdTree.cxx
	echo "$(CC) -c -o testingkdTree.o testingkdTree.cxx"
	$(CC) -c -o testingkdTree.o testingkdTree.cxx 
		
kdTree.o:kdTree.cxx kdTree.h
	echo "$(CC) -c -o kdTree.o kdTree.cxx"
	$(CC) -c -o kdTree.o kdTree.cxx
	
kdTreeTools.o:kdTreeTools.cxx
	echo "$(CC) -c -o kdTreeTools.o kdTreeTools.cxx"
	$(CC) -c -o kdTreeTools.o kdTreeTools.cxx
	
clean:
	rm *.o
	rm *.exe