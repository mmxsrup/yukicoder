#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int t; cin >> t;
	rep(i, t){
		string s; cin >> s;
		int cntg = 0, cntr = 0, cntw = 0;
		bool flag = true; //falseならWに対応するGがこなければならない
		if(s.size() < 3){
			printf("impossible\n");
			continue;
		}
		rep(p, s.size()){
			if(s[p] == 'G'){
				if(cntg >= cntr && cntw >= 1){
					cntg++;
					cntw--;
					flag = true;//対応するGが来た
				}else{
					printf("impossible\n");
					break;
				}
			}else if(s[p] == 'R'){
				if(cntg >= cntr + 1){
					cntr++;
				}else{
					printf("impossible\n");
					break;
				}
			}else{
				cntw++;
				flag = false;
			}

			if(p == s.size() - 1){
				//GとRの数は等しく、wはgより多く、Wのあとに対応するGがある
				if(cntg == cntr && cntw >= 0 && flag){
					printf("possible\n");
				}else{
					printf("impossible\n");
				}
			}
		}
	}
	return 0;
}