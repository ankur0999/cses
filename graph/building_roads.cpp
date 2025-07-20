#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int n,m;
vector<vector<int>> adj(MAXN);
vector<int> component;
vector<bool> visited(MAXN, false);

void dfs(int node){
    visited[node] = true;
    for(auto nbr : adj[node]){
        if(!visited[nbr]){
            dfs(nbr);
        }
    }
}


int main() {
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int city1, city2;
        cin>>city1>>city2;
        adj[city1].push_back(city2);
        adj[city2].push_back(city1);
    }

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            component.push_back(i);
            dfs(i);
        }
    }

    cout<<component.size()-1<<endl;
    int i = 1;
    while(i<component.size()){
        cout<<component[i-1]<<" "<<component[i]<<endl;
        i++;
    }
    return 0;

}