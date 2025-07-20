#include<bits/stdc++.h>
using namespace std;
#define SZ 200005

const int ht = 21; //  ceil(log2(200005));

int n,q,x,y,m,u,v;
vector<int> adj[SZ];
int up[SZ][ht];
int L[SZ];
int prefix[SZ];

void dfs(int u, int p, int l){
    up[u][0] = p;
    L[u] = l;
    for(int it:adj[u]){
        if(it!=p)
            dfs(it,u, l+1);
    }
}

int LCA(int u, int v){
    if(L[u] < L[v])
    swap(u,v);

    int diff = L[u] - L[v];
    for(int i=0; i<=20; i++)
        if(diff & (1<<i))
            u = up[u][i];
    
    if(u == v) return u;
    for(int i=20; i>=0; i--){
        if(up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

void ancestor(){
    dfs(1,0,0);

    for(int j=1; 1<<j <=n; j++)
    for(int u=1; u<=n; u++)
    up[u][j] = up[ up[u][j-1] ][j-1];

}

void prefix_dfs(int u, int p){
    for(int v : adj[u]){
        if(v != p){
            prefix_dfs(v,u);
            prefix[u] += prefix[v];
        }
    }
}

int main() {
    cin>>n>>m;
    for(int i=0; i<n-1; i++){
        cin>>x>>y;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
    ancestor();
    int k;
    while(m--){
        cin>>u>>v;
        prefix[u]++;
        prefix[v]++;
        int lca = LCA(u,v);
        prefix[lca]--;
        prefix[up[lca][0]]--;
        
    }
    prefix_dfs(1,0);
    for(int i=1; i<=n; i++) cout<<prefix[i]<<" ";
    return 0;

}