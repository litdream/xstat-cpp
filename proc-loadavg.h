#ifndef __PROC_LOADAVG_H
#define __PROC_LOADAVG_H

#include <fstream>

struct LoadavgInfo
{
	double nRunQueue_1;
	double nRunQueue_5;
	double nRunQueue_15;
	int nRunnable;
	int totRunnable;
	int latestPid;
};

class ProcLoadavg
{
 public:
	ProcLoadavg();
	void reset();
	const LoadavgInfo& getInfo() const;
	void Print();
 protected:
	LoadavgInfo info;
	std::ifstream fh;
	const std::string fname = "/proc/loadavg";
};

#endif  /* __PROC_LOADAVG_H */
