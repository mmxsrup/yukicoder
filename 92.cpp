#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <set>
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

int main(void){
	int n, m, k;
	cin >> n >> m >> k;
	int a[1010];
	int b[1010];
	int c[1010];
	rep(i, m){
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		A--; B--;
		a[i] = A; b[i] = B; c[i] = C;
	}
	
	set<int> U1; set<int> U2;
	rep(i, n) U1.insert(i);//初期化
	rep(i, k){//dのクエリを
		int d; scanf("%d", &d);
		for(set<int>::iterator it = U1.begin(); it != U1.end(); it++){
			int tmp = *it;//集合ないの頂点の番号
			rep(j, m){
				if(c[j] == d){
					if(a[j] == tmp) U2.insert(b[j]);
					if(b[j] == tmp) U2.insert(a[j]);
				}
			}

		}
		U1.clear();
		U1 = U2;
		U2.clear();
	}
	
	int size = U1.size();
	printf("%d\n", size);

	for(set<int>::iterator it = U1.begin(); it != U1.end(); it++){
		printf("%d ", *it + 1);
	}
	printf("\n");
	return 0;
}