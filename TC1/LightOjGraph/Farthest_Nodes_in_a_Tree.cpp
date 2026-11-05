#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif
struct State {
    int a, b, c;
};
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

bool vis[26][26][26];
int dis[26][26][26];

void solve() {
    string a, b;
    cin >> a >> b;

    int n;
    cin >> n;

    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));

    for (int i = 0; i < n; i++) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        for (char c1 : s1) {
            for (char c2 : s2) {
                for (char c3 : s3) {
                    vis[c1 - 'a'][c2 - 'a'][c3 - 'a'] = true;
                }
            }
        }
    }

    int sa = a[0] - 'a', sb = a[1] - 'a', sc = a[2] - 'a';
    int fa = b[0] - 'a', fb = b[1] - 'a', fc = b[2] - 'a';

    if (vis[sa][sb][sc] || vis[fa][fb][fc]) {
        cout << -1 << endl;
        return;
    }

    queue<State> q;
    q.push({sa, sb, sc});
    vis[sa][sb][sc] = true;
    dis[sa][sb][sc] = 0;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        if (cur.a == fa && cur.b == fb && cur.c == fc) {
            break;
        }

        for (int i = 0; i < 6; i++) {
            int na = (cur.a + dx[i] + 26) % 26;
            int nb = (cur.b + dy[i] + 26) % 26;
            int nc = (cur.c + dz[i] + 26) % 26;

            if (!vis[na][nb][nc]) {
                vis[na][nb][nc] = true;
                dis[na][nb][nc] = dis[cur.a][cur.b][cur.c] + 1;
                q.push({na, nb, nc});
            }
        }
    }

    cout << dis[fa][fb][fc] << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}