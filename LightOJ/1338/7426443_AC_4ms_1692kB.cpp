// In the name of Allah the Lord of the worlds .


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char f(char x)
{
    if(x>='A'&&x<='Z')x+=32;

    return x;
}

int main(void)
{
    int a;
    string ar;
    cin >> a;
    scanf("\n");
    map<char, int>maping1;
    map<char,int>maping2;

    for(int i=0;i<a;i++){

        maping1.clear();
        maping2.clear();

        getline(cin , ar);

        int si = ar.size();

        for(int j=0;j<si;j++){

            if(ar[j]==' ')continue;
            maping1[f(ar[j])]++;
        }
        ar="";

        getline(cin , ar);

        si = ar.size();
        bool check = true;

        for(int j=0;j<si;j++){

            if(ar[j]==' ')continue;
            maping2[f(ar[j])]++;
        }

        printf("Case %d: ",i+1);

        for(int j=0;j<26;j++){

            if(maping1['a'+j]!=maping2['a'+j])check = false;
        }

        if(check==false)cout << "No" << endl;

        else cout << "Yes" << endl;
    }

    return 0;
}
