#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
const ll INF = 1e18;

ll n;
ll a[1010], b[1010];

ll search(ll m){
	ll ma = 0, mi = INF;
	rep(i, n){
		ll num = a[i] + b[i] * m;
		ma = max(ma, num);
		mi = min(mi, num);
	}
	return ma - mi;
}

int main(void){
	cin >> n;
	bool flag = true;
	rep(i, n){
		cin >> a[i] >> b[i];
		if(!(a[i] == 0 && b[i] == 0)) flag = false;
	}
	if(flag){
		printf("1\n"); return 0;
	}

	//下とつ
	ll l = 1, r = 1000000000;
	for (int i = 0; i < 50; ++i){
		ll m1 = (l * 2 + r) / 3;
		ll m2 = (l + r * 2) / 3;
		if(search(m1) > search(m2)){//左側が高い
			l = m1;
		}else{//右側が高い
			r = m2;
		}
	}

	//念のためlの周辺を探す
	vector<pair<ll, ll> > kai;
	ll p = l;
	if(l - 100 >= 1) p -= 100;
	else p = 1;
	for (ll i = p; i < p + 200; ++i){
		ll ret = search(i);
		kai.push_back(make_pair(ret, i));
	}
	sort(kai.begin(), kai.end());
	printf("%lld\n", kai[0].second);

	return 0;
}