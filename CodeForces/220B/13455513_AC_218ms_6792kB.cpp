// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int a;

struct s{

    int l , r , idx;

    s(int _l , int _r , int _idx){

        l = _l;
        r = _r;
        idx = _idx;
    }
};

bool cmp(s A , s B)
{
    if(A.l/a!=B.l/a){

        return A.l/a<B.l/a;
    }

    return A.r<B.r;
}

int ar[100005];
int ans[100005] , mp[100005];
vector<s>v;
int c = 0;

void add(int idx)
{
    int temp = ar[idx];
    if(temp>100000)return;

    if(mp[temp]==temp)c--;
    mp[temp]++;
    if(mp[temp]==temp)c++;
}

void rem(int idx)
{
    int temp = ar[idx];
    if(temp>100000)return;

    if(mp[temp]==temp)c--;
    mp[temp]--;
    if(mp[temp]==temp)c++;
}

int main(void)
{
    memset(mp , 0 , sizeof(mp));
    int n , m;
    scanf("%d %d",&n , &m);

    for(int i=1;i<=n;i++)scanf("%d",&ar[i]);
    for(int i=0;i<m;i++){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        v.push_back(s(in1 , in2 , i));
    }

    a = sqrt(n);

    sort(v.begin() , v.end() , cmp);

    int l = 0 , r = 0;

    for(int i=0;i<m;i++){

        int left = v[i].l;
        int right = v[i].r;

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

        ans[v[i].idx] = c;
    }

    for(int i=0;i<m;i++){

        printf("%d\n",ans[i]);
    }

    return 0;
}
