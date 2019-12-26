// In the name of Allah the most Merciful

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll input [30] , CAP , si , dp[100][1000000];

bool check;


void set_up()
{
    for(int i=0;i<30;i++){

        for(int j=0;j<1000;j++){

            dp[i][j] = -1;
        }
    }
}

ll f(ll i , ll w)
{
    if(i==si) return 0;
    if(w==CAP)return 1;

    if(dp[i][w]!=-1)return dp[i][w];

    ll r1=0 , r2=0;

    if(w+input[i]<=CAP){

        r1 = f(i+1 , input[i]+w);
    }

    else r1 = 0;

    r2 = f(i+1 , w);

    return dp[i][w] = (r1 | r2);
}

int main(void)
{
    ll a , in , sum;
    string ar;

    cin >> a;
    getchar();
    while(a--){

        sum = 0;
        ar="";
        si = 0;

        getline(cin , ar);

            stringstream ss(ar);

            while(ss>> in){

                //cout << in << endl;

                input[si++] = in;
                sum+=in;
                //cout << sum << endl;
            }




        if(sum%2==1){

            cout << "NO" << endl;
        }

        else{

            check = false;

            CAP = sum/2;

            set_up();

            ll l = f(0 , 0);
            //cout << CAP  << " " << sum << endl;
            if(l)cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}
