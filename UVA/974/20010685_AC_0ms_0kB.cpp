// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6+9;
vector<ll>ans;

vector<ll> g(ll x)
{
    vector<ll>temp;
    while(x){
        temp.push_back(x%10);
        x/=10;
    }
    reverse(temp.begin() , temp.end());
    return temp;
}
void pre()
{
    for(ll i=1;i<=40000;i++){
        vector<ll>v = g(i*i);
        bool check = false;
        ll sum = 0;
        for(int j=0;j<v.size();j++){
            sum*=10;
            sum+=v[j];
            ll now = 0;
            for(int k=j+1;k<v.size();k++){
                now*=10;
                now+=v[k];
            }
            if(sum>0&&now>0&&sum+now==i){
                check = true;
                break;
            }
        }
        if(check)ans.push_back(i);
    }
}

int main(void)
{
    pre();
    int t , c = 0;
    scanf("%d",&t);
    while(t--){
        if(c>0)printf("\n");
        ll a , b;
        scanf("%lld %lld",&a , &b);
        printf("case #%d\n",++c);
        if(upper_bound(ans.begin() , ans.end() , b)-lower_bound(ans.begin() , ans.end() , a)==0)printf("no kaprekar numbers\n");
        else{
            int idx = lower_bound(ans.begin() , ans.end() , a-10) - ans.begin();
            idx = max(0 , idx-10);
            for(int i=idx;i<ans.size();i++){
                if(ans[i]>b)break;
                if(ans[i]>=a&&ans[i]<=b)printf("%lld\n",ans[i]);
            }
        }
    }
    return 0;
}
