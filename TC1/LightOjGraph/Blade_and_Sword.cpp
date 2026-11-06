#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;

int m, n;
char grid[55][55];
bool vis[55][55];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int r, int c, char wall) {
    vis[r][c] = true;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        // Stay within the padded grid [0 .. m+1][0 .. n+1]
        if (nr >= 0 && nr <= m + 1 && nc >= 0 && nc <= n + 1) {
            if (!vis[nr][nc] && grid[nr][nc] != wall) {
                dfs(nr, nc, wall);
            }
        }
    }
}

void solve(int tc) {
    cin >> m >> n;

    // Initialize padded grid with '.'
    memset(grid, '.', sizeof(grid));
    bool present[26] = {false};

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] != '.') {
                present[grid[i][j] - 'A'] = true;
            }
        }
    }

    // Try every letter that exists in the initial grid
    for (int c = 0; c < 26; c++) {
        if (!present[c]) continue;
        char ch = 'A' + c;

        memset(vis, false, sizeof(vis));
        
        // Flood fill from the outside border (0, 0)
        // Since (0, 0) is guaranteed to be '.', it is never equal to ch
        dfs(0, 0, ch);

        // Any cell not reached by the outside flood is enclosed by 'ch'
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (!vis[i][j]) {
                    grid[i][j] = ch;
                }
            }
        }
    }

    cout << "Case " << tc << ":\n";
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        solve(tc);
    }
    return 0;
}