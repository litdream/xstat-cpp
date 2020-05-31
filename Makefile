CXX = g++
CFLAGS = -Wall -std=c++11

all: uptime

uptime: uptime.o proc-uptime.o
	$(CXX) -o uptime uptime.o proc-uptime.o

uptime.o: proc-uptime.o
proc-uptime.o:

.PHONY: clean

clean:
	rm -f *.o uptime
