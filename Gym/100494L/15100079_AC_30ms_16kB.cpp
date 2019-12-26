// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(pair<int , int>A , pair<int , int>B)
{
    return A.first<B.first;
}

int ar[24*60+10] , br[24*60+10];

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){
        
        memset(ar , 0 , sizeof(ar));
        memset(br , 0 , sizeof(br));
        
        int n , n1 , n2;
        scanf("%d %d %d",&n , &n1 , &n2);
        
        for(int i=0;i<n1;i++){
            
            int h1 , h2 , m1 , m2;
            scanf("%d:%d %d:%d",&h1 ,&m1 ,&h2 , &m2);
            
            h1 = h1*60+m1;
            h2 = h2*60+m2;
            
            ar[h1]--;
            br[h2+n]++;
        }
        
        for(int i=0;i<n2;i++){
            
            int h1 , h2 , m1 , m2;
            scanf("%d:%d %d:%d",&h1 ,&m1 ,&h2 , &m2);
            
            h1 = h1*60+m1;
            h2 = h2*60+m2;
            
            br[h1]--;
            ar[h2+n]++;
        }
        
        int t1 = 0 , t2 = 0 , c1 = 0 , c2 = 0;
        
        for(int i=0;i<=24*60;i++){
            
            t1+=ar[i];
            c1 = min(t1 , c1);
            t2+=br[i];
            c2 = min(t2 , c2);
        }
        
        printf("Case #%d: %d %d\n",++c , abs(c1) , abs(c2));
    }
    
    return 0;
}