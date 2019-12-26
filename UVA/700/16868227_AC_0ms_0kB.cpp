// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int ar[10005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , c = 0;
    while(cin >> n){

        if(n==0)break;
        memset(ar , 0 , sizeof(ar));

        for(int i=0;i<n;i++){

            int in1 , in2 , in3;
            cin >> in1 >> in2 >> in3;

            int now = in1-in2;
            int t = in3-in2;
            ar[in1]++;
            for(int j=0;j*t+now+in3<=10000;j++){

                ar[j*t+now+in3]++;
            }
        }

        int ans = -1;

        for(int i=0;i<10000;i++){

            if(ar[i]==n){

                ans = i;
                break;
            }
        }

        cout << "Case #" << ++c << ":" << endl;
        if(ans==-1)cout << "Unknown bugs detected." << endl;
        else cout << "The actual year is " << ans << "." << endl;
        cout << endl;
    }

    return 0;
}
