#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n,w;
    cin>>n>>w;
    vector<int> coins(n), dp(w+1);

    for(int &c : coins) cin>>c;
    dp[0] = 1;
    for(int c: coins){ // making coins restrict so that 2+2+5 and 2 + 5 +2 counts one
        for(int i=1; i<=w; i++){
            if(i-c>=0)
                dp[i] += dp[i-c];
                dp[i] %= mod;
        }
    }
    cout<<dp[w]<<"\n";
    
}