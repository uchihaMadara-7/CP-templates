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

#define endl "\n"
#define debug1(x) cout << x << "\n"
#define debug2(x, y) cout << x << " " << y << "\n"
#define debug3(x, y, z) cout << x << " " << y << " " << z << "\n"
#define debug4(x, y, z, a) cout << x << " " << y << " " << z << " " << a << "\n"

using ll = long long;
using db = long double;

using pi = pair<int, int>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
tcT> using V = vector<T>;
using vi = V<int>;
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
#define l0p(i,a) for(i,0,a)
#define pool(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define p0l(i,a) pool(i,0,a)
#define rep(a) p0l(_,a)
#define each(a,x) for (auto& a: x)

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1}; // for every grid problem!!

const int MOD = 1e9+7;
const int MX = (int)2e5+5;
const ll BIG = 1e18; // not too close to LLONG_MAX

tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; } // set a = max(a,b)

void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }

void setIO(string s = "") {
	unsyncIO();
	// cin.exceptions(cin.failbit);
	// throws exception when do smth illegal
	// ex. try to read letter into int
	// if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for USACO
}

/* 
    https://usaco.org/index.php?page=viewproblem2&cpid=1061
*/

int main() {
    setIO();

	int n;
	cin >> n;
	vi ans(n, INT_MAX);
	vvi nor, est, col;
	vpi pos(n);
	loop(i, 0, n) {
		int first, second;
		char dir;
		cin >> dir >> first >> second;
		if (dir == 'N') nor.pb({i, first, second});
		else est.pb({i, first, second});
		pos[i] = mp(first, second);
	}

	loop(i, 0, sz(est)) {
		loop(j, 0, sz(nor)) {
			if (est[i][1] > nor[j][1] || nor[j][2] > est[i][2]) continue;
			int fd = nor[j][1] - est[i][1];
			int sd = est[i][2] - nor[j][2];
			if (fd == sd) continue;
			if (fd > sd) col.pb({fd, est[i][0], nor[j][0], 0});
			else col.pb({sd, nor[j][0], est[i][0], 1});
		}
	}

	sor(col);
	loop(i, 0, sz(col)) {
		// debug3(col[i][0], col[i][1], col[i][2]);
		if (ans[col[i][1]] == INT_MAX && ans[col[i][2]] == INT_MAX) {
			ans[col[i][1]] = col[i][0];
		}
		else if (ans[col[i][1]] == INT_MAX) {
			if (col[i][3]) {
				int finish = pos[col[i][2]].first + ans[col[i][2]];
				if (pos[col[i][1]].first < finish) {
					ans[col[i][1]] = col[i][0];
				}
			}
			else {
				int finish = pos[col[i][2]].second + ans[col[i][2]];
				if (pos[col[i][1]].second < finish) {
					ans[col[i][1]] = col[i][0];
				}
			}
		}
	}

	loop(i, 0, n) {
		if (ans[i] == INT_MAX) debug1("Infinity");
		else debug1(ans[i]);
	}

    return 0;
}
