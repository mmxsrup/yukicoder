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
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int main(void){
	cin >> w >> h;
	rep(i, h)rep(j, w) cin >> b[i][j];
	rep(i, 110)rep(j, 110) d[i][j] = false;
	rep(i, h)rep(j, w){
		if(d[i][j]) continue;//すでに調べている
		int used[110][110];//今回の記録用
		rep(a, 110)rep(b, 110)used[a][b] = 0;
		queue<pair<int, int> > q;
		queue<int> v;
		int num = b[i][j];
		used[i][j] = 1; d[i][j] = true;
		q.push(make_pair(i, j));//スタート
		v.push(-1);
		while(!q.empty()){
			auto now = q.front(); q.pop();
			auto from = v.front(); v.pop();
			rep(k, 4){
				if(from == (k + 2) % 4 && from != -1) continue;//来た方向に戻るのを防ぐ
				int y = now.first + dy[k], x = now.second + dx[k];
				if(y < 0 || h <= y || x < 0 || w <= x) continue;
				if(used[y][x] == 1){
					printf("possible\n");
					return 0;
				}
				if(b[y][x] == num && used[y][x] == 0){
					q.push(make_pair(y, x));
					v.push(k);
					used[y][x] = 1; d[i][j] = true;
				}

			}
		}
		
	}
	printf("impossible\n");
	return 0;
}