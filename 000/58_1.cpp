#include <iostream>
#include <cstdio>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int n, k;
//dp1[i][j] := 太郎君がサイコロをi回振って、合計がjの時の確率
//dp2[i][j] := 次郎君がサイコロをi回振って、合計がjの時の確率
double dp1[20][150], dp2[20][150];

//何通りあるかで調べる
int main(void){
    cin >> n >> k;
    rep(i, 20)rep(j, 150) dp1[i][j] = dp2[i][j] = 0;
    dp1[0][0] = 1.0;
    dp2[0][0] = 1.0;

    //太郎
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= 6 * i; ++j){
            if(i <= k){
                for (int k = 4; k <= 6; ++k){
                    if(j - k >= 0){
                        dp1[i][j] += dp1[i - 1][j - k] / 3.0;
                        // printf("1 dp1[%d][%d] = %d\n", i, j, dp1[i][j]);
                    }
                }
            }else{
                for (int k = 1; k <= 6; ++k){
                    if(j - k >= 0){
                        dp1[i][j] += dp1[i - 1][j - k] / 6.0;
                        // printf("2 dp1[%d][%d] = %f\n", i, j, dp1[i][j]);
                    }
                }
            }
        }
    }

    //次郎
   for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= 6 * i; ++j){
            for (int k = 1; k <= 6; ++k){
                if(j - k >= 0){
                    dp2[i][j] += dp2[i - 1][j - k] / 6.0;
                    // printf("3 dp2[%d][%d] = %f\n", i, j, dp2[i][j]);
                }
            }
        }
    }

    double ans = 0;
    for (int sum1 = 1; sum1 <= n * 6; ++sum1){//太郎の合計
        for (int sum2 = 0; sum2 < sum1; ++sum2){//次郎の合計
            //太郎の合計がsum1で次郎の合計がsum2 (< sum1)の時の確率を足しお合わせる
            ans += dp1[n][sum1] * dp2[n][sum2];
        }
    }
    printf("%.9f\n", ans);
    return 0;
}