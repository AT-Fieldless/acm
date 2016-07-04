//
//  main.cpp
//  uva 1636
//
//  Created by apple on 16/5/3.
//  Copyright (c) 2016年 Mr.13. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
char num[110];
int main() {
    while (gets(num)!=NULL) {
        //puts(num);
        
        int len = strlen(num);
        int x = 0,y = 0,sum = 0;
        for (int i = 0; i<len-1; i++) {
            if (num[i] == '0') {
                if (num[i+1] == '1') {
                    x++;
                }
                else
                    y++;
                sum++;
            }
        }
        if (num[len-1] == '0') {
            if (num[0] == '1') {
                x++;
            }
            else
                y++;
            sum++;
        }
        double a = y*1.0/(x+y);
        double b = sum*1.0/(len);
        if (a<b) {
            cout<<"ROTATE"<<endl;
        }
        else if (a>b) {
            cout<<"SHOOT"<<endl;
        }
        else
            cout<<"EQUAL"<<endl;
    }
    return 0;
}
