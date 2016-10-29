//求小于n且与n互素的数的个数
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

