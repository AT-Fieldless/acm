//
//  main.cpp
//  poj 2345
//
//  Created by apple on 16/8/17.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1e3+10;
typedef int Matrix[maxn][maxn];
//要求系数矩阵可逆
//这里的A是增广矩阵，即A[i][n]是第i个方程右边的常数bi。
//运行结束后A[i][n]是第i个未知数的值
void gauss_elimination(Matrix A,int n){
    int i,j,k,r;
    //消元过程
    for (i = 0; i<n; i++) {
        //选一行r并与第i行交换
        r = i;
        for (j = i+1; j<n; j++) {
            if (fabs(A[j][i])>fabs(A[r][i])) {
                r = j;
            }
        }
        if (r!=i) {
            for (int j = 0; j<=n; j++) {
                swap(A[r][j], A[i][j]);
            }
        }
        //与第i+1~n行进行消元
        for (k = i+1; k<n; k++) {
            if (A[k][i]) {
                for (j = i; j<=n; j++) {
                    A[k][j] ^= A[i][j];
                }
            }
        }
    }
    for (i = n-1; i>=0; i--) {
        int temp = 0;
        for (j = i+1; j<n; j++) {
            temp ^= A[j][n]&A[i][j];
        }
        A[i][n] -= temp;
    }
}
int main() {
    int n;
    while (~scanf("%d",&n)) {
        Matrix A;
        for (int i = 0; i<n; i++) {
            int x;
            cin>>x;
            while (x!=-1) {
                x--;
                A[x][i] = 1;
                cin>>x;
            }
            A[i][n] = 1;
        }
        gauss_elimination(A, n);
        int flag = 0;
        for (int i = 0; i<n; i++) {
            if (A[i][n]) {
                if (!flag) {
                    cout<<i+1;
                    flag = 1;
                }
                else
                    cout<<' '<<i+1;
            }
        }
        cout<<endl;
    }
    return 0;
}
