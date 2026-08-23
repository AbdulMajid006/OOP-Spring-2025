#include <iostream>

using namespace std;

int main() 
{
    int m, n;
    cout << "Enter the rows and columns of matrix: ";
    cin >> m >> n;
    cout << "Enter the elements of matrix: ";
    int **a = new int*[m];
    for (int i = 0; i < m; i++) 
    {
        a[i] = new int[n];
    }
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> a[i][j];
        }
    }

    int **t = new int*[n];
    for (int i = 0; i < n; i++) 
    {
        t[i] = new int[m];
    }
    
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            t[j][i] = a[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < m; i++) 
    {
        delete[] a[i];
    }
    delete[] a;

    for (int i = 0; i < n; i++) 
    {
        delete[] t[i];
    }
    delete[] t;
    return 0;
}
