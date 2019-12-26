// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5;

char ar[MAX+9];
int tree[4*MAX+9] , lazy[4*MAX+9];
#define SS( a ) scanf("%s",a)

void update(int node , int b , int e , int i , int j)
{
    if (i > e || j < b)return ;

    if(b>=i&&e<=j){

        lazy[node] ^= 1;
        return ;
    }

    if(lazy[node]){

        lazy[2*node]^=1;
        lazy[2*node+1]^=1;

        lazy[node] = 0;
    }

    int mid = (b+e)/2;
    int left = 2*node;
    int right = 2*node+1;

    update(left , b , mid , i , j);
    update(right , mid+1 , e , i , j);
}

int query(int node , int b ,int e , int i , int j)
{
    if(b>=i&&e<=j){

        return lazy[node];
    }

    if(lazy[node]){

        lazy[2*node]^=1;
        lazy[2*node+1]^=1;

        lazy[node] = 0;
    }

    int mid = (b+e)/2;
    int left = 2*node;
    int right = 2*node+1;

    if(i<=mid) return query(left , b , mid , i , j);
    else return query(right , mid+1 ,e, i , j);


}

int main(void)
{
    //freopen("input.txt","r",stdin);
    int t, c = 0;
    scanf("%d",&t);
    while(t--){

        memset(lazy , 0 , sizeof(lazy));
        SS(ar);//cin >> ar;

        int n = strlen(ar);
//        build(1 , 1 , n);

        int q;
        scanf("%d",&q);
        printf("Case %d:\n",++c);
        while(q--){
            char x[3];
            SS(x);

            if(x[0]=='I'){
                int i , j;
                scanf("%d %d",&i, &j);
                update(1 , 1 , n , i , j);
            }

            else{

                int i;
                scanf("%d",&i);
                int ret = query(1 , 1 , n , i , i);
                int ans = ar[i-1] - '0';

                if(ret==1)ans^=1;

                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
