#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;

static const int MAX_NODES = 1600005; 
static const int B = 30;

class BitwiseTrie {
private:
    int trie[MAX_NODES][2];
    int cnt[MAX_NODES];
    int nodes_cnt = 1;

public:
    BitwiseTrie() {
        reset();
    }

    void reset() {
        for (int i = 0; i < nodes_cnt; ++i) {
            trie[i][0] = trie[i][1] = 0;
            cnt[i] = 0;
        }
        nodes_cnt = 1;
    }

    int count(long long num) {
        int cur = 0;
        for (int b = B; b >= 0; --b) {
            int bit = ((unsigned long long)num >> b) & 1;
            if (!trie[cur][bit]) return 0;
            cur = trie[cur][bit];
        }
        return cnt[cur];
    }

    void insert(long long num) {
        int cur = 0;
        cnt[cur]++;
        for (int b = B; b >= 0; --b) {
            int bit = ((unsigned long long)num >> b) & 1;
            if (!trie[cur][bit]) {
                trie[cur][bit] = nodes_cnt++;
            }
            cur = trie[cur][bit];
            cnt[cur]++;
        }
    }

    long long queryMaxXor(long long num) {
        if (cnt[0] == 0) return 0;
        int cur = 0;
        long long res = 0;
        for (int b = B; b >= 0; --b) {
            int bit = ((unsigned long long)num >> b) & 1;
            int want = bit ^ 1;
            if (trie[cur][want] && cnt[trie[cur][want]] > 0) {
                res |= (1ULL << b);
                cur = trie[cur][want];
            } else {
                cur = trie[cur][bit];
            }
        }
        return res;
    }

    long long queryMinXor(long long num) {
        if (cnt[0] == 0) return 0;
        int cur = 0;
        long long res = 0;
        for (int b = B; b >= 0; --b) {
            int bit = ((unsigned long long)num >> b) & 1;
            if (trie[cur][bit] && cnt[trie[cur][bit]] > 0) {
                cur = trie[cur][bit];
            } else {
                res |= (1ULL << b);
                cur = trie[cur][bit ^ 1];
            }
        }
        return res;
    }
} btr;

void solve(int tc) {
    btr.reset();

    int n;
    cin >> n;

    long long pref_xor = 0;
    btr.insert(0); 

    long long max_ans = 0;
    long long min_ans = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        pref_xor ^= x;

        max_ans = max(max_ans, btr.queryMaxXor(pref_xor));
        min_ans = min(min_ans, btr.queryMinXor(pref_xor));

        btr.insert(pref_xor);
    }

    cout << "Case " << tc << ": " << max_ans << " " << min_ans << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
    return 0;
}