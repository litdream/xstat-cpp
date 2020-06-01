#include <iostream>
#include <fstream>
#include <cstdlib>
#include "proc-loadavg.h"

ProcLoadavg::ProcLoadavg()
{
	reset();
}

void ProcLoadavg::reset()
{
        if ( fh.is_open()) {
                fh.seekg(0, std::ios::end);
        }
        else {
                fh.open(fname);
        }

        fh >> info.nRunQueue_1;
        fh >> info.nRunQueue_5;
	fh >> info.nRunQueue_15;

	std::string tok;
	fh >> tok;

	int loc = tok.find('/');
	info.nRunnable = atof( tok.substr(0, loc).c_str());
	info.totRunnable = atof( tok.substr(loc+1, tok.length()-loc ).c_str());

	fh >> info.latestPid;
}

void ProcLoadavg::Print()
{
	std::cout << info.nRunQueue_1 << " "
		  << info.nRunQueue_5 << " "
		  << info.nRunQueue_15 << " "
		  << info.nRunnable << "/"  << info.totRunnable << " "
		  << info.latestPid << std::endl;
}

const LoadavgInfo& ProcLoadavg::getInfo() const
{
        return info;
}
