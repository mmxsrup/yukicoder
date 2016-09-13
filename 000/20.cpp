#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e8;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int n, v, ox, oy;
int cost[210][210];//dist[i][j] i->jのコスト
int dist[210][210];//距離

void diskstra(int y, int x){
	rep(i, n)rep(j, n)dist[i][j] = INF;
	//<cost, (座標)>
	priority_queue<P, vector<PP>, greater<PP> > que;
	que.push(make_pair(0, make_pair(y, x)));
	dist[y][x] = 0;
	while(!que.empty()){
		auto c = que.top().first;
		auto now = que.top().second;
		que.pop();

		// if(dist[now.first][now.second] < c) continue;
		rep(i, 4){
			int ny = now.first + dy[i], nx = now.second + dx[i];
			if(!(0 <= ny && ny < n && 0 <= nx && nx < n)) continue;
			if(dist[ny][nx] <= c + cost[ny][nx]) continue;
			dist[ny][nx] = c + cost[ny][nx];
			que.push(make_pair(dist[ny][nx], make_pair(ny, nx)));
		}
	}
}

int main(void){
	cin >> n >> v >> ox >> oy;
	ox--; oy--;
	rep(i, n)rep(j, n) cin >> cost[i][j];
	diskstra(0, 0);
	//オアシスを使わずにゴールに行けるか
	if(dist[n - 1][n - 1] < v){
		printf("YES\n"); return 0;
	}
	if(ox == -1 && oy == -1){//オアシスなし
		printf("NO\n"); return 0;
	}
	//オアシスについたあとのの体力
	int t = (v - dist[oy][ox]) * 2; //2倍
	diskstra(oy, ox);//オアシスからゴールまでに必要な体力の最小値を求める
	if(t - dist[n - 1][n - 1] > 0){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	return 0;
}