// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        
        int n , k;
        scanf("%d %d",&n,&k);
        int sum = 0;
        for(int i=0;i<n;i++){
            
            int h1 , m1 , h2 , m2;
            scanf("%d:%d %d:%d",&h1 , &m1 , &h2 , &m2);
            sum+=h2*60+m2-h1*60-m1;
        }
        
        sum/=60;
        if(sum>=k)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}