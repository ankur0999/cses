#include<bits/stdc++.h>

using namespace std;

// use cordinate compression and BIT to solve this problem

const int MAX = 400005;
int n,q;
long long BIT[MAX];
vector<int> allValues;

int getIndex(int val){
    return upper_bound(allValues.begin(), allValues.end(), val) - allValues.begin();
}

void updateBIT(int idx, int val){
    while(idx < MAX){
        BIT[idx] += val;
        idx += (idx & (-idx)); // move to next index
    }
}

void addValues(int val, int count){
    int idx = getIndex(val);
    updateBIT(idx, count);
}

long long prefixSum(int idx){
    long long sum = 0;
    while(idx > 0){
        sum += BIT[idx];
        idx -= (idx & (-idx));
    }
    return sum;
}



int main(){
    cin>>n>>q;
    long long arr[n];
    for(int i=0; i<n; i++){ cin>>arr[i]; allValues.push_back(arr[i]);}

    vector<array<int,3>> queries;
    char ch;
    int a,b;
    while(q--){
        cin >> ch >> a >> b;
        queries.push_back({ch == '!',a,b});
        if(ch == '!') allValues.push_back(b);
    }
    // erasing all the duplicates present in the array
    sort(allValues.begin(), allValues.end());
    allValues.erase(unique(allValues.begin(), allValues.end()), allValues.end());
    
    // adding every element count to BIT
    for(int i=0; i<n; i++){
        addValues(arr[i],1);
    }

    for(auto q : queries){
        q[1]--;
        if(q[0] == 1){ // update
            addValues(arr[q[1]], -1);
            arr[q[1]] = q[2];
            addValues(arr[q[1]], 1);

        }else{ // get count
            long long total = (prefixSum(getIndex(q[2])) - prefixSum(getIndex(q[1])));  // get range of sum from [a,b]
            cout<<total<<endl;
        }
    }

    return 0;
}
