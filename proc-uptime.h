#ifndef __PROC_UPTIME_H
#define __PROC_UPTIME_H

#include <fstream>

struct UptimeInfo
{
	double sec;
	double idleSec;
};

class ProcUptime
{
 public:
	ProcUptime();
	void reset();
	const UptimeInfo& getInfo() const;
	void Print() const;
	
 protected:
	UptimeInfo info;
	std::ifstream fh;
	const std::string fname = "/proc/uptime";
};

#endif  /* __PROC_UPTIME_H */
