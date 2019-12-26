// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

struct s{

    int l , r , idx;
    s(int _l , int _r , int _idx){

        l = _l;
        r = _r;
        idx = _idx;
    }
};

vector<s>query;
int ar[1000005] , a = 0;
vector<int>v , ans;

void add(int idx)
{
    ar[v[idx]]++;
    if(ar[v[idx]]==1)a++;
}

void rem(int idx)
{
    ar[v[idx]]--;
    if(ar[v[idx]]==0)a--;
}

bool cmp(s A , s B)
{
    if(A.l/170!=B.l/170){

        return A.l/170<B.l/170;
    }

    return A.r<B.r;
}

int main(void)
{
    memset(ar , 0 , sizeof(ar));

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        v.push_back(in);
    }

    int q;
    scanf("%d",&q);

    for(int i=0;i<q;i++){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        in1--;
        in2--;
        query.push_back(s(in1 , in2 , i));
        ans.push_back(0);
    }

    sort(query.begin() , query.end() , cmp);
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

    for(int i=0;i<q;i++){

        printf("%d\n",ans[i]);
    }

    return 0;
}
