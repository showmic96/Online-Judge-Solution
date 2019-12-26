// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 2e5+9;
int l[MAX] , r[MAX];

int main(void)
{
    ios::sync_with_stdio();
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int in;
        cin >> in;
        v.push_back(in);
    }
    l[n-1] = 1;
    for(int i=n-2;i>=0;i--){
        if(v[i]<v[i+1]){
            l[i] = l[i+1]+1;
        }
        else{
            l[i] = 1;
        }
    }
    r[0] = 1;
    for(int i=1;i<n;i++){
        if(v[i]<v[i-1]){
            r[i] = r[i-1]+1;
        }
        else{
            r[i] = 1;
        }
    }
    string ans = "";
    int cur = 0 , i = 0 , j = n-1;
    while(true){
        if(i>j)break;
        if(v[i]>cur&&v[j]>cur){
            if(v[i]==v[j]){
                if(l[i]>r[j]){
                    cur = v[i];
                    ans+="L";
                    i++;
                }
                else{
                    cur = v[j];
                    ans+="R";
                    j--;
                }
            }
            else{
                if(v[i]<v[j]){
                    cur = v[i];
                    ans+="L";
                    i++;
                }
                else{
                    cur = v[j];
                    ans+="R";
                    j--;
                }
            }
        }
        else if(v[i]>cur){
            cur = v[i];
            ans+="L";
            i++;
        }
        else if(v[j]>cur){
            cur = v[j];
            ans+="R";
            j--;
        }
        else break;
    }
    cout << ans.size() << endl << ans << endl;
    return 0;
}
