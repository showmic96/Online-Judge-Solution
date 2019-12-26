// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 200000 + 9;

struct node{

    ll one , zero;
};

node tree[4*MAX];
vector<int>v;

void build(int node , int st , int en)
{
    if(st==en){

        tree[node].one = tree[node].zero = 0;

        if(v[st-1]==0)tree[node].zero = 1;
        if(v[st-1]==-1)tree[node].one = 1;
        return ;
    }

    int mid = (st+en)/2;

    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);

    tree[node].one = tree[2*node].one + tree[2*node+1].one;
    tree[node].zero = tree[2*node].zero + tree[2*node+1].zero;
}

void update(int node , int st , int en , int idx , int value)
{
    if(st==en){

        if(value==-1)tree[node].one = 1 , tree[node].zero = 0;
        else if(value==0)tree[node].zero = 1 , tree[node].one = 0;
        else if(value==1)tree[node].zero = 0 , tree[node].one = 0;
        return ;
    }

    int mid = (st+en)/2;

    if(idx>=st&&idx<=mid)update(2*node , st , mid , idx , value);
    else update(2*node+1 , mid+1 , en , idx , value);

    tree[node].one = tree[2*node].one + tree[2*node+1].one;
    tree[node].zero = tree[2*node].zero + tree[2*node+1].zero;
}

node query(int node , int st , int en , int l , int r)
{
    if(st>=l&&en<=r){

        return tree[node];
    }

    if(r<st||l>en){

        struct node t;
        t.zero = 0;
        t.one = 0;

        return t;
    }

    int mid = (st+en)/2;

    struct node p1 = query(2*node , st , mid , l , r);
    struct node p2 = query(2*node+1 , mid+1 , en , l , r);

    struct node p;

    p.zero = p1.zero+p2.zero;
    p.one = p1.one+p2.one;

    return p;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n , q;
    bool space = false;

    while(cin >> n >> q){

        v.clear();

        for(int i=0;i<n;i++){

            int in;
            cin >> in;

            if(in>0)v.push_back(1);
            else if(in<0)v.push_back(-1);
            else v.push_back(0);
        }

        build(1 , 1 , n);

        string ar;

        while(q--){

            cin >> ar;

            if(ar=="C"){

                int in1 , in2;
                cin >> in1 >> in2;

                if(in2<0)in2 = -1;
                else if(in2>0)in2 = 1;

                update(1 , 1 , n , in1 , in2);
            }
            else{

                int in1 , in2;
                cin >> in1 >> in2;

                node ans = query(1 , 1 , n , in1 , in2);

                if(ans.zero>0)cout << 0;
                else if(ans.one%2==0)cout << "+";
                else cout << "-";
            }
        }

        cout << endl;
    }
    return 0;
}
