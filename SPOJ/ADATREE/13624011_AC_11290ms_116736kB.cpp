// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>v;
struct t{

    vector<int>v;

}tree[2000005];

void _merge(int node)
{
    tree[node].v.clear();
    int i = 0 , j = 0;
    int si1 = tree[2*node].v.size() , si2 = tree[2*node+1].v.size();

    for(int k=0;k<si1+si2;k++){

        if(i==si1){

            tree[node].v.push_back(tree[2*node+1].v[j]);
            j++;
        }
        else if(j==si2){

            tree[node].v.push_back(tree[2*node].v[i]);
            i++;
        }
        else if(tree[2*node].v[i]<tree[2*node+1].v[j]){

            tree[node].v.push_back(tree[2*node].v[i]);
            i++;
        }

        else {

            tree[node].v.push_back(tree[2*node+1].v[j]);
            j++;
        }
    }

}

void build(int node , int st , int en)
{
    if(st==en){

        tree[node].v.push_back(v[st-1]);
        return ;
    }

    int mid = (st+en)/2;

    build(2*node , st , mid);
    build(2*node+1 , mid+1 , en);

    _merge(node);
}

int query(int node , int st , int en , int l , int r , int h)
{
    if(r<st||l>en){
        return 0;
    }

    if(st>=l&&en<=r){

        vector<int>::iterator it = --lower_bound(tree[node].v.begin() , tree[node].v.end() , h+1);

        if((int)*it>h)return 0;
        return (int)*it;
    }

    int mid = (st+en)/2;

    return max(query(2*node , st , mid , l , r , h) , query(2*node+1 , mid+1 , en , l , r , h));

}

int main(void)
{
    int n , q;
    scanf("%d %d",&n , &q);
    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        v.push_back(in);
    }

    build(1 , 1 , n);

    for(int i=0;i<q;i++){

        int in1 , in2 , in3;
        scanf("%d %d %d",&in1 , &in2 , &in3);

        printf("%d\n",query(1 , 1 , n , in1+1 , in2+1 , in3));
    }

    return 0;
}
