// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6+100;

bool isPrime[MAX+9];
vector<ll>primes;

void seive()
{
    for(int i=0;i<=MAX;i++)isPrime[i]=true;

    isPrime[0] = false;
    isPrime[1] = false;

    for(ll i = 2;i<=MAX;i++){

        for(ll j =2;j*i<=MAX;j++){

            if(isPrime[i]==true)isPrime[i*j] = false;
        }

        if(isPrime[i]==true)primes.push_back(i);
    }
}

int main(void)
{
    seive();
    queue<ll>ans;
    ll n , k;
    cin >> n >> k;

    ll temp = n;

    ll lim = sqrt(n);

    for(int i=0;primes[i]<=lim;i++){

        if(temp%primes[i]==0){

            if(temp==primes[i])continue;

            ans.push(primes[i]);
            bool check = true;

            while(temp%primes[i]==0){

                if(check==false)ans.push(primes[i]);
                temp/=primes[i];
                check = false;
            }

            if(isPrime[temp]==true){ans.push(temp);temp = 1;}
        }
    }
    if(isPrime[temp]==true)ans.push(temp);

    //cout << ans.size() << " " << primes.size() << endl;

    if(ans.size()<k)cout << -1 << endl;
    else{

        while(ans.size()!=k){

            ll t1 = ans.front();ans.pop();
            ll t2 = ans.front();ans.pop();

            ans.push(t1*t2);
        }

        int si = ans.size();

        for(int i=0;i<si;i++){cout << ans.front() << " ";ans.pop();}

        cout << endl;
    }

    return 0;
}
