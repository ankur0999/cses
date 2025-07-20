#include<bits/stdc++.h>
using namespace std;
#define SZ 200005

const int ht = 21; //  ceil(log2(200005));

int n,q,x,y;
vector<int> adj[SZ];
int up[SZ][ht];
int L[SZ];

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

int main() {
    cin>>n>>q;
    for(int i=2; i<=n; i++){
        cin>>x>>y;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
    ancestor();
    int k;
    while(q--){
        cin>>x>>k;
        
        cout<<(L[x] + L[k] - (2 *L[LCA(x,k)]))<<endl;
    }

}