// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string ar;
int n;

ll dp[88][10][2][2];

ll f(int i , int last , int smaller , int zero)
{
    if(i==n){

        if(zero)return 1;
        return 0;
    }
    if(dp[i][last][smaller][zero]!=-1)return dp[i][last][smaller][zero];

    int lim = ar[i]-'0';
    if(smaller==1)lim = 9;

    ll value = 0;

    for(int j=0;j<=lim;j++){

        if(j<lim){

            if(j>=last){

                if(j>0)value+=f(i+1 , j , 1 , 1);
                else value+=f(i+1 , j , 1 , zero);
            }
        }

        else{

            if(j>=last){

                if(j>0)value+=f(i+1 , j , smaller , 1);
                else value+=f(i+1 , j , smaller , zero);
            }
        }
    }

    return dp[i][last][smaller][zero] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        cin >> ar;
        n = ar.size();

        bool check = true;

        for(int i=1;i<n;i++){

            if(ar[i]<ar[i-1])check = false;
        }

        if(check){

            memset(dp , -1 , sizeof(dp));

            cout << f(0 , 0 , 0 , 0) << endl;
        }

        else cout << -1 << endl;
    }

    return 0;
}
