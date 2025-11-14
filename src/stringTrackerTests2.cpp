#include <sstream>
#include "stringTracker.h"
#include <catch2/catch_test_macros.hpp> 

TEST_CASE("StringTracker::empty() - check empty for empty list")
{
    bool retValue;
    StringTracker myTracker;

    retValue = myTracker.empty();
    REQUIRE( retValue );
}

TEST_CASE("StringTracker::empty() - check empty for non-empty list")
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

TEST_CASE("StringTracker::size() - check size for empty list")
{
    StringTracker myTracker;
    REQUIRE( myTracker.size() == 0 );
}

TEST_CASE("StringTracker::size() - check size for non-empty list")
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

TEST_CASE("StringTracker::clear() - clear an empty list")
{
    StringTracker myTracker;
    myTracker.clear();
    REQUIRE( myTracker.empty() );
    REQUIRE( myTracker.size() == 0 );
}

TEST_CASE("StringTracker::clear() - clear a list with multiple items")
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

TEST_CASE("StringTracker::getMaximumcount() - empty list")
{
    StringTracker myTracker;
    REQUIRE( myTracker.getMaximumcount() == 0 );
}

TEST_CASE("StringTracker::getMaximumcount() - list with one item")
{
    StringTracker myTracker;
    myTracker.addString("hello");
    myTracker.incrementCount("hello");
    myTracker.incrementCount("hello");
    REQUIRE( myTracker.getMaximumcount() == 3 );
}

TEST_CASE("StringTracker::getMaximumcount() - list with multiple items")
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
