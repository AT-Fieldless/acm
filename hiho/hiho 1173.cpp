//
//  main.cpp
//  hiho 1173
//
//  Created by apple on 16/8/5.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
//int sg[110];
//int vis[110];
//sg函数打表
/*void init(){
    memset(sg, -1, sizeof(sg));
    sg[0] = 0;
    sg[1] = 1;
    sg[2] = 2;
}
int get_sg(int x){
    if (x == 0) {
        return 0;
    }
    if (x == 1) {
        return 1;
    }
    if (x == 2) {
        return 2;
    }
    if (sg[x]!=-1) {
        return sg[x];
    }
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    for (int i = 1; i<x; i++) {
        int t = 0;
        int a = get_sg(i);
        int b = get_sg(x-i);
        t ^= a;
        t ^= b;
        vis[a] = 1;
        vis[b] = 1;
        vis[t] = 1;
    }
    for (int i = 0; ; i++) {
        if (!vis[i]) {
            sg[x] = i;
            return i;
        }
    }
}*/
int sg(int x){
    if (x%4 == 0) {
        return x-1;
    }
    else if (x%4 == 3)
        return x+1;
    return x;
}
int main() {
    /*init();
    for (int i = 0; i<=100; i++) {
        get_sg(i);
    }
    for (int i = 0; i<=100; i++) {
        cout<<i<<' '<<sg[i]<<endl;
    }*/
    int n;
    while (~scanf("%d",&n)) {
        int ans = 0;
        for (int i = 0; i<n; i++) {
            int x;
            cin>>x;
            ans ^= sg(x);
        }
        if (ans) {
            cout<<"Alice"<<endl;
        }
        else
            cout<<"Bob"<<endl;
    }
    return 0;
}
