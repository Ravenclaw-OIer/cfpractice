
// Problem : B. Longest Palindrome
// Contest : Codeforces Round #620 (Div. 2)
// URL : https://codeforces.com/contest/1304/problem/B
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

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
	char c = getchar();
	int neg = 1;
	long long val = 0;
	while (c != '-' && !isdigit(c)) c = getchar();
	if (c == '-') c = getchar(), neg = -1;
	while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
	return neg * val;
}
int n, m;
const int N = 110;
string s[N];
int rev[N];
string revself;
int main() {
	n = qread();
	m = qread();
	rep(i, n) {
		string ss; cin >> ss;
		s[i] = ss;
		string sss = ss;
		reverse(sss.begin(), sss.end());
		if (sss == ss) revself = ss;
		rep(j, i) {
			if (sss == s[j]) rev[j] = i;
		}
	}
	string a, b;
	rep(i, n) if (rev[i]) {
		for (auto c:s[i]) {
			a.pb(c);
			b.pb(c);
		}
	}
	reverse(b.begin(), b.end());
	string ans = a + revself + b;
	cout << ans.length() << endl << ans << endl;
	return 0;
}
