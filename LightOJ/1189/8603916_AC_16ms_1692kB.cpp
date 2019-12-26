// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fact[22] , n;

void pre_process()
{
    fact[0] = 1;
    fact[1] = 1;
    for(ll i =2;i<22;i++){

        fact[i] = fact[i-1] * i;
    }
}

int main(void)
{
    pre_process();
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){

        scanf("%lld",&n);

        stack < ll > st;

        for(int j = 20;j>=0;j--){

            if(fact[j]<=n){

                st.push(j);
                n-=fact[j];
            }
        }

        int temp = st.top();
        st.pop();

        printf("Case %d: ",i+1);

        if(n!=0){printf("impossible\n");continue;}

        printf("%d!",temp);

        while(!st.empty()){

            temp = st.top();
            st.pop();

            printf("+%d!",temp);
        }

        printf("\n");
    }
    return 0;
}
