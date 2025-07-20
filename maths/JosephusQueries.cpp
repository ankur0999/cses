#include<bits/stdc++.h>
using namespace std;

int JosephQueries(int n, int k){
    if(n == 1) return n;
    if(k<=(n+1)/2){
        return 2*k > n ? (2*k)%n : 2*k;
    }
    int temp = JosephQueries(n/2, k-(n+1)/2);
    return n%2==1 ? 2*temp+1 : 2*temp - 1;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--){
        int n,k;
        cin>>n>>k;
        cout<<JosephQueries(n,k)<<endl;
    }
    return 0;
}