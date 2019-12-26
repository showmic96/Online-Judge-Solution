// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while(t--){

        string ar;
        cin >> ar;

        int si = ar.size();

        char x;
        double value = 0;
        double ans = 0;

        map<char,double>mp;
        mp['C'] = 12.01;
        mp['H'] = 1.008;
        mp['O'] = 16.00;
        mp['N'] = 14.01;


        for(int i=0;i<si;i++){

            if(i==0){

                x = ar[i];
            }

            else if(ar[i]>='A'&&ar[i]<='Z'){

                if(value==0)value = 1;

                ans+=value*mp[x];

                x = ar[i];
                value=0;
            }

            else{

                value*=10;
                value+=ar[i]-'0';
            }
        }

        if(value==0)value = 1;

        ans+=value*mp[x];

        printf("%.3f\n",ans);
    }
    return 0;
}
