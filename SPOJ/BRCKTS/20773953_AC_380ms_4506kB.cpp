// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

string ar;
bool check = true;
int tree[6*30005] , mi[6*30005];

void build(int node , int st , int en)
{
    if(st==en){
        if(ar[st-1]=='(')tree[node] = 1;
        else tree[node] = -1;
        mi[node] = tree[node];
        return ;
    }
    int mid = (st+en)/2;
    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);
    tree[node] = tree[2*node]+tree[2*node+1];
    mi[node] = min(mi[2*node] , tree[2*node]+mi[2*node+1]);
}

void update(int node , int st , int en , int idx)
{
    if(st==en){
        if(tree[node]==1)tree[node] = -1;
        else tree[node] = 1;
        mi[node] = tree[node];
        return ;
    }
    int mid = (st+en)/2;
    if(idx>=st&&idx<=mid)update(2*node , st , mid , idx);
    else update(2*node+1 , mid+1 , en , idx);
    tree[node] = tree[2*node]+tree[2*node+1];
    mi[node] = min(mi[2*node] , tree[2*node]+mi[2*node+1]);
}

int main(void)
{
    int n , c = 0;
    while(scanf("%d",&n)==1){
        cin >> ar;
        check = true;
        build(1 , 1 , n );
        int q;
        scanf("%d",&q);
        printf("Test %d:\n",++c);
        while(q--){
            int in;
            scanf("%d",&in);
            if(in==0){
                if(tree[1]==0&&mi[1]==0)printf("YES\n");
                else printf("NO\n");
            }
            else{
                check = true;
                update(1 , 1 , n , in);
            }
        }
    }
    return 0;
}
