// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 100000+9;
vector<ll>v , v1 , v2 , vr;

int main(void)
{
    v.push_back(0);
    ll sum = 0 , n;
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        ll in;
        scanf("%lld",&in);
        v.push_back(in);
        vr.push_back(in);
        sum+=in;
    }
    if(sum%2)printf("NO\n");
    else{
        vr.push_back(0);
        reverse(vr.begin() , vr.end());
        v1.push_back(0);
        v2.push_back(0);
        for(int i=1;i<=n;i++){
            v1.push_back(v[i]+v1[i-1]);
        }
        for(int i=1;i<=n;i++){
            v2.push_back(vr[i]+v2[i-1]);
        }
        bool found = false;
        for(int i=1;i<=n;i++){
            if(binary_search(v1.begin()+i , v1.end() , sum/2+v[i])==true)found=true;
            if(binary_search(v2.begin()+i , v2.end() , sum/2+vr[i])==true)found=true;
        }
        if(found)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
