// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int l , r , a;
    cin >> l >> r >> a;

    int ans = 0;

    for(int i=2;;i+=2){

        int temp = a;
        int t = i/2;

        if(t>l){

            temp-=t-l;
        }

        if(t>r){

            temp-=t-r;
        }

        if(temp<0)break;
        ans = i;
    }

    cout << ans << endl;

    return 0;
}
