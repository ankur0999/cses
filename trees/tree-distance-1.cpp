#include<bits/stdc++.h>
#define dt pair<int,int>
using namespace std;
const int sz = 200005;


vector<vector<int>> adj;
vector<int> dist1(sz,0);
vector<int> dist2(sz,0);

dt bfs(int node, char ch = '0'){
    queue<dt> q;
    q.push({node,0});
    vector<bool> vis(sz, false);
    dt u;
    while(!q.empty()){
        u = q.front();
        q.pop();
        vis[u.first] = true;
        if(ch == '1') dist1[u.first] = u.second;
        if(ch == '2') dist2[u.first] = u.second;
        for(int it:adj[u.first]){
            if(!vis[it]){
                q.push({it,u.second+1});
            }
        }
    }
    return u;
}


int main() {
    int n;
    cin>>n;
    adj.resize(n+1);
    for(int i=0; i<n-1; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dt end1 = bfs(1);
    // cout<<"end1 :"<<end1.first<<endl;
    dt end2 = bfs(end1.first,'1');
    // cout<<"end2 :"<<end2.first<<endl;

    dt end3 = bfs(end2.first,'2');
    for(int i=1; i<=n; i++){
        cout<<max(dist1[i],dist2[i])<<" ";
    }
    cout<<endl;
}