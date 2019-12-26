// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<string>v;
int n , k;
string ar;

void f(int i , int counter , string br)
{
    if(i==n){

        if(counter<=k)v.push_back(br);
        return ;
    }

    if(ar[i]=='A')f(i+1 , counter , br+"A");
    else f(i+1 , counter+1 , br+"A");

    if(ar[i]=='C')f(i+1 , counter , br+"C");
    else f(i+1 , counter+1 , br+"C");

    if(ar[i]=='G')f(i+1 , counter , br+"G");
    else f(i+1 , counter+1 , br+"G");

    if(ar[i]=='T')f(i+1 , counter , br+"T");
    else f(i+1 , counter+1 , br+"T");
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){

        cin >> n >> k >> ar;
        v.clear();
        f(0 , 0 , "");
        //v.push_back(ar);
        //sort(v.begin() , v.end());
        cout << v.size() << endl;
        for(int i=0;i<v.size();i++)cout << v[i] << endl;
    }
    return 0;
}
