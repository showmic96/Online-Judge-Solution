// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char get(char x)
{
    if(x=='3')return 'E';
    if(x=='0')return 'O';
    if(x=='1')return 'I';
    if(x=='4')return 'A';
    if(x=='9')return 'P';
    if(x=='2')return 'Z';
    if(x=='5')return 'S';
    if(x=='6')return 'G';
    if(x=='7')return 'T';
    if(x=='8')return 'B';
}

int main(void)
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);

    int t , c = 0;
    cin >> t;
    cin.ignore();
    while(t--){

        if(c>0)cout << endl;
        c++;

        string ar;
        while(getline(cin , ar)){

            if(ar=="")break;

            for(int i=0;i<ar.size();i++){

                if(ar[i]>='0'&&ar[i]<='9')cout << get(ar[i]);
                else cout << ar[i];
            }
            cout << endl;
        }
    }

    return 0;
}
