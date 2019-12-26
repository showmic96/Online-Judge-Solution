// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bitset<305>bs;
vector<int>primes;

bool cmp(pair<ll , ll> A , pair<ll , ll> B)
{
    return A.second<B.second;
}

ll get(ll x)
{
    vector<int>temp;
    while(x){

        temp.push_back(x%10);
        x/=10;
    }
    reverse(temp.begin() , temp.end());
    ll ans = 0 , t = 1e17;
    for(int i=0;i<temp.size();i++){

        ans+=(ll)temp[i]*t;
        t/=10;
    }
    return ans;
}

void sieve()
{
    bs&=0;
    vector<pair<ll , ll > > temp;
    for(int i=2;i<=300;i++){

        if(bs[i]==0){

            for(int j=2*i;j<=300;j+=i){

                bs[j] = 1;
            }
            temp.push_back(make_pair(i , get(i)));
        }
    }
    sort(temp.begin() , temp.end() , cmp);
    for(int i=0;i<temp.size();i++)primes.push_back(temp[i].first);
}

int dp[65][1005][15];

int f(int i , int sum , int rem)
{
    if(rem<0)return 0;
    if(sum<0)return 0;
    if(i==primes.size()){

        if(sum==0&&rem==0)return 1;
        return 0;
    }
    if(dp[i][sum][rem]!=-1)return dp[i][sum][rem];

    int value = 0;

    value = max(value , f(i+1 , sum , rem));
    if(sum-primes[i]>=0&&rem>0)value = max(value , f(i+1 , sum-primes[i] , rem-1));
    if(sum-2*primes[i]>=0&&rem>1&&primes[i]>2)value = max(value , f(i+1 , sum-2*primes[i] , rem-2));

    return dp[i][sum][rem] = value;
}

int main(void)
{
    sieve();
    memset(dp , -1 , sizeof(dp));

    int c = 0 , n , t;
    while(scanf("%d %d",&n , &t)==2){

        if(n==0&&t==0)break;

        if(f(0 , n , t)==0)printf("CASE %d:\nNo Solution.\n",++c);
        else{

            printf("CASE %d:\n",++c);
            int now = n , rem = t;
            vector<int>ans;

            for(int i=0;i<primes.size();i++){

                if(primes[i]>2&&f(i+1 ,now-2*primes[i] , rem-2)==1){

                    now-=2*primes[i];
                    rem-=2;
                    ans.push_back(primes[i]);
                    ans.push_back(primes[i]);
                }
                else if(f(i+1 , now-primes[i] , rem-1)==1){

                    ans.push_back(primes[i]);
                    now-=primes[i];
                    rem--;
                }
            }

            for(int i=0;i<ans.size();i++){

                if(i>0)printf("+");
                printf("%d",ans[i]);
            }
            printf("\n");
        }
    }

    return 0;
}
