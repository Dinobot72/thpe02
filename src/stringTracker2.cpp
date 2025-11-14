#include "stringTracker.h"

int StringTracker::getMaximumcount() const
{
    if (head == nullptr) {
        return 0;
    }

    int maxCount = 0;
    Node* current = head;
    while (current != nullptr) {
        if (current->count > maxCount) {
            maxCount = current->count;
        }
        current = current->next;
    }
    return maxCount;
}

int StringTracker::size() const
{
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void StringTracker::clear()
{
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

void StringTracker::printPhrases( ostream& out ) const
{
    // create temporary node to traverse array
    Node *temp;
    temp = this->head;

    // until the array is empty
    while( temp != nullptr )
    {
        // print node
        out << temp->value << " (" << temp->count << ")";

        // if node is not the end then add coma
        if ( temp->next != nullptr )
        {
            out << ",";
        }
        temp = temp->next;
    }
}

void StringTracker::printCounters( ostream& out) const
{
    // create temporary node to traverse array
    Node *temp;
    temp = this->head;

    // until the array is empty
    while( temp != nullptr )
    {
        // print node
        out << temp->value << " (" << temp->count << ")";

        // if node is not the end then add coma
        if ( temp->next != nullptr )
        {
            out << ",";
        }
        temp = temp->next;
    }
}

bool StringTracker::empty() const
{
    Node *current = head;

    if (current == nullptr)
    {
        return true;
    }
    return false;
}