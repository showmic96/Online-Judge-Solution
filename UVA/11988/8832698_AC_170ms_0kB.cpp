#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    string ar;
    while(getline(cin ,ar)){

        int si = ar.size();
        int b = 0;
        list<string>ans;
        string temp = "";
        for(int i=0;i<si;i++){

            if(ar[i]=='['){

                if(b==0||b==2)ans.push_back(temp);
                else ans.push_front(temp);
                b = 1;
                temp = "";
            }

            else if(ar[i]==']'){

                if(b==0||b==2)ans.push_back(temp);
                else ans.push_front(temp);
                b = 2;
                temp = "";
            }

            else temp+=ar[i];
        }

        if(b==0||b==2)ans.push_back(temp);
        else ans.push_front(temp);

        list<string>::iterator it;

        for(it = ans.begin();it!=ans.end();it++)cout << *it;
        cout << endl;
    }
    return 0;
}
