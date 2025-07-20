#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n;
    cin>>n;
    char grid[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    if(grid[0][0] == '*' ){
        cout<<0<<endl;
        return 0;
    }
    vector<vector<int>> dp(n, vector<int>(n,0));
    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == '*' || (i==0 && j == 0)) continue;
            dp[i][j] = (i > 0 ? dp[i-1][j] : 0) + (j>0 ? dp[i][j-1] : 0);
            dp[i][j] %= mod;
            
            
        }
        
    }
    cout<<dp[n-1][n-1]<<endl;
}