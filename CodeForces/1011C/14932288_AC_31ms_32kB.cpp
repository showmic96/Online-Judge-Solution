// In the name of Allah the Lord of the Worlds. 

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , m;
vector<int>v1 , v2;

bool f(double now)
{
    double tot = m+now;
    
    double req = tot/(double)v1[0];
    now-=req;
    
    for(int i=1;i<n;i++){
        
        tot = m+now;
        double req = tot/(double)v1[i];
        now-=req;
        tot = m+now;
        
        req=tot/(double)v2[i];
        now-=req;
        if(now<0)return false;
    }
    
    tot = m+now;
    req = tot/(double)v2[0];
    now-=req;
    
    if(now<0)return false;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    scanf("%d %d",&n , &m);
    
    for(int i=0;i<n;i++){
        
        int in;
        scanf("%d",&in);
        v1.push_back(in);
    }
    
    for(int i=0;i<n;i++){
        
        int in;
        scanf("%d",&in);
        v2.push_back(in);
    }
    
    double hi = 1e9 , low = 0 , mid , ans = -1;
    int t = 200;
    while(t--){
        
        mid = (hi+low)/2;
        
        if(f(mid)==true){
            
            ans = mid;
            hi = mid-1;
        }
        else low = mid+1;
    }
    
    printf("%.14f\n",ans);
    
    return 0;
}