#include <iostream>
#include <cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void){
	string s; cin >> s;
	int x = 0, y = 0;
	rep(i, s.size()){
		if(s[i] == 'N'){
			x += dx[0]; y += dy[0];
		}else if(s[i] == 'E'){
			x += dx[1]; y += dy[1];
		}else if(s[i] == 'S'){
			x += dx[2]; y += dy[2];
		}else{
			x += dx[3]; y += dy[3];
		}
	}
	double ans = sqrt((pow((double)x - 0.0, 2.0) + pow((double)y, 2.0)));
	cout << ans << endl;
	return 0;
}