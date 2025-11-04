#ifndef STRINGTRACKER_H
#define STRINGTRACKER_H

#include <string>
#include <iostream>
using namespace std;

class StringTracker
{
    public:
        StringTracker();
        ~StringTracker();

        bool addString(const string& str);
        void print(ostream& out) const;

        // other functions

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