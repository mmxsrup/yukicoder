#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;

string c[5010];

typedef unsigned long long ull;
const ull B = 100000007;
//aはｂにいくつ
int contain(string a, string b){
	int ret = 0;
	int al = a.length(), bl = b.length();
	if(al > bl) return 0;

	ull t = 1;
	for (int i = 0; i < al; ++i) t *= B;

	ull ah = 0, bh = 0;
	for (int i = 0; i < al; ++i) ah = ah * B + a[i];
	for (int i = 0; i < al; ++i) bh = bh * B + b[i];

	for (int i = 0; i + al <= bl; ++i){
		if(ah == bh) ret++;
		if(i + al < bl) bh = bh * B + b[i + al] - b[i] * t;
	}
	return ret;
}

int main(void){
	string s; cin >> s;
	int m; cin >> m;
	rep(i, m) cin >> c[i];
	ll ans = 0;
	rep(i, m){
		ans += contain(c[i], s);
	}
	printf("%lld\n", ans);
	return 0;
}