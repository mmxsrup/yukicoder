#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int w, h;
int b[110][110];
bool d[110][110];//一度調べた部分を記録
int used[110][110];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool flag = false;

void bfs(int y, int x, int py, int px, int num){
	d[y][x] = true; used[y][x] = 1;
	rep(i, 4){
		int nowy = y + dy[i], nowx = x + dx[i];
		if(nowy < 0 || h <= nowy || nowx < 0 || w <= nowx) continue;
		if(nowy == py && nowx == px) continue;//戻るの禁止
		if(b[nowy][nowx] != num) continue;
		if(used[nowy][nowx]){
			flag = true;
			return;
		}
		bfs(nowy, nowx, y, x, num);
	}
	return;
}

int main(void){
	cin >> w >> h;
	rep(i, h)rep(j, w) cin >> b[i][j];
	rep(i, h)rep(j, w){
		if(d[i][j]) continue;
		rep(a, 110)rep(b, 110) used[a][b] = 0;
		bfs(i, j, -1, -1, b[i][j]);
	}
	if(flag) printf("possible\n");
	else printf("impossible\n");
	return 0;
}