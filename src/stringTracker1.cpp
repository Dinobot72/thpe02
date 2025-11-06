#include "stringTracker.h"

StringTracker::StringTracker()
{
    Node *head = nullptr;
}

StringTracker::~StringTracker()
{
    clear();
}

bool StringTracker::empty() const
{
    return head == nullptr;
}


bool StringTracker::addString( const string& str )
{
    return true;
}

void StringTracker::print( ostream& out ) const
{
    Node *temp;
    temp = this->head;
    while( temp != nullptr )
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}

bool StringTracker::removeString( const string& str )
{
    return true;

}

bool StringTracker::findString( const string str ) const
{
    Node *temp;
    temp = this->head;
    while( temp != nullptr )
    {
        if( temp->value == str )
        return true;

        temp = temp->next;
    }

}

bool StringTracker::incrementCount( const string str )
{
    return true;

}

bool StringTracker::decrementCount( const string str )
{
    return true;

}