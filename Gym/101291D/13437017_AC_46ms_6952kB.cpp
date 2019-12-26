// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5+9;
ll tree[4*MAX];
bool camera[MAX+9];

void update(int node , int st , int en , int idx)
{//cout << node << endl;
    if(st==en){

        tree[node] = 1;
        return ;
    }

    int mid = (st+en)/2;
    if(idx>=st&&idx<=mid)update(2*node , st , mid , idx);
    else update(2*node+1 , mid+1 , en , idx);

    tree[node] = tree[2*node] + tree[2*node+1];
}

ll query(int node , int st , int en , int l , int r)
{
    if(st>r||en<l)return 0;
    if(st>=l&&en<=r)return tree[node];
    int mid = (st+en)/2;

    return query(2*node , st , mid , l , r) + query(2*node+1 , mid+1 , en , l , r);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int>v;
    memset(tree , 0 , sizeof(tree));
    memset(camera , false , sizeof(camera));

    int n , k , r;
    cin >> n >> k >> r;

    for(int i=0;i<k;i++){

        int in;
        cin >> in;

        update(1 , 1 , MAX , in);

        camera[in] = true;
    }

    int counter = 0;

    for(int i=1;i<=n-r+1;i++){

        while(query(1 , 1 , MAX , i ,  i+r-1)<2){

            for(int i1=min(n, i+r-1);i1>=1;i1--){

                if(camera[i1]==false){

                    camera[i1] = true;
                    update(1 , 1 , MAX , i1);
                    break;
                }
            }
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}
