#include<bits/stdc++.h>
using namespace std;
#define SZ 200005


int n,q,x,y,m,u,v,s,k;
vector<int> adj[SZ];
int start[SZ], endd[SZ], flat[SZ],val[SZ];
int timer = 0;

class FenwickTree{
    long long int *tree;
    int size;
    public:
    FenwickTree(int n){
        size = n+1;
        tree = new long long int[size];
        fill(tree, tree+size,0);
        
    }

    void build(){
        for(int i=1; i<size; i++){
            tree[i] = val[flat[i]];
        }
        for(int i=1; i<size; i++){
            int p = i + (i & -i);
            if(p<size) tree[p] += tree[i];
        }
    }

    void add(int ind, int elm){
        while(ind<size){
            tree[ind] += elm;
            ind += ind & -ind;
        }
    }

    long long int sum(int ind){
        long long int sum = 0;
        while(ind>0){
            sum += tree[ind];
            ind -= ind & -ind;
        }
        return sum;
    }
    ~FenwickTree(){
        delete[] tree;
    }
};


// flattening a tree using dfs
void dfs(int u, int p){
    start[u] = ++timer;
    flat[timer] = u;
    for(int v : adj[u]){
        if(v != p){
            dfs(v,u);
        }
    }
    endd[u] = timer;
}

// if you need any query of subtree see all node
// in between start[u] and endd[u]


int main() {
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>val[i];
    }

    for(int i=0; i<n-1; i++){
        cin>>x>>y;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }

    dfs(1,0);// flattening an array

    FenwickTree *tree = new FenwickTree(n);
    tree->build();

    while(q--){
        cin>>k;
        if(k&1){
            cin>>s>>x;
            int diff = x - val[s];
            val[s] = x;
            int u = start[s];
            tree->add(u, diff);
        }
        else{
            cin>>u;
            int l = start[u], r = endd[u];
            cout<<(tree->sum(r) - tree->sum(l-1))<<endl;
        }
        
        
    }
    delete tree;
    return 0;

}