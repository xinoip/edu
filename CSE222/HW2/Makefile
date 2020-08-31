OBJS = Main.java
CC = javac
JAVA_DOC = javadoc

ALL = ./com/pionix/*.java ./com/pionix/accessors/*.java ./com/pionix/models/*.java ./com/pionix/controllers/*.java


DOC_DIR = ./docs
CLASS_DIR = ./build/com/pionix

all : $(OBJS)
	$(CC) $(OBJS)

javadoc: $(OBJS)
	mkdir -p $(DOC_DIR); \
	$(JAVA_DOC) -d $(DOC_DIR) $(ALL);

run : $(OBJS)
	java Main

clean:
	rm ./com/pionix/*.class; \
	rm ./com/pionix/accessors/*.class; \
	rm ./com/pionix/models/*.class; \
	rm ./com/pionix/controllers/*.class; \
	rm ./Main.class;
