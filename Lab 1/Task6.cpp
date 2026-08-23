#include "iostream"
using namespace std;

void participants(string event1[5], string event2[5])
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter name " << i + 1 << " for event 1: ";
        cin >> event1[i];  
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter name " << i + 1 << " for event 2: ";
        cin >> event2[i];  
    }
}

int main()
{
    string event1[5];
    string event2[5];
    participants(event1, event2);
}
