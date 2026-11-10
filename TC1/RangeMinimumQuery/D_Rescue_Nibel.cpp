#include <bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()

struct segment_tree{
    vector<int> y;
    vector<int> sgt, cnt;
    int m;

    segment_tree(const vector<int>& y_coords) {
        this->y = y_coords;
        this->m = (int)y.size() - 1;
        sgt.assign(4 * m + 5, 0);
        cnt.assign(4 * m + 5, 0);
    }

    void push(int node, int start, int end) {
        if (cnt[node] > 0) {
            sgt[node] = y[end + 1] - y[start];
        } else if (start == end) {
            sgt[node] = 0;
        } else {
            sgt[node] = sgt[node * 2] + sgt[node * 2 + 1];
        }
    }

    void update(int node, int start, int end, int l, int r, int value){
        if (start > r or end < l) {
            return;
        }
        if (start >= l and r >= end){
            cnt[node] += value;
            push(node, start, end);
            return;
        }
        int mid = start + (end - start) / 2;
        update(node * 2, start, mid, l, r, value);
        update(node * 2 + 1, mid + 1, end, l, r, value);
        push(node, start, end);
    }

    void update(int l, int r, int val) {
        update(1, 0, m, l, r, val);
    }
};

void solve(int tc) {
    int n;
    cin >> n;

    struct event {
        int x, y1, y2;
        int type;
    };
    vector<event> a;
    vector<int> y;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        y.push_back(y1);
        y.push_back(y2);

        a.push_back({x1, y1, y2, +1});
        a.push_back({x2, y1, y2, -1});
    }

    sort(all(y));
    y.resize(unique(all(y)) - y.begin());

    sort(all(a), [&](event &x, event &y_ev){
        if (x.x != y_ev.x) return x.x < y_ev.x;
        return x.type > y_ev.type;
    });

    segment_tree st(y);

    int ans = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (i) {
            int dx = a[i].x - a[i - 1].x;
            int dy = st.sgt[1];
            ans += dy * dx;
            // cout << "area: " << a[i - 1].x << " " << a[i].x << " " << st.sgt[1] << endl;
        }

        int Y1 = lower_bound(all(y), a[i].y1) - y.begin();
        int Y2 = lower_bound(all(y), a[i].y2) - y.begin();
        // cout << "Update y-axis Range: " << a[i].x << " " << y[Y1] << " " << y[Y2] << " " << a[i].type << endl;

        st.update(Y1, Y2 - 1, a[i].type);
        // cout << endl;
    }

    cout << "Case " << tc << ": " << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    if (cin >> t) {
        for (int i = 1; i <= t; i++) {
            solve(i);
        }
    }
    return 0;
}
