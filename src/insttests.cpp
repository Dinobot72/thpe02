#include <sstream>
#include "stringTracker.h"
#include <catch2/catch_test_macros.hpp> 

TEST_CASE("StringTracker::addString - add to empty list")
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