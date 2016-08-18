#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
static const int mod = 1e9 + 7;
//dp[i][j][k][l][m]
//整数pを考えた時に、i番目の桁まで考えて、j=1の時は考えている数がp未満であることが決定していて、j=0の時はp以下である。
//k=1の時はすでにi番目までに数字3を含んでいて、k=0の時は含まれていない。 lはi番目の桁まで考えた時のmod3の値
//mはi番目まで考えた時のmod8の値
long long dp[10010][2][2][3][8];
string a, b;

long long slv(string s){
	rep(i, 10010)rep(j, 2)rep(k, 2)rep(l, 3)rep(m, 8){
		dp[i][j][k][l][m] = 0;
	}

	dp[0][0][0][0][0] = 1;
	rep(i, s.size()){
		rep(j, 2){

			int lim;
			if(j == 1) lim = 9;
			else lim = s[i] - '0';
			
			rep(k, 2) rep(l, 3) rep(m, 8) rep(d, lim + 1){//dは末尾に追加する数字
				(dp[i + 1][j || d < lim][k || d == 3][(l + d) % 3][(10 * m + d) % 8] += dp[i][j][k][l][m]) %= mod;
			}
		}
	}

	long long ans = 0;
	rep(j, 2) rep(k, 2) rep(l, 3) rep(m, 8){
		if(k == 1|| l == 0){//３が含まれているまたは３の倍数
			if(m % 8 != 0)
			(ans += dp[s.size()][j][k][l][m]) %= mod;
		}
	}
	return ans;
}

bool hantei(void){
	//数字の３を含んでいるか判定
	bool flag = false;
	rep(i, a.size()){
		if(a[i] == '3'){
			flag = true; break;
		}
	}
	//3の倍数であるかをすべての桁の数字を足して３の倍数であるかで判定
	bool flag_3bai = false;
	long long sum = 0;
	rep(i, a.size()){	
		sum += (a[i] - '0');
	}
	if(sum % 3 == 0) flag_3bai = true;
	//8の倍数であるかを数字が大きい場合下三桁が８の倍数であるかで判定
	bool flag_8bai = false; int tm;
	if(a.size() > 6){
		string tmp = a.substr(a.size() - 3, 3);
		tm = stoi(tmp);
	}else{
		tm = stoi(a);
	}
	if(tm % 8 == 0) flag_8bai = true;

	if((flag || flag_3bai) && !flag_8bai) return true;
	else return false;
}

int main(void){
	cin >> a >> b;
	long long ans_a = slv(a);
	long long ans_b = slv(b);
	
	if(hantei()){//aが条件を満たす数字の時
		cout << (ans_b - ans_a + 1 + mod) % mod<< endl;
	}else{//満たさない時
		cout << (ans_b - ans_a + mod) % mod << endl;
	}
	return 0;
}