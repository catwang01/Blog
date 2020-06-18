#include <iostream>

using namespace std;


inline int Index(int x, int y, int L)
{
    return x * L + y;
}

extern "C" {
    void print(int* A, int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << A[Index(i, j, m)] << endl;
            }
        }
    }
}
