#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int t;
    int xor1=0, xor2=0;
    for(int i=0; i<n-1; i++){
        cin>>t;
        xor2 ^= t;
        xor1 ^= (i+1);
    }
    xor1 ^= n;
    
    cout << (xor1 ^ xor2)<<endl;
}