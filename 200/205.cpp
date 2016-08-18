#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int n; cin >> n;
	priority_queue<string, vector<string>, greater<string>> q;
	rep(i, n){
		string s; cin >> s;
		s += '\xff';//番兵
		q.push(s);
	}

	string t;
	while(!q.empty()){
		auto tmp = q.top(); q.pop();
		if(tmp[0] == '\xff') break;
		t += tmp[0];
		tmp.erase(tmp.begin());
		q.push(tmp);
	}
	cout << t << endl;
	return 0;
}