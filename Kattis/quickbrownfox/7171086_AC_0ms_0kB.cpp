#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 , MAX = 100010;
typedef long long ll;
typedef unsigned long long LL;



int main(void)
{
    int a;
    cin >> a;

    string ar;

    scanf("\n");
    map<char,int>maping;
    set<char>ans;
    set<char>::iterator it;
    while(a--){

        maping.clear();
        ans.clear();

        getline(cin, ar);

        int si = ar.size();

        for(int i=0;i<si;i++){

            if(ar[i]>='A'&&ar[i]<='Z')ar[i] = ar[i]+32;

            maping[ar[i]] = 1;
        }

        for(int i=0;i<26;i++){

            if(maping['a'+i]==0)ans.insert('a' + i);
        }

        if(ans.empty()==true)cout << "pangram" << endl;
        else{

            cout << "missing ";

            for(it=ans.begin();it!=ans.end();it++)cout << *it;
            cout << endl;
        }

    }

    return 0;
}
