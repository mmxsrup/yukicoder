#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;

int main(void){
	int h, w; cin >> h >> w;
	int g = __gcd(h, w);
	h /= g; w /= g;
	if(h == 4 && w  == 3){
		printf("TATE\n");
	}else{
		printf("YOKO\n");
	}
	return 0;
}