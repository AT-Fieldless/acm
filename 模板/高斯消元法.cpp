//
//  main.cpp
//  hdu 5833
//
//  Created by apple on 16/8/16.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e3+10;
typedef double Matrix[maxn][maxn];
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
        for (j = n; j>=i; j--) {
            for (k = i+1; k<n; k++) {
                A[k][j] -= A[k][i]/A[i][i]*A[i][j];
            }
        }
        for (i = n-1; i>=0; i--) {
            for (j = i+1; j<n; j++) {
                A[i][n] -= A[j][n]*A[i][j];
            }
            A[i][n] /= A[i][i];
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
