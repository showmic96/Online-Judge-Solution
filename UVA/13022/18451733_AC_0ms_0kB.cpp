// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll>ans;
void pre()
{
    for(int i=1;i<=63;i++){

        for(int j=1;j<=63;j++){

            int len = 0;
            int t1 = i , t2 = j;
            ll temp = 0;
            while(len<=63){

                if(t1>0){

                    temp*=2LL;
                    temp+=1LL;
                    t1--;
                    len++;
                }
                else if(t1==0){
                    ans.push_back(temp);
                    t1--;
                }
                else if(t2>0){

                    temp*=2LL;
                    t2--;
                    len++;
                }
                else if(t2==0){
                    ans.push_back(temp);
                    t1 = i;
                    t2 = j;
                }
            }
        }
    }
    sort(ans.begin() , ans.end());
    ans.erase(unique(ans.begin() , ans.end()) , ans.end());
    //for(int i=0;i<100;i++)cout << ans[i] << endl;
}

int main(void)
{
    pre();
    ll x , y;
    while(scanf("%lld %lld",&x , &y)==2){

        ll counter = 0;
        for(auto it : ans)if(it>=x&&it<=y)counter++;
        printf("%lld\n",counter);
    }
    return 0;
}
