// 50 lines maximum
#include "thpe02.h"
int main(int argc, char* argv[])
{
    ifstream fin;
    ofstream fout;
    StringTracker stringTracker;


    if (!openFiles(fin, argc, argv, stringTracker))
    {
        return 1;
    }

    writeOutputFiles(fout, argv, stringTracker);

    fin.close();
    fout.close();


    return 0;
}