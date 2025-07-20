#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int x, int n, vector<int>& coins, vector<int>& dp) {
    if (x == 0) return 0;
    if (dp[x] != -1) return dp[x];

    int res = 1e9;
    for (int j = 0; j < n; j++) {
        if (x >= coins[j]) {
            res = min(res, 1 + solve(x - coins[j], n, coins, dp));
        }
    }
    
    return dp[x] = res;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<int> dp(x + 1, -1);
    int ans = solve(x, n, coins, dp);
    
    cout << (ans >= 1e9 ? -1 : ans) << endl;
    return 0;
}
