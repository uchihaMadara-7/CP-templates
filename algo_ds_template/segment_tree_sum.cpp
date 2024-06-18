#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
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
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using ll = long long;
using db = long double;

using pi = pair<int, int>;
using ps = pair<string, string>;
#define mp make_pair
#define f first
#define s second

#define tcT template <class T
tcT > using V = vector<T>;
using vi = V<int>;
using vll = V<ll>;
using vs = V<string>;
using vb = V<bool>;
using vpi = V<pi>;
using vps = V<ps>;
using vvi = V<V<int>>;
using vvs = V<V<string>>;

//  uordered sets and maps
tcT > using uset = unordered_set<T>;
using useti = uset<int>;
using usets = uset<string>;
tcT, class U > using umap = unordered_map<T, U>;
// tcT> using mxheap = priority_queue<T, greater<T>>;
// tcT> using mnheap = priority_queue<T, less<T>>;
// using mxheapi = mxheap<int>;
// using mnheapi = mnheap<int>;
// using mxheapvi = priority_queue<int, vi, greater<int>>;
// using mnheapvi = priority_queue<int, vi, less<int>>;

#define sz(x) (static_cast<int>((x).size()))
// #define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(rbegin(x), rend(x))
#define rsz resize
#define pb push_back
#define pob pop_back
#define ft front()
#define bk back()

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define l0p(i, a) loop(i, 0, a)
#define pool(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define p0l(i, a) pool(i, 0, a)
#define rep(i, a) l0p(i, a)
#define each(a, x) for (auto &a : x)

const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  // for every grid problem!!
const int d8[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                      {0, 1},   {1, -1}, {1, 0},  {1, 1}};
const int d4[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
#define seq(a, s) iota(a.begin(), a.end(), s)
#define rseq(a, start) iota(a.begin(), a.end(), start)

const int MOD = 1e9 + 7;
const int MX = static_cast<int>(2e5)+5;
// const int MX = (int)2e5 + 5;
const ll BIG = 1e18;  // not too close to LLONG_MAX

// __builtin_clz: count leading 0s in a number, __builtin_ctz counts trailing 0s
constexpr int pct(int x) { return __builtin_popcount(x); }  // count of bits set
// floor(log2(x)) - msb
constexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }
constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }

tcT > bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}  // set a = min(a,b)
tcT > bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}  // set a = max(a,b)
// tcT> T gcd(const T &a, const T &b) { return b?gcd(b,a%b):a;}

// utility
tcT > void cpy(T &src, T &dest) {}

//  output/debug
void debug(vi ar, int n) {
  rep(i, n) cout << ar[i] << " ";
  cout << endl;
}
tcT > void debug(const T &t) { cout << t << endl; }
tcT, class... U > void debug(const T &t, const U &...u) {
  cout << t << " ";
  debug(u...);
}

// input/reading
tcT > void val(T &x) { cin >> x; }
tcT, class... U > void val(T &x, U &...u) {
  val(x);
  val(u...);
}
tcT > void vala(T &ar, int n) { rep(i, n) val(ar[i]); }
tcT > void valap(T &ar, int n) { rep(i, n) val(ar[i].first, ar[i].second); }
tcT > void pbval(T &ar, int n) {
  using elment_type = typename T::value_type;
  elment_type x;
  rep(i, n) {
    val(x);
    ar.pb(x);
  }
}

void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void setIO(string s = "") {
  unsyncIO();
  // cin.exceptions(cin.failbit);
  // throws exception when do smth illegal
  // ex. try to read letter into int
  if (sz(s))
    setIn(s + ".in"), setOut(s + ".out");  // for USACO
}

const int MAXN = static_cast<int>(1e5);
int n, ar[MAXN], sgt[4*MAXN];

void build(int index, int left, int right) {
    if (left == right) {
        sgt[index] = ar[left];
        return;
    }
    int mid = left + (right-left)/2;
    int lindex = 2*index;
    int rindex = lindex+1;
    build(lindex, left, mid);
    build(rindex, mid+1, right);
    sgt[index] = sgt[lindex] + sgt[rindex];
}

int sum(int index, int left, int right, int l, int r) {
    if (l > r) return 0;
    if (l == left && r == right) return sgt[index];
    int mid = left + (right-left)/2;
    int lindex = 2*index;
    int rindex = lindex+1;
    return sum(lindex, left, mid+1, l, min(r, mid))
        + sum(rindex, mid+1, right, max(l, mid+1), r);
}

void update(int index, int left, int right, int pos, int value) {
    if (left == right) {
        sgt[index] = value;
    }
    int mid = left + (right-left)/2;
    int lindex = 2*index;
    int rindex = lindex+1;
    if (pos <= mid) update(lindex, left, mid, pos, value);
    else update(rindex, mid+1, right, pos, value);
    sgt[index] = sgt[lindex] + sgt[rindex];
}

int main() {
    setIO();

    return 0;
}
