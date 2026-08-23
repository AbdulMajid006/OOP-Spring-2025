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
    cout << "The city with the worst AQI is city " << worstcity << " with an average AQI of " << highestavgAQI << endl;
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

void monthlyAQI(int array1[4][28])
{
    cout << "Enter the AQI values for the entire month (28 days): " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter the AQI value for City " << i + 1 << ":" << endl;
        for (int j = 0; j < 28; j++)
        {
            cout << "Day " << j + 1 << ": ";
            cin >> array1[i][j];
        }
        
    }

    int total;
    float avrg;
    for (int i = 0; i < 4; i++)
    {
        total = 0;
        for (int j = 0; j < 28; j++)
        {
            total += array1[i][j];
        }
        avrg = total/28;
        cout << "The monthly average AQI of city " << i + 1 << " is: " << avrg << endl;
        
    }
    
    int week1, week4, improvedcity = 0;
    float week1avg, week4avg, improvement, maximprovement = 0;
    for (int i = 0; i < 4; i++)
    {
        week1 = 0;
        for (int j = 0; j < 7; j++)
        {
            week1 += array1[i][j];
        }
        week1avg = week1/7;
        week4 = 0;
        for (int j = 21; j < 28; j++)
        {
            week4 += array1[i][j];
        }
        week4avg = week4/7;
        improvement = week1avg - week4avg;
        if(improvement > maximprovement)
        {
            maximprovement = improvement;
            improvedcity = i;
        }
    }
    cout << "The city with the most improved air quality: city " << improvedcity + 1 << endl;
    cout << "Improvement: " << maximprovement;
    
}

int  main()
{
    int array[4][7];
    inputAQI(array);
    average(array);
    pollutedDays(array);
    visualization(array); 
    int array1[4][28];
    monthlyAQI(array1);  
}
