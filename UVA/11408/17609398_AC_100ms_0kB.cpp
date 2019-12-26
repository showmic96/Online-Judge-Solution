// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 5000000+9;
int sum[MAX+9];
bool prime[MAX+9];

vector<int>ans;

void sieve()
{
    memset(prime , false , sizeof(prime));

    for(int i=2;i<=MAX;i++){

        if(sum[i]==0){

            prime[i] = true;
            for(int j=i;j<=MAX;j+=i)sum[j]+=i;
        }
    }

    for(int i=0;i<=MAX;i++){

        if(prime[sum[i]]==true)ans.emplace_back(i);
    }
}

int main(void)
{
    sieve();
    int n , m;
    while(scanf("%d",&n)==1){
        
        if(n==0)break;
        scanf("%d",&m);
        cout << upper_bound(ans.begin() , ans.end() , m) - lower_bound(ans.begin() , ans.end() , n) << endl;
    }
    return 0;
}
