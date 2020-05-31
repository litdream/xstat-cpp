#ifndef __PROC_UPTIME_H
#define __PROC_UPTIME_H

#include <fstream>

class ProcUptime
{
 public:
	const double sec = -1;
	const double idleSec = -1;
	
	ProcUptime();
	
 protected:
	std::ifstream fh;
	const std::string fname = "/proc/uptime";
};

#endif  /* __PROC_UPTIME_H */
