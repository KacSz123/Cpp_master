# the compiler: gcc for C program, define as g++ for C++
CC = g++

# PATH = .\ 
# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -std=c++2a -g -Wall -pedantic
CLIBS =  -pthread
# The build target 
TARGET = r03_data_race
# r02_chrono

all: $(TARGET)
 
$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp $(CLIBS)

run:
	.\$(TARGET).exe

clean:
	rm $(TARGET)

# cleanExec:
# 	@echo 123
# 	rm .\$(PATH)$(TARGET).exe
