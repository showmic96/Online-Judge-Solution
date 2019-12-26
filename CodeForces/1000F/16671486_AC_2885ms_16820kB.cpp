// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int a;

struct s{

    int l , r , idx;

}query[500005];
bool cmp(const s &lhs ,const s &rhs){
   if(lhs.l/a!=rhs.l/a) return lhs.l/a < rhs.l/a;
   else return ((lhs.l/a)&1 ? lhs.r < rhs.r : lhs.r > rhs.r);
}

int n , q;
int ans[500005] , counter = 0 , mp[500005] , yes[500005] , v[500005];
vector<int>st;

void add(int idx)
{
    mp[v[idx]]++;
    if(mp[v[idx]]==1){if(yes[v[idx]]==0)st.emplace_back(v[idx]) , yes[v[idx]] = 1;}
}

void rem(int idx)
{
    mp[v[idx]]--;
    if(mp[v[idx]]==1){if(yes[v[idx]]==0)st.emplace_back(v[idx]) , yes[v[idx]] = 1;}
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++){

        int in;
        cin >> in;
        v[i] = in;
        mp[in]++;
        if(mp[in]==1)st.emplace_back(in) , yes[in] = 1;
    }

    a = sqrt(n);

    cin >> q;
    for(int i=0;i<q;i++){

        int in1 , in2;
        cin >> in1 >> in2;
        query[i].l = in1;
        query[i].r = in2;
        query[i].idx = i+1;
    }

    sort(query , query+q , cmp);

    int l = 0 , r = n;
    for(int i=0;i<q;i++){

        int left = query[i].l-1;
        int right = query[i].r-1;

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

        while(st.empty()==false&&mp[st.back()]!=1)yes[st.back()] = 0 , st.pop_back();
        if(st.size()>0)ans[query[i].idx] = st.back();
    }

    for(int i=1;i<=q;i++)cout << ans[i] << '\n';

    return 0;
}
