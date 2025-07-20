#include<bits/stdc++.h>
using namespace std;
#define SZ 200005

int arr[SZ];
int n,q,x,u,k,a,b;

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
            tree[i] = arr[i];
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

int main(){
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    FenwickTree* tree = new FenwickTree(n);
    tree->build();

    while(q--){
        cin>>x;
        if(x == 1){
            cin>>k>>u;
            int diff = u - arr[k];
            arr[k] = u;
            tree->add(k,diff);
        }else{
            cin>>a>>b;
            cout<<(tree->sum(b) - tree->sum(a-1))<<endl;
        }
    }
    delete tree;
    return 0;
}