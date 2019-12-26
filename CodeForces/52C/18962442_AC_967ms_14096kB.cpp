// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 200000+9;
ll tree[4*MAX] , val[MAX] , lazy[4*MAX];

void build(int node , int st , int en)
{
    if(st==en){
        tree[node] = val[st];
        return ;
    }
    int mid = (st+en)/2;
    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);
    tree[node] = min(tree[2*node] , tree[2*node+1]);
}
void update(int node , int st , int en , int l , int r , ll val)
{
    if(lazy[node]!=0){
        tree[node]+=lazy[node];
        if(st!=en){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(l>en||st>r)return ;
    if(st>=l&&en<=r){
        tree[node]+=val;
        if(st!=en){
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }
        return ;
    }
    int mid = (st+en)/2;
    update(2*node , st , mid , l , r , val);
    update(2*node+1 , mid+1 , en , l , r , val);
    tree[node] = min(tree[2*node] , tree[2*node+1]);
}
ll query(int node , int st , int en , int l , int r)
{
    if(lazy[node]!=0){
        tree[node]+=lazy[node];
        if(st!=en){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(l>en||st>r)return 1e18;
    if(st>=l&&en<=r){
        return tree[node];
    }
    int mid = (st+en)/2;
    ll q1 = query(2*node , st , mid , l , r);
    ll q2 = query(2*node+1 , mid+1 , en , l , r);
    return min(q1 , q2);
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++)cin >> val[i];
    build(1 , 1 , n);
    int m;
    cin >> m;
    cin.ignore();
    while(m--){
        string ar;
        getline(cin , ar);
        stringstream ss(ar);
        ll in1 , in2 , in3;
        ss >> in1;ss >> in2;
        in1++;in2++;
        if(ss >> in3){
            if(in2>=in1){
                update(1 , 1 , n , in1 , in2 , in3);
            }
            else{
                update(1 , 1 , n , in1 , n , in3);
                update(1 , 1 , n , 1 , in2 , in3);
            }
        }
        else{
            if(in2>=in1){
                cout << query(1 , 1 , n , in1 , in2) << endl;
            }
            else{
                cout << min(query(1 , 1 , n , in1 , n) , query(1 , 1 , n , 1 , in2)) << endl;
            }
        }
        //for(int i=1;i<=n;i++)cout << query(1 , 1 , n , i , i) << " ";
        //cout << endl;
    }
    return 0;
}
