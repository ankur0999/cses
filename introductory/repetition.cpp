#include<iostream>
#include<string>
using namespace std;

int main(){
    

    string s;
    cin>>s;
    int i=0,j=0;
    int size = 1;
    while(j<s.length()){
        if(s[i] != s[j]){
            if(j-i > size) size = j-i;
            i = j;
        }
       
        
    }
    if(j-i > size) size = j-i;
    cout<<size<<endl;
}
