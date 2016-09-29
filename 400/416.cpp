#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

//Quick Find Weighted
const int MAX_N = 200010;
int i2g[MAX_N];//i2g[i] := 頂点iが所属するグループ
vector<int> g2i[MAX_N];//g2i[g]:= グループgに所属する頂点番号

// アイテムiaとアイテムibは同じグループに所属しているか？
bool issame(int ia, int ib){
	return i2g[ia] == i2g[ib];
}

// アイテムiaの所属するグループとアイテムibの所属するグループを1つにする(異なるグループに属するものに)
void merge(int ia, int ib){
	if(issame(ia, ib)) return;
	//iaの所属するグループがibの所属するグループより小さくならないようにする(一般的マージテク)
	if(g2i[i2g[ia]].size() < g2i[i2g[ib]].size()){
		swap(ia, ib);
	}
	int ga = i2g[ia], gb = i2g[ib];//グループgbの方が要素数が少ない
	for(auto u : g2i[gb]){//uには頂点の番号はいる
		i2g[u] = ga;//グループの番号を更新
	}
	g2i[ga].insert(g2i[ga].end(), g2i[gb].begin(), g2i[gb].end());//つなげる
	g2i[gb].clear();
}

void init(int n){
	for (int i = 0; i < n; ++i){
		i2g[i] = i;
		g2i[i].push_back(i);
	}
}

int ans[MAX_N];

int main(void){
	int n, m, q; cin >> n >> m >> q;
	vector<pair<int, int> > cd;
	set<pair<int, int> > s;//最後まで残っている橋を入れる

	for (int i = 0; i < m; ++i){
		int a, b; cin >> a >> b;
		a--; b--;
		s.insert(make_pair(a, b));
	}
	for (int i = 0; i < q; ++i){
		int c, d; cin >> c >> d;
		c--; d--;
		cd.push_back(make_pair(c, d));
		s.erase(make_pair(c, d));
	}

	init(n);//初期化
	for(auto u : s){//最後まで残っている橋をつなげる
		merge(u.first, u.second);
	}

	rep(i, n) ans[i] = 0;
	int g = i2g[0];//最後まで0と同じグループにあるものは、-1
	for(int v : g2i[g]){
		ans[v] = -1;
	}

    for (int i = q - 1; i >= 0 ; --i){
 		int a = cd[i].first, b = cd[i].second;
 		if(!issame(a, b)){
 			if(!issame(0, a) && !issame(0, b)){//0につながることはない
 				merge(a, b);
 				continue;
 			}

 			if(issame(0, a)){//0とaが同じグループなら、bも0と同じグループになる
 				for(auto u : g2i[i2g[b]]){
 					if(ans[u] == 0) ans[u] = i + 1;
 				}
 			}else{//0とbが同じグループなら、aも0と同じグループになる
 				for(auto u : g2i[i2g[a]]){
 					if(ans[u] == 0) ans[u] = i + 1;
 				}
 			}
 			merge(a, b);
 		}
    }
    for (int i = 1; i < n; ++i){
    	printf("%d\n", ans[i]);
    }
	return 0;
}