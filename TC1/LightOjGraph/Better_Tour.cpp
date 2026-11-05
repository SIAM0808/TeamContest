#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;

const int mx = 50005;
vector<vector<int>> g(mx);
vector<int> par(mx, -1);
vector<bool> vis(mx, false);

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i : v) {
        g[i].clear();
        vis[i] = false;
        par[i] = -1;
    }

    for (int i = 0; i < n - 1; i++) {
        g[v[i]].push_back(v[i + 1]);
        g[v[i + 1]].push_back(v[i]);
    }

    for (int u : v) {
        if (!g[u].empty()) {
            sort(g[u].begin(), g[u].end());
        }
    }

    int src = v[0];
    int des = v[n - 1];

    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == des) break;

        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                par[v] = u;
                q.push(v);
            }
        }
    }

    vector<int> path;
    int cur = des;
    while(cur != -1) {
        path.push_back(cur);
        cur = par[cur];
    }
    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}