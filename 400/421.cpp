#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;
const int MAX_V = 3000;//頂点数

int N, M;
struct Flow{
    struct edge{
        int to, cap, rev;
    };
    vector<edge> G[MAX_V];//隣接リスト
    bool used[MAX_V];

    void add_edge(int from, int to, int cap){
        G[from].push_back((edge){to, cap, (int)G[to].size()});//from -> to
        G[to].push_back((edge){from, 0, (int)G[from].size() - 1});//to -> from
    }

    //増加パスを探す
    int dfs(int v, int t, int f){
        if(v == t) return f;
        used[v] = true;
        for (int i = 0; i < G[v].size(); ++i){
            edge &e = G[v][i];
            if(!used[e.to] && e.cap > 0){
                int d = dfs(e.to, t, min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    //sからtへの最大流
    int max_flow(int s, int t){
        int flow = 0;
        while(1){
            memset(used, 0, sizeof(used));
            int f = dfs(s, t, INF);
            if(f == 0) return flow;
            flow += f;
        }
    }
};

string board[55];
int dy[] = {1, 0, 0, -1};
int dx[] = {0, 1, -1, 0};

int main(void){
	cin >> N >> M;
    rep(i, N) cin >> board[i];

	int s = N * M ;
	int t = N * M + 1;
    int numw = 0, numb = 0;
	Flow mf;
	//s -> w  b -> t
	rep(i, N)rep(j, M){
        if(board[i][j] == 'w'){
            mf.add_edge(s, M * i + j, 1);
            numw++;
        }else if(board[i][j] == 'b'){
            mf.add_edge(M * i + j, t, 1);
            numb++;
        }
	}

	// x -> y
	rep(i, N)rep(j, M){
        if(board[i][j] == 'w'){
            rep(k, 4){
                int ny = i + dy[k], nx = j + dx[k];
                if(!(0 <= ny && ny < N && 0 <= nx && nx < M)) continue;
                if(board[ny][nx] == 'b'){
                    mf.add_edge(M * i + j, M * ny + nx, 1);
                }
            }
        }
    }

    int max_f = mf.max_flow(s, t);//100点
    int nw = numw - max_f, nb = numb - max_f;//残っている数
    int two = min(nw, nb);//10点
    int one = nw + nb - (two) * 2;//1点
    printf("%d\n", 100 * max_f + 10 * two + one);
    return 0;
}