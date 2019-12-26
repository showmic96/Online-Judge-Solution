// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string ar;

void print(string temp)
{
    bool check = false;
    int last = -1;
    for(int i=0;i<temp.size();i++){

        if(ar[i]!=' ')last = i;
    }
    for(int i=0;i<=last;i++){

        if(temp[i]==' '&&check==false)continue;
        check = true;
        cout << temp[i];
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    while(getline(cin , ar)){

        bool check = true;

        int si = ar.size();
        vector<int>v;
        v.push_back(0);

        for(int i=0;i<si;i++){

            if(ar[i]==' ')continue;

            if(ar[i]>='0'&&ar[i]<='9'){

                if(v.size()>0){

                    if(v[v.size()-1]==10)check = false;
                }
                v.push_back(ar[i]-'0');
                continue;
            }
            if(ar[i]=='X'){
                if(v.size()>0){

                    if(v[v.size()-1]==10)check = false;
                }
                v.push_back(10);
                continue;
            }
            if(ar[i]=='-')continue;
            check = false;
        }

        if(v.size()!=11)check = false;

        for(int i=1;i<v.size();i++){

            v[i] = v[i-1] + v[i];
        }
        for(int i=1;i<v.size();i++){

            v[i] = v[i-1] + v[i];
        }

        if(v[10]%11!=0)check = false;
        print(ar);

        if(check)cout << " is correct." << '\n';
        else cout << " is incorrect." << '\n';
    }
    return 0;
}
