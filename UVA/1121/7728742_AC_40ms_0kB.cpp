// In the name of Allah the most Merciful .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e5+10;

int ar[MAX];

int main(void)
{
    ll n , lim;

    while(cin >> n >> lim){

        for(int i=0;i<n;i++)cin >> ar[i];

        int point1 = 0 , point2 = 0;
        ll temp = 0 , d = 0 , ans = 1e15;

        for(;point1!=n;point1++){

                while(temp<lim){

                    if(point2>=n)break;
                    temp+=ar[point2++];

                }

                if(temp>=lim){

                    if(ans>point2-point1){

                        ans = point2 - point1 ;
                    }
                }

            temp -=ar[point1];
        }

        if(ans==1e15)ans = 0;
        cout << ans << endl;
    }

    return 0;
}
