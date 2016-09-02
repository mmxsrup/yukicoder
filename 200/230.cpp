#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;
const int MAX_N = 1 << 18;
//segはその区間での現在の正しい値を持つ このあたはサボれる
//lazyはその区間に評価を遅延している(加えていない、書き換えていない)ものを持つ
//再帰で根から辿りながら、遅延評価を辿った頂点の子に振りまいていきながら、こまめに節点の本当の値を再計算。必要になったときだけ細かく計算すればよいという感じらしい。
int size;
struct segtree{
	vector<ll> lazy;//Aさんが塗っていれば1　Bさんが塗っていれば2
	vector<pair<ll, ll> > seg;//firstはAさんの色の数 secondはBさんの色の数
	segtree(int n){
		size = 1;
		while(size < n) size *= 2;//要素数を2のべき乗に
		seg.resize(size * 2);
		lazy.resize(size * 2, -1);
	}

	//遅延評価
	void lazy_evaluate_node(int k, int l, int r){
		if(lazy[k] != -1){//遅延がある時
			//(1)この位置を変える(遅延情報の適用方法)
			if(lazy[k] == 1){
				seg[k] = make_pair(r - l, 0);
			}else if(lazy[k] == 2){
				seg[k] = make_pair(0, r - l);
			}

			if(r  - l > 1){
				//(2)この位置を変える(遅延情報の伝搬方法) 今回は数字を置き換える
				lazy[k * 2 + 1] = lazy[k];//左の子に伝搬
				lazy[k * 2 + 2] = lazy[k];//右の子に伝搬
			}
			lazy[k] = -1;//ノードkは伝搬完了
		}
	}

	//update(a,b,v) := [a,b)を全てvに書き換える
	void update(int a, int b, ll v, int k = 0, int l = 0, int r = size){
		lazy_evaluate_node(k, l, r);//辿ったノードはついでについでに伝搬しておく
		if(r <= a || b <= l) return;//[a,b)がノードkの区間[l, r)と交差しない
		if(a <= l && r <= b){//[a,bが[l,r)を完全に含んでいる
			lazy[k] = v;//ノードkの区間[l,r)を全てvに書き換える
			lazy_evaluate_node(k, l, r);//一回遅延評価しとかないと都合悪い?? ([l,r)の葉の数字は全て同じ値)
		}else{//必要になったら、詳細に調べる
			update(a, b, v, k * 2 + 1, l, (l + r) / 2);
			update(a, b, v, k * 2 + 2, (l + r) / 2, r);
			//(3)この位置を変える (値のマージ)
			seg[k] = make_pair(seg[k * 2 + 1].first + seg[k * 2 + 2].first, seg[k * 2 + 1].second + seg[k * 2 + 2].second);
		}
	}

	//get(a,b) := [a,b)に対する総和を求める
	pair<ll, ll> get(int a, int b, int k = 0, int l = 0, int r = size){
		lazy_evaluate_node(k, l, r);//辿ったノードはついでについでに伝搬しておく
		if(r <= a || b <= l) return make_pair(0, 0);//[a,b)がノードkの区間[l, r)と交差しない時0を返す
		if(a <= l && r <= b) return seg[k];//[a,bが[l,r)を完全に含んでいる時そのノードの値を返す
		pair<ll, ll> x = get(a, b, k * 2 + 1, l, (l + r) / 2);//左の子の総和
		pair<ll, ll> y = get(a, b, k * 2 + 2, (l + r) / 2, r);//右の子の総和
		return make_pair(x.first + y.first, x.second + y.second);//それぞれの子の和を返すd
	}
};

int main(void){
	int n; cin >> n;
	int q; cin >> q;
	segtree st(n);
	
	ll ansa = 0, ansb = 0;
	rep(i, q){
		int x; cin >> x;
		int left, right; cin >> left >> right;
		if(x == 0){//ボーナス
			auto u = st.get(left, right + 1);
			if(u.first > u.second) ansa += u.first;
			else if(u.first < u.second) ansb += u.second;
		}else if(x == 1){
			st.update(left, right + 1, 1);
		}else{
			st.update(left, right + 1, 2);
		}
	}
	auto ret = st.get(0, n);
	ansa += ret.first; ansb += ret.second;
	printf("%lld %lld\n", ansa, ansb);
	return 0;
}