//
//  main.cpp
//  cf 731B
//
//  Created by apple on 2016/10/20.
//  Copyright © 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
using namespace std;
int num[210000];
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    for (int i = 0; i<n; i++) {
        cin>>num[i];
    }
    int flag = 0;
    for (int i = 0; i<n-1; i++) {
        if (num[i]<0) {
            flag = 1;
            break;
        }
        if (num[i]%2) {
            num[i+1]--;
        }
    }
    if (num[n-1]%2) {
        flag = 1;
    }
    if (flag) {
        cout<<"NO"<<endl;
    }
    else
        cout<<"YES"<<endl;
    return 0;
}
