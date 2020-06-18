#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <stdio.h>
using namespace std;


// 封装C接口
extern "C" {
// 创建对象
    void test(int* A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            A[i] = i;
        }
        for (int i = 0; i < n; i++) cout << A[i] << endl;
    }
}
