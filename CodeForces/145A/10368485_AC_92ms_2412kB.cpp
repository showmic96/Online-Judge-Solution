// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s , t;
    cin >> s >> t;

    int s_4 = 0 , s_7 = 0 , t_4 = 0 , t_7 = 0 , mis = 0 , counter = 0;

    int si = s.size();

    for(int i=0;i<si;i++){

        if(s[i]=='7')s_7++;
        else s_4++;

        if(t[i]=='7')t_7++;
        else t_4++;

        if(s[i]!=t[i])mis++;
    }

    counter+=abs(s_4-t_4);
    mis-=abs(s_4-t_4);

    counter+= mis/2;

    cout << counter << endl;

    return 0;
}
