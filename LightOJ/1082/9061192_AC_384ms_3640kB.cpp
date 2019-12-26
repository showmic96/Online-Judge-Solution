// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5;
int ar[MAX+9] , tree[4*MAX+9] , ans;

void built_tree(int node , int st , int en)
{
    if(st==en){

        tree[node] = ar[st];
    }

    else{

        int mid = (st+en)/2;
        int left = 2*node;
        int right = 2*node+1;

        built_tree(left , st , mid);
        built_tree(right, mid+1 , en);

        tree[node] = min(tree[right] , tree[left]);
    }
}

int query(int node , int st , int en , int i , int j)
{
    if(i>en||j<st)return 123456;
    if(st>=i&&en<=j){ans = min(ans , tree[node]);return tree[node];}

    int mid = (st+en)/2;
    int left = 2*node;
    int right = 2*node+1;

    int v = query(left , st , mid , i , j);
    v = min(query(right , mid+1 , en , i , j) , v);

    return v;
}

int main(void)
{
    int t , c =0;
    scanf("%d",&t);
    while(t--){

        int n , q;
        scanf("%d %d",&n , &q);

        for(int i=1;i<=n;i++)scanf("%d",&ar[i]);

        built_tree(1 , 1 , n);
        printf("Case %d:\n",++c);
        while(q--){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            ans = 123456;
            query(1 , 1 , n , in1 , in2);
            printf("%d\n",ans);
        }
    }
    return 0;
}
