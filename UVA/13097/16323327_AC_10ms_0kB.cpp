// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n , t;
    char x;
    while(cin >> n >> t >> x){

        cin.ignore();

        string s1 , s2 , s3;
        getline(cin , s1);
        getline(cin , s2);
        getline(cin , s3);

        string temp = "";

        for(int i=0;i<s2.size();i++){

            if(s2[i]=='|')temp+="|";
            else temp+=" ";
        }

        int now = 2*n;

        for(int i=0;i<s2.size();i++){

            if(s2[i]=='|')continue;

            if(x=='R')temp[(i+2*t)%now] = s2[i];
            else temp[(((i-2*t)%now)+now)%now] = s2[i];
        }

        cout << s1 << endl << temp << endl << s3 << endl;
    }
    return 0;
}
