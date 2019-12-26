// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5+9;
vector<int>v[MAX] , sum[MAX];

bool cmp(int A , int B)
{
    return A>B;
}
bool cp(pair<int , int>A , pair<int , int> B)
{
    return A.first>B.first;
}

int main(void)
{
    int n , m;
    scanf("%d %d",&n , &m);
    for(int i=0;i<n;i++){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        v[in1].push_back(in2);
    }

    vector<pair<int , int> > idx;

    for(int i=1;i<=m;i++){

        sort(v[i].begin() , v[i].end() , cmp);
        for(int j=0;j<v[i].size();j++){

            if(j)sum[i].push_back(sum[i][j-1]+v[i][j]);
            else sum[i].push_back(v[i][j]);
        }
        if(v[i].size()>0)idx.push_back({v[i].size() , i});
    }
    sort(idx.begin() , idx.end() , cp);

    ll ans = 0 , counter = 0;

    for(int i=0;i<n;i++){

        vector<int>temp;
        for(int j=0;j<idx.size();j++){
            if(sum[idx[j].second].size()<=i)break;
            temp.push_back(sum[idx[j].second][i]);
        }
        sort(temp.begin() , temp.end() , cmp);
        counter = 0;

        for(int j=0;j<temp.size();j++){
            counter+=temp[j];
            ans = max(ans , counter);
        }
    }

    printf("%lld\n",ans);

    return 0;
}
