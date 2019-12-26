// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<ll , ll > > v;
vector<pair<ll , pair<ll , ll > > > temp;
bool cmp(pair<ll , ll > A , pair<ll , ll > B)
{
    return A.first < B.first;
}

bool cmp2(pair<ll , pair<ll , ll > > A , pair<ll , pair<ll , ll > > B)
{
    return A.second.second<B.second.second;
}

int par[200005];
int sz[200005];

int Find(int x)
{
    if(par[x]==x)return x;
    return par[x] = Find(par[x]);
}

void Union(int x , int y)
{
    int u = Find (x);
    int v = Find (y);

    if (sz [u] < sz [v]) swap (u, v);
    par [v] = u;
    sz [u] += sz [v];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , m;
    cin >> n >> m;

    for(int i=0;i<=n;i++){

        par[i] = i;
        sz[i] = 1;
    }

    for(int i=0;i<n;i++){
        ll in;
        cin >> in;
        v.push_back(make_pair(in , i+1));
    }
    for(int i=0;i<m;i++){

        ll in1 , in2 , in3;
        cin >> in1 >> in2 >> in3;
        temp.push_back(make_pair(in1 , make_pair(in2 , in3)));
    }
    if(n==1){
        cout << 0 << endl;
        return 0;
    }
    sort(v.begin() , v.end() , cmp);
    sort(temp.begin() , temp.end() , cmp2);

    int i = 1 , j = 0;
    ll ans = 0;

    while(true){

        if(j==m){
            if(Find(v[0].second)==Find(v[i].second)){

                i++;
                continue;
            }
            ll t = v[i].first+v[0].first;
            Union(v[0].second , v[i].second);
            ans+=t;
            i++;
            if(sz[Find(v[0].second)]>=n)break;
        }
        else if(i>=n){
            if(Find(temp[j].first)==Find(temp[j].second.first)){
                j++;
                continue;
            }
            Union(temp[j].first , temp[j].second.first);
            ans+=temp[j].second.second;

            if(sz[Find(temp[j].first)]>=n)break;
            j++;
        }
        else if(i>=n&&j>=m)break;

        else{

            ll t = v[i].first+v[0].first;

            if(t<temp[j].second.second){
                if(Find(v[0].second)==Find(v[i].second)){

                    i++;
                    continue;
                }
                Union(v[0].second , v[i].second);
                ans+=t;
                i++;
                if(sz[Find(v[0].second)]>=n)break;
            }
            else{
                if(Find(temp[j].first)==Find(temp[j].second.first)){
                    j++;
                    continue;
                }
                Union(temp[j].first , temp[j].second.first);
                ans+=temp[j].second.second;

                if(sz[Find(temp[j].first)]>=n)break;
                j++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
