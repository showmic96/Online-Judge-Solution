// In the name of Allah the Lord of the worlds .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int a;
    cin >> a;

    string ar ;

    map<char,int>maping1;
    map<char,int>maping2;

    scanf("\n");

    while(a--){

        maping1.clear();
        maping2.clear();

        getline(cin , ar);

        int si = ar.size();

        for(int i=0;i<si/2;i++){

            maping1[ar[i]]++;
        }

        for(int i=0;i<si/2;i++){

            maping2[ar[si-1-i]]++;
        }

        bool check = true;

        for(int i=0;i<26;i++){

            if(maping1['a'+i]!=maping2['a'+i])check = false;
        }

        if(check==true)cout << "YES" << endl;
        else cout << "NO" << endl;

    }


    return 0;
}
