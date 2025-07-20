#include<iostream>
using namespace std;

int n,q,x,a,b;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>q;
    int *arr = new int[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    // create a prefix
    int *prefix = new int[n+1]; prefix[0] = 0;
    for(int i=0; i<n; i++) prefix[i+1] = prefix[i] ^ arr[i];

    while(q--){
        cin>>a>>b;
        cout<<(prefix[b] ^ prefix[a-1])<<endl;
    }
    delete[] arr;
    delete[] prefix;
    return 0;
}