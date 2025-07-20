#include<bits/stdc++.h>
using namespace std;

// via dynammic programming approach
/*
vector<vector<int>> adj;
vector<int> dp1;  // selecting parent node
vector<int> dp2;  // not selecting parent node

void dfs(int node, int parent){
    for(int it: adj[node]){
        if(it != parent){
            dfs(it, node);
            dp2[node] += max(dp1[it], dp2[it]);
        }
        
    }
    for(int it: adj[node]){
        if(it != parent){
            dp1[node] = max(dp1[node],dp2[it] + 1 + dp2[node] - max(dp2[it], dp1[it]));
        }
    }
}
int main() {
    int n;
    cin>>n;
    adj.resize(n+1);
    dp1.resize(n+1, 0);
    dp2.resize(n+1, 0);
    for(int i=0; i<n-1; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,-1);
    cout<<max(dp1[1], dp2[1])<<endl;

    return 0;
}
*/

// via greedy method
vector<vector<int>> adj;
vector<bool> vis;
int ans = 0;

void dfs(int node, int parent){
    for(int it : adj[node]){
        if(it != parent){
            dfs(it, node);
            if(!vis[it] && !vis[node]){ vis[it] = true; vis[node] = true; ans++;}
        }
    }
}
int main(){
    int n;
    cin>>n;
    adj.resize(n+1);
    vis.resize(n+1, false);
    for(int i=0; i<n-1; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,-1);
    cout<<ans<<endl;
}