// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 9;

int tree[4*MAX+9] , last[MAX+9] ,ans[MAX+9];

struct node{

    int x , y , idx;

    node(int _x , int _y , int _idx){

        x = _x;
        y = _y;
        idx = _idx;
    }
};

bool operator<(node A , node B)
{
    return A.y<B.y;
}

vector<node> v;

void update(int node , int st , int en , int idx , int value)
{
    if(st==en){

        tree[node] = value;
        return ;
    }

    int mid = (st+en)/2;

    if(idx>=st&&idx<=mid)update(2*node , st , mid , idx , value);
    else update(2*node+1 , mid+1 , en , idx , value);

    tree[node] = tree[2*node]+tree[2*node+1];
}

int query(int node , int st , int en , int l , int r)
{
    if(st>=l&&en<=r)return tree[node];

    if(l>en||r<st)return 0;

    int mid = (st+en)/2;

    int p1 = query(2*node , st , mid , l , r);
    int p2 = query(2*node+1 , mid+1 , en , l , r);


    return p1+p2;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int n , q;
        scanf("%d %d",&n,&q);

        v.clear();
        vector<int>data;

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            data.push_back(in);
        }

        for(int i=0;i<q;i++){

            int in1 , in2;
            scanf("%d %d",&in1 ,&in2);
            v.push_back(node(in1 , in2 , i));
        }

        sort(v.begin() , v.end());

        memset(tree , 0 , sizeof(tree));
        memset(last , -1 , sizeof(last));

        int j = 0;

        for(int i=0;i<q;i++){

            while(v[i].y>=j+1){

                update(1 , 1 , n , j+1 , 1);

                if(last[data[j]]!=-1){

                    update(1 , 1 , n , last[data[j]]+1 , 0);
                }

                last[data[j]] = j;

                j++;
            }

            ans[v[i].idx] = query(1 , 1 , n , v[i].x , v[i].y);
        }

        printf("Case %d:\n",++c);

        for(int i=0;i<q;i++){

            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
