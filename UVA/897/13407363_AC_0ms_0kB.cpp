// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4+9;
bool isPrime[MAX+9];

vector<int>primes , ans;

void sieve()
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

bool f(int x)
{
    string ar = "";

    while(x){

        ar+=x%10+'0';
        x/=10;
    }

    sort(ar.begin() , ar.end());

    do{
        int now = 0;
        for(int i=0;i<ar.size();i++){
            now*=10;
            now+=ar[i]-'0';
        }
        if(isPrime[now]==false)return false;

    }while(next_permutation(ar.begin() , ar.end()));

    return true;
}

void pre()
{
    sieve();

    for(int i=0;i<primes.size();i++){

        if(f(primes[i])==true){

            ans.push_back(primes[i]);
        }
    }
}

int main(void)
{
    pre();
    int n;
    while(scanf("%d",&n)==1){

        if(n==0)break;

        bool check = false;
        int temp = (int)pow(10 , (int)log10(n)+1);

        for(int i=0;i<ans.size();i++){

            if(n<ans[i]){

                n = ans[i];
                check = true;
                break;
            }
        }

        if(check&&n<temp){

            printf("%d\n",n);
        }
        else printf("0\n");
    }
    return 0;
}
