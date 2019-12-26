// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 3*1e6;

double data[MAX+9];
double lg[1111];

void pre()
{
    data[0] = 1;
    data[1] = log(1);

    for(int i=2;i<=MAX;i++){

        data[i] += log10(i) + data[i-1];
    }

    for(int i=2;i<=1010;i++){

        lg[i] = log10(i);
    }
}

ll dig(int n , int b)
{
    double sum = 0.0;

    for(int i=2;i<=n;i++)sum+=log(i);
    double dem = log(b);

    return (ll)((sum/dem+1e-4)+1);
}

int main(void)
{
    pre();

    ll n , b;
    while(scanf("%lld %lld",&n, &b)==2){

        set<int>st;
        map<int , int>mp;

        ll lim = sqrt(b) , bt = b , nt = n;

        for(int i=2;i<=lim;i++){

            while(bt%i==0){

                st.insert(i);
                mp[i]++;
                bt/=i;
            }
        }

        if(bt>1)st.insert(bt) , mp[bt]++;

        int zero = 1e9;

        for(set<int>::iterator it = st.begin();it!=st.end();it++){

            ll temp = *it;
            ll value = *it;
            int counter = 0;
            while(true){
                counter += n/temp;
                temp*= value;
                if(temp>n)break;
            }
            if(mp[value]==0)zero = 0;
            else zero = min(zero , counter/mp[value]);
        }

        ll value = dig(n , b);

        printf("%d %lld\n",zero , value);
    }
    return 0;
}
