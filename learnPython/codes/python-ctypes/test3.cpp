#include <iostream>
#include <queue>
#include <vector>

using namespace std;


inline int Index(int x, int y, int L)
{
    return x * L + y;
}


extern "C" {
    void getTopN(int* A, int* ret, int n, int m, int topn)
    {
        const int len = n * topn;
        int k = len - 1;
        priority_queue<int, vector<int>, greater<int> > heap;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < topn; j++)
                heap.push(A[Index(i, j, m)]);

            for (int j = topn; j < m; j++)
            {
                heap.push(A[Index(i, j, m)]);
                heap.pop();
            }

            while (!heap.empty())
            {
                ret[k] = heap.top();
                k--;
                heap.pop();
            }
        }
        cout << "finished!" << endl;
    }
}
