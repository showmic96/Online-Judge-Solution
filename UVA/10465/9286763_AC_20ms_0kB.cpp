// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n , m , t;
    while(scanf("%d %d %d",&n , &m , &t)==3){

        if(m<n)swap(n , m);

        int ans = 0 , time = 12345678 , n_counter = 0 , m_counter = 0;

        n_counter = t/n;

        while(n_counter>=0){

            m_counter = t - n_counter*n;
            m_counter/=m;

            if(t-(n_counter*n+m_counter*m)<time){

                time = t-(n_counter*n+m_counter*m);
                ans = n_counter+m_counter;
            }
            
            else if(t-(n_counter*n+m_counter*m)==time){
                
                if(n_counter+m_counter>ans){
                    
                    ans = n_counter+m_counter;
                }
            }

            n_counter--;
        }

        if(time==0)printf("%d\n",ans);
        else printf("%d %d\n",ans , time);
    }

    return 0;
}
