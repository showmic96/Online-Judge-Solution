// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    vector<string>v , ans;
    cin >> n;

    for(int i=0;i<n;i++){

        string ar;
        cin >> ar;
        v.push_back(ar);
    }
    reverse(v.begin() , v.end());
    ans.push_back(v[0]);

    for(int i=1;i<n;i++){

        int si1 = v[i].size();
        int j = 0;
        bool found = false;
        string temp = "";

        for(int i1=0;i1<si1;i1++){

            if(found==false&&v[i][i1]==ans[i-1][j]){
                temp+=v[i][i1];
                j++;
                if(j==ans[i-1].size())break;
            }
            else if(found==false&&v[i][i1]<ans[i-1][j]){

                found = true;
                temp+=v[i][i1];
            }
            else if(found==false&&v[i][i1]>ans[i-1][j])break;
            else temp+=v[i][i1];
        }
        ans.push_back(temp);
    }

    reverse(ans.begin() , ans.end());
    for(auto it : ans)cout << it << endl;

    return 0;
}
