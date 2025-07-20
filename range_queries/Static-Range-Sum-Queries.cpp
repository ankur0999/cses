#include<bits/stdc++.h>
using namespace std;

int *arr;
long long int *prefix;
int n,q,a,b;

class RangeQuery{
    int size;
    public:
    RangeQuery(int n){
        size = n;
        prefix = new long long int[n+1];
        prefix[0] = 0;
    }
    void build(){
        for(int i=1; i<=size; i++){
            prefix[i] = prefix[i-1] + arr[i];
        }
    }
};


int main() {
    cin>>n>>q;
    arr = new int[n+1];
    arr[0] = 0;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    RangeQuery* rq = new RangeQuery(n);
    rq->build();
    while(q--){
        cin>>a>>b;
        cout<<(prefix[b] - prefix[a-1])<<endl;
    }


}