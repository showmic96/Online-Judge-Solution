// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 123456;
int ar[MAX] , tree[4*MAX];

void build_tree(int node , int st , int en , int ar[] , int tree[])
{
    if(st==en){

        tree[node] = ar[st];
        return ;
    }
    else{

        int mid = (st+en)/2;
        int left = 2*node;
        int right = 2*node + 1;

        build_tree(left , st , mid , ar , tree);
        build_tree(right , mid+1 , en , ar , tree);

        tree[node] = tree[right] + tree[left];
    }

    return ;
}

void update(int node , int st , int en , int value , int idx , int ar[] , int tree[])
{

    if(idx>en||idx<st)return ;
    if (st >= idx && en <= idx) {

        tree[node] += value;

        return ;
    }

    int mid = (st+en)/2;
    int left = 2*node;
    int right = 2*node + 1;

    update(left , st , mid , value , idx , ar , tree);
    update(right , mid+1 , en , value , idx , ar , tree);

    tree[node] = tree[left] + tree[right];

    return ;
}

int query(int node , int st , int en , int i , int j , int ar[] , int tree[])
{
    if(i>en||j<st)return 0;
    if(st>=i&&en<=j){

        return tree[node];
    }
    int mid = (st+en)/2;
    int left = 2*node;
    int right = 2*node + 1;

    int value = query(left , st , mid , i , j , ar , tree);
    value += query(right , mid+1 , en , i , j , ar , tree);

    return value;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){

        int n , q;
        scanf("%d %d",&n , &q);

        for(int j=0;j<n;j++)scanf("%d",&ar[j]);

        build_tree(1 , 0 , n-1 , ar , tree);
        printf("Case %d:\n",i+1);

        while(q--){

            int in1 , in2 , in3;
            scanf("%d",&in1);
            if(in1==1){

                scanf("%d",&in2);

                int res = query(1 , 0 , n-1 , in2 , in2 , ar , tree);
                printf("%d\n",res);

                update(1 , 0 , n-1 , -res , in2 , ar , tree);
            }

            if(in1==2){

                scanf("%d %d",&in2 , &in3);
                update(1 , 0 , n-1 , in3 , in2  , ar , tree);
            }

            if(in1==3){

                scanf("%d %d",&in2 , &in3);

                int res = query(1 , 0 , n-1 , in2 , in3 , ar , tree);

                printf("%d\n",res);
            }
        }
    }

    return 0;
}
