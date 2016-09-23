#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(n);i++)

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int h, w, sx, sy, gx, gy;
string b[55];
bool used[55][55];
int main(void){
	cin >> h >> w >> sy >> sx >> gy >> gx;
	sx--; sy--; gx--; gy--;
	rep(i, h) cin >> b[i];
	rep(i, 55)rep(j, 55){
		used[i][j] =  false;
	}

	queue<pair<int, int> > q;
	q.push(make_pair(sy, sx));
	used[sy][sx] = true;
	while(!q.empty()){
		auto n = q.front(); q.pop();
		if(n.fi == gy && n.se == gx) break;
		int hh = b[n.fi][n.se] - '0';

		rep(i, 4){
			int ny = n.fi + dy[i], nx = n.se + dx[i];
			if(!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
			if(used[ny][nx]) continue;

			int nh = b[ny][nx] - '0';
			if(abs(nh - hh) <= 1){
				used[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
		rep(i, 4){
			int ny = n.fi + 2 * dy[i], nx = n.se + 2 * dx[i];
			if(!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
			if(used[ny][nx]) continue;
			int nh = b[ny][nx] - '0';
			int ah = b[(ny + n.fi) / 2][(nx + n.se) / 2] - '0';
			if(hh - ah > 0 && nh == hh){
				used[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}

	if(used[gy][gx]) printf("YES\n");
	else printf("NO\n");
	return 0;
}