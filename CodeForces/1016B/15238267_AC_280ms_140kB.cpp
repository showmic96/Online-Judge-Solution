// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ar[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , m , q;
    cin >> n >> m >> q;

    string s , t;
    cin >> s >> t;

    memset(ar , 0 , sizeof(ar));

    for(int i=0;i<n;i++){

        string temp = "";

        for(int j=i;j<n;j++){

            temp+=s[j];
            if(temp[temp.size()-1]!=t[temp.size()-1])break;
            if(temp.size()==t.size()){

                ar[i+1] = 1;
                break;
            }
        }
    }
    for(int i=1;i<=1000;i++)ar[i]+=ar[i-1];

    while(q--){

        int in1 , in2;
        cin >> in1 >> in2;

        in2-=t.size()-1;

        if(in2<in1)cout << 0 << endl;
        else cout << ar[in2]-ar[in1-1] << endl;
    }

    return 0;
}
