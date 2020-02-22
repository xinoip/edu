OBJS = ./src/*.java
CC = javac
JAVA_DOC = javadoc

DOC_DIR = ./docs
BUILD_DIR = ./build

all : $(OBJS)
	$(CC) -d $(BUILD_DIR) $(OBJS)

javadoc: $(OBJS)
	$(JAVA_DOC) -d $(DOC_DIR) $(OBJS)
run : 
	cd $(BUILD_DIR) && java Main

clean :
	rm $(BUILD_DIR)/*