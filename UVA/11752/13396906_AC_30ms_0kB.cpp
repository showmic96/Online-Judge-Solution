// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

const int MAX =  1e3+9;
bool isPrime[MAX+9];
vector<ll>primes , v;
set<ll>st;
set<ll>::iterator it;
ll two;

void seive()
{
    for(int i=0;i<=MAX;i++)isPrime[i] = true;
    for(int i=2;i<=MAX;i++){

        if(isPrime[i]){

            for(int j=2*i;j<=MAX;j+=i){

                isPrime[j] = false;
            }

            primes.push_back(i);
        }
    }
}


void add(ll x , ll y)
{
    ll temp = 1;
    ll lim = 18446744073709551615;
    
    for(int i=1;i<=y;i++){

        if(temp>lim/x){

            return ;
        }

        else{

            temp*=x;
        }
    }

    st.insert(temp);
}

int main(void)
{
    seive();
    for(int i=2;i<=100005;i++){

        for(int j=4;j<=64;j++){

            if(isPrime[j]==false)add(i , j);
        }
    }

    st.insert(1);

    for(it = st.begin();it!=st.end();it++)printf("%llu\n",(ll)*it);

    return 0;
}
