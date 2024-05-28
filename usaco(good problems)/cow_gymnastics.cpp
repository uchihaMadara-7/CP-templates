// https://usaco.org/index.php?page=viewproblem2&cpid=963
// Solution: https://usaco.guide/problems/usaco-963-cow-gymnastics/solution
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

//  output/debug
tcT> void debug(const T &t) { cout << t << endl; }
tcT, class... U> void debug(const T& t, const U&... u) {
	cout << t << " "; debug(u...);
}

// input/reading
tcT> void iar(T &ar, int n) {
    loop(i,0,n) cin >> ar[i];
}

void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }

void setIn(string s)  { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
	unsyncIO();
	// cin.exceptions(cin.failbit);
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for USACOs
}

int main() {
    setIO("gymnastics");

	int k, n;
	cin >> k >> n;
	vvi ar(k, vi(n));
	rep(i,k) {
		iar(ar[i], n);
	}

	set<string> s;
	map<string, int> hash;
	rep(i,n) loop(j, i+1, n) {
		string key = to_string(ar[0][i]) + "," + to_string(ar[0][j]);
		s.insert(key);
		hash[key] = 1;
	}

	loop(i, 1, k) {
		rep(j,n) loop(k, j+1, n) {
			string key = to_string(ar[i][j]) + "," + to_string(ar[i][k]);
			if (hash.count(key)) ++hash[key];
		}
	}

	int ans = 0;
	each(x, hash) {
		 if (x.second == k) ++ans;
	}
	debug(ans);

    return 0;
}
