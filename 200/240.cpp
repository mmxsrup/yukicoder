#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
// (x-2,y-1),(x-2,y+1),(x-1,y-2),(x-1,y+2),(x+1,y-2),(x+1,y+2),(x+2,y-1),(x+2,y+1)
int main(void){
	int a, b; cin >> a >> b; //X, Y
	queue<pair<int, int> > q;
	queue<int> num;
	q.push(make_pair(0, 0));
	num.push(0);
	while(!q.empty()){
		auto now = q.front(); q.pop();
		auto cnt = num.front(); num.pop();
		if(cnt >= 3) continue;
		rep(i, 8){
			int y = now.first + dy[i];
			int x = now.second + dx[i];
			if(y == b && x == a){
				printf("YES\n");
				return 0;
			}
			q.push(make_pair(y, x));
			num.push(cnt + 1);
		}
	}	
	printf("NO\n");
}