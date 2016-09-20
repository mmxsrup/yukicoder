#include <iostream>
#include <cstdio>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;
//上　右　下　左　0 1 2 3
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int h, w;
int board[110][110];
//d[y][x][i] := (x, y)へi方向から入るときの、最短距離
int d[110][110][4];
int main(void){
	cin >> w >> h;
	rep(i, h)rep(j, w) cin >> board[i][j];
	rep(i, h)rep(j, w)rep(k, 4) d[i][j][k] = INF;

	queue<tuple<P, P, int>> q;
	q.push(make_tuple(make_pair(0, 1), make_pair(0, 0), 1));
	q.push(make_tuple(make_pair(1, 0), make_pair(0, 0), 2));
	rep(i, 4) d[0][0][i] = 0;
	d[0][1][1] = 1; d[1][0][2] = 1;

	while(!q.empty()){
		P p1, p2;//1つまえ　2つまえ
		int v;//どの方向から来たか
		auto t = q.front(); q.pop();
		tie(p1, p2, v) = t;
		if(p1.first == h - 1 && p1.second == w - 1) break;

		rep(i, 4){
			int ny = p1.first + dy[i], nx = p1.second + dx[i];
			if(!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
			if(d[ny][nx][i] != INF) continue;

			int len0 = board[ny][nx];
			int len1 = board[p1.first][p1.second];
			int len2 = board[p2.first][p2.second];
			if(len0 == len1 || len1 == len2 || len2 == len0) continue;
			int mid = (len0 + len1 + len2) 
				- min(len0, min(len1, len2)) - max(len0, max(len1, len2));
			if(mid == len0 || mid == len2){
				q.push(make_tuple(make_pair(ny, nx), p1, i));
				d[ny][nx][i] = d[p1.first][p1.second][v] + 1;
			}
		}
	}

	int ans = INF;
	rep(i, 4){
		ans  = min(ans, d[h - 1][w - 1][i]);
	}
	if(ans == INF) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}