#include<bits/stdc++.h>
using namespace std;
#define outofbound INT_MAX


int returnValue(int val1, int val2){
    return (val1 + val2);
}

int n;
int *arr;
int *idx;

class SegmentTree{
    private:
    int size;
    int *tree;
    int *data;

    void build(int pos, int left, int right){
        if(right-left == 1){
            if(left < n){
                tree[pos] = 1;
            }
            return;
        }
        int mid = left + (right - left)/2;
        build(2*pos+1, left, mid);
        build(2*pos+2, mid, right);
        tree[pos] = returnValue(tree[2*pos+1], tree[2*pos+2]);
    }


    void del(int ind, int pos, int left, int right){
        if(tree[pos] < ind) throw std::runtime_error("Element doesn't exist");
        else {
            tree[pos]--;
            int mid = left + (right - left)/2;
            if(right - left == 1) cout << data[left] << " ";
            else if(tree[2*pos+1] > ind)  del(ind, 2*pos+1, left, mid);
            else  del(ind - tree[2*pos+1], 2*pos+2, mid, right);
        }
    }
    
    public:
    SegmentTree(int n, int *input){
        size = 1;
        while(size<n) size *= 2;
        tree = new int[2*size];
        fill(tree, tree + 2*size, 0);
        data = input;
    }

    
    void build(){
        build(0,0,size);
    }


    void del(int ind){
        del(ind, 0, 0, size);
    }

    ~SegmentTree(){
        delete[] tree;
    }

};



int main() {
     ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    arr = new int[n];
    idx = new int[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    
    for(int i=0; i<n; i++) cin >> idx[i];

    

    SegmentTree *st = new SegmentTree(n, arr);
    st->build();

    for(int i=0; i<n; i++){
        st->del(idx[i]-1);
    }

    delete st;
    delete[] arr;
    delete[] idx;
    return 0;

}