#include <iostream>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	string s1, s2; cin >> s1 >> s2;
	string s = s1 + s2;
	int ans = 0, tmp = 0;
	rep(i, s.size()){
		if(s[i] == 'o') tmp++;
		else{
			ans = max(tmp, ans); tmp = 0;
		}
		if(i == s.size() - 1) ans = max(tmp, ans);
	}
	cout << ans << endl;
	return 0;
}