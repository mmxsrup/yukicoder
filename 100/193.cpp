#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	string s; cin >> s;
	int n = s.size();
	s += s;//2倍に伸ばす

	int ans = -1e9;//答えはマイナスもあるから小さい値で
	for (int l = 0; l < n; ++l){
		if(!('0' <= s[l] && s[l] <= '9' && '0' <= s[l + n - 1] && s[l + n - 1] <= '9')){
			continue;
		}
		int tl = l;
		vector<int> num, v;
		for (int r = l; r < l + n; ++r){
			if(!('0' <= s[r] && s[r] <= '9')){
				if(s[r] == '+') v.push_back(1);
				else if(s[r] == '-') v.push_back(0);
				
				string ss = s.substr(tl, r - tl);
				num.push_back(stoi(ss));
				tl = r + 1;//次に数字が出てくる位置
			}

			if(r == l + n - 1 && '0' <= s[r] && s[r] <= '9'){//最後
				string ss = s.substr(tl, r - tl + 1);
				num.push_back(stoi(ss));
			}
		}

		int sum = 0;
		rep(i, num.size()){
			if(i == 0){
				sum += num[i];	
			}else{
				if(v[i - 1] == 1) sum += num[i];
				else sum -= num[i];
			}
		}
		ans = max(ans, sum);
	}
	printf("%d\n", ans);
	return 0;
}