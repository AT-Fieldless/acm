//求最长回文子串
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 1100100;
char Ma[MAXN*2];
char s[MAXN];
int Mp[MAXN*2];
void Manacher(char s[],int len){
    int l = 0;
    Ma[l++] = '$';
    Ma[l++] = '#';
    for (int i = 0; i<len; i++) {
        Ma[l++] = s[i];
        Ma[l++] = '#';              //把所有回文串变成奇数长度
    }
    Ma[l] = 0;
    int mx = 0,id = 0;
    for (int i = 0; i<l; i++) {
        Mp[i] = mx>i?min(Mp[2*id-i], mx-i):1;
        while (Ma[i+Mp[i]] == Ma[i-Mp[i]]) {
            Mp[i]++;
        }
        if (i+Mp[i]>mx) {
            mx = i+Mp[i];
            id = i;
        }
    }
}
int main() {
    while (~scanf("%s",s)) {
        //puts(s);
        int len = strlen(s);
        memset(Mp, 0, sizeof(Mp));
        Manacher(s, len);
    }
    return 0;
}