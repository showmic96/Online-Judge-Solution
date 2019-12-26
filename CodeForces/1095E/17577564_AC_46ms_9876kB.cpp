// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e6+9;
int fre[MAX] , mi[MAX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    string ar;
    cin >> n >> ar;

    if(n%2==1)cout << 0 << endl;
    else{

        int now = 0;
        for(int i=0;i<n;i++){

            if(ar[i]=='(')now++;
            else now--;

            fre[i] = now;

        }


        mi[n-1] = fre[n-1];
        for(int i=n-2;i>=0;i--){

            mi[i] = min(mi[i+1] , fre[i]);
        }

        int ans = 0 , temp = 0;
        for(int i=0;i<n;i++){

            if(ar[i]=='('){

                if(mi[i]>=2&&now==2)ans++;
                temp++;
            }
            else{

                if(mi[i]>=-2&&now==-2)ans++;
                temp--;
            }

            if(temp<0)break;
        }

        cout << ans << endl;
    }

    return 0;
}
