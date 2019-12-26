// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bitset<1000005>isPrime;
vector<ll>primes , ans;
ll dv[1000005] , dv2[1000005];
vector<ll>divisor[1000005];

void seive()
{
    for(int i=0;i<1000005;i++)isPrime[i] = 1 , dv[i] = 0 , dv2[i] = 1;

    for(int i=2;i<1000005;i++){

        if(isPrime[i]==1){

            for(int j=2*i;j<1000005;j+=i){

                isPrime[j] = 0;
            }

            primes.push_back(i);
        }
    }
    
    
    dv[1] = 1;

    for(int i=2;i<1000005;i++){

        ll counter = 1 , now = i;

        for(int j=0;primes[j]*primes[j]<=now;j++){

            if(now%primes[j]==0){

                ll t = 0;
                while(now%primes[j]==0){

                    t++;
                    now/=primes[j];
                }

                counter*=(t+1);
            }
        }

        if(now>1){
            counter*=2;
        }

        dv[i] = counter;
    }

    for(int i=2;i<1000005;i++){

        for(int j=2*i;j<1000005;j+=i){

            if(dv[j]%dv[i]!=0){
                
                dv2[j] = 0;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    seive();
    int now = 0;
    
    for(int i=2;i<1000005;i++){

        if(dv2[i]==1&&dv[i]>3){
            now++;
            if(now%108==0)cout << i << endl;
        }
    }

    return 0;
}
