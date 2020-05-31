#include <iostream>
#include <fstream>
#include "proc-uptime.h"

ProcUptime::ProcUptime()
{
	if ( fh.is_open()) {
		fh.seekg(0, std::ios::end);
	}
	else {
		fh.open(this->fname);
	}

	fh >> *((double *)&sec);
	fh >> *((double *)&idleSec);
}
