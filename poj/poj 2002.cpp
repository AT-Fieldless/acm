//
//  main.cpp
//  poj 2002
//
//  Created by apple on 16/8/8.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e5;
const int mod = 10007;
int hash_table[maxn];
int px[maxn];
int py[maxn];
int sum;
struct node{
    int x;
    int y;
    int next;
}h[maxn];
void init(){
    for (int i = 0; i<maxn; i++) {
        hash_table[i] = -1;
        h[i].next = -1;
    }
    sum = 0;
}
void insert(int x,int y){
    int temp =(x*x+y*y)%mod;
    h[sum].x = x;
    h[sum].y = y;
    h[sum].next = hash_table[temp];
    hash_table[temp] = sum;
    sum++;
}
bool f(int x,int y){
    int temp = (x*x+y*y)%mod;
    temp = hash_table[temp];
    while (temp!=-1) {
        if (h[temp].x == x&&h[temp].y == y) {
            return true;
        }
        temp = h[temp].next;
    }
    return false;
}
int main(int argc, const char * argv[]) {
    int n;
    while (scanf("%d",&n)&&n) {
        init();
        for (int i = 0; i<n; i++) {
            scanf("%d%d",&px[i],&py[i]);
            insert(px[i], py[i]);
        }
        int ans = 0;
        for (int i = 0; i<n; i++) {
            for (int j = i+1; j<n; j++) {
                int x3 = px[i]+(py[i]-py[j]);
                int y3 = py[i]-(px[i]-px[j]);
                int x4 = px[j]+(py[i]-py[j]);
                int y4 = py[j]-(px[i]-px[j]);
                ans+=(f(x3,y3)&&f(x4, y4));
            }
        }
        for (int i = 0; i<n; i++) {
            for (int j = i+1; j<n; j++) {
                int x3 = px[i]-(py[i]-py[j]);
                int y3 = py[i]+(px[i]-px[j]);
                int x4 = px[j]-(py[i]-py[j]);
                int y4 = py[j]+(px[i]-px[j]);
                ans+=(f(x3,y3)&&f(x4, y4));
            }
        }
        ans>>=2;
        cout<<ans<<endl;
    }
    return 0;
}
