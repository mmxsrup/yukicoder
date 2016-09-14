#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int dp[110];

int grundy(int x){
	if(dp[x] != -1)return dp[x];
	if(x <= 1)return dp[x] = 0;

	set<int> s;
	//状態遷移
	if(x % 2 == 0 && x >= 2) s.insert(grundy(x / 2) ^ grundy(x / 2));
	if(x % 2 == 1 && x >= 3) s.insert(grundy(x / 2) ^ grundy(x / 2 + 1));
	if(x % 3 == 0 && x >= 3) s.insert(grundy(x / 3) ^ grundy(x / 3) ^ grundy(x / 3));
	if(x % 3 == 1 && x >= 4) s.insert(grundy(x / 3) ^ grundy(x / 3) ^ grundy(x / 3 + 1));
	if(x % 3 == 2 && x >= 5) s.insert(grundy(x / 3) ^ grundy(x / 3 + 1) ^ grundy(x / 3 + 1));

	int res = 0;
	while(s.count(res)) res++;
	return dp[x] = res;
}

int main(void){
	rep(i, 110) dp[i] = -1;
	int n; cin >> n;

	if(grundy(n) == 0){
		printf("B\n");
	}else{
		printf("A\n");
	}
	return 0;
}