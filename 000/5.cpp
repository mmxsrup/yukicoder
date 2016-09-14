#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int l, n; cin >> l >> n;
	vector<int> w(n);
	rep(i, n) cin >> w[i];
	sort(w.begin(), w.end());
	int ans = 0;
	rep(i, n){
		if(l >= w[i]){
			ans++;
			l -= w[i];
		}else{
			break;
		}
	}
	printf("%d\n", ans);
}