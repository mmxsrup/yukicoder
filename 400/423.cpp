#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){

	string n; cin >> n;
	if(n == "ham"){
		printf("ham\n");
		return 0;
	}

	cout << n + "ham" << endl;

	return 0;
}
