// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string ar;
    while(getline(cin ,ar)){
        int b = 0;
        list<string>ans;
        string temp = "";
        for(auto i:ar){
            if(i=='['){
                if(b==0||b==2)ans.push_back(temp);
                else ans.push_front(temp);
                b = 1;
                temp = "";
            }
            else if(i==']'){
                if(b==0||b==2)ans.push_back(temp);
                else ans.push_front(temp);
                b = 2;
                temp = "";
            }
            else temp+=i;
        }
        if(b==0||b==2)ans.push_back(temp);
        else ans.push_front(temp);
        for(auto it:ans)cout << it;
        cout << endl;
    }
    return 0;
}
