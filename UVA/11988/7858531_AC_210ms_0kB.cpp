// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    //freopen("input.txt","r",stdin);
    string ar;
    while(getline(cin , ar)){

        int si = ar.size();
        list<char>l;
        list<char>::iterator it = l.begin();
        for(int i=0;i<si;i++){

            if(ar[i]=='[')it = l.begin();
            else if(ar[i]==']')it = l.end();
            else{

                l.insert(it , ar[i]);
            }
        }

        for(it=l.begin();it!=l.end();it++)cout << *it;
        cout << endl;
    }
    return 0;
}