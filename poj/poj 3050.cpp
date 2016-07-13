//
//  main.cpp
//  poj 3050
//
//  Created by apple on 16/7/13.
//  Copyright (c) 2016年 Mr.Thirteen. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#define judge(x,y) x>=0&&x<5&&y>=0&&y<5
int num[10][10][10][10][10][10];
int temp[10];
int maps[10][10];
int d1[5] = {-1,0,1,0};
int d2[5] = {0,-1,0,1};
void dfs(int x,int y,int count){
    if (count == 6) {
        int a = temp[0];
        int b = temp[1];
        int c = temp[2];
        int d = temp[3];
        int e = temp[4];
        int f = temp[5];
        num[a][b][c][d][e][f] = 1;
        return;
    }
    for (int i = 0; i<4; i++) {
        int tx = x+d1[i];
        int ty = y+d2[i];
        if (judge(tx, ty)) {
            temp[count] = maps[tx][ty];
            dfs(tx, ty, count+1);
        }
    }
}
int main() {
    memset(num, 0, sizeof(num));
    for (int i = 0; i<5; i++) {
        for (int j = 0; j<5; j++) {
            scanf("%d",&maps[i][j]);
        }
    }
    for (int i = 0; i<5; i++) {
        for (int j = 0; j<5; j++) {
            temp[0] = maps[i][j];
            dfs(i, j, 1);
        }
    }
    int ans = 0;
    for (int a = 0; a<10; a++) {
        for (int b = 0; b<10; b++) {
            for (int c = 0; c<10; c++) {
                for (int d = 0; d<10; d++) {
                    for (int e = 0; e<10; e++) {
                        for (int f = 0; f<10; f++) {
                            if (num[a][b][c][d][e][f]) {
                                ans++;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
