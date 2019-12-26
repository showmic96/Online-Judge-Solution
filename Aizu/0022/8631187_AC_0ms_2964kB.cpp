// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n;
    while(cin >> n){

        if(!n)break;

        ll sum = 0 , mx = 0;

        cin >> sum;
        mx = sum;
        if(sum<0)sum = 0;

        for(int i=1;i<n;i++){

            int in;
            cin >> in;

            sum+=in;

            mx = max(sum , mx);

            if(sum<0)sum = 0;
        }

        cout << mx << endl;
    }
    return 0;
}
