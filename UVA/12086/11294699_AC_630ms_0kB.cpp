// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 200000 + 9;

ll tree[4*MAX];
vector<int>v;

void build(int node , int st , int en)
{
    if(st==en){

        tree[node] = v[st-1];
        return ;
    }

    int mid = (st+en)/2;

    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);

    tree[node] = tree[2*node]+tree[2*node+1];
}

void update(int node , int st , int en , int idx , int value)
{
    if(st==en){

        tree[node] = value;
        v[idx-1] = value;
        return ;
    }

    int mid = (st+en)/2;

    if(idx>=st&&idx<=mid)update(2*node , st , mid , idx , value);
    else update(2*node+1 , mid+1 , en , idx , value);

    tree[node] = tree[2*node] + tree[2*node+1];
}

ll query(int node , int st , int en , int l , int r)
{
    if(st>=l&&en<=r){

        return tree[node];
    }

    if(r<st||l>en)return 0;

    int mid = (st+en)/2;

    ll p1 = query(2*node , st , mid , l , r);
    ll p2 = query(2*node+1 , mid+1 , en , l , r);

    return p1+p2;
}

int main(void)
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int n , c = 0;
    bool space = false;
    
    while(cin >> n){

        if(n==0)break;

        if(space)cout << endl;
        space = true;

        v.clear();

        for(int i=0;i<n;i++){

            int in;
            cin >> in;
            v.push_back(in);
        }

        build(1 , 1 , n);

        string ar;

        printf("Case %d:\n",++c);

        while(cin >> ar){

            if(ar=="END")break;

            if(ar=="S"){

                int in1 , in2;
                cin >> in1 >> in2;

                update(1 , 1 , n , in1 , in2);
            }
            else{

                int in1 , in2;
                cin >> in1 >> in2;

                printf("%lld\n",query(1 , 1 , n , in1 , in2));
            }
        }
    }
    return 0;
}
