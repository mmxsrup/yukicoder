#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <set>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;

int a[100010], b[100010];
int main(void){
	int n, k, x; cin >> n >> k >> x;
	int idx;
	rep(i, k){
		string ta, tb; cin >> ta >> tb;
		if(ta == "?" && tb == "?"){
			idx = i;
			a[i] = 0, b[i] = 0;
		}else{
			a[i] = stoi(ta); b[i] = stoi(tb);
		}
	}
	vector<int> rv(n);
	rep(i, n){
		cin >> rv[i];
	}
	vector<int> v(n);
	rep(i, n){
		v[i] = i + 1;
	}

	//順方向
	for (int i = 0; i < idx; ++i){
		swap(v[a[i] - 1], v[b[i] - 1]);
	}
	//逆方向
	for (int i = k - 1; i > idx; --i){
		swap(rv[a[i] - 1], rv[b[i] - 1]);
	}

	vector<int> ans;
	rep(i, n){
		if(v[i] != rv[i]) ans.push_back(i);
	}
	rep(i, ans.size()){
		printf("%d ", ans[i] + 1);
	}
	printf("\n");
	return 0;
}