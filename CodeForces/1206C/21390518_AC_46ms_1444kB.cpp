// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    if(n%2==0)cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        vector<int>v1 , v2;
        int t = 1;
        for(int i=1;i<=2*n;i+=2){
            if(t%2==1){
                v1.push_back(i);
                v2.push_back(i+1);
            }
            else{
                v1.push_back(i+1);
                v2.push_back(i);
            }
            t++;
        }
        for(int i=0;i<v1.size();i++)cout << v1[i] << " ";
        for(int i=0;i<v2.size();i++)cout << v2[i] << " ";
    }

    return 0;
}
