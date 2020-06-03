class Solution {
public:
    vector<int>v;
    int n , tree[4*100005];
    void update(int node, int st , int en , int idx , int val){
        if(st==en){
            tree[node] = val;
            return ;
        }
        int mid = (st+en)/2;
        if(idx<=mid)update(2*node, st , mid , idx , val);
        else update(2*node+1, mid+1 , en , idx , val);
        tree[node] = max(tree[2*node], tree[2*node+1]);
    }
    int query(int node , int st , int en , int l , int r){
        if(st>r||en<l)return -1e9;
        if(st>=l&&en<=r)return tree[node];
        int mid = (st+en)/2;
        return max(query(2*node , st , mid , l , r), query(2*node+1 , mid+1 , en , l , r));
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        n = nums.size();
        v = nums;
        for(int i=0;i<k;i++){
            update(1 , 1 , n , i+1, v[i]);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(query(1 , 1 , n , i+1 , i+k));
            if(i+k>=n)break;
            update(1 , 1 , n , i+1 , 0);
            update(1 , 1 , n , i+k+1 , v[i+k]);
        }
        return ans;
    }
};