#include <iostream>
#include <vector>
using namespace std;
#define N 200005
 
struct node{
    int l,r;
    long long int val;
    node *left, *right;
    node(int ll, int rr) : l(ll), r(rr), val(0), left(nullptr), right(nullptr) {}
    
} *Node[N];
 
vector<int> adj[N], chains[N];
long long int val[N];
int parent[N], syze[N], chainHD[N], pos[N], height[N];
 
node* build_segmentTree(int n, int l, int r){
    node* p = new node(l,r);
    if(l<r){
        int mid = (l+r)>>1;
        p->left = build_segmentTree(n, l, mid);
        p->right = build_segmentTree(n, mid+1, r);
    }
    l == r ?  p->val = val[chains[n][l]] : p->val = p->left->val + p->right->val;
    return p;
}
 
void update(node *p, int ind, int x){
    if(p->l == p->r){
        p->val = x;
    }else{
        int mid = (p->l + p->r)>>1;
        
        update(ind <= mid ? p->left : p->right, ind,  x);
       
        p->val = p->left->val + p->right->val;
    }
    
}
 
long long int query_segmentTree(node *p, int l, int r){
    long long int sum = 0;
    if(p->l > r || p->r < l) return 0;
    if(p->l >= l && p->r <= r ) return p->val;
    sum += query_segmentTree(p->left, l, r);
    sum += query_segmentTree(p->right, l, r);
    return sum;
    
}
 
long long int HLD_query(int u, int v){
    long long int sum = 0;
    while(chainHD[u] != chainHD[v]){
        if(height[chainHD[u]] > height[chainHD[v]])
            swap(u,v);
        sum += query_segmentTree(Node[chainHD[v]], 0, pos[v]);
        v = parent[chainHD[v]];
    }

    if(pos[u] >= pos[v])
        swap(u,v);
    sum += query_segmentTree(Node[chainHD[u]], pos[u], pos[v]);
    return sum;
    
}
 
void heavy_light_decomposition(int n){
    chains[n].push_back(n);
    
    for(int i=0; i<chains[n].size(); i++){
        int u = chains[n][i];
        chainHD[u] = n;
        pos[u] = i;
        for(int j=0; j<adj[u].size(); j++){
            int v = adj[u][j];
            if(v!=parent[u]){
                syze[v]<<1 >= syze[u] ?  chains[n].push_back(v) : heavy_light_decomposition(v);
            }
        }
    }
    
    Node[n] = build_segmentTree(n, 0, chains[n].size()-1);
    
}
 
void build_tree(int n, int p, int h){
    syze[n] = 1;
    parent[n] = p;
    height[n] = h;
    for(int i=0; i<adj[n].size(); i++){
        int v = adj[n][i];
        if(v-p){
            build_tree(v, n, h+1);
            syze[n] += syze[v];
        }
    }
}
 
int main() {
	int n,q;
	cin>>n>>q;
	for(int i=1; i<=n; i++){
	    cin>>val[i];
	}
	
	for(int i=0; i<n-1; i++){
	    int a,b;
	    cin>>a>>b;
	    adj[a].push_back(b);
	    adj[b].push_back(a);
	}
	
	build_tree(1,1,0);
	heavy_light_decomposition(1);
	while(q--){
	    int qt;
	    cin>>qt;
	    if(qt&1){
	        int s,x;
    	    cin>>s>>x;
    	    update(Node[chainHD[s]], pos[s], x);
	        
	    }
	    else{
	        int s;
	        cin>>s;
	        cout<<HLD_query(1,s)<<endl;
	    }
	}
	
	return 0;
 
}