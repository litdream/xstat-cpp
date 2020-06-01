#include <iostream>
#include "proc-loadavg.h"

int main(int argc, char **argv)
{
	ProcLoadavg lavg;
	
	// loadavg is not a real Executable.
	// This file is only for testing.
	lavg.Print();
	
	return 0;
}
