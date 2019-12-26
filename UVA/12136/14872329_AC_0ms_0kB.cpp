// In the name of Allah the Lord of the Worlds. 

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){
        
        int h1 , m1 , h2 , m2;
        scanf("%d:%d %d:%d",&h1, &m1 , &h2 , &m2);
        
        int t1 = h1*60+m1;
        int t2 = h2*60+m2;
        
        if(t1>t2)swap(t1 , t2);
        scanf("%d:%d %d:%d",&h1, &m1 , &h2 , &m2);
        
        int t3 = h1*60+m1;
        int t4 = h2*60+m2;
        
        if(t3>t4)swap(t3 , t4);
        
        if(t2>t3){
            
            swap(t1 , t3);
            swap(t2 , t4);
        }
        
        if(t3>t2)printf("Case %d: Hits Meeting\n",++c);
        else printf("Case %d: Mrs Meeting\n",++c);
        
    }
    return 0;
}