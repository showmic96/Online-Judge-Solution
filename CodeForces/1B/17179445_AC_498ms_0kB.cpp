// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool found(string ar)
{
    for(int i=0;i<ar.size();i++){

        if(ar[i]=='C')return true;
    }
    return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    while(n--){

        string ar;
        cin >> ar;

        if(ar[0]=='R'&&(ar[1]>='0'&&ar[1]<='9')&&found(ar)==true){

            int i = 1;
            ll n1 = 0 , n2 = 0;

            for(;i<ar.size();i++){

                if(ar[i]<'0'||ar[i]>'9')break;
                n1*=10;
                n1+=ar[i]-'0';
            }
            for(i++;i<ar.size();i++){

                n2*=10;
                n2+=ar[i]-'0';
            }

            string ans="";

            while(n2){

                int t = (n2%26)-1;
                if(t<0)t+=26;
                if(n2%26==0)n2--;
                ans+='A'+t;
                n2/=26;
            }
            reverse(ans.begin() , ans.end());
            cout << ans << n1 << endl;
        }
        else{

            int i = 0;
            ll n1 = 0 , n2 = 0;

            while(ar[i]>='A'&&ar[i]<='Z'){

                n2*=26;
                n2+=(ar[i]-'A'+1);
                i++;
            }

            for(;i<ar.size();i++){

                n1*=10;
                n1+=ar[i]-'0';
            }

            cout << "R" << n1 << "C" << n2 << endl;
        }
    }

    return 0;
}
