// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll block , a = 0;
ll fr[1000005];
ll v[200005] , ans[200005];

struct s{

    int l , r , idx;

}query[200005];

bool cmp(s A , s B)
{
    if(A.l/block!=B.l/block){

        return A.l/block<B.l/block;
    }

    return A.r<B.r;
}

void add(int idx)
{
    a-=fr[v[idx]]*fr[v[idx]]*v[idx];
    fr[v[idx]]++;
    a+=fr[v[idx]]*fr[v[idx]]*v[idx];
}

void rem(int idx)
{
    a-=fr[v[idx]]*fr[v[idx]]*v[idx];
    fr[v[idx]]--;
    a+=fr[v[idx]]*fr[v[idx]]*v[idx];
}

int main(void)
{
    ios_base:: sync_with_stdio( false );
    cin.tie(0);

    int n , q;
    cin >> n >> q;//scanf("%d %d",&n , &q);

    for(int i=0;i<n;i++){

        cin >> v[i];//scanf("%lld",&v[i]);
    }

    for(int i=0;i<q;i++){

        int in1 , in2;
        cin >> query[i].l >> query[i].r;//scanf("%d %d",&in1 , &in2);
        query[i].l--;query[i].r--;
        query[i].idx = i;
    }

    block = 1000;
    sort(query, query+q , cmp);

    int l = 0 , r = 0;

    for(int i=0;i<q;i++){

        int left = query[i].l;
        int right = query[i].r;

        while(l<left){

            rem(l);
            l++;
        }
        while(l>left){

            add(l-1);
            l--;
        }

        while(r<=right){

            add(r);
            r++;
        }

        while(r>right+1){

            rem(r-1);
            r--;
        }

        ans[query[i].idx] = a;
    }

    for(int i=0;i<q;i++)cout << ans[i] << "\n";//printf("%lld\n",ans[i]);

    return 0;
}