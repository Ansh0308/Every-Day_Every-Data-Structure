#include <bits/stdc++.h>
using namespace std;

// -------------------------------
// 🔹 Shortcuts & Typedefs
// -------------------------------
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<string> vs;

// -------------------------------
// 🔹 Macros
// -------------------------------
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define sz(x) (int)(x).size()

#define forn(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i <= (n); i++)
#define forr(i, n) for (int i = (n)-1; i >= 0; i--)

// -------------------------------
// 🔹 Input / Output Helpers
// -------------------------------
vi input_vi(int n = -1) {
    if (n == -1) cin >> n;
    vi v(n);
    forn(i, n) cin >> v[i];
    return v;
}

vll input_vll(int n = -1) {
    if (n == -1) cin >> n;
    vll v(n);
    forn(i, n) cin >> v[i];
    return v;
}

template<typename T>
void print_vec(const vector<T>& v, string sep = " ") {
    for (auto &x : v) cout << x << sep;
    cout << endl;
}

// -------------------------------
// 🔹 Debug Utility
// -------------------------------
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << x << endl
#else
#define dbg(x)
#endif

// -------------------------------
// 🔹 Constants
// -------------------------------
const ll INF = 1e18;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

// -------------------------------
// 🔹 Main Logic Example
// -------------------------------
int Rat_in_Maze_Init(vvi& maze, int cu_row, int cu_col,vector<string>& paths, string path_so_far = "") {
    int n = maze.size();

    if (cu_row < 0 || cu_col < 0 || cu_row >= n || cu_col >= n || maze[cu_row][cu_col] == 0)
        return 0;

    if (cu_row == n - 1 && cu_col == n - 1) {
        paths.push_back(path_so_far);
        return 1;
    }

    // mark visited
    maze[cu_row][cu_col] = 0;

    int total =
        Rat_in_Maze_Init(maze, cu_row + 1, cu_col, paths, path_so_far + "D") +
        Rat_in_Maze_Init(maze, cu_row - 1, cu_col, paths, path_so_far + "U") +
        Rat_in_Maze_Init(maze, cu_row, cu_col + 1, paths, path_so_far + "R") +
        Rat_in_Maze_Init(maze, cu_row, cu_col - 1, paths, path_so_far + "L");

    // unmark AFTER recursion
    maze[cu_row][cu_col] = 1;

    return total;
}


void solve() {
    vvi maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vs paths;
    int total_paths = Rat_in_Maze_Init(maze, 0, 0, paths);
    cout << "Total paths from source to destination: " << total_paths << endl;
    cout << "Paths:" << endl;
    for (const auto& p : paths) {
        cout << p << endl;
    }

}

// -------------------------------
// 🔹 Entry Point
// -------------------------------
int main() {
    solve();
    return 0;
}
