#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;
int n, m;

int main(void){
	cin >> n;
	vector<int> A(n);
	rep(i, n) cin >> A[i];
	sort(A.begin(), A.end());
	cin >> m;
	vector<int> B(m);
	rep(i, m) cin >> B[i];
	//箱は大きいものから使ったほうがいい
	sort(B.begin(), B.end());
	reverse(B.begin(), B.end());

	int ans = INF;
	//商品を入れていく順番をすべて試す　(n!)
	do{
		vector<int> hako(m);
		rep(i, m) hako[i] = B[i];
		int tm = 0;//どこ箱まで使ったかをメモするもの
		bool flag = false;

		for (int i = 0; i < n ; ++i){//順番におもちゃを入れていく
			for (int j = 0; j < m; ++j){//箱を大きいものから使っていく
				if(hako[j] - A[i] >= 0){
					hako[j] -= A[i];//容量を減らす
					tm = max(tm, j);
					break;
				}
				if(j == m - 1){
					flag = true;
					break;
				}
			}
			if(flag) break;
		}
		if(flag) continue;//すべての荷物が入っている時のみ、ansを更新
		ans = min(ans, tm);
	}while(next_permutation(A.begin(), A.end()));

	if(ans != INF) cout << ans  + 1 << endl;
	else cout << -1 << endl;
	return 0;
}