#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int n, k;

bool solve(){//モンテカルロ法

    int sum_taro = 0;
    rep(i, k){
        sum_taro += rand() % 3 + 4;
    }
    rep(i, n - k){
        sum_taro += rand() % 6 + 1;
    }

    int sum_ziro = 0;
    rep(i, n){
        sum_ziro += rand() % 6 + 1;
    }

    if(sum_taro > sum_ziro) return true;
    else return false;
}

int main(void){
    cin >> n >> k;
    
    int win = 0;
    rep(i, 4000000){
        if(solve()) win++;
    }
    printf("%.9f\n", (double)win / 4000000.0);
    return 0;
}