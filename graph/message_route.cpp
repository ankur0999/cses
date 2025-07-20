#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
int n,m;
vector<vector<int>> adj;

int parent[MAXN];
int dist[MAXN];


int main() {
    

    cin>>n>>m;
    adj.resize(n+1);
    int com1, com2;
    for(int i=0; i<m; i++){
        cin>>com1>>com2;
        adj[com1].push_back(com2);
        adj[com2].push_back(com1);
    }
    memset(dist, -1, sizeof(dist));

    queue<int> q;
    q.push(1);
    dist[1] = 1;
    while(!q.empty()){
        int com = q.front();
        q.pop();
        for(auto it : adj[com]){
            if(dist[it] == -1){
                q.push(it);
                dist[it] = dist[com] + 1;
                parent[it] = com;
            
            }

        }
    }

    if(dist[n] == -1){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        cout<<dist[n]<<endl;
        vector<int> ans;
        ans.push_back(n);
        int it = n;
        while(it != 1){
            ans.push_back(parent[it]);
            it = parent[it];
        }
        for(int i=0; i<(int)ans.size(); i++){
            cout<<ans[ans.size()-i-1];
            if(i < (int)ans.size() - 1) cout << " ";
        }
        cout<<endl;
    }
    return 0;
}