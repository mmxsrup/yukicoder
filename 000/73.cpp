#include <iostream>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int d[30];
int main(void){
	rep(i, 26){
		cin >> d[i];
	}
	ll numd = d[3];
	ll nume = d[4];
	ll numh = d[7];
	ll numl = d[11];
	ll numo = d[14];
	ll numr = d[17];
	ll numw = d[22];

	//num* c 1
	ll sum = numd * nume * numh * numr * numw;
	//numl
	ll maxl = 0;
	for (int i = 2; i < numl; ++i){
		ll tmp = (i * (i - 1) / 2) * (numl - i);
		maxl = max(maxl, tmp);
	}
	//numo
	ll maxo = 0;
	for (int i = 1; i < numo; ++i){
		ll tmp = i * (numo - i);
		maxo = max(maxo, tmp);
	}

	sum *= (maxl * maxo);
	cout << sum << endl;
	return 0;
}