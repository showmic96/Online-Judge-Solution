// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    string s , t;
    cin >> n >> s >> t;
    string ar = "abc";
    vector<string>v;
    do{
        string temp = "";
        for(int i=0;i<n;i++)temp+=ar;
        v.push_back(temp);
        string temp2 = string(n , ar[0]) + string(n , ar[1]) + string(n , ar[2]);
        v.push_back(temp2);
    }while(next_permutation(ar.begin() , ar.end()));
    for(auto br:v){
        if(br.find(s)==string::npos&&br.find(t)==string::npos){
            cout << "YES" << endl << br << endl;
            break;
        }
    }

    return 0;
}
