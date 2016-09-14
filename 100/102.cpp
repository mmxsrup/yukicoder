#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)


int main(void){
	int n[4];
	rep(i, 4) cin >> n[i];
	int sum = 0;
	//残り枚数:0 1 2 3 4 5
	//grundy:0 1 2 3 0 1
	//残り枚数が4の時遷移先の最小のgrundyは1
	rep(i, 4){
		sum ^= n[i] % 4;
	}
	if(sum == 0)printf("Jiro\n");
	else printf("Taro\n");
}