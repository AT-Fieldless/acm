//
//  main.cpp
//  cf 725D
//
//  Created by apple on 2016/10/27.
//  Copyright © 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn = 301000;
long long t[maxn];
long long w[maxn];
long long temp[maxn];
struct xixi{
    long long w,t;
};
bool operator <(xixi a,xixi b){
    return a.t<b.t;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    priority_queue<long long,vector<long long>, greater<long long>>q;
    priority_queue<xixi>q2;
    int n;
    scanf("%d",&n);
    cin>>t[0]>>w[0];
    for (int i = 1; i<n; i++) {
        cin>>t[i]>>w[i];
        temp[i] = w[i]-t[i]+1;
        if (t[i]>t[0]) {
            q.push(temp[i]);
        }
        else{
            xixi c;
            c.w = w[i];
            c.t = t[i];
            q2.push(c);
        }
    }
    //cout<<q2.size()<<endl;
    int ans = q.size();
    while (q.size()&&t[0]>=q.top()) {
       // cout<<q.size()<<' '<<q.top()<<endl;
            t[0] -= q.top();
            q.pop();
            while (q2.size()&&q2.top().t>t[0]) {
                //cout<<"lala";
                q.push(q2.top().w-q2.top().t+1);
                q2.pop();
            }
            ans = min(int(q.size()), ans);
    }
    cout<<ans+1<<endl;
    return 0;
}
