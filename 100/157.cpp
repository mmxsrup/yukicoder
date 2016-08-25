#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int dy[4] = {1, 0, 0, -1};
int dx[4] = {0, 1, -1, 0};
int w, h; 
vector<string> s;
vector<pair<int, int> > ana[2];

void bfs(int f, int y, int x){
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	s[y][x] = '#'; ana[f].push_back(make_pair(y, x));
	while(!q.empty()){
		auto now = q.front(); q.pop();
		rep(i, 4){
			int nowy = dy[i] + now.first, nowx = dx[i] + now.second;
			if(nowy < 0 && h <= nowy && nowx < 0 && w <= nowx) continue;
			if(s[nowy][nowx] == '.'){
				q.push(make_pair(nowy, nowx));
				ana[f].push_back(make_pair(nowy, nowx));
				s[nowy][nowx] = '#';
			}
		}
	}
	return;
}
int main(void){
	cin >> w >> h;
	rep(i, h){
		string tmp; cin >> tmp;
		s.push_back(tmp);
	}

	int cnt = 0;
	rep(y, h){
		rep(x, w){
			if(s[y][x] == '.'){
				if(cnt == 0){
					bfs(0, y, x); cnt++;
				}
				else if(cnt == 1){
					bfs(1, y, x);
				}
			}
		}
	}
	rep(i, 2){
		sort(ana[i].begin(), ana[i].end());
		ana[i].erase(unique(ana[i].begin(), ana[i].end()), ana[i].end());//重複消去
	}

	int ans = 1e9;
	for(auto u : ana[0]){
		for(auto v : ana[1]){
			// printf("%d\n", abs(u.first - v.first) + abs(u.second - v.second));
			ans = min(ans, abs(u.first - v.first) + abs(u.second - v.second));
		}
	}
	cout << ans - 1<< endl;
	return 0;
}