//
//  main.cpp
//  uva 10820
//
//  Created by apple on 2016/10/22.
//  Copyright © 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
using namespace std;
const int maxn = 5e4+10;
int phi[maxn];
void phi_tabel(int n){
    for (int i = 2; i<=n; i++) {
        phi[i] = 0;
    }
    phi[1] = 1;
    for (int i = 2; i<=n; i++) {
        if (!phi[i]) {
            for (int j = i; j<=n; j+=i) {
                if (!phi[j]) {
                    phi[j] = phi[j] = j;
                }
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    phi_tabel(50000);
    int n;
    while (cin>>n&&n) {
        long long ans = 0;
        for (int i = 2; i<=n; i++) {
            ans += 2*phi[i];
        }
        ans++;
        cout<<ans<<endl;
    }
    return 0;
}
