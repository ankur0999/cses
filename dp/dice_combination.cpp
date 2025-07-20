#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    // Use a sliding window of size 6 (since j <= 6)
    int dp[6] = {0};
    dp[0] = 1;  // Base case: there's 1 way to represent 0

    for (int i = 1; i <= n; i++) {
        int current = 0;
        for (int j = 1; j<=i && j <= 6; j++) {
            
            current = (current + dp[(i - j) % 6]) % mod;
            
        }
        dp[i % 6] = current;  // Update dp for this position
    }

    cout << dp[n % 6] << endl;  // Final result
    return 0;

    // old model code

    // int n;
    // cin>>n;
    // vector<int> dp(n+1, 0);
    // dp[0] = 1;
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=i && j<=6; j++){
            
    //         dp[i] = (dp[i] + dp[i-j])%mod;
            
    //     }
    // }
    
    // cout<< dp[n]<<endl;

}
