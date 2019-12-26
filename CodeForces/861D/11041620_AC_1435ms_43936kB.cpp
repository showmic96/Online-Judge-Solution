// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 70000 + 9;

unordered_map <string, int>mp;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string>v;
    vector<string>data;

    for(int i=0;i<n;i++){

        string ar;
        cin >> ar;

        v.push_back(ar);

        for(int j=0;j<9;j++){

            string temp = "";

            for(int k=j;k<9;k++){

                temp+=ar[k];
                mp[temp]++;
            }
        }
    }

    for(int i=0;i<n;i++){

        data.clear();

        int mi = 1e9;
        string ans;

        for(int j=0;j<9;j++){

            string temp = "";

            for(int k=j;k<9;k++){

                temp+=v[i][k];
                mp[temp]--;
                data.push_back(temp);
            }
        }

        for(int j=0;j<9;j++){

            string temp = "";

            for(int k=j;k<9;k++){

                temp+=v[i][k];
                if(mp[temp]==0){

                    if(temp.size()<mi){

                        mi = temp.size();
                        ans = temp;
                    }
                }
            }
        }

        cout << ans << endl;

        int si = data.size();

        for(int i=0;i<si;i++){

            mp[data[i]]++;
        }
    }

    return 0;
}
