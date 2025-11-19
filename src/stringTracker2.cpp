#include "stringTracker.h"

// Return the highest count among all nodes.
// If empty, return 0.
int StringTracker::getMaximumcount() const
{
    int maxCount = 0;

    if ( head == nullptr )
        return 0;
    
    Node* current = head;

    // going through linked list
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
    // variables
    int count = 0;
    Node* current = head;

    // going through linked list
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

    // going through linked list
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
    char currentHeader = '\0';
    char firstChar;
    int colCount = 0;

    // check for null head
    if (head == nullptr) {
        return;
    }

    Node* current = head;

    while ( current != nullptr )
    {
         firstChar = current->value[0];

        if (firstChar != currentHeader) {
            if ( colCount != 0 )
            {
                out << endl;
                colCount = 0;
            }

            if (currentHeader != '\0') {
                out << endl ;
            }

            currentHeader = firstChar;

            out << "***************************************************************************" << endl;
            out << "*  Phrases Starting With: " << firstChar << endl;
            out << "***************************************************************************" << endl;
        }

        out << left << setw(25) << current->value;
        colCount++;

        if (colCount == 3) {
            out << endl; 
            colCount = 0;
        }

        current = current->next;
    }

    if (colCount != 0) {
        out << endl;
    }
}


// Print only the counters (count values) in order.
void StringTracker::printCounters( ostream& out ) const
{
    bool hasItems = false;

    if ( head == nullptr ) return;

    int maxCount = getMaximumcount();
    bool firstSectionPrinted = false;

    // Loop from highest count down to 1
    for ( int i = maxCount; i > 0; i-- )
    {
        // 1. Check if any node has this specific count before printing header
        Node* checker = head;
        hasItems = false;
        while ( checker != nullptr )
        {
            if ( checker->count == i )
            {
                hasItems = true;
                break;
            }
            checker = checker->next;
        }

        // If no items have this count, skip to next number
        if ( !hasItems ) 
        {
            continue;
        }

        // 2. Print spacing and header
        if ( firstSectionPrinted )
        {
            out << endl;
        }

        out << "***************************************************************************" << endl;
        out << "*  Phrases With Counts Of: " << i << endl;
        out << "***************************************************************************" << endl;

        
        firstSectionPrinted = true;

        // 3. Print items with this count
        int colCount = 0;
        Node* current = head;
        
        while ( current != nullptr )
        {
            if ( current->count == i )
            {
                out << left << setw(25) << current->value;
                colCount++;

                if ( colCount == 3 )
                {
                    out << endl;
                    colCount = 0;
                }
            }
            current = current->next;
        }

        // Clean up newline for the section
        if ( colCount != 0 )
        {
            out << endl;
        }
    }
}


// True if list is empty. False if it isn't.
bool StringTracker::empty() const
{
    // if empty this should return true, if it isn't then it returns false
    return head == nullptr;
}