// In the name of Allah the Lord of the worlds .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAX = 1e7;

bool isPrime[MAX+1];
vector<ll>prime;

void seive()
{
    long long lim = sqrt(MAX);

    for(int i=0;i<=MAX;i++)isPrime[i] = true;

    for(ll i=2;i<=MAX;i++){

        for(ll j=2;j*i<=MAX;j++){

            if(isPrime[(ll)i]==true){

                isPrime[(ll)(i*j)]=false;
            }
        }
        if(isPrime[(ll)i]==true)prime.push_back((ll)i);
    }

   // for(int i=0;i<prime.size();i++)cout << prime[i] << " ";

}

int main(void)
{
    seive();
    ll a;
    vector<ll>ans;
    ll si = prime.size();
    //cout << si << endl;
    while(cin >> a){
        if(a<0)break;

        ans.clear();

        for(ll i=0;i<si;i++){

            while(a%prime[i]==0){ans.push_back(prime[i]);a/=prime[i];if(a==0)break;}
            if(a==0)break;
        }
        if(a>1)ans.push_back(a);

        int si2 = ans.size();
        for(int i=0;i<si2;i++)cout << "    " <<  ans[i] << endl;

        cout << endl;
    }


    return 0;
}
