#include "thpe02.h"

bool openFiles(ifstream& fin, int argc, char* argv[], StringTracker& stringTracker)
{
    if (argc != 4)
    {
        cout << "Usage: " << argv[0] << " <input file> <output file 1> <output file 2>" << endl;
        return false;
    }

    fin.open(argv[1]);

    if ( !fin.is_open() )
    {
        cout << "failure upon opening input file" << endl;
        return false;
    }

    readData(fin, stringTracker);

    fin.close();
    return true;
}

bool writeOutputFiles(ofstream& fout, char* argv[], StringTracker& stringTracker)
{
    fout.open(argv[2]);
    if ( !fout.is_open() )
    {
        cout << "failure upon opening output file 1" << endl;
        return false;
    }

    stringTracker.printPhrases(fout);
    fout.close();

    fout.open(argv[3]);
    if ( !fout.is_open() )
    {
        cout << "failure upon opening output file 2" << endl;
        return false;
    }

    stringTracker.printCounters(fout);
    fout.close();

    return false;
}

void readData(ifstream& fin, StringTracker& stringTracker)
{
    string tempString;

    while(fin >> tempString )
    {
        stringTracker.addString(tempString);
    }

    cout << endl;
}
