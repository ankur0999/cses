#include<bits/stdc++.h>
using namespace std;
#define SZ 200005
#define int long long int

int n, x, y;

vector<int> adj[SZ];
int sub[SZ];
int in[SZ];
int out[SZ];

void dfs_in(int node, int parent){
    sub[node] = 1;
    for(int it : adj[node]){
        if(it!=parent){
            dfs_in(it,node);
            sub[node] += sub[it];
            in[node] += in[it] + sub[it];
        }
    }
}

void dfs_out(int node, int parent){
    if(parent>0)
        out[node] = out[parent] + n + in[parent] - in[node] - 2*sub[node]; 
    for(int it:adj[node]){
        if(it!= parent)
            dfs_out(it,node);
    }
}


signed main() {
    cin>>n;
    for(int i=0; i<n-1; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs_in(1,0);
    dfs_out(1,0);
    for(int i=1; i<=n; i++){
        cout<<in[i] + out[i] <<" ";
    }
    

}