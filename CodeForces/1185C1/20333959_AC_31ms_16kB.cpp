// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ar[105];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n , m , sum = 0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        ll in;
        cin >> in;
        sum+=in;
        if(sum>m){
            ll counter = 0 , temp = sum;
            for(int j=100;j>=1;j--){
                if(temp-ar[j]*(ll)j<=m){
                    ll rem = temp-m;
                    counter+=(rem+j-1)/j;
                    break;
                }
                else{
                    temp-=ar[j]*(ll)j;
                    counter+=ar[j];
                }
            }
            cout << counter << " ";
        }
        else cout << 0 << " ";
        ar[in]++;
    }

    return 0;
}
