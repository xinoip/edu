OBJS = *.cpp

CC = g++
COMPILER_FLAGS = -Wfatal-errors
CXXFLAGS= -std=c++11 

OBJ_NAME = app
all : $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ_NAME)

debug : $(OBJS)
	clear && $(CC) $(CXXFLAGS) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ_NAME) -g

clean :
	rm $(OBJ_NAME)