#include "stringTracker.h"

// Return the highest count among all nodes.
// If empty, return 0.
int StringTracker::getMaximumcount() const
{
    int maxCount = 0;

    if ( head == nullptr )
        return 0;
    
    Node* current = head;

    while ( current != nullptr )
    {
        if ( current->count > maxCount )
            maxCount = current->count;
        current = current->next;
    }

    return maxCount;
}


// Return number of nodes in the list.
int StringTracker::size() const
{
    int count = 0;
    Node* current = head;

    while ( current != nullptr )
    {
        count++;
        current = current->next;
    }

    return count;
}


// Delete all nodes and reset head to nullptr
void StringTracker::clear()
{
    Node* current = head;

    while ( current != nullptr )
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    head = nullptr;
}


// Print only the phrases (string values) in sorted order.
void StringTracker::printPhrases( ostream& out ) const
{
    Node* current = head;

    while ( current != nullptr )
    {
        out << current->value;

        if ( current->next != nullptr )
            out << ",";

        current = current->next;
    }
}


// Print only the counters (count values) in order.
void StringTracker::printCounters( ostream& out ) const
{
    Node* current = head;

    while ( current != nullptr )
    {
        out << current->count;

        if ( current->next != nullptr )
            out << ",";

        current = current->next;
    }
}


// True if list is empty. False if it isn't.
bool StringTracker::empty() const
{
    return head == nullptr;
}