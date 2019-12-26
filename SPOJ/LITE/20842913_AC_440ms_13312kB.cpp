// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5+9;

ll ar[MAX+9] , one[3*MAX+9] , two[3*MAX+9] , three[3*MAX+9] , lazy[3*MAX+9];

void build(int node , int st , int en)
{
    if(st==en){
        one[node] = 1;
        return ;
    }
    else{
        int mid = (st+en)/2;
        build(2*node , st , mid);
        build(2*node+1 , mid+1 , en);
        one[node] = one[2*node] + one[2*node+1];
        two[node] = two[2*node] + two[2*node+1];
    }
}

int query(int node , int st , int en , int l , int r)
{
    if(st>r||en<l){

        return 0;
    }
    if(lazy[node]!=0){
        lazy[node]%=2;
        if(lazy[node]==1){
            swap(one[node] , two[node]);
        }
        if(st!=en){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node] = 0;
    }
    if(st>=l&&en<=r){
        return two[node];
    }
    int mid = (st+en)/2;
    int p1 = query(2*node , st , mid , l , r);
    int p2 = query(2*node+1 , mid+1 , en , l , r);
    return p1+p2;
}

void update(int node , int st , int en , int l , int r)
{
    if(lazy[node]!=0){
        lazy[node]%=2;
        if(lazy[node]==1){
            swap(one[node] , two[node]);
        }
        if(st!=en){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node] = 0;
    }
    if(st>r||en<l||st>en)return ;
    if(st>=l&&en<=r){
        swap(one[node] , two[node]);
        if(st!=en){
            lazy[2*node]+=1;
            lazy[2*node+1]+=1;
        }
        return ;
    }
    int mid = (st+en)/2;

    update(2*node , st , mid , l , r);
    update(2*node+1 , mid+1 , en , l , r);

    one[node] = one[2*node] + one[2*node+1];
    two[node] = two[2*node] + two[2*node+1];
}

void SetUp()
{
    for(int i=0;i<3*MAX;i++){
        one[i] = 0;
        two[i] = 0;
        three[i] = 1;
        lazy[i] = 0;
    }
}

int main(void)
{
    int n , q;
    scanf("%d %d",&n , &q);
    SetUp();
    for(int i=1;i<=n;i++){
        ar[i] = 0;
    }
    build(1 , 1 , n);
    while(q--){
        int in1 , in2 , in3;
        scanf("%d %d %d",&in1 , &in2 , &in3);
        if(in1==1){
            printf("%d\n",query(1 , 1 , n , in2 , in3));
        }
        else{
            update(1 , 1 , n , in2 , in3);
        }
    }
    return 0;
}
