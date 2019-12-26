// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[1005];

bool palin(string ar)
{
    for(int i=0;i<ar.size()/2;i++){

        if(ar[i]!=ar[ar.size()-i-1])return false;
    }
    return true;
}

int main(void)
{
    while(scanf("%s",&s)==1){

        string ar(s);
        set<string>st;

        for(int i=0;i<ar.size();i++){

            string temp = "";

            for(int j=i;j<ar.size();j++){

                temp+=ar[j];
                if(palin(temp)==true)st.insert(temp);
            }
        }

        printf("The string '%s' contains %d palindromes.\n",s , (int)st.size());
    }

    return 0;
}
