#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<char>>& graph, vector<vector<bool>>& visited, int i, int j){
    int n = graph.size(), m = graph[0].size();
    
    queue<int> q;
    q.push(i*m + j);
    
    while(!q.empty()){
        
        int temp = q.front();
        q.pop();
        int row = temp/m;
        int col = temp%m;
        vector<pair<int, int>> directions = {{0,1}, {-1,0}, {1,0}, {0,-1}};
        for(auto& dir : directions){
            int n_row = row + dir.first;
            int n_col = col + dir.second;
            if(n_row >= 0 && n_col >= 0 && n_row < n && n_col < m 
                && graph[n_row][n_col] == '.' && visited[n_row][n_col] == false){
                visited[n_row][n_col] = true;
                q.push(n_row*m + n_col);
            }
        } 
       

    }
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<bool>> visited(n,vector<bool>(m, false));
    vector<vector<char>> graph(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>graph[i][j];
        }
    }
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(graph[i][j] == '.' && !visited[i][j]){
                visited[i][j] = true;
                count++;
                bfs(graph, visited, i, j);
            }
        }
    }
    cout<<count<<endl;
}