// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ar[19];
ll n , k;
vector<ll>first;
map<ll , int>second;

void f(int i , int lim , ll value)
{
    if(i==lim){

        first.push_back(value);
        //cout << "First : " << value << endl;
        return ;
    }

    f(i+1 , lim , value);
    f(i+1 , lim , value + ar[i]);
    f(i+1 , lim , value + ar[i]+ar[i]);
}

void f2(int i , int lim , ll value )
{
    if(i==lim){

        second[value] = 1;
        //cout << "second : " << value << endl;
        return ;
    }

    f2(i+1 , lim , value);
    f2(i+1 , lim , value + ar[i]);
    f2(i+1 , lim , value + ar[i] + ar[i]);
}

int main(void)
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){

        first.clear();
        second.clear();

        scanf("%lld %lld",&n , &k);
        for(int j=0;j<n;j++){

            scanf("%lld",&ar[j]);
        }

        f(0 , n/2 , 0);
        f2(n/2 , n , 0);

        int si = first.size();
        bool check = false;
        for(int j=0;j<si;j++){

            if(second[k-first[j]]==1){check=true;break;}
        }

        if(check==true)printf("Case %d: Yes\n",i+1);
        else printf("Case %d: No\n",i+1);
    }
    return 0;
}
