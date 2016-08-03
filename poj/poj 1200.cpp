#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
int b1 = 31,b2 = 1031;
const int M1 = 12345677,M2 = 16000057;
char s[16000010];
bool mp1[M1];
bool mp2[M2];
int main(int argc, const char * argv[]) {
    int n,nc;
    while (~scanf("%d%d",&n,&nc)) {
        b2 = nc;
        scanf("%s",s);
        memset(mp1, 0, sizeof(mp1));
        memset(mp2, 0, sizeof(mp2));
        int len = 0;
        for (int i = 0; s[i]; i++) {
            s[i]-='a';
            len++;
        }
        if (n>len) {
            puts("0");
        }
        long long t1 = 0,t2 = 0;
        long long m1 = 1,m2 = 1;
        for (int i = 0; i<n; i++) {
            t1 = (t1*b1+s[i])%M1;
            m1 *= b1;
            m1 %= M1;
            t2 = (t2*b2+s[i])%M2;
            m2 *= b2;
            m2 %= M2;
        }
        mp1[t1] = 1;
        mp2[t2] = 1;
        int cnt = 1;
        for (int i = n; i<len; i++) {
            t1 = (t1*b1- s[i-n]*m1+s[i])%M1;
            t2 = (t2*b2- s[i-n]*m2+s[i])%M2;
            if (t1<0) {
                t1 += M1;
            }
            if (t2<0) {
                t2 += M2;
            }
            if (!mp1[t1]||!mp2[t2]) {
                cnt++;
            }
            mp1[t1] = 1;
            mp2[t2] = 1;
        }
        printf("%d\n",cnt);
    }
    
    return 0;
}