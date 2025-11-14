#include <sstream>
#include "stringTracker.h"

// addString tests
TEST_CASE( "StringTracker::addString - add 'pickle' to empty list" )
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

TEST_CASE( "StringTracker::addString - add 'sandwich' to list of 1" )
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
    REQUIRE( sout.str() == "pickle (1),sandwich (1)" );
}

TEST_CASE( "StringTracker::addString - add 'mayo' to list containing mayo" )
{
    bool retValue;
    string stringValue = "mayo";
    string addValue[4] = {"cheese", "mayo", "sandwich", "pickle"};
    ostringstream sout;


    StringTracker myTracker;

    myTracker.addString( addValue[0] );
    myTracker.addString( addValue[1] );
    myTracker.addString( addValue[2] );
    myTracker.addString( addValue[3] );

    retValue = myTracker.addString( stringValue );
    REQUIRE( retValue );

    myTracker.print( sout );
    REQUIRE( sout.str() == "cheese (1),mayo (1),pickle (1),sandwich (1)" );
}

// incrementCount tests
TEST_CASE( "StringTracker::incrementCount - increment 'pickle' to count of 2" )
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

TEST_CASE( "StringTracker::incrementCount - increment 'pickle' to count of 7" )
{
    bool retValue;
    string addValue = "pickle";
    ostringstream sout;

    StringTracker myTracker;

    myTracker.addString( addValue );

    retValue = myTracker.incrementCount( addValue );
    REQUIRE( retValue );

    myTracker.incrementCount( addValue );
    myTracker.incrementCount( addValue );
    myTracker.incrementCount( addValue );
    myTracker.incrementCount( addValue );
    myTracker.incrementCount( addValue );

    myTracker.print( sout );
    REQUIRE( sout.str() == "pickle (7)" );
}

TEST_CASE( "StringTracker::incrementCount - fail to increment 'pickle'" )
{
    bool retValue;
    string addValue = "pickle";

    StringTracker myTracker;

    retValue = myTracker.incrementCount( addValue );
    REQUIRE( !retValue );
}

// decrementCount tests
TEST_CASE( "StringTracker::dencrementCount - dencrement 'pickle' to count of 2" )
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

TEST_CASE( "StringTracker::decrementCount - dencrement 'mayo' to count of 0" )
{
    bool retValue;
    string addValue[4] = {"cheese", "mayo", "sandwich", "pickle"};
    ostringstream sout;


    StringTracker myTracker;

    myTracker.addString( addValue[0] );
    myTracker.addString( addValue[1] );
    myTracker.addString( addValue[2] );
    myTracker.addString( addValue[3] );

    retValue = myTracker.decrementCount( addValue[1] );
    REQUIRE( retValue );

    myTracker.print( sout );
    REQUIRE( sout.str() == "cheese (1),mayo (0),pickle (1),sandwich (1)" );

}

TEST_CASE( "StringTracker::decrementCount - fail to decrement 'pickle'" )
{
    bool retValue;
    string addValue = "pickle";

    StringTracker myTracker;

    retValue = myTracker.decrementCount( addValue );
    REQUIRE( !retValue );
}

// print tests
TEST_CASE( "StringTracker::print - print list of 4" )
{
    string stringValue = "mayo";
    string addValue[4] = {"cheese", "mayo", "sandwich", "pickle"};
    ostringstream sout;


    StringTracker myTracker;

    myTracker.addString( addValue[0] );
    myTracker.addString( addValue[1] );
    myTracker.addString( addValue[2] );
    myTracker.addString( addValue[3] );


    myTracker.print( sout );
    REQUIRE( sout.str() == "cheese (1),mayo (1),pickle (1),sandwich (1)" );
}

TEST_CASE( "StringTracker::print - print list of 1" )
{
    bool retValue;
    string stringValue = "mayo";
    ostringstream sout;

    StringTracker myTracker;

    retValue = myTracker.addString( stringValue );
    REQUIRE( retValue );

    myTracker.print( sout );
    REQUIRE( sout.str() == "mayo (1)" );
}

TEST_CASE( "StringTracker::print - print empty list" )
{
    StringTracker myTracker;
    ostringstream sout;

    myTracker.print( sout );
    REQUIRE( sout.str() == "" );

}

// removeString tests
TEST_CASE( "StringTracker::removeString - remove 'pickle'" )
{
    bool retValue;
    string stringValue = "pickle";
    string addValue[4] = {"cheese", "mayo", "sandwich", "pickle"};
    ostringstream sout;


    StringTracker myTracker;

    myTracker.addString( addValue[0] );
    myTracker.addString( addValue[1] );
    myTracker.addString( addValue[2] );
    myTracker.addString( addValue[3] );

    retValue = myTracker.removeString( stringValue );
    REQUIRE( retValue );

    myTracker.print( sout );
    REQUIRE( sout.str() == "cheese (1),mayo (1),sandwich (1)" );
}

TEST_CASE( "StringTracker::removeString - fail to remove 'mayo' from empty list" )
{
    bool retValue;
    string stringValue = "mayo";

    StringTracker myTracker;

    retValue = myTracker.removeString( stringValue );
    REQUIRE( !retValue );
}

TEST_CASE( "StringTracker::removeString - remove 'pickle' to count of 1" )
{
    bool retValue;
    string stringValue = "pickle";
    string addValue[4] = {"cheese", "mayo", "sandwich", "pickle"};
    ostringstream sout;


    StringTracker myTracker;

    myTracker.addString( addValue[0] );
    myTracker.addString( addValue[1] );
    myTracker.addString( addValue[2] );
    myTracker.addString( addValue[3] );

    myTracker.addString( stringValue );

    retValue = myTracker.removeString( stringValue );
    REQUIRE( retValue );

    myTracker.print( sout );
    REQUIRE( sout.str() == "cheese (1),mayo (1),sandwich (1)" );
}

// getCount tests
TEST_CASE( "StringTracker::getCount - get count of 'pickle'  at count of 4" )
{
    int retValue;
    string addValue[4] = {"cheese", "mayo", "sandwich", "pickle"};

    StringTracker myTracker;

    myTracker.addString( addValue[0] );
    myTracker.addString( addValue[1] );
    myTracker.addString( addValue[2] );
    myTracker.addString( addValue[3] );
    myTracker.incrementCount( addValue[3] );
    myTracker.incrementCount( addValue[3] );
    myTracker.incrementCount( addValue[3] );

    retValue = myTracker.getCount( addValue[3] );
    REQUIRE( retValue == 4 );

}

TEST_CASE( "StringTracker::getCount - get count of 'mayo' at count of 2" )
{
    int retValue;
    string addValue[4] = {"cheese", "mayo", "sandwich", "pickle"};

    StringTracker myTracker;

    myTracker.addString( addValue[0] );
    myTracker.addString( addValue[1] );
    myTracker.incrementCount( addValue[1] );
    myTracker.addString( addValue[2] );
    myTracker.addString( addValue[3] );

    retValue = myTracker.getCount( addValue[1] );
    REQUIRE( retValue == 2 );
}

TEST_CASE( "StringTracker::getCount - fail to get count and return 0" )
{
    bool retValue;
    string addValue[4] = {"cheese", "mayo", "sandwich", "pickle"};

    StringTracker myTracker;

    myTracker.addString( addValue[0] );
    myTracker.addString( addValue[1] );
    myTracker.addString( addValue[2] );
    myTracker.addString( addValue[3] );

    retValue = myTracker.getCount( "notExistent" );
    REQUIRE( retValue == 0 );
}

// findString tests
TEST_CASE( "StringTracker::findString - find 'pickle'" )
{
    bool retValue;
    string stringValue = "pickle";

    StringTracker myTracker;

    myTracker.addString( stringValue );

    retValue = myTracker.findString( stringValue );
    REQUIRE( retValue );
}

TEST_CASE( "StringTracker::findString - find 'Giant Chicken Lazer Monkeys'" )
{
    bool retValue;
    string stringValue = "Giant Chicken Lazer Monkeys";
    string addValue[4] = {"cheese", "mayo", "sandwich", "pickle"};

    StringTracker myTracker;

    myTracker.addString( addValue[0] );
    myTracker.addString( addValue[1] );
    myTracker.addString( addValue[2] );
    myTracker.addString( addValue[3] );

    myTracker.addString( stringValue );

    retValue = myTracker.findString( stringValue );
    REQUIRE( retValue );
}

TEST_CASE("StringTracker::findString - doesn't find 'pickle'")
{
    bool retValue;
    string stringValue = "pickle";

    StringTracker myTracker;

    retValue = myTracker.findString( stringValue );
    REQUIRE( !retValue );
}