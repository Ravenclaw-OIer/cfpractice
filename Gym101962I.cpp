
// Problem : I. Colonial Mansions
// Contest : UFBA Practice Session for Brazilian ICPC Regionals - 2018
// URL : https://codeforces.com/gym/101962/problem/I
// Memory Limit : 256 MB
// Time Limit : 2500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define y2 y1919810
typedef pair <int, int> PII;
//#define int long long
#define all(x) (x.begin(),  x.end())
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define range(i, s, t)  for (int i = s; i <= (int)t; i++)
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
const int N = 500050;
struct segTreeNode {
	int l, r, v;
	segTreeNode(int l = 0, int r = 0, int v = 0): l(l), r(r), v(v) {}
}t[N];	//segment tree maintains the difference of nodes
int a[N], n, q;
void pushup(int p) {
	t[p].v = max(t[p << 1].v, max(t[p << 1 | 1].v, abs(t[p << 1].r - t[p << 1 | 1].l)));
	t[p].l = t[p << 1].l;
	t[p].r = t[p << 1 | 1].r;
}
void build(int p, int l, int r) {
	if (l == r) {
		t[p].v = 0;
		t[p].l = t[p].r = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	pushup(p);
}
void modify(int p, int l, int r, int pos, int v) {
	if (l == r && pos == l) {
		t[p].l = t[p].r = v;
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid) modify(p << 1, l, mid, pos, v);
	else modify(p << 1 | 1, mid + 1, r, pos, v);
	pushup(p);
}
int query(int p, int ql, int qr, int l, int r) {
	if (ql <= l && r <= qr) return t[p].v;
	int mid = (l + r) >> 1;
	if (qr <= mid) return query(p << 1, ql, qr, l, mid);
	else if (mid < ql) return query(p << 1 | 1, ql, qr, mid + 1, r);
	else return max(query(p << 1, ql, qr, l, mid), max(query(p << 1 | 1, ql, qr, mid + 1, r), abs(t[p << 1].r - t[p << 1 | 1].l)));
}
int solve(int pos, int v) {
	int res = 0, l = pos, r = n;
	//solve for the right part
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (query(1, l, mid, 1, n) > v) r = mid;
		else l = mid;
	}
	if (abs(a[r] - a[l]) <= v) res += r - pos + 1;	//whole parts can be added to the answer
	else res += l - pos + 1; //[l, r] is not okay, so only [pos, l] counts
	//then, solve for the left part
	l = 1, r = pos;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (query(1, mid, r, 1, n) > v) l = mid;
		else r = mid;
	}	//everything is done reversed-ly
	//similarly, count the answer
	if (abs(a[r] - a[l]) <= v) res += pos - l;
	else res += pos - l - 1;
	return res;
}
int main() {
	n = qread(); q = qread();
	repn(i, n) a[i] = qread();
	build(1, 1, n);
	while (q--) {
		int op = qread();
		int p = qread(), v = qread();
		if (op == 1) {
			modify(1, 1, n, p, v);
			a[p] = v;
		}
		else cout << solve(p, v) << endl;
	}
	return 0;
}