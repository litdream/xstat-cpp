#include <iostream>
#include <fstream>
#include <ctime>
#include <utmp.h>
#include "proc-uptime.h"
#include "proc-loadavg.h"

const std::string currentTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	
	// Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
	// for more information about date/time format
	strftime(buf, sizeof(buf), "%H:%M:%S", &tstruct);

	return buf;
}

ProcUptime::ProcUptime()
{
	reset();
}

void ProcUptime::reset()
{
	if ( fh.is_open()) {
		fh.seekg(0, std::ios::end);
	}
	else {
		fh.open(fname);
	}

	fh >> info.sec;
	fh >> info.idleSec;
}

const UptimeInfo& ProcUptime::getInfo() const
{
	return info;
}

void ProcUptime::Print() const
{
	ProcLoadavg ldavg;
	LoadavgInfo ldinfo = ldavg.getInfo();
	
	// TODO:
	//   1. This is simply copy of /proc/uptime.  Make meaningful output showed above.
	//   2. This could be done in ProcUptime class.
	//
	std::cout << currentTime() << "\n";

	int days = static_cast<int>(info.sec) / 86400;
	int remainder = static_cast<int>(info.sec) % 86400;
	int hr = remainder / 3600;
	int min = remainder % 60;
	
	std::cout << "up " << days << " days, " << hr << ":" << min << '\n';

	// Users
	int numuser = 0;
	struct utmp *utmpstruct;
	setutent();
	while ((utmpstruct = getutent())) {
		if ((utmpstruct->ut_type == USER_PROCESS) &&
		    (utmpstruct->ut_name[0] != '\0'))
			numuser++;
	}
	endutent();
	std::cout << numuser << " users" << '\n';
	
	std::cout << ldinfo.nRunQueue_1 << " "
		  << ldinfo.nRunQueue_5 << " "
		  << ldinfo.nRunQueue_15 << std::endl;
		
}
