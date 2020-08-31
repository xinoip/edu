OBJS = ./src/com/pionix/*.java
CC = javac
JAVA_DOC = javadoc

DOC_DIR = ./docs
BUILD_DIR = ./build
CLASS_DIR = ./build/com/pionix

all : $(OBJS)
	mkdir -p $(BUILD_DIR); \
	$(CC) -d $(BUILD_DIR) $(OBJS);

javadoc: $(OBJS)
	mkdir -p $(DOC_DIR); \
	$(JAVA_DOC) -d $(DOC_DIR) $(OBJS);

run :
	java -cp $(BUILD_DIR) com.pionix.Main;

clean :
	rm -rf $(BUILD_DIR);