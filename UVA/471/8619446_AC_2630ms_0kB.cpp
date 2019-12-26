// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool taken[10];

ll n;

vector<ll>ans;

bool is_valid(ll x){

    bool found[10];
    memset(found , false , sizeof(found));

    while(x!=0){

        if(found[x%10]==true)return false;
        found[x%10]=true;
        x/=10;
    }

    return true;
}

bool check = false;

void f(ll value)
{
    if(value!=0)if(value%n==0){

        if(is_valid(value/n)){

            ans.push_back(value);
            //printf("%lld / %lld = %lld\n",value , value/n , n);
        }
    }

    for(int i=0;i<10;i++){

        if(taken[i]==false){

            taken[i]=true;

            f(value*10+i);

            taken[i]=false;
        }

        if(check==false)taken[0]=false;
        check = true;
    }

    return;
}

int main(void)
{
    int t;
    cin >> t;

    bool space = false;

    while(t--){

        if(space)cout << endl;
        space = true;
        check = false;
        cin >> n;

        memset(taken , false , sizeof(taken));
        taken[0] = true;
        f(0);

        sort(ans.begin() ,ans.end());

        int si = ans.size();

        for(int i=0;i<si;i++)printf("%lld / %lld = %lld\n",ans[i] , ans[i]/n , n);

        ans.clear();

    }

    return 0;
}
