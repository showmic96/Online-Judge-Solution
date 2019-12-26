// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5+9;
ll tree[4*MAX];

string ar;
int n , m , counter;

void build(int node , int st , int en)
{
    if(st==en){

        int idx = st-1;
        if(ar[idx]==ar[n-idx-1])tree[node] = 0;
        else tree[node] = 1;
        return ;
    }

    int mid = (st+en)/2;
    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);

    tree[node] = tree[2*node] + tree[2*node+1];
}

void update(int node , int st , int en , int idx , char x)
{
    if(st==en){

        int idx = st-1;
        ar[idx] = x;
        if(ar[idx]==ar[n-idx-1])tree[node] = 0;
        else tree[node] = 1;
        return ;
    }

    int mid = (st+en)/2;
    if(idx>=st&&idx<=mid)update(2*node , st , mid , idx , x);
    else update(2*node+1 , mid+1 , en , idx , x);

    tree[node] = tree[2*node] + tree[2*node+1];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        counter = 0;

        cin >> n >> m;
        cin >> ar;

        build(1 , 1 , n);

        while(m--){

            int in1;
            char in2;
            cin >> in1 >> in2;

            update(1 , 1 , n , in1 , in2);
            update(1 , 1 , n , n-in1+1 , ar[n-in1]);

            if(tree[1]==0)counter++;
        }

        cout << counter << endl;
    }

    return 0;
}
