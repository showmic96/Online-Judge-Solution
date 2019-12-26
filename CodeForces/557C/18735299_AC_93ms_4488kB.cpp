// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
set<int>st;
vector<int>v;
vector<pair<int , int> > p;
int ar[100005] , sum[100005];

bool cmp(pair<int , int>A , pair<int , int>B)
{
    return A.second > B.second;
}

int main(void)
{
    int n , tot = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int in;
        scanf("%d",&in);
        ar[in]++;
        st.insert(in);
        p.push_back({in , 0});
    }
    for(int i=0;i<n;i++){
        int in;
        scanf("%d",&in);
        sum[p[i].first]+=in;
        tot+=in;
        p[i].second = in;
    }
    for(auto it : st)v.push_back(it);
    sort(p.begin() , p.end() , cmp);
    int mi = tot;
    for(int i=0;i<v.size();i++){
        int l = ar[v[i]];
        int now = sum[v[i]];
        for(int j=0;j<p.size();j++){
            if(l==1)break;
            if(v[i]>p[j].first){
                now+=p[j].second;
                l--;
            }
        }
        mi = min(mi , tot-now);
    }
    printf("%d\n",mi);
    return 0;
}
