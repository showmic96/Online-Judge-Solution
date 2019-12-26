// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

bool cmp(int a , int b){return a > b;}

int main(void)
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++){

        int n , k;
        cin >> n >> k;

        int data[n];
        long long ans = 0;

        for(int j =0;j<n;j++)cin >> data[j];

        for(int j=0;j<n;j++){

            int in;
            cin >> in;

            data[j] = in - data[j];
        }

        sort(data , data+n , cmp);

        for(int j=0;j<n;j++){

            if(data[j]<0){

                if(j>=n-k)break;
            }

            ans+=data[j];
        }

        printf("Case %d: " , i+1);
        if(ans>0)cout << ans << endl;
        else cout << "No Profit" << endl;
    }
    return 0;
}
