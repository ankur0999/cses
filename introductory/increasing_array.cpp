#include<bits/stdc++.h>
using namespace std;



int main() {
    int n;
    cin>>n;
    vector<long long> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    long long steps = 0;
    // cout<<"before for loops"<<endl;
    for(int i=1; i<n; i++){
        if(arr[i] < arr[i-1]){
            steps += (arr[i-1] - arr[i]);
            arr[i] = arr[i-1];
        }
    }
    // cout<<"after for loops"<<endl;
    cout<<steps<<endl;
    return 0;
}