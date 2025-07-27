#include<bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long int row,col;
        cin>>row>>col;
        if(row >= col){
            if(row%2==0){
                cout<<(row*row - col + 1)<<endl;
            }else{
                row--;
                cout<<(row*row + col)<<endl;
            }
        }else{
            if(col%2 == 0){
                col--;
                cout<<(col*col + row)<<endl;
            }else{
                cout<<(col*col - row + 1)<<endl;
            }
        }
    }
    return 0;

}