// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int fr[26];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    memset(fr , 0 , sizeof(fr));
    string ar , br;
    int n;
    cin >> n >> br >> ar;

    for(int i=0;i<n;i++){

        fr[ar[i]-'a']++;
    }

    for(int i=0;i<n;i++){

        fr[br[i]-'a']--;
    }

    for(int i=0;i<26;i++){

        if(fr[i]!=0){

            cout << -1 << endl;
            return 0;
        }
    }

    vector<int>ans;

    for(int i=0;i<n;i++){

        for(int j=i;j<n;j++){

            if(ar[i]==br[j]&&i!=j){

                for(int k=j;k>i;k--)ans.push_back(k);
                char x = br[j];

                for(int k=j;k>i;k--){

                    br[k] = br[k-1];
                }

                br[i] = x;
                break;
            }
        }
    }

    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++){

        if(i>0)cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
