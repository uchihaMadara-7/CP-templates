// https://usaco.org/index.php?page=viewproblem2&cpid=739
// Solution: https://usaco.guide/problems/usaco-739-bovine-genomics/solution
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
#include <numeric>
#include <queue>
#include <random>
#include <set>
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

int getid(char x) {
	switch(x) {
		case 'A': return 0;
		case 'C': return 1;
		case 'G': return 2;
		default: return 3;
	}
}

int main() {
    setIO("cownomics");

	int n, m;
	cin >> n >> m;
	vs ars(n), arp(n);
	rep(i,n) cin >> ars[i];
	rep(i,n) cin >> arp[i];

	int ans = 0;
	rep(i,m) loop(j,i+1,m) loop(k,j+1,m) {
		vi id(100, 0);
		rep(u,n) {
			int key = getid(ars[u][i])*16+getid(ars[u][j])*4+getid(ars[u][k]);
			++id[key];
		}
		bool flag = true;
		rep(u,n) {
			int key = getid(arp[u][i])*16+getid(arp[u][j])*4+getid(arp[u][k]);
			if (id[key]) {
				flag = false;
				break;
			}
		}
		if (flag) ++ans;
	}
	debug(ans);

    return 0;
}
