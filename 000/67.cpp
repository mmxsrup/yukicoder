#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

ll n, L[200010];
ll k;

bool hantei(double m){
	ll sum = 0;
	rep(i, n){
		sum += floor((double)L[i] / m);
		if(sum >= k) return true;
	}
	return false;
}

int main(void){
	cin >> n;
	rep(i, n) cin >> L[i];
	cin >> k;

	//2分探索
	double r = 1e10 + 1, l = 0.0;
	int cnt = 0;
	while(r - l > 1e-10 && cnt < 100){
		cnt++;
		double mid = (l + r) / 2.0;
		if(hantei(mid)){
			l = mid;
		}else{
			r = mid;
		}
	}

	printf("%.10f\n", l);
	return 0;
}
