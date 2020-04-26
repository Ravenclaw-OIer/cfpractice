#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define y2 y1919810
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
#define range(i, s, t)  for (int (i) = s; (i) <= (int)t; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
long long qread() {
	char c;
	int neg = 1;
	long long val = 0;
	while (c != '-' && !isdigit(c)) c = getchar();
	if (c == '-') c = getchar(), neg = -1;
	while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
	return neg * val;
}
const string NO = "There is no route, Karl!";
const int N = 100010;
vector <int> G[N];
int n, m;
int indeg[N], outdeg[N];
int vis[N], cnt;
stack <int> s;
bool good = 0;
vector <int> ans;
void dfs(int u) {
	if (good) return;
	vis[u] = true;
	s.push(u);
//	cerr << "CALL DFS " << u << endl; 
	for (auto v:G[u]) {
		if ((int)s.size() == n && v == 1) {
			while (!s.empty()) {
				ans.pb(s.top());
				s.pop();
			}
			good = true;
			return;
		}
		if (!vis[v]) dfs(v);
	}
//	cerr << "RET " << u << endl;
	if (!s.empty())s.pop();
	vis[u] = false;
}
int main() {
#ifndef CHTHOLLY
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
#endif
	n = qread(); m = qread();
	rep(i, m) {
		int u = qread(), v = qread(); 
		G[u].pb(v); 
		outdeg[u]++;
		indeg[v]++;
	}
	memset(vis, 0, sizeof(vis)); cnt = 0;
	dfs(1);
	reverse(ans.begin(), ans.end());
	if (!good) {
		cout << NO << endl;
		return 0;
	}
	rep(i, n) cout << ans[i] << ' ';
	cout << 1 << endl;
	return 0;
}
