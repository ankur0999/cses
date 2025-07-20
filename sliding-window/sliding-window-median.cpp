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
         tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
int arr[200005];
Tree<int> O;

int main(){

    // O.insert(1);
    // O.insert(2);
    // O.insert(1);
    // O.insert(2);

    // cout<<"element at given position: "<< *O.find_by_order(1)<<endl;

    // cout<<"number of element less than : "<<O.order_of_key(3)<<endl;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q, k, x,a, b;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        int x;
        cin>>arr[i];        
    }
    int left=0,right=0;
    while(right<k){
        O.insert(arr[right++]);
    }
    
    while(right<=n){
        if(k%2){
            cout<<*O.find_by_order(k/2)<<endl;
            O.erase(O.find_by_order(O.order_of_key(arr[left++])));
            // O.erase(O.begin())
        }
        else{
            cout<<*O.find_by_order(k/2 - 1)<<endl;
            O.erase(O.find_by_order(O.order_of_key(arr[left++])));
        }
        if(right == n) break;
        O.insert(arr[right++]);
        
    }
    return 0;
}


