
// Problem : 1025 - A Spy in the Metro
// Contest : UVa Online Judge
// URL : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=847&page=show_problem&problem=3466
// Memory Limit : 32.000000 MB 
// Time Limit : 3000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
const int N = 60, MAXT = 210;
int dp[N][MAXT], t[N], n, T, at[N], m1, m2, d1[N], d2[N];
bool ride[N][MAXT][2];
void clear() {
	memset(dp, INF, sizeof(dp));
	memset(t, 0, sizeof(t));
	memset(at, 0, sizeof(at));
	memset(d1, 0, sizeof(d1));
	memset(d2, 0, sizeof(d2));
	memset(ride, 0, sizeof(ride));
}
void init() {
	repn(i, m1) {
		int tot = d1[i];
		if (tot > T) break;
		ride[1][tot][0] = true;
		repn(j, n - 2) {
			tot += t[j];
			if (tot > T) break;
			ride[j + 1][tot][0] = true;
		}
	}
	repn(i, m2) {
		int tot = d2[i];
		if (tot > T) break;
		ride[n][tot][1] = true;
		for (int j = n - 1; j >= 2; j--) {
			tot += t[j];
			if (tot > T) break;
			ride[j][tot][1] = true;
		}
	}
}
#define chmin(x, y) y = min(x, y);
int main() {
	freopen("qwq.out","w", stdout); 
	int kase = 0;
	while (cin >> n && n) {
		clear();
		cin >> T;
		repn(i, n - 1) cin >> t[i];
		cin >> m1; repn(i, m1) cin >> d1[i];
		cin >> m2; repn(i, m2) cin >> d2[i];
		init();
		dp[T][n] = 0;
		for (int i = T - 1; i >= 0; i--) repn(j, n) {
			//wait
			chmin(dp[i + 1][j] + 1, dp[i][j]);	//increase by one for waiting at a station
			//ride to the right
			if (j < n && ride[j][i][0] && i + t[j] <= T)	//check if a train is available
				chmin(dp[i + t[j]][j + 1], dp[i][j]);	//stay the same, or update it
			//ride to the left
			if (j > 1 && ride[j][i][1] && i + t[j - 1] <= T)	//check if a train is available
				chmin(dp[i + t[j - 1]][j - 1], dp[i][j]);
		}
		cout << "Case Number " << ++kase << ": " << (dp[0][1] == INF ? "impossible" : to_string(dp[0][1])) << endl;
	}
	return 0;
}

