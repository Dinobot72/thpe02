#include <sstream>
#include "stringTracker.h"
#include <catch2/catch_test_macros.hpp> 

TEST_CASE("StringTracker::addString - add 'pickle' to empty list")
{
    bool retValue;
    string addValue = "pickle";
    ostringstream sout;

    StringTracker myTracker;

    
    retValue = myTracker.addString( addValue );
    REQUIRE( retValue );
    
    myTracker.print( sout );
    REQUIRE( sout.str() == "pickle (1)" );
}

TEST_CASE("StringTracker::addString - add 'sandwich' to list of 1")
{
    bool retValue;
    string addValue = "pickle";
    string addValue2 = "sandwich";
    ostringstream sout;

    StringTracker myTracker;

    
    retValue = myTracker.addString( addValue );
    REQUIRE( retValue );

    retValue = myTracker.addString( addValue2 );
    REQUIRE( retValue );

    
    myTracker.print( sout );
    REQUIRE( sout.str() == "pickle (1)sandwich (1)" );
}

TEST_CASE("StringTracker::addString - add 'mayo' to nonexistent")
{
    bool retValue;
    string addValue = "mayo";
    ostringstream sout;

    StringTracker myTracker;

    
    retValue = myTracker.addString( addValue );
    REQUIRE( retValue );
    
    myTracker.print( sout );
    REQUIRE( sout.str() == "mayo (1)" );
}

TEST_CASE("StringTracker::incrementCount - increment 'pickle' to count of 2")
{
    bool retValue;
    string addValue = "pickle";
    ostringstream sout;

    StringTracker myTracker;

    myTracker.addString( addValue );

    retValue = myTracker.incrementCount( addValue );
    REQUIRE( retValue );

    myTracker.print( sout );
    REQUIRE( sout.str() == "pickle (2)" );
}

TEST_CASE("StringTracker::dencrementCount - dencrement 'pickle' to count of 2")
{
    bool retValue;
    string addValue = "pickle";
    ostringstream sout;

    StringTracker myTracker;

    myTracker.addString( addValue );

    myTracker.incrementCount( addValue );
    myTracker.incrementCount( addValue );

    retValue = myTracker.decrementCount( addValue );
    REQUIRE( retValue );

    myTracker.print( sout );
    REQUIRE( sout.str() == "pickle (2)" );
}

