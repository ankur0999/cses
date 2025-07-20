#include<bits/stdc++.h>
using namespace std;

int getMaxDigit(int n){
    int maxi = 0;
    while(n>0){
        int ones = n%10;
        maxi = max(ones, maxi);
        n /= 10;
    }
    return maxi;

}

int main() {
    int n;
    cin>>n;
    int step = 0;
    while(n>0){
        int digit = getMaxDigit(n);
        n -= digit;
        step++;
    }
    cout<<step<<endl;
}