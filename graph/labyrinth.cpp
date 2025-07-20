#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
char grid[MAXN][MAXN];
int n,m;
struct State{
    int r, c;
};

State parent[MAXN][MAXN];
int dist[MAXN][MAXN];
char move_dir[MAXN][MAXN];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
char dir[4] = {'L', 'U', 'D', 'R'};

bool isValid(int r, int c){
    return r>=0 && c>=0 && r<n && c<m && grid[r][c] != '#';
}

int main() {
    cin>>n>>m;
    State start, end;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
            if(grid[i][j] == 'A'){
                start = {i,j};
            }
            if(grid[i][j] == 'B'){
                end = {i,j};
            }
        }
    }
    memset(dist, -1, sizeof(dist));
    dist[start.r][start.c] = 0;
    queue<State> q;
    q.push(start);
    bool flag = false;
    while(!q.empty()){
        State front = q.front();
        q.pop();
        int r = front.r, c = front.c;
        
        for(int i=0; i<4; i++){
            int nr = r + dy[i];
            int nc = c + dx[i];
            if(isValid(nr,nc) && dist[nr][nc] == -1){
                dist[nr][nc] = dist[r][c]+1;
                parent[nr][nc] = {r,c};
                move_dir[nr][nc] = dir[i];
                q.push({nr,nc});
                if(nr == end.r && nc == end.c){
                    flag = true;
                    break;
                }
            }
        }
        if(flag == true) break;

    }
    if(dist[end.r][end.c] == -1){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    cout<<dist[end.r][end.c]<<endl;


    string path = "";
    State temp = end;
    while(!(temp.r == start.r && temp.c == start.c)){
        path += move_dir[temp.r][temp.c];
        temp = parent[temp.r][temp.c];

    }

    reverse(path.begin(), path.end());
    cout<<path<<endl;
    return 0;


}