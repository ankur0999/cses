#include<bits/stdc++.h>
using namespace std;

int *arr;
int n,q,x,u,k,a,b;

class FenwickTree{
    long long int *tree;
    int size;
    public:
    FenwickTree(int n){
        size = n+1;
        tree = new long long int[size]();
        fill(tree, tree+size, 0);
        
    }

    void build(){
        for(int i=1; i<size; i++){
            tree[i] = arr[i];
        }
        // this process for prefix sum
        // for(int i=1; i<size; i++){
        //     int p = i + (i & -i);
        //     if(p<size) tree[p] += tree[i];
        // }
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
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>q;
    arr = new int[n+1];
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    FenwickTree* tree = new FenwickTree(n);
    // tree->build();

    while(q--){
        cin>>x;
        if(x == 1){
            cin>>a>>b>>u;
            //int diff = u - arr[k];
            //arr[k] = u;
            tree->add(a,u);
            tree->add(b+1,-u);
        }else{
            cin>>k;
            cout<<(tree->sum(k) + arr[k])<<endl;
        }
    }

    delete tree;
    delete[] arr;
    return 0;
}