/* Order Statistic tree */

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file

using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
const int MOD = 1000000007;

template <class T>
using Tree =  
         tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int arr[200005];
Tree<pii> A;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n,q, k, x,a, b;
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        A.insert({x,i});
        arr[i] = x;
    }
    
    while(q--){
        char ch;
        cin>>ch;
        if(ch == '!'){
            cin>>k>>x;
            A.erase({arr[k],k});
            arr[k] = x;
            A.insert({arr[k],k});
            
        }
        else{
            cin>>a>>b;
            int count = A.order_of_key({b,MOD}) - A.order_of_key({a-1,MOD});
            cout<<count<<endl;
        }
    }


}