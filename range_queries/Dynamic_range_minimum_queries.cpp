#include<bits/stdc++.h>
using namespace std;
#define outofbound INT_MAX


int returnValue(int val1, int val2){
    return min(val1, val2);
}

int n,q,x,a,b;
int *arr;

class SegmentTree{
    private:
    int size;
    int *tree;
    int *data;

    void build(int pos, int left, int right){
        if(right-left == 1){
            if(left < n){
                tree[pos] = data[left];
            }
            return;
        }
        int mid = left + (right - left)/2;
        build(2*pos+1, left, mid);
        build(2*pos+2, mid, right);
        tree[pos] = returnValue(tree[2*pos+1], tree[2*pos+2]);
    }

    void set(int ind, int val, int pos, int left, int right){
        if(right-left == 1){
            tree[pos] = val;
            return;
        }
        int mid = left + (right-left)/2;
        if(ind<mid)
            set(ind, val, 2*pos+1, left, mid);
        else
            set(ind, val, 2*pos+2, mid, right);
        tree[pos] = returnValue(tree[2*pos+1], tree[2*pos+2]);
    }

    int get(int q_left, int q_right, int pos, int left, int right){
        // no overlap
        if(right <= q_left || left >= q_right) return outofbound;
        // total overlap
        if(left >= q_left && right <=q_right) return tree[pos];

        int mid = left + (right - left)/2;
        int val1= get(q_left, q_right, 2*pos+1, left, mid);
        int val2 = get(q_left, q_right, 2*pos+2, mid, right);
        return returnValue(val1, val2);
    }
    
    public:
    SegmentTree(int n, int *input){
        size = 1;
        while(size<n) size *= 2;
        tree = new int[2*size];
        fill(tree, tree + 2*size, INT_MAX);
        data = input;
    }

    
    void build(){
        build(0,0,size);
    }

    
    void set(int ind, int val){
        set(ind, val, 0,0,size);
    }

    
    int get(int q_left, int q_right){
        return get(q_left, q_right, 0, 0, size);
    }

    ~SegmentTree(){
        delete[] tree;
    }

};



int main() {
    cin >> n >> q;
    arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    SegmentTree *st = new SegmentTree(n, arr);
    st->build();

    while(q--){
        cin>>x;
        if(x&1){
            cin>>a>>b;
            st->set(a-1, b);
        }else{
            cin >>a >> b;
            cout << st->get(a-1, b) << endl;
        }
        
    }

    delete st;
    delete[] arr;
    return 0;

}