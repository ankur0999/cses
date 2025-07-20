#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> applicant(n);
    vector<int> appartment(m);
    for(int i=0; i<n; i++){
        cin>>applicant[i];
    }
    for(int i=0; i<m; i++){
        cin>>appartment[i];
    }
    sort(appartment.begin(), appartment.end());
    sort(applicant.begin(), applicant.end());
    
    int i=0,j=0;
    int ans = 0;
    while(i<n && j<m){
        if(abs(appartment[j]-applicant[i]) <= k){
            ans++; i++; j++;
        }
        else if(appartment[j]>applicant[i]){
            i++;
        }
        else{
            j++;
        }
    }
    cout<<ans<<endl;
}