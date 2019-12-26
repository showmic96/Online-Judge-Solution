// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char ar[] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};

int main(void)
{
    int t;
    cin >> t;
    while(t--){

        string s;
        cin >> s;

        bool check = true;

        for(int i=0;i<s.size();i++){

            bool c = false;

            for(int j=0;j<11;j++){

                if(s[i]==ar[j])c=true;
            }

            if(c==false)check = false;
        }

        for(int i=0;i<s.size();i++){

            if(s[i]!=s[s.size()-i-1])check = false;
        }

        if(check)cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
