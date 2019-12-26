// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    t = 1;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n);
        for(auto &x:v)cin >> x;
        int i , j , cur = n;
        for(int i1=0;i1<n;i1++){
            if(v[i1]==n){
                i = i1-1;
                j = i1+1;
                break;
            }
        }
        while(true){
            if(i==-1&&j==n)break;
            else if(i==-1){
                if(v[j]<cur){
                    cur = v[j];
                    j++;
                }
                else break;
            }
            else if(j==n){
                if(v[i]<cur){
                    cur = v[i];
                    i--;
                }
                else break;
            }
            else if(v[i]>v[j]){
                if(v[i]<cur){
                    cur = v[i];
                    i--;
                }
                else break;
            }
            else{
                if(v[j]<cur){
                    cur = v[j];
                    j++;
                }
                else break;
            }
        }
        if(i==-1&&j==n)cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
