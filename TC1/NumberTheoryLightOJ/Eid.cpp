#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
const int MAXN = 10005;
vector<int> primes;
bool is_prime[MAXN];
int mxp[MAXN];

void sieve() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAXN; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j < MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
string mul(string num, int x) {
    int carry = 0;
    for (int i = 0; i < num.size(); i++) {
        int prod = (num[i] - '0') * x + carry;
        num[i] = (prod % 10) + '0';
        carry = prod / 10;
    }
    while (carry) {
        num.push_back((carry % 10) + '0');
        carry /= 10;
    }
    return num;
}
void Solve()
{
    int n;
    cin >> n;
    
    memset(mxp, 0, sizeof(mxp));
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        for (int p : primes) {
            if (p * p > x) break;
            if (x % p == 0) {
                int cnt = 0;
                while (x % p == 0) {
                    x /= p;
                    cnt++;
                }
                mxp[p] = max(mxp[p], cnt);
            }
        }
        if (x > 1) {
            mxp[x] = max(mxp[x], 1);
        }
    }

    string ans = "1"; 
    
    for (int p : primes) {
        if (mxp[p] > 0) {
            int val = 1;
            for (int j = 0; j < mxp[p]; j++) {
                val *= p; 
            }
            ans = mul(ans, val);
        }
    }
    
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    sieve();
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}