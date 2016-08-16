//
//  main.cpp
//  uva 10870
//
//  Created by apple on 16/8/16.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100;
int d,n,m;
struct matrix{
    long long a[maxn][maxn];
};
matrix mul(matrix a,matrix b){
    matrix c;
    for (int i = 0; i<=d; i++) {
        for (int j = 0; j<=d; j++) {
            c.a[i][j] = 0;
        }
    }
    for (int i = 0; i<d; i++) {
        for (int j = 0; j<d; j++) {
            for (int k = 0; k<d; k++) {
                c.a[i][j] += a.a[i][k]*b.a[k][j];
                c.a[i][j] %= m;
            }
        }
    }
    //for (int i = 0; i<=d; i++) {
      //  for (int j = 0; j<=d; j++) {
            //cout<<c.a[i][j]<<' ';
        //}
        //cout<<endl;
    //}
    return c;
}
matrix mod_pow(matrix x,int k){
    matrix c;
    for (int i = 0; i<d; i++) {
        for (int j = 0; j<d; j++) {
            c.a[i][j] = (i == j);
        }
    }
    while (k) {
        if (k&1) {
            c = mul(c, x);
        }
        x = mul(x, x);
        k>>=1;
    }
    return c;
}
int main() {
    while (~scanf("%d%d%d",&d,&n,&m)&&(d&&n&&m)) {
        matrix x,y;
        for (int i = 0; i<d; i++) {
            scanf("%lld",&x.a[0][i]);
        }
        for (int i = 1; i<d; i++) {
            for (int j = 0; j<d; j++) {
                x.a[i][j] = (i == (j+1));
            }
        }
        for (int i = 0; i<d; i++) {
            scanf("%lld",&y.a[d-i-1][0]);
        }
        int temp = 0;
        x = mod_pow(x, n-d);
        y = mul(x, y);
        printf("%lld\n",y.a[0][0]);
    }
    return 0;
}
/*
1 1 100 
2
1
 
2 10 100 
1 1
1 1
 
3 2147483647 12345 
12345678 0 12345 
1 2 3
 
0 0 0
*/