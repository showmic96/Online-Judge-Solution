class Solution {
public:
    pair<int, int> tree[4*100005];
    vector<int>v;
    int n;
    long long ans = 0;
    void build(int node , int st , int en){
        if(st==en){
            tree[node] = {v[st-1] , st-1};
            return ;
        }
        int mid = (st+en)/2;
        build(2*node , st , mid);
        build(2*node+1 , mid+1 , en);
        if(tree[2*node].first<=tree[2*node+1].first){
            tree[node] = tree[2*node];
        }
        else{
            tree[node] = tree[2*node+1];
        }
    }
    pair<int,int> query(int node , int st , int en , int l , int r){
        if(st>r||en<l)return {1e9 , 1e9};
        if(st>=l&&en<=r){
            return tree[node];
        }
        int mid = (st+en)/2;
        pair<int,int>q1 = query(2*node , st , mid , l , r);
        pair<int,int>q2 = query(2*node+1 , mid+1 , en , l , r);
        if(q1.first<=q2.first)return q1;
        return q2;
    }
    void f(int l , int r){
        if(l>r)return ;
        if(l==r){
            ans = max(ans , (long long)v[l]);
            return ;
        }
        pair<long long,long long>p = query(1 ,1 , n , l+1 , r+1);
        ans = max(ans , (r-l+1)*p.first);
        f(l , p.second-1);
        f(p.second+1 , r);
        
    }
    int largestRectangleArea(vector<int>& heights) {
        v = heights;
        n = v.size();
        if(n==0)return 0;
        build(1 , 1, n);
        f(0 , n-1);
        return ans;
    }
};
