#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;

bool isprime[5000010];
//エラトテネス
void eratos(int m){
    for (int i = 0; i <= m; ++i) isprime[i] = true;
    isprime[0] = isprime[1] = false;
    //iを残してiの倍数を消していく
    for (int i = 2; i <= m; ++i){
        if(isprime[i]){
            for (int j = 2 * i; j <= m; j += i){
                isprime[j] = false;
            }
        }
    }
}

int n;
set<int> a;
int cnt[10];

bool hantei(){
	rep(i, 10){
		if(a.count(i) == 0){//含んでいけない数
			if(cnt[i] != 0) return false;
		}
	}
	return true;
}

bool ok(){
	rep(i, 10){
		if(a.count(i) != 0){
			if(cnt[i] == 0) return false;
		}
	}
	return true;
}

int main(void){
	cin >> n;
	rep(i, n){
		int t; cin >> t;
		a.insert(t);
	}
	eratos(5000000);

	rep(i, 10) cnt[i] = 0;
	int ans = -1;
	//[l, r]でしゃくとり法
	int l = 1;
	for (int r = 1; r <= 5000000; ++r){//右を伸ばせるだけのばす
		if(isprime[r]){
			string tm = to_string(r);
			rep(i, tm.size()){
				cnt[tm[i] - '0']++;
			}
		}

		if(!hantei()){//含んでいけない文字を含んでしまっているので、左を縮める
			while(!isprime[l] && l <= r - 1) l++;//素数のつぎの数まで縮める
			string tmp = to_string(l);
			rep(j, tmp.size()){
				cnt[tmp[j] - '0']--;
			}
			l++;
		}

		if(ok()){//条件を満たす
			ans = max(ans, r - l);
		}
	}
	printf("%d\n", ans);
}