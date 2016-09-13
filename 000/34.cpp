#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstdio>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e8;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int n, v, sx, sy, gx, gy;
int cost[110][110];//cost[i][j] i->jのコスト
//used[y][x][t] := (x,y)に残り体力tで行くときの最短時間
int used[110][110][10010];

int main(void){
	cin >> n >> v >> sx >> sy >> gx >> gy;
	sx--; sy--; gx--; gy--;
	rep(i, n)rep(j, n) cin >> cost[i][j];
	rep(i, 110)rep(j, 110)rep(k, 10010)used[i][j][k] = INF;

	queue<tuple<int, int, int>> q;
	q.push(make_tuple(sy, sx, v));
	used[sy][sx][v] = 0;
	while(!q.empty()){
		int y, x, t;
		tie(y, x, t) = q.front(); q.pop();
		if(y == gy && x == gx){
			printf("%d\n", used[y][x][t]);
			return 0;
		}
		rep(i, 4){
			int ny = y + dy[i], nx = x + dx[i];
			if(!(0 <= ny && ny < n && 0 <= nx && nx < n)) continue;
			int nv = t - cost[ny][nx];
			if(nv <= 0) continue;
			if(used[ny][nx][nv] != INF) continue;
			used[ny][nx][nv] = used[y][x][t] + 1;
			q.push(make_tuple(ny, nx, nv));
		}

	}
	printf("-1\n");
	return 0;
}