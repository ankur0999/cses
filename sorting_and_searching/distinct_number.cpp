#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    int i=0,j=1;
    int cnt = 1;
    while(j<n){
        if(arr[i] != arr[j]){
            i = j;
            cnt++;
        }
        j++;
    }
    cout<<cnt<<endl;
}