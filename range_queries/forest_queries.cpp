#include<bits/stdc++.h>
using namespace std;
#define llt long long int


vector<vector<int>> tree;
vector<vector<llt>> dp;
int n, q;
char x;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;

    tree.resize(n+1, vector<int>(n+1,0));
    dp.resize(n+1, vector<llt>(n+1,0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>x;
            if(x == '*'){
                tree[i][j] = 1;

            }
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + tree[i][j];
        }
    }


    
    int y1, y2, x1, x2;
    while(q--){
        cin>> y1 >> x1 >> y2 >> x2;
        
        cout<< (dp[y2][x2] - dp[y1-1][x2] - dp[y2][x1-1] + dp[y1-1][x1-1])<<endl;
        
    }

    return 0;
    
}