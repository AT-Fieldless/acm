//
//  main.cpp
//  hdu 1217
//
//  Created by apple on 16/7/17.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <cstring>
using namespace std;
double dis[50][50];
int main() {
    int n,kase = 1;
    while (cin>>n&&n) {
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                dis[i][j] = 0;
            }
        }
        map<string, int>mp;
        for (int i = 0; i<n; i++) {
            string a;
            cin>>a;
            mp[a] = i;
        }
        int m;
        scanf("%d",&m);
        for (int i = 0; i<m; i++) {
            string a,b;
            double sum;
            cin>>a>>sum>>b;
            dis[mp[a]][mp[b]] = max(sum,dis[mp[a]][mp[b]]);
        }
        for (int k = 0; k<n; k++) {
            for (int i = 0; i<n; i++) {
                for (int j = 0; j<n; j++) {
                    dis[i][j] = max(dis[i][j], dis[i][k]*1.0*dis[k][j]);
                    //cout<<dis[i][k]*dis[k][j]<<' ';
                }
                //cout<<endl;
            }
        }
        int flag = 0;
        for (int i = 0; i<n; i++) {
            if (dis[i][i]>1) {
                flag = 1;
            }
        }
        printf("Case %d: ",kase++);
        if (flag) {
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
    }
    return 0;
}
