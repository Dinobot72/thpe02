#include <sstream>
#include "stringTracker.h"

TEST_CASE("StringTracker::addString - RS add to empty list")
{
    bool retValue;
    string addValue = "The Banana";
    ostringstream sout;

    StringTracker myTracker;

    
    retValue = myTracker.addString( addValue );
    REQUIRE( retValue );
    
    myTracker.print( sout );
    REQUIRE( sout.str() == "The Banana (1)" );
    
}

TEST_CASE("StringTracker::addString - RS try duplicates being added to list")
{
    bool retValue;
    string addValue = "Bananas";
    ostringstream sout;

    StringTracker myTracker;

    
    retValue = myTracker.addString( addValue );
    REQUIRE( retValue );

    retValue = myTracker.addString( addValue );
    REQUIRE( retValue );
    
    // check printout with output string stream
    myTracker.print( sout );
    REQUIRE( sout.str() == "Bananas (1)" );
    
}