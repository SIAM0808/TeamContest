#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif
#define int long long
using ll = long long;
using namespace std;
// N - Failed System Test

     

/*
x+1, y
x, y+1
x-1, y
x, y-1
*/

int bfs(pair<int, int> src, int n, vector<vector<char>> &v, char tar){
	queue<pair<int, int>> q;
	q.push(src);
	vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
	dis[src.first][src.second] = 0;
	while(!q.empty()){
		auto [x, y] = q.front();
		// if(x == 2 && y == 4){
		// 	debug(v[x][y-1]);
		// }
		q.pop();
		// if(tar == 'B')
		// cerr << x << " " << y << endl;
		if(x+1 < n && (v[x+1][y] != '#' && (v[x+1][y] == '.' || v[x+1][y] <= tar))){
			if(dis[x+1][y] > dis[x][y] + 1){
				q.push({x+1, y});
				dis[x+1][y] = dis[x][y] + 1;
			}
		}if(y+1 < n && (v[x][y+1] != '#' && (v[x][y+1] == '.' || v[x][y+1] <= tar))){
			if(dis[x][y+1] > dis[x][y] + 1){
				q.push({x, y+1});
				dis[x][y+1] = dis[x][y] + 1;
			}
		}if(x-1 >= 0 && (v[x-1][y] != '#' && (v[x-1][y] == '.' || v[x-1][y] <= tar))){
			if(dis[x-1][y] > dis[x][y] + 1){
				q.push({x-1, y});
				dis[x-1][y] = dis[x][y] + 1;		
			}
		}if(y-1 >= 0 && (v[x][y-1] != '#' && (v[x][y-1] == '.' || v[x][y-1] <= tar))){
			// cerr << "axis: " << endl;
			// cerr << x << " " << y-1 << endl;
			if(dis[x][y-1] > dis[x][y] + 1){
				q.push({x, y-1});
				dis[x][y-1] = dis[x][y] + 1;
			}
		}
	}
	int res = INT_MAX;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(v[i][j] == tar){
				res = dis[i][j];
			}
		}
	}
	// debug(dis[0][0]);
	// if(res == INT_MAX){
	// 	debug(tar);
	// 	// debug()
	// 	// cerr << src.first << " " << src.second << endl;
	// 	for(int i=0; i<n; i++){
	// 		for(int j=0; j<n; j++) cerr << dis[i][j] << " ";
	// 			cerr << endl;
	// 	}
	// }
	return res;
}
void Solve()
{
	int n;
	cin >> n;
	queue<pair<int, int>> q;
	vector<vector<char>> v(n, vector<char>(n));
	// vector<vector<int>> dis(n, vector<int>(n));
	// auto fi = [&]() -> void{
	// 		for(int i=0; i<n; i++){
	// 			for(int j=0; j<n; j++) dis[i][j] = INT_MAX;
	// 		}
	// };
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> v[i][j];
			// if(v[i][j] == 'A') q.push({i, j});
		}
	}
	vector<char> ache;
	map<char, pair<int, int>> mp;
	for(int i =0; i<n; i++){
		for(int j=0; j<n; j++){
			if(v[i][j] != '#' && v[i][j] != '.') ache.push_back(v[i][j]), mp[v[i][j]] = {i, j};
		}
	}
	sort(ache.begin(), ache.end());
	// for(auto i : ache) cerr << i << " ";
	
	char c = 'A';
	int ans = 0;
	for(char i : ache){
		int res = bfs(mp[c], n, v, i);
		if(res == INT_MAX){
			// debug(i);
			// debug(c);
			cout << "Impossible" << endl;
			return;
		}
		c = i;		
		ans += res;
	}
	cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for(int i=1; i<=t; i++){
    	cout << "Case " << i << ": ";
    	Solve();
    }
    return 0;
}