#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;

int n, k;
int x[100010], y[100010], hp[100010];
int imos[1510][1510];

//imos
int main(void){
	cin >> n >> k;
	rep(i, n){
		cin >> x[i] >> y[i] >> hp[i];
		x[i] += 500; y[i] += 500;
	}

	rep(i, 1510)rep(j, 1510) imos[i][j] = 0;

	rep(i, k){
		int ax, ay, w, h, d;
		cin >> ax >> ay >> w >> h >> d;
		ax += 500; ay += 500;
		imos[ay][ax] += d;//左上
		imos[ay][ax + w + 1] -= d;//右上
		imos[ay + h + 1][ax] -= d;//左下
		imos[ay + h + 1][ax + w + 1] += d;//右下
	}

	//横方向への累積和
	rep(i, 1505)rep(j, 1505){
		imos[i][j + 1] += imos[i][j];
	}
	//縦方向の累積和
	rep(i, 1505)rep(j, 1505){
		imos[i + 1][j] += imos[i][j];
	}

	ll ans = 0;
	rep(i, n){
		int ty = y[i], tx = x[i];
		ans += max((ll)0, (ll)(hp[i] - imos[ty][tx]));
	}
	printf("%lld\n", ans);
	return 0;
}