#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

const int INF = 1e9;
int n, x[100010], y[100010];
vector<int> G[100010];
int dist1[100010], dist2[100010];

int main(void){
	cin >> n;
	rep(i, n - 1){
		int tx, ty; cin >> tx >> ty;
		tx--; ty--;
		G[tx].push_back(ty); G[ty].push_back(tx);
	}

	//葉のノード
	vector<int> ha;
	rep(i, n){
		if(G[i].size() == 1 && i != 0) ha.push_back(i);
	}

	rep(i, n) dist1[i] = dist2[i] = INF;

	//根->葉へ
	queue<pair<int, int> > q;
	q.push(make_pair(0, -1));
	dist1[0] = 0;
	while(!q.empty()){
		int u = q.front().first;
		int p = q.front().second;
		q.pop();
		for(auto v : G[u]){
			if(v != p && dist1[v] == INF){//戻るの禁止と一度調べたところはもう最短で調べ済み
				dist1[v] = min(dist1[v], dist1[u] + 1);
				q.push(make_pair(v, u));
			}
		}
	}

	//葉->根
	queue<pair<int, int> > que;
	for(auto start : ha){//スタート時点をまとめて記録する
		que.push(make_pair(start, -1));
		dist2[start] = 0;
	}

	while(!que.empty()){
		int u = que.front().first;
		int p = que.front().second;
		que.pop();
		for(auto v : G[u]){
			if(v != p && dist2[v] == INF){//戻るの禁止と一度調べたところはもう最短で調べ済み
				dist2[v] = min(dist2[v], dist2[u] + 1);
				que.push(make_pair(v, u));
			}
		}
	}

	rep(i, n){
		printf("%d\n", min(dist1[i], dist2[i]));
	}
	return 0;
}