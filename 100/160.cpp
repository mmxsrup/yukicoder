#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<pint> vpint;
#define mp make_pairt
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

const int MAX_N = 200;
int dist[MAX_N][MAX_N];
int distmemo[MAX_N][MAX_N];//経路復元の時に使う
const int INF = 1e9;
int s, g;//start goal

//ワーシャルフロイド法 全点対間最短経路をもとめるとき) (0オリジンで使うこと)
//dpを利用している
//dist[i][i] = 0 dist[i][j](経路がないもの)= dist[j][i] = INF(1e9)で初期化しておくこと
//dist[i][j] = dist[j][i] = (距離)を代入しておくこと
//経路復元用distmemo[i][j] は0で初期化しておいたらできた。
//この関数を利用することで、dist[i][j]の値(i,j間の距離)の最小値に更新されていく

//これで最短経路がもとまってる
void floyd (int n){//nは頂点の数
	rep(k, n) rep(i, n) rep(j, n)
		dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);//最終的に最短距離が入る
	
	//経路復元
    printf("%d ", s);
    int now = s;//nowの次の頂点を復元する
    while (now != g){
    	rep(i, n){//全ての頂点を確かめる
    		if (now == i) continue;//この時すでに出力済み
    		//経路があるかどうかは distmemo[now][i] を見ればよい
    		//これは元の経路とワーシャルフロイトによって求められた最短経路の和が最短経路と一致するかを確かめている
    		if (dist[now][g] == distmemo[now][i] + dist[i][g] && distmemo[now][i] > 0){
        		now = i;
        		if (now == g) printf("%d\n", g);
        		else printf("%d ", now);
        		break;
        	}
        }
    }
}


int main(void){
	int n, m;
	cin >> n >> m >> s >> g;
	//大きめの数字で初期化
	rep(i, n)rep(j, n) dist[i][j] = dist[j][i] = INF;
	//復元用は0で初期化しておく??
	rep(i, n)rep(j, n) distmemo[i][j] = distmemo[j][i] = 0;

	//同じところは0
	rep(i, n) dist[i][i] = 0;
	//入力
	rep(i, m){
		int a, b, c;
		scanf("%d%d%d", &a,&b,&c);
		//a--; b--; //0オリジンへ
		dist[a][b] = dist[b][a] = c;//バスは往復可能なので、2つに代入すること
		distmemo[a][b] = distmemo[b][a] = c;//経路復元に使うメモ用
	}
	floyd(n);//頂点の数
	return 0;		
}