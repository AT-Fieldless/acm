//
//  main.cpp
//  hdu 5700
//
//  Created by apple on 16/5/24.
//  Copyright (c) 2016年 Mr.13. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
using namespace std;
long long sum[100100];
vector<int> vec[100100];
multiset<int>mul;
int main() {
    int n,k,m;
    while (scanf("%d%d%d",&n,&k,&m)!=EOF) {
        sum[0] = 0;
        mul.clear();
        for (int i = 0; i<100100; i++) {
            vec[i].clear();
        }
        for (int i = 1; i<=n; i++) {
            int x;
            scanf("%d",&x);
            sum[i] = sum[i-1]+x;
        }
        int flag = 0;
        for (int i = 0; i<m; i++) {
            int l,r;
            scanf("%d%d",&l,&r);
            flag = max(flag, l);
            vec[l].push_back(r);
        }
        long long ans = 0;
        for (int i = 1; i<=flag; i++) {
            for (int j = 0; j<vec[i].size(); j++) {
                mul.insert(vec[i][j]);
            }
            while (mul.size()>k) {
                mul.erase(mul.begin());
            }
            if (mul.size() == k&& *mul.begin() >= i) {
                ans = max(ans, sum[*mul.begin()] - sum[i-1]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
