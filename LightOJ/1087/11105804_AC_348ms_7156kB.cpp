// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 9;

ll ar[2*MAX] , tree[5*MAX];

void update(int node , int st , int en , int idx , int value)
{
    if(st==en&&st==idx){

        tree[node] = value;
        //ar[st] = value;
        return ;
    }

    else{

        int mid = (st+en)/2;

        if(idx>=st&&idx<=mid){

            update(2*node , st , mid , idx , value);
        }
        else{

            update(2*node+1 , mid+1 , en , idx , value);
        }

        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

int query(int node , int st , int en , int value)
{
    //cout << node << " " << st << " " << en << " " << value << endl;

    if(st==en){

        return st;
    }

    else{

        int mid = (st+en)/2;

        if(value>tree[node]){

            return -1;
        }

        if(value<=tree[2*node]){

            return query(2*node , st , mid , value);
        }

        else{

            return query(2*node+1 , mid+1 , en , value-tree[2*node]);
        }
    }
}

int main(void)
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int t , c = 0;

    scanf("%d",&t);

    while(t--){

        int n , q , n_temp;
        scanf("%d %d", &n , &q);
        n_temp = n;
        memset(ar , 0 , sizeof(ar));
        memset(tree , 0 , sizeof(tree));

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            ar[i] = in;
            update(1 , 1 , n+q , i+1 , 1);
        }

        printf("Case %d:\n", ++c);

        for(int i=0;i<q;i++){

            scanf("\n");

            char x;

            scanf("%c",&x);

            if(x=='c'){

                int in;
                scanf("%d",&in);

                in = query(1 , 1 , n+q , in);

                if(in!=-1)printf("%d\n",ar[in-1]);
                else printf("none\n");
                if(in!=-1)update(1 , 1 , n+q , in , 0);
            }
            else{

                int in;
                scanf("%d",&in);
                ar[n_temp++] = in;
                update(1 , 1 , n+q , n_temp , 1);
            }
        }
    }

    return 0;
}
