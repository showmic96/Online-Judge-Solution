// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        string s , t;
        cin >> s >> t;

        int si = s.size();

        long long ans = 0 , t_one = 0 , s_one = 0 , t_zero = 0 , s_zero = 0;

        for(int i=0;i<si;i++){

            if(s[i]=='1')s_one++;
            if(t[i]=='1')t_one++;
            if(s[i]=='0')s_zero++;
            if(t[i]=='0')t_zero++;
        }

        for(int i=0;i<si;i++){

            if(s[i]!='?')continue;

            ans++;
            if(s_zero==t_zero){

                s_one++;
                s[i] = '1';
                continue;
            }

            else if(s_one==t_one){

                s_zero++;
                s[i]='0';
                continue;
            }

            if(t[i]=='1'){

                s[i] = '1';
                s_one++;
            }

            if(t[i]=='0'){

                s_zero++;
                s[i] = '0';
            }
        }


        for(int i=0;i<si;i++){

            if(s_one==t_one)break;

            if(s[i]=='0'&&t[i]=='1'){

                s_zero--;
                s_one++;

                s[i] = '1';
                ans++;
            }
        }

        int counter = 0;

        for(int i=0;i<si;i++){

            if(s[i]!=t[i])counter++;
        }

        ans+= (counter/2);

        if(s_one > t_one)ans = -1;

        printf("Case %d: %lld\n",++c,ans);

    }

    return 0;
}
