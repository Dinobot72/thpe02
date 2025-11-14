#include <sstream>
#include "stringTracker.h"
#include <catch2/catch_test_macros.hpp> 

// empty test cases
TEST_CASE( "StringTracker::empty() - check empty for empty list" )
{
    bool retValue;
    StringTracker myTracker;

    retValue = myTracker.empty();
    REQUIRE( retValue );
}

TEST_CASE( "StringTracker::empty() - check empty for non-empty list" )
{
    bool retValue;
    StringTracker myTracker;

    myTracker.addString("Bananas");

    retValue = myTracker.empty();
    REQUIRE( !retValue );
}

TEST_CASE("StringTracker::empty() - check empty for empty and non-empty list")
{
    bool retValue;
    StringTracker myTracker;

    retValue = myTracker.empty();
    REQUIRE( retValue );

    myTracker.addString("Bananas");

    retValue = myTracker.empty();
    REQUIRE( !retValue );
}


// size test cases
TEST_CASE("StringTracker::size() - check size for empty list")
{
    StringTracker myTracker;
    REQUIRE( myTracker.size() == 0 );
}

TEST_CASE( "StringTracker::size() - check size for non-empty list" )
{
    StringTracker myTracker;
    myTracker.addString("one");
    myTracker.addString("two");
    myTracker.addString("three");
    REQUIRE( myTracker.size() == 3 );
}

TEST_CASE("StringTracker::size() - check size for large non-empty list")
{
    int i;
    StringTracker myTracker;
    for (i = 0; i < 100; i++)
    {
        myTracker.addString(to_string(i));
    }
    REQUIRE( myTracker.size() == 100 );
}


// clear test cases
TEST_CASE("StringTracker::clear() - clear an empty list")
{
    StringTracker myTracker;
    myTracker.clear();
    REQUIRE( myTracker.empty() );
    REQUIRE( myTracker.size() == 0 );
}

TEST_CASE( "StringTracker::clear() - clear a list with multiple items" )
{
    StringTracker myTracker;
    myTracker.addString("one");
    myTracker.addString("two");
    myTracker.addString("three");

    myTracker.clear();
    REQUIRE( myTracker.empty() );
    REQUIRE( myTracker.size() == 0 );
}

TEST_CASE("StringTracker::clear() - clear a list with 1 items")
{
    StringTracker myTracker;
    myTracker.addString("one");

    myTracker.clear();
    REQUIRE( myTracker.empty() );
    REQUIRE( myTracker.size() == 0 );
}


// maximum test cases
TEST_CASE("StringTracker::getMaximumcount() - empty list")
{
    StringTracker myTracker;
    REQUIRE( myTracker.getMaximumcount() == 0 );
}

TEST_CASE( "StringTracker::getMaximumcount() - list with one item" )
{
    StringTracker myTracker;
    myTracker.addString("hello");
    myTracker.incrementCount("hello");
    myTracker.incrementCount("hello");
    REQUIRE( myTracker.getMaximumcount() == 3 );
}

TEST_CASE( "StringTracker::getMaximumcount() - list with multiple items" )
{
    StringTracker myTracker;
    myTracker.addString("apple"); 
    myTracker.addString("banana"); 
    myTracker.incrementCount("banana"); 
    myTracker.incrementCount("banana"); 
    myTracker.addString("cherry"); 
    myTracker.incrementCount("cherry"); 
    REQUIRE( myTracker.getMaximumcount() == 3 );
}


// print phases test cases
TEST_CASE( "StringTracker::printPhrases() - single item prints without comma" )
{
    StringTracker myTracker;
    myTracker.addString("solo");

    std::ostringstream out;
    myTracker.printPhrases(out);

    REQUIRE( out.str() == "solo" );
}

TEST_CASE( "StringTracker::printPhrases() - empty list prints nothing" )
{
    StringTracker myTracker;
    std::ostringstream out;

    myTracker.printPhrases(out);

    REQUIRE( out.str() == "" );
}

TEST_CASE( "StringTracker::printPhrases() - correct comma formatting with multiple items" )
{
    StringTracker myTracker;
    myTracker.addString("alpha");
    myTracker.addString("beta");
    myTracker.addString("gamma");

    std::ostringstream out;
    myTracker.printPhrases(out);

    REQUIRE( out.str() == "alpha,beta,gamma" );
}


// print counters test cases
TEST_CASE( "StringTracker::printCounters() - single count" )
{
    StringTracker myTracker;
    myTracker.addString("test");

    std::ostringstream out;
    myTracker.printCounters(out);

    REQUIRE( out.str() == "1" );
}

TEST_CASE( "StringTracker::printCounters() - multiple counts formatted correctly" )
{
    StringTracker myTracker;
    myTracker.addString("a");   // 1
    myTracker.addString("b");   // 1
    myTracker.incrementCount("b"); // 2
    myTracker.addString("c");   // 1

    std::ostringstream out;
    myTracker.printCounters(out);

    REQUIRE( out.str() == "1,2,1" );
}

TEST_CASE( "StringTracker::printCounters() - empty list prints nothing" )
{
    StringTracker myTracker;
    std::ostringstream out;

    myTracker.printCounters(out);

    REQUIRE( out.str() == "" );
}
