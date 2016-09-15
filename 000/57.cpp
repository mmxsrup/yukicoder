#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;

int main(void){
	double e = 3.5;
	double n; cin >> n;
	//http://mathtrain.jp/expectation
	printf("%.9f\n", e * n);
	return 0;
}