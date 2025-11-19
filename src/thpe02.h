#include "stringTracker.h"
#include <fstream>
#include <iostream>

bool openFiles(ifstream& fin, int argc, char* argv[], StringTracker& stringTracker);
bool writeOutputFiles(ofstream& fout, char* argv[], StringTracker& stringTracker);
void readData(ifstream& fin, StringTracker& stringTracker);

