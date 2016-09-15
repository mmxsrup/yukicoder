#include <iostream>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int kr, kb;
string s;
string a[2000000];

int main(void){
	cin >> kr >> kb;
	cin >> s;

	for (int mask = 0; mask < (1 << 20); ++mask){
		int i = 0;
		for (int p = 0; p < 20; ++p){
			while(1){
				if(s[i] == 'W'){
					a[mask] += 'W';//'w'無条件で追加
					i++;
				}else{
					break;
				}
			}

			if(mask & (1 << p)){//bitが立っていれば'r' or 'b'を追加
				a[mask] += s[i];
			}

			if(p == 19){
				for (int k = i + 1; k < 30; ++k){
					a[mask] += 'W';
				}
			}
			i++;
		}
	}

	int ans = 0;
	for (int mask = 0; mask < (1 << 20); ++mask){
		for (int i = 0; i < a[mask].size(); ++i){
			if(a[mask][i] == 'R'){
				if(i - kr >= 0){
					if(a[mask][i - kr] == 'R') break;
				}
				if(i + kr < a[mask].size()){
					if(a[mask][i + kr] == 'R') break;
				}
			}else if(a[mask][i] == 'B'){
				if(i - kb >= 0){
					if(a[mask][i - kb] == 'B') break;
				}
				if(i + kb < a[mask].size()){
					if(a[mask][i + kb] == 'B') break;
				}
			}

			if(i == a[mask].size() - 1){
				ans = max(ans, (int)a[mask].size());
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}