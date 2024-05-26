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
using ps = pair<string, string>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
tcT> using V = vector<T>;
using vi = V<int>;
using vs = V<string>;
using vb = V<bool>;
using vpi = V<pi>;
using vps = V<ps>;
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
tcT> void input(T &x) { cin >> x; }
tcT, class... U> void input(T &x, U&... u) {
	cin >> x; input(u...);
}
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
    setIO();

    return 0;
}