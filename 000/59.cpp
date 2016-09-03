#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
//[1,n]
const int MAX_W = 1000010;
int bit[MAX_W + 1];

int sum(int i){//iまでの和を求める
	int s = 0;
	while(i > 0){
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(int i, int x){//iの値にxを加える
	while(i <= MAX_W){
		bit[i] += x;
		i += i & -i;
	}
}

int main(void){
	int n, k; cin >> n >> k;
	vector<int> w(n);
	rep(i, MAX_W + 1) bit[i] = 0;
	rep(i, n){
		int w; cin >> w;
		if(w > 0){
			if(sum(MAX_W) - sum(w - 1) < k){
				add(w, 1);
			}
		}else{
			if(sum(-w) - sum(-w - 1) >= 1){
				add(-w, -1);
			}
		}
	}
	cout << sum(MAX_W) << endl;
	return 0;
}