// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);

    int t;
    cin >> t;

    //getchar();

    while(t--){

        int n;
        cin >> n;

        vector<ll>v;

        for(int i=0;i<=n;i++){

            ll in;
            cin >> in;
            v.push_back(in);
        }

        int d , k;
        int counter = 0;
        cin >> d >> k;//scanf("%d %d",&d , &k);


        for(int i=1;;i++){

            ll temp = 0;

            int si = v.size();

            for(int j=0;j<si;j++){

                temp+=v[j]*pow(i , j);
            }

            counter+=i*d;
            if(counter>=k){

                cout << temp << endl;
                break;
            }
        }
    }

    return 0;
}
