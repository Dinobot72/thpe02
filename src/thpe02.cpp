// 50 lines maximum
#include "thpe02.h"
int main(int argc, char* argv[])
{
    ifstream fin;
    ofstream fout;
    StringTracker stringTracker;

    // write output files and exit if failure
    if (!openFiles(fin, argc, argv, stringTracker))
    {
        return 1;
    }

    // write output files and exit if failure
    if (!writeOutputFiles(fout, argv, stringTracker))
    {
        return 1;
    }
    writeOutputFiles(fout, argv, stringTracker);

    fin.close();
    fout.close();

    return 0;
}