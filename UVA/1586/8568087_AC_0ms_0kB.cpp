// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    map<char , double > mp;
    mp['C'] = 12.01;
    mp['H'] = 1.008;
    mp['N'] = 14.01;
    mp['O'] = 16.00;
    double ans = 0;

    while(t--){

        string ar;
        cin >> ar;
        ans = 0;
        int si = ar.size();

        for(int i=0;i<si;i++){

            char x = ar[i];

            i++;
            int value = 0;

            while(ar[i]>='0'&&ar[i]<='9'){

                value*=10;
                value+=ar[i] - '0';
                i++;
            }

            if(value==0)value = 1;

            ans += mp[x] * 1.00 * value;

            i--;

        }

        printf("%.3lf\n",ans);
    }
    return 0;
}
