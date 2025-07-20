#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> tree;
vector<int> ans;
int preorder(int node){
    if(tree[node].size() == 0){
        ans[node-1] = 0;
        return 1;
    }
    int sum = 0;
    for(int it : tree[node]){
        sum += preorder(it);
    }
    ans[node-1] = sum;
    return sum+1;

}

int main() {
    int n,x;
    cin>>n;
    ans.resize(n,0);
    tree.resize(n+1);
    for(int i=2; i<=n; i++){
        cin>>x;
        tree[x].push_back(i);

    }
    preorder(1);
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }


}