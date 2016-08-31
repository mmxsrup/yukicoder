#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int n;
double pa, pb;

vector<int> solve(double p){//取り出す順番の添字を返す
	vector<int> v, ret;
	rep(i, n) v.push_back(i);//スロット

	int x;
	rep(i, n - 1){
		//rand()%(B-A+1)+A; B=1000 A=0
		double nowp = rand() % (1001) / 1000.0;
		if(nowp <= p) x = 0;
		else x = 1 + (n - i - 1) * (nowp - p) / (1 - p);
		if(x < 0) x = 0;
		if(n - 1 - i < x) x = n - 1 - i;
		ret.push_back(v[x]);
		v.erase(v.begin() + x);
	}
	ret.push_back(v[0]);//使うカードが一枚しかない場合
	return ret;
}

int main(void){
	cin >> n >> pa >> pb;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	int win = 0;
	rep(i, 400000){
		vector<int> va, vb;
		va = solve(pa);
		vb = solve(pb);
		int sa = 0, sb = 0;
		rep(j, n){
			if(a[va[j]] > b[vb[j]]) sa += a[va[j]] + b[vb[j]];
			else sb += a[va[j]] + b[vb[j]];
		}
		if(sa > sb) win++;
	}
	printf("%.9f\n", (double)win / 400000.0);
	return 0;
}