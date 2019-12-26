// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

vector<int>primes;
bool isPrime[111];

void seive()
{
    for(int i=0;i<111;i++)isPrime[i]=true;
    isPrime[0]=false;
    isPrime[1]=false;

    for(int i=2;i<111;i++){

        for(int j=2;i*j<111;j++){

            if(isPrime[i]==true)isPrime[i*j]=false;
        }

        if(isPrime[i]==true)primes.push_back(i);
    }
}

int main(void)
{
    seive();
    int t;
    scanf("%d",&t);

    for(int i=0;i<t;i++){

        int in;
        scanf("%d",&in);

        map<int , int>mp;

        for(int j=2;j<=in;j++){

            if(isPrime[j]==true)mp[j]++;

            else{

                int temp = j;
                int lim = sqrt(temp);

                for(int k=0;primes[k]<=lim;k++){

                    int temp2 = 4;

                    while(temp%primes[k]==0){

                        mp[primes[k]]++;

                        temp2 = temp/primes[k];

                        temp/=primes[k];
                    }

                    if(isPrime[temp2]==true){mp[temp2]++;break;}
                }
            }
        }

        printf("Case %d: ",i+1);
        bool check = false;

        for(int j=0;j<primes.size();j++){

            if(mp[primes[j]]!=0){

                if(check==false){printf("%d = %d (%d)",in, primes[j] , mp[primes[j]]);check=true;}
                else printf(" * %d (%d)",primes[j] , mp[primes[j]]);
            }
        }

        printf("\n");
    }

    return 0;
}
