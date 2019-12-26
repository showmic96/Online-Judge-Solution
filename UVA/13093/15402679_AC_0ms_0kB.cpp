// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string ar , br;
    while(getline(cin , ar)){

        getline(cin , br);

        string t1 = "" , t2 = "";

        stringstream s1(ar);
        string temp;

        while(s1>>temp){

            t1+=temp[0];
        }

        stringstream s2(br);

        while(s2>>temp){

            t2+=temp[0];
        }

        if(t1==t2)cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}
