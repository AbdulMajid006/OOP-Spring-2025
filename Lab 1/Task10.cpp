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

void attendence(string event1[5], string event2[5])
{
    string check;
    int fond = 0;
    cout << "Enter the name to be checked: ";
    cin >> check;
    for (int i = 0; i < 5; i++)
    {
        if(check == event1[i])
        {
            cout << check << " is registered in event 1" << endl;
            fond = 1;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if(check == event2[i])
        {
            cout << check << " is registered in event 2" << endl;
            fond = 1;
        }
    }
    if(fond == 0)
    {
        cout << check << " is not present in any event" << endl;
    }
    
}

int donation()
{
    int total;
    total = 10*10;
    return total; 
}

void reverse(string event1[5],string event2[5])
{
    cout << "The names of participants in event 1 in reversed order are: " << endl;
    for (int i = 4; i >= 0; i--)
    {
        cout << event1[i] << endl;  
    }

    cout << "The names of participants in event 2 in reversed order are: " << endl;
    for (int i = 4; i >= 0; i--)
    {
        cout << event2[i] << endl;  
    }
}

void barchart()
{
    cout << "Event 1:" << endl;
    for (int  i = 0; i < 5; i++)
    {
        cout << "*";
    }
    cout << endl << "Event 2:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "*";
    }
}

int main()
{
    string event1[5];
    string event2[5];
    participants(event1, event2);
    attendence(event1, event2);
    cout << "The total donation collected from both events is: " << donation() << endl;
    reverse(event1, event2);
    barchart();
}
