// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        int h1 , m1 , h2 , m2 , n , need , ans = 1e9;
        scanf("%d %d:%d",&n , &h1 , &m1);
        for(int i=0;i<n;i++){

            scanf("%d:%d %d",&h2 , &m2 , &need);
            int t1 , t2;
            if(h2<h1){

                t1 = 24-h1;
                t1+=h2;
            }
            else t1 = h2-h1;

            if(m2<m1){

                if(t1==0)t1 = 24;
                t1--;
                t2 = 60-m1;
                t2+=m2;
            }
            else t2=m2-m1;

            if(t1*60+t2+need<ans)ans = t1*60+t2+need;
        }

        printf("Case %d: %d\n",++c , ans);
    }
    return 0;
}
