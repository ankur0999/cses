#include<iostream>
#include<vector>
using namespace std;
#define N 100005

vector<int> adj[N];
int lenght[N];
bool visited[N];

int dfs(int n, int h, bool &found){
    lenght[n] = h;
    visited[n] = true;
    // cout<<"at city "<<n<<endl;
    for(int u : adj[n]){
        if(lenght[u]){
            if(abs(lenght[n] - lenght[u]) >= 2){
                cout<<(abs(lenght[n] - lenght[u]) + 2)<<endl;
                cout<<u<<" "<<n<<" ";
                found = true;
                return abs(lenght[n] - lenght[u]);
            }
        }

        if(lenght[u]==0){
            int ans = dfs(u, h+1, found);
            if(ans > 0){
                cout<<n<<" ";
                return ans-1;
            }
        }
        if(found) return 0;
    }
    lenght[n] = 0;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // cout<<"graph completed\n";
    bool found = false;
    for(int city = 1; city<=n-2; city++){
        if(!visited[city])
        int ans = dfs(city, 1, found);
        if(found) return 0;
    }
    cout<<"IMPOSSIBLE\n";
    return 0;
}

//Why it's giving time limit exceeded in the bigger test cases?