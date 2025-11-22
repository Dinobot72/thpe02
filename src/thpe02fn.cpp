#include "thpe02.h"

bool openFiles(ifstream& fin, int argc, char* argv[], StringTracker& stringTracker)
{
    // If arguments are less than 
    if (argc != 4)
    {
        cout << "Usage: " << argv[0] << " <input file> <output file 1> <output file 2>" << endl;
        return false;
    }

    // Open input file
    fin.open(argv[1]);

    // If input file fails to open
    if ( !fin.is_open() )
    {
        cout << "failure upon opening input file" << endl;
        return false;
    }

    // Read data from input file
    readData(fin, stringTracker);

    // Close input file
    fin.close();
    return true;
}

bool writeOutputFiles(ofstream& fout, char* argv[], StringTracker& stringTracker)
{
    // Open output files
    fout.open(argv[2]);
    if ( !fout.is_open() )
    {
        cout << "failure upon opening output file 1" << endl;
        return false;
    }

    // write printPhrases function to the first output file
    stringTracker.printPhrases(fout);
    fout.close();

    // open 2nd output file and check for failure
    fout.open(argv[3]);
    if ( !fout.is_open() )
    {
        cout << "failure upon opening output file 2" << endl;
        return false;
    }

    // write printCounters function to the first output file
    stringTracker.printCounters(fout);
    fout.close();

    return true;
}

void readData(ifstream& fin, StringTracker& stringTracker)
{
    string tempString;

    // read each string into a temporary string
    while(fin >> tempString )
    {

        // check if string is empty
        if ( tempString.empty() )
        {
            continue;
        }

        // clean string of punctuations
        cleanWord( tempString );


        // chck if string is already in linked list
        if (stringTracker.findString( tempString ))
        {
            stringTracker.incrementCount( tempString );
        } else // if not in linked list add to the linked list
        {
            stringTracker.addString( tempString );
        }
    }

    cout << endl;
}

void cleanWord( string& word ) 
{
    // convert strign to lower case
    for (char &c : word)
    {
        c = tolower( c );
    }

    // remove leading and trailing punctuation
    while (!word.empty() && ispunct(word.front()))
    {
        word.erase(0,1);
    }
    while (!word.empty() && ispunct(word.back()))
    {
        word.pop_back();
    }

}
