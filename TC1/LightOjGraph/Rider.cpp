#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

void solve(int tc) {
    int m, n;
    cin >> m >> n;
    vector<string> v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }

    vector<vector<int>> tot(m, vector<int>(n, 0));
    vector<vector<int>> rCount(m, vector<int>(n, 0));
    int riders = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] != '.') {
                riders++;
                int k = v[i][j] - '0';
                vector<vector<int>> dist(m, vector<int>(n, -1));
                queue<pair<int, int>> q;

                q.push({i, j});
                dist[i][j] = 0;

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();

                    for (int d = 0; d < 8; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if (nx >= 0 && nx < m && ny >= 0 && ny < n && dist[nx][ny] == -1) {
                            dist[nx][ny] = dist[x][y] + 1;
                            q.push({nx, ny});
                        }
                    }
                }

                for (int r = 0; r < m; r++) {
                    for (int c = 0; c < n; c++) {
                        if (dist[r][c] != -1) {
                            rCount[r][c]++;
                            tot[r][c] += (dist[r][c] + k - 1) / k;
                        }
                    }
                }
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rCount[i][j] == riders) {
                ans = min(ans, tot[i][j]);
            }
        }
    }

    if (ans == INT_MAX) ans = -1;
    cout << "Case " << tc << ": " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        solve(tc);
    }
    return 0;
}