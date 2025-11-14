#ifndef STRINGTRACKER_H
#define STRINGTRACKER_H

#include <string>
#include <iostream>
#include <catch2/catch_test_macros.hpp> 
using namespace std;

class StringTracker
{
    public:
        StringTracker() : head( nullptr ) {}
        ~StringTracker() 
        {
            Node* current = head;
            while ( current != nullptr )
            {
                Node* nextNode = current->next;
                delete current;
                current = nextNode;
            }
        }
        

        // Teammate 1's functions
        bool addString( const string& str );
        void print( ostream& out ) const;
        bool removeString( const string& str );
        bool findString( const string str ) const;
        bool incrementCount( const string str );
        bool decrementCount( const string str );
        int getCount( const string str ) const;


        // Teammate 2's functions
        int getMaximumcount() const;
        int size() const;
        void clear();
        void printPhrases( ostream& out ) const;
        void printCounters( ostream& out) const;
        bool empty() const;

    private:
        struct Node
        {
            string value;
            int count;
            Node* next;
        };
        Node* head;
};

#endif