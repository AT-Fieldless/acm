//
//  main.cpp
//  poj 2010
//
//  Created by apple on 16/7/18.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
P cows[100100];
int lower[100100];
int upper[100100];
int main() {
    long long n,c,f;
    scanf("%lld%lld%lld",&n,&c,&f);
    long long half = n/2;
    for (int i = 0; i<c; i++) {
        scanf("%d%d",&cows[i].first,&cows[i].second);
    }
    sort(cows, cows+c);
    {
        int total = 0;
        priority_queue<int> q;
        for (int i = 0; i < c; ++i)
        {
            lower[i] = q.size() == half ? total : 0x3f3f3f3f;
            q.push(cows[i].second);
            total += cows[i].second;
            if (q.size() > half)
            {
                // 然后踢掉一个学费最高的家伙
                total -= q.top(); q.pop();
            }
        }
    }
    
    {
        int total = 0;
        priority_queue<int> q;
        for (int i = c - 1; i >= 0; --i)
        {
            upper[i] = q.size() == half ? total : 0x3f3f3f3f;
            q.push(cows[i].second);
            total += cows[i].second;
            if (q.size() > half)
            {
                // 然后踢掉一个学费最高的家伙
                total -= q.top(); q.pop();
            }
        }
    }
    int ans;
    for (int i = c - 1; i >= 0; --i)
    {
        if (lower[i] + cows[i].second + upper[i] <= f)
        {
            ans = cows[i].first;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}