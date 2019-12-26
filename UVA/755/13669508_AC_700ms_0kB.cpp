// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string get(char x)
{
    if(x=='A'||x=='B'||x=='C')return "2";
    if(x=='D'||x=='E'||x=='F')return "3";
    if(x=='G'||x=='H'||x=='I')return "4";
    if(x=='J'||x=='K'||x=='L')return "5";
    if(x=='M'||x=='N'||x=='O')return "6";
    if(x=='P'||x=='R'||x=='S')return "7";
    if(x=='T'||x=='U'||x=='V')return "8";
    if(x=='W'||x=='X'||x=='Y')return "9";
    string temp = "";
    temp+=x;
    if(x=='Q'||x=='Z')return temp;
    if(x>='0'&&x<='9')return temp;
    return "";
}

string process(string ar)
{
    string temp =  "";

    for(int i=0;i<ar.size();i++){

        temp+=get(ar[i]);
    }

    return temp;
}

string fin(string ar)
{
    string temp = "";
    for(int i=0;i<ar.size();i++){

        if(i==3)temp+="-";
        temp+=ar[i];
    }
    return temp;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    bool blank = false;

    int t;
    cin >> t;

    while(t--){

        if(blank)cout << endl;
        blank = true;

        int n;
        cin >> n;

        map<string,int>mp;
        set<string>st;
        set<string>::iterator it;

        for(int i=0;i<n;i++){

            string ar;
            cin >> ar;

            ar = process(ar);
            mp[ar]++;
            st.insert(ar);
        }
        
        bool check = false;
        
        for(it=st.begin();it!=st.end();it++){

            if(mp[*it]>1){
                cout << fin(*it) << " " << mp[*it] << endl;
                check = true;
            }
        }
        
        if(check==false)cout << "No duplicates." << endl;
    }
    return 0;
}
