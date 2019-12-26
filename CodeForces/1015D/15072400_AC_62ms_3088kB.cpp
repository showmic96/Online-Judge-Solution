// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll n , k , s;
    scanf("%lld %lld %lld",&n , &k , &s);
    if(k>s||(n-1)*k<s)printf("NO\n");
    else{
        
        printf("YES\n");
        vector<ll>v;
        
        while(s-(n-1)>k){
            
            s-=(n-1);
            k--;
            if(v.size()%2==0)v.push_back(n);
            else v.push_back(1);
        }
        ll last = 1;
        if(v.size()!=0)last = v[v.size()-1];
        
        ll rem = s-k+1;
        rem = min(n-1 , rem);
        
        if(last==1){
            v.push_back(last+rem);
            s-=rem;
            k--;
            last = last+rem;
        }
        else {
            v.push_back(last-rem);
            s-=rem;
            k--;
            last = last-rem;
        }
        
        rem = s-k+1;
        rem = min(n-1 , rem);
        
        if(last==1&&k>0){
            v.push_back(last+rem);
            s-=rem;
            k--;
            last = last+rem;
        }
        
        else if(k>0){
            v.push_back(last-rem);
            s-=rem;
            k--;
            last = last-rem;
        }
        
        while(k>0){
            
            if(last+1<=n){
                
                v.push_back(last+1);
                last++;
            }
            else{
                
                v.push_back(last-1);
                last--;
            }
            
            k--;
        }
        
        for(int i=0;i<v.size();i++){
            
            if(i)printf(" ");
            printf("%lld",v[i]);
        }
        
        printf("\n");
    }

    return 0;
}