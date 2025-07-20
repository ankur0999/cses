#include<bits/stdc++.h>
using namespace std;

const int sz = 200005;

vector<int> adj[sz];

pair<int,int> bfs(int node){
    queue<pair<int,int>> q;
    q.push({node,0});
    vector<bool> vis(sz,false);
    pair<int,int> u;
    while(!q.empty()){
        u = q.front();
        vis[u.first] = true;
        q.pop();
        for(int it : adj[u.first]){
            if(!vis[it]){
                q.push({it, u.second+1});
            }
        }
    }
    return u;
}

int main() {
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    pair<int,int> end1 = bfs(1);
    pair<int,int> end2 = bfs(end1.first);
    cout<<end2.second<<endl;
}