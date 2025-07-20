#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int n,m;
vector<vector<int>> adj;
int color[MAXN];


int main() {
    cin>>n>>m;
    adj.resize(n+1);
    memset(color, -1, sizeof(color));
    int a,b;
    for(int i=0; i<m; ++i){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(color[i] != -1) continue;
        q.push(i);
        color[i] = 0;
        
        while(!q.empty()){
            int v = q.front();
            q.pop();

            for(int u : adj[v]){
                if(color[u] == -1){ // not color
                    color[u] = color[v] ^ 1;
                    q.push(u);
                }else if(color[u] == color[v]){
                    cout<<"IMPOSSIBLE\n";
                    return 0;
                }
                
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout<<color[i]+1<<" ";
    }
    return 0;
}