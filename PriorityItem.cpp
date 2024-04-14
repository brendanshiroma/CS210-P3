#include <string>
#include <iostream>
#include "PriorityItem.h"
using namespace std;

// Constructor.  Creates a new PriorityItem instance.
PriorityItem::PriorityItem(int pri, string priData) : priority(pri), data(priData) {}
// standard get methods
int PriorityItem::getPriority() {
    return priority;
}
string PriorityItem::getData() {
    return data;
}

// Overloaded relational operators
bool PriorityItem::operator<(PriorityItem other) {
    return priority < other.priority;
}

bool PriorityItem::operator>(PriorityItem other) {
    return priority > other.priority;
}

bool PriorityItem::operator<=(PriorityItem other) {
    return priority <= other.priority;
}

bool PriorityItem::operator>=(PriorityItem other) {
    return priority >= other.priority;
}

bool PriorityItem::operator==(PriorityItem other) {
    return priority == other.priority;
}

bool PriorityItem::operator!=(PriorityItem other) {
    return priority != other.priority;
}

// Overloaded output operator
ostream& operator<<(ostream& os, const PriorityItem& pri)
{
    os << "[priority=" << pri.priority << ", data=" << pri.data << "]";
    return os;
}
  
