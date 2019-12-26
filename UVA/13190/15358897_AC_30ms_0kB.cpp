// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct s{

    string name;
    ll val , idx;

    s(string _name, ll _val , ll _idx){

        name = _name;
        val = _val;
        idx = _idx;
    }
};

bool operator<(s A , s B)
{
    if(A.val==B.val)return A.idx<B.idx;
    return A.val<B.val;
}

vector<s>v;
vector<pair<string , ll> > data;

char x[100];
ll n , k;

bool possible(ll mid)
{
    ll counter = 0;

    for(int i=0;i<data.size();i++){

        counter+=mid/data[i].second;
    }
    if(counter>=k)return true;
    return false;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%lld %lld",&n , &k);

        v.clear();data.clear();

        for(int i=0;i<n;i++){

            ll in;
            scanf("%s %lld",&x , &in);
            string ar(x);

            data.push_back(make_pair(ar , in));
        }

        ll hi = 1e9 , low = 0 , mid , ans = -1;
        int ite = 50;

        while(ite--){

            mid = (hi+low)/2;
            if(possible(mid)==true){

                ans = mid;
                hi = mid-1;
            }
            else{

                low = mid+1;
            }
        }

        for(int i=0;i<n;i++){

            for(ll j=1;j*data[i].second<=ans;j++){

                v.push_back(s(data[i].first , j*data[i].second , i));
            }
        }

        sort(v.begin() , v.end());

        for(int i=0;i<k;i++){

            printf("%lld ",v[i].val);

            for(int j=0;j<v[i].name.size();j++)printf("%c",v[i].name[j]);
            printf("\n");
        }
    }
    return 0;
}
