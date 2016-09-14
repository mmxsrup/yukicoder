#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstdio>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int n; cin >> n;
	int sum = 0;
	for (int i = 2; i <= n; ++i){
		int cnt = 0;
		while(n % i == 0){
			cnt++; n /= i;
		}
		sum ^= cnt;//xor
	}
	if(sum == 0)printf("Bob\n");
	else printf("Alice\n");
	return 0;
}