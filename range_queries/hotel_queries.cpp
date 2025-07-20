#include<bits/stdc++.h>
using namespace std;
#define outofbound INT_MAX


int returnValue(int val1, int val2){
    return max(val1, val2);
}

int n, m, h, r;
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

    int get(int val, int pos, int left, int right){
        if (tree[pos] < val) return -1; // ❗ base case: no value ≥ val in this segment

        if (right - left == 1) {
            return left; // ✅ this is the valid index
        }

        int mid = (left + right) / 2;

        int res = get(val, 2 * pos + 1, left, mid);
        if (res != -1) return res;
        return get(val, 2 * pos + 2, mid, right);
    }
    
    public:
    SegmentTree(int n, int *input){
        size = 1;
        while(size<n) size *= 2;
        tree = new int[2*size];
        fill(tree, tree + 2*size, INT_MIN);
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

    int get(int val){
        return get(val, 0, 0, size);
    }

    ~SegmentTree(){
        delete[] tree;
    }

};



int main() {
     ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    SegmentTree *st = new SegmentTree(n, arr);
    st->build();

    while(m--){
        cin>>r;
        int x = st->get(r);
        cout << x+1 << endl;
        if(x != -1){
            arr[x] -= r;
            st->set(x, arr[x]);
        }
            
        
        
    }

    delete st;
    delete[] arr;
    return 0;

}