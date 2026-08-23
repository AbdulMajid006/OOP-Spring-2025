#include "iostream"
using namespace std;
void inputAQI(int array[4][7])
{
    cout << "Enter the AQI values: " << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << "Enter the AQI value for city " << i + 1 << " day " << j + 1 << endl;
            cin >> array[i][j];
        }
        
    }
    
}

void average(int array[4][7])
{
    int totalAQI, highestavgAQI = 0, worstcity = 0;
    float avgAQI;
    for (int i = 0; i < 4; i++)
    {
        totalAQI = 0; 
        for (int j = 0; j < 7; j++)
        {
            totalAQI += array[i][j];
        }
        avgAQI = totalAQI/7;
        cout << "The average AQI of city " << i + 1 << " is: " << avgAQI << endl;
        if (avgAQI > highestavgAQI)
        {
            highestavgAQI = avgAQI;
            worstcity = i + 1;
        }
    }
    cout << "The city with the worst AQI is city " << worstcity << " with an average AQI of " << highestavgAQI << "." << endl;
}

void pollutedDays(int array[4][7])
{
    int found;
    cout << "AQI exceeded 150: " << endl;
    for(int i = 0; i < 4; i++)
    {
        found = 0;
        cout << "City " << i + 1 << ":" << endl;
        for (int j = 0; j < 7; j++)
        {
            if(array[i][j] > 150)
            {
                cout << "Day " << j + 1 << endl;
                found = 1;
            }
        }
        if(found == 0)
        {
            cout << "No day exceeded 150" << endl;
        }
        
    }
}

void visualization(int array[4][7])
{
    for (int i = 0; i < 4; i++)
    {
        cout << "Data Visualization of City " << i + 1 << ": " << endl;
        for (int j = 0; j < 7; j++)
        {
            cout << "Week " << j + 1 << ": ";
            if(array[i][j] >= 50)
            {
                for (int k = 0; k < array[i][j]/50; k++)
                {
                    cout << "*";                    
                }
            }
            cout << endl;
        }
        
    }
    
}

int  main()
{
    int array[4][7];
    inputAQI(array);
    average(array);
    pollutedDays(array);
    visualization(array);   
}
