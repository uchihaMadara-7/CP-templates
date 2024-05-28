// https://usaco.org/index.php?page=viewproblem2&cpid=526
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

const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; // for every grid problem!!

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
https://usaco.guide/problems/usaco-526-censoring/solution

Explanation

Let us define $\texttt{censored}$ as the final censored text.

We can iterate through every character of $s$, appending it to $\texttt{censored}$.
However, whenever we append a character we we need to check if $\texttt{censored}$ ends with the censored word.
If it does, we remove it from $\texttt{censored}$ by taking off the last few characters.

As a demonstration, let's try this on the example case where:

$$\begin{align*} s&=\texttt{whatthemomooofun} \\ t&=\texttt{moo} \end{align*}$$

Our solution will loop through each character of $s$, appending it to $\texttt{censored}$ until it becomes $\texttt{whatthemomoo}$, when it will cut off the last 3 characters since they equal $t$. This results in $\texttt{censored}$ becoming $\texttt{whatthemo}$.
Right after this, $\texttt{censored}$ becomes $\texttt{whatthemoo}$ as the next letter in $s$ is $o$, so we omit the last 3 characters again and $\texttt{censored}$ becomes $\texttt{whatthe}$.

After this, the check isn't triggered anymore, so we end up with $\texttt{whatthefun}$ as our final word.

*/

int main() {
    setIO();

	string str, pattern, ans = "";
	cin >> str >> pattern;
	int size_str = sz(str);
	int size_pattern = sz(pattern);
	loop(i, 0, size_str) {
		ans.append(1, str[i]);
		if (sz(ans) >= size_pattern
				&& ans.substr(sz(ans)-size_pattern, sz(ans)) == pattern) {
			ans.resize(sz(ans)-size_pattern);
		}
	}
	debug1(ans);

    return 0;
}
