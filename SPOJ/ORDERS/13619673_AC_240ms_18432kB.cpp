// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e5+9;

int tree[4*MAX];

void build(int node , int st , int en)
{
    if(st==en){

        tree[node] = 1;
        return;
    }
    int mid = (st+en)/2;
    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);

    tree[node] = tree[2*node]+tree[2*node+1];
}

int query(int node , int st , int en , int val)
{
    if(st==en){

        return st;
    }

    int mid = (st+en)/2;
    if(tree[2*node]>=val)return query(2*node , st , mid , val);
    else return query(2*node+1 , mid+1 , en , val-tree[2*node]);
}

void update(int node , int st , int en , int idx)
{
    if(st==en){

        tree[node] = 0;
        return ;
    }

    int mid = (st+en)/2;
    if(idx>=st&&idx<=mid)update(2*node , st , mid , idx);
    else update(2*node+1 , mid+1 , en , idx);

    tree[node] = tree[2*node] + tree[2*node+1];
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);
        vector<int>v;
        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        build(1 , 1 , n );
        vector<int>ans;

        for(int i=n-1;i>=0;i--){

            int temp = query(1 , 1 , n , i+1-v[i]);
            ans.push_back(temp);
            update(1 , 1 , n , temp);
        }

        reverse(ans.begin() , ans.end());

        for(int i=0;i<n;i++){

            if(i>0)printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
