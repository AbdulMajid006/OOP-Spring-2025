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
    int totalAQI, worstcity = 0;
    float avgAQI, highestavgAQI = 0;
    for (int i = 0; i < 4; i++)
    {
        totalAQI = 0; 
        for (int j = 0; j < 7; j++)
        {
            totalAQI += array[i][j];
        }
        avgAQI = static_cast<float>(totalAQI)/7;
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
            cout << "Day " << j + 1 << ": ";
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
        avrg = static_cast<float>(total)/28;
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
        week1avg = static_cast<float>(week1)/7;
        week4 = 0;
        for (int j = 21; j < 28; j++)
        {
            week4 += array1[i][j];
        }
        week4avg = static_cast<float>(week4)/7;
        improvement = week1avg - week4avg;
        if(improvement > maximprovement)
        {
            maximprovement = static_cast<float>(improvement);
            improvedcity = i;
        }
    }
    cout << "The city with the most improved air quality: city " << improvedcity + 1 << endl;
    cout << "Improvement: " << maximprovement << endl;
    
}

void report(int array1[4][28])
{
    int w1, w2, w3, w4;
    float aw1, aw2, aw3, aw4;
    cout << endl << "----------------------------------------------------------------" << endl;
    cout << "Report: " << endl;
    cout << endl << "Weekly Averages: " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "Weekly averages for city " << i + 1 << ": " << endl;
        w1 = 0;
        cout << "Week 1: ";
        for (int j = 0; j < 7; j++)
        {
            w1 += array1[i][j];

        }
        aw1 = static_cast<float>(w1)/7;
        cout << aw1 << endl;
        w2 = 0;
        cout << "Week 2: ";
        for (int j = 7; j < 14; j++)
        {
            w2 += array1[i][j];

        }
        aw2 = static_cast<float>(w2)/7;
        cout << aw2 << endl;
        w3 = 0;
        cout << "Week 3: ";
        for (int j = 14; j < 21; j++)
        {
            w3 += array1[i][j];

        }
        aw3 = static_cast<float>(w3)/7;
        cout << aw3 << endl;
        w4 = 0;
        cout << "Week 4: ";
        for (int j = 21; j < 28; j++)
        {
            w4 += array1[i][j];

        }
        aw4 = static_cast<float>(w4)/7;
        cout << aw4 << endl;
    }

    int present;
    cout << endl << "Critical Pollution days for each city: " << endl;
    for (int i = 0; i < 4; i++)
    {
        present = 0;
        cout << "City " << i + 1 << ": " << endl;
        for (int j = 0; j < 28; j++)
        {
            if(array1[i][j] > 150)
            {
                cout << "Day " << j + 1 << endl;
                present = 1;
            }

        }
        if(present == 0)
        {
            cout << "No critical polluted days" << endl;
        }
        
    }
    
    int highest, lowest, hiday = 0, loday = 0, compare;
    for (int i = 0; i < 4; i++)
    {
        compare = 0;
        highest = array1[i][0];
        lowest = array1[i][0];
        cout << endl << "City " << i + 1 << ": " << endl;
        for (int j = 0; j < 28; j++)
        {
            if(array1[i][j] > highest)
            {
                highest = array1[i][j];
                hiday = j + 1;
            }
            if(array1[i][j] < lowest)
            {
                lowest = array1[i][j];
                loday = j + 1;
            }
        }
        cout << "Highest AQI: " << highest << " at Day " << hiday << endl;
        cout << "Lowest AQI: " << lowest << " at Day " << loday << endl;
        compare = highest - lowest;
        cout << "Difference between highest and lowest AQI: " << compare << endl;

    }

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
    report(array1);  
}
