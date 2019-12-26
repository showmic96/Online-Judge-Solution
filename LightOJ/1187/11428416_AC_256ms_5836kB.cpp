// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 9;

ll tree[4*MAX];

void build(int node , int st , int en)
{
    if(st==en){

        tree[node] = 1;
        return ;
    }

    int mid = (st+en)/2;
    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);

    tree[node] = tree[2*node]+tree[2*node+1];
}

int update(int node , int st , int en , int value)
{
    if(st==en){

        tree[node] = 0;
        return st;
    }

    tree[node]--;

    int mid = (st+en)/2;

    if(tree[2*node]>=value)return update(2*node , st , mid , value);
    else return update(2*node+1 , mid+1 , en , value-tree[2*node]);
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);

        build(1 , 1 , n);

        vector<int>v;

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        int ans;

        for(int i=n-1;i>=0;i--){

            ans = update(1 , 1 , n , i+1-v[i]);
        }

        printf("Case %d: %d\n",++c , ans);
    }
    return 0;
}
