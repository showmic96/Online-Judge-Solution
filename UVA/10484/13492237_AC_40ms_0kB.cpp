// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ll n , d;
    while(scanf("%lld %lld",&n , &d)==2){

        if(n==0&&d==0)break;

        int ar[110];
        memset(ar , 0 , sizeof(ar));

        for(int i=2;i<=n;i++){

            int temp = i;

            for(int j=2;j<=temp;j++){

                while(temp%j==0){

                    temp/=j;
                    ar[j]++;
                }
            }
        }

        bool check = true;

        for(int i=2;i<=100;i++){

            while(d%i==0){

                if(ar[i]==0){

                    check = false;
                    break;
                }

                ar[i]--;
                d/=i;
            }

            if(check==false)break;
        }

        if(check==false)printf("0\n");
        else{

            if(d>1&&d>100)printf("0\n");
            else{

                if(d>1)ar[d]--;

                ll ans = 1;

                for(int i=0;i<=100;i++){

                    ll temp = ar[i]+1;
                    ans*=temp;
                }

                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
