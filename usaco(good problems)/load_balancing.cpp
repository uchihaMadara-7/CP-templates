// https://usaco.org/index.php?page=viewproblem2&cpid=617
// Solution: https://usaco.guide/problems/usaco-617-load-balancing/solution
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <unordered_set>
#include <vector>
#include <climits>
using namespace std;

using ll = long long;
using db = long double;

using pi = pair<int, int>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
tcT> using V = vector<T>;
using vi = V<int>;
using vs = V<string>;
using vb = V<bool>;
using vpi = V<pi>;
using vvi = V<V<int>>;
using vvs = V<V<string>>;

//  uordered sets and maps
tcT> using uset = unordered_set<T>;
using useti = uset<int>;
using usets = uset<string>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define pob pop_back
#define ft front()
#define bk back()

#define loop(i,a,b) for (int i = (a); i < (b); ++i)
#define l0p(i,a) loop(i,0,a)
#define pool(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define p0l(i,a) pool(i,0,a)
#define rep(i,a) l0p(i,a)
#define each(a,x) for (auto& a: x)

const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; // for every grid problem!!

const int MOD = 1e9+7;
const int MX = (int)2e5+5;
const ll BIG = 1e18; // not too close to LLONG_MAX

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; } // set a = max(a,b)

// utility
tcT> void cpy(T &src, T &dest) {}

//  output/debug
tcT> void debug(const T &t) { cout << t << endl; }
tcT, class... U> void debug(const T& t, const U&... u) {
	cout << t << " "; debug(u...);
}

// input/reading
tcT> void iar(T &ar, int n) {
    rep(i,n) cin >> ar[i];
}
tcT> void iarp(T &ar, int n) {
    rep(i, n) cin >> ar[i].first >> ar[i].second;
}
tcT> void ipar(T &ar, int n) {
	using elment_type = typename T::value_type;
	elment_type x;
	rep(i,n) {
		cin >> x;
		ar.pb(x);
	}
}

void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }

void setIn(string s)  { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
	unsyncIO();
	// cin.exceptions(cin.failbit);
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for USACO
}

int main() {
    setIO("balancing");

	int n, b;
	cin >> n >> b;
	vpi ar(n);
	set<int> stx, sty;
	rep(i, n) {
		cin >> ar[i].first >> ar[i].second;
		stx.insert(ar[i].first);
		sty.insert(ar[i].second);
	}

	vi px, py;
	each(x,stx) px.pb(x+1);
	each(y,sty) py.pb(y+1);

	int ans = INT_MAX;
	int x1f = sz(px)/3, y1f = sz(py)/3;
	each(x,px) each(y,py) {
	// loop(xi, x1f, sz(px)-x1f+1) loop(yi, y1f, sz(py)-y1f+1) {
	// 	int x = px[xi], y = py[yi];
		vvi quad{{0, 0}, {0, 0}};
		int ret = INT_MIN;
		rep(i, n) quad[x < ar[i].first][y < ar[i].second]++;
		rep(i, 2) rep(j, 2) ckmax(ret, quad[i][j]);
		ckmin(ans, ret);
	}
	debug(ans);

    return 0;
}