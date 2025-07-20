#include<bits/stdc++.h>
using namespace std;
#define SZ 200005

const int ht = 21; //  ceil(log2(200005));

int n,q,x,y;
vector<int> adj[SZ];
int up[SZ][ht];

void dfs(int u, int p){
    up[u][0] = p;
    for(int it:adj[u]){
        if(it!=p)
            dfs(it,u);
    }
}

void ancestor(){
    dfs(1,0);

    for(int j=1; 1<<j <=n; j++)
    for(int u=1; u<=n; u++)
    up[u][j] = up[ up[u][j-1] ][j-1];

}

int main() {
    cin>>n>>q;
    for(int i=2; i<=n; i++){
        cin>>x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    ancestor();
    int k;
    while(q--){
        cin>>x>>k;
        for(int i=0; i<=20; i++){
            if(k & (1<<i))
            x = up[x][i];
        }
        cout<< (x == 0 ? -1 : x )<<endl;
    }

}