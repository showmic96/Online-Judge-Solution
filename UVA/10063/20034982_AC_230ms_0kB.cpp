// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string ar;
void f(int i , string temp)
{
    if(i==ar.size()){
        cout << temp << endl;
        return ;
    }
    char now = ar[i];
    for(int i1=0;i1<=temp.size();i1++){
        string s = temp;
        s.insert(s.begin()+i1 , now);
        f(i+1, s);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    bool blank = false;
    while(cin >> ar){
        if(blank)cout << endl;
        else blank = true;
        f(0 , "");
    }

    return 0;
}
