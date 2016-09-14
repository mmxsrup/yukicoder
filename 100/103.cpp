#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)


int main(void){
	int n; cin >> n;

	int sum = 0;
	rep(i, n){
		int m; cin >> m;
		for (int p = 2; p <= m; ++p){
			int cnt = 0;
			while(m % p == 0){
				cnt++;
				m /= p;
			}
			sum ^= cnt % 3;
		}
	}

	if(sum == 0){
		printf("Bob\n");
	}else{
		printf("Alice\n");
	}
	return 0;
}