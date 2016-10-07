#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;	
typedef long long ll;
typedef pair<int, int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;
int n;
int a[3010], b[3010];

int main(void){
	cin >> n;
	rep(i, n){
		cin >> a[i];
		a[i + n] = a[i];
	}
	rep(i, n){
		cin >> b[i];
		b[i + n] = b[i];
	}

	int ans = INF;
	rep(i, n){
		priority_queue<P, vector<P>, greater<P> > pq;
		for (int j = 0; j < n; ++j){
			pq.push(make_pair(a[j], 0));
		}


		for (int j = i; j < i + n; ++j){
			int nlv = pq.top().first;
			int t = pq.top().second;
			pq.pop();
			int lvup = b[j] / 2;
			pq.push(make_pair(nlv + lvup, t + 1));
		}
		int tmp = 0;
		while(!pq.empty()){
			int t = pq.top().second; pq.pop();
			tmp = max(tmp, t);
		}
		ans = min(ans, tmp);
	}
	printf("%d\n", ans);
	return 0;
}