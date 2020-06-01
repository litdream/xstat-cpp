CXX = g++
CFLAGS = -Wall -std=c++11

all: uptime loadavg

uptime: uptime.o proc-uptime.o proc-loadavg.o
	$(CXX) -o uptime uptime.o proc-uptime.o proc-loadavg.o

loadavg: loadavg.o proc-loadavg.o
	$(CXX) -o loadavg loadavg.o proc-loadavg.o

uptime.o: proc-uptime.o
proc-uptime.o:

loadavg.o: proc-loadavg.o
proc-loadavg.o:

.PHONY: clean

clean:
	rm -f *.o uptime loadavg
