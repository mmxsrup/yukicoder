#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int n; cin >> n;
	string s1, s2; cin >> s1 >> s2;
	//与えられた14日の前後は平日が無限いつづく
	string s = "xxxxxxxxxxxxxxx" + s1 + s2 + "xxxxxxxxxxxxxxx";
	int ans = 0, tmp = 0;
	for (int i = 0; i < s.size() - n; ++i){
		tmp = 0;
		string t = s;
		for (int j = i; j < i + n; ++j){
			if(t[j] == 'x') t[j] = 'o';
			else break;
		}
		rep(j, t.size()){
			if(t[j] == 'o') tmp++;
			else{
				ans = max(tmp, ans); tmp = 0;
			}
			if(j == t.size() - 1){
				ans = max(tmp, ans);
			}
		}
	}
	cout << ans << endl;
	return 0;
}