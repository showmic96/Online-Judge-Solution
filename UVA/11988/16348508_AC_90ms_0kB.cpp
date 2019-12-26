// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    string ar;
    while(getline(cin ,ar)){

        int si = ar.size();
        int state = 0;

        list<string>l;
        string temp = "";

        for(int i=0;i<si;i++){

            if(ar[i]=='['){

                if(state==0||state==2)l.push_back(temp);
                else l.push_front(temp);
                state = 1;
                temp = "";
            }

            else if(ar[i]==']'){

                if(state==0||state==2)l.push_back(temp);
                else l.push_front(temp);
                state = 2;
                temp = "";
            }

            else temp+=ar[i];
        }

        if(state==0||state==2)l.push_back(temp);
        else l.push_front(temp);

        for(auto it = l.begin();it!=l.end();it++)cout << *it;
        cout << endl;
    }
    return 0;
}
