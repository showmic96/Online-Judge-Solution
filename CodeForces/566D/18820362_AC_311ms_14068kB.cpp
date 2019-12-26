// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 2e5+9;
int tree[4*MAX] , lazy[4*MAX] , par[MAX] , nxt[MAX];

int Find(int x)
{
    if(x==par[x])return x;
    return par[x] = Find(par[x]);
}
void Union(int x , int y)
{
    int px = Find(x);
    int py = Find(y);
    if(px==py)return ;
    par[py] = px;
}

void build(int node ,int st , int en)
{
    if(st==en){
        tree[node] = st;
        return ;
    }
    int mid = (st+en)/2;
    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);
}

void update(int node , int st , int en , int l , int r , int val)
{
    if(lazy[node]!=0){
        if(st!=en){
            if(lazy[2*node]==0){
                lazy[2*node] = Find(lazy[node]);
            }
            else{
                Union(lazy[node] , lazy[2*node]);
            }
            if(lazy[2*node+1]==0){
                lazy[2*node+1] = Find(lazy[node]);
            }
            else{
                Union(lazy[node] , lazy[2*node+1]);
            }
        }
        Union(lazy[node] , tree[node]);
        lazy[node] = 0;
    }
    if(st>r||en<l)return ;
    if(st>=l&&en<=r){
        if(st==en){
            Union(val , tree[node]);
            tree[node] = Find(tree[node]);
        }
        else{
            lazy[node] = Find(val);
        }
        return ;
    }
    int mid = (st+en)/2;
    update(2*node , st , mid , l , r , val);
    update(2*node+1 , mid+1 , en , l , r , val);
}

int query(int node , int st , int en , int idx)
{
    if(lazy[node]!=0){
        if(st!=en){
            if(lazy[2*node]==0){
                lazy[2*node] = Find(lazy[node]);
            }
            else{
                Union(lazy[node] , lazy[2*node]);
            }
            if(lazy[2*node+1]==0){
                lazy[2*node+1] = Find(lazy[node]);
            }
            else{
                Union(lazy[node] , lazy[2*node+1]);
            }
        }
        Union(lazy[node] , tree[node]);
        lazy[node] = 0;
    }
    if(st==en)return Find(tree[node]);
    int mid = (st+en)/2;
    if(idx<=mid)return query(2*node , st , mid , idx);
    return query(2*node+1 , mid+1 , en , idx);
}

int main(void)
{
    int n , m;
    scanf("%d %d",&n , &m);
    for(int i=0;i<=n;i++)par[i] = i , nxt[i] = i+1;
    build(1 , 1 , n);
    while(m--){
        int in1 , in2 , in3;
        scanf("%d %d %d",&in1 , &in2 , &in3);
        if(in1==1){
            Union(in2 , in3);
        }
        else if(in1==2){
            int i = in2;
            while(i<=in3){
                Union(i , in3);
                int temp = nxt[i];
                nxt[i] = nxt[in3];
                i = temp;
            }
        }
        else{
            if(Find(in2)==Find(in3))printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
