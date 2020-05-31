#include <iostream>
#include "proc-uptime.h"

/*
SAMPLE OUTPUT:

 [rchung@localhost ~]$ uptime
  13:56:11 up 58 days, 49 min,  3 users,  load average: 0.00, 0.00, 0.00

 rchung@DESKTOP-E7RQ7AG:~/bitbucket/cpp-test/prj/vmstat$ uptime
  13:55:47 up 1 day, 21:05,  0 users,  load average: 0.52, 0.58, 0.59


The current time, 
how long the system has been running, 
how many users are currently logged on, 
and the system load averages for the past 1, 5, and 15 minutes.

*/	
	
int main(int argc, char **argv)
{
	ProcUptime up;

	// TODO:
	//   1. This is simply copy of /proc/uptime.  Make meaningful output showed above.
	//   2. This could be done in ProcUptime class.
	//
	std::cout << up.sec << " " << up.idleSec << std::endl;
	return 0;
}
