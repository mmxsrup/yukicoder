#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int n, m;
int main(void){
	cin >> n >> m;

	vector<int> v;
	for (int i = 1; i <= n; ++i){
		v.push_back(i);
	}
	rep(i, m){
		int a; cin >> a; a--;
		int t = v[a];
		v.erase(v.begin() + a);
		v.insert(v.begin(), t);
	}
	printf("%d\n", v[0]);
	return 0;

}