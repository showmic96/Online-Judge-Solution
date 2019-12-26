// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string ar;
    while(cin >> ar){

        int ans = 1e9;

        for(int i=1;i<=10000;i++){

            vector<int>v;

            for(int j=0;j<ar.size();j++){

                int temp = ar[j]-'A'+i;
                vector<int>t;
                while(temp){

                    t.push_back(temp%10);
                    temp/=10;
                }

                for(int k=t.size()-1;k>=0;k--){
                    v.push_back(t[k]);
                }
            }

            while(v.size()>2){

                vector<int>t;

                for(int j=0;j<v.size()-1;j++){

                    t.push_back((v[j]+v[j+1])%10);
                }

                if(t.size()==3){

                    if(t[0]==1&&t[1]==0&&t[2]==0){

                        ans = i;
                        break;
                    }
                }

                v = t;
            }

            if(ans!=1e9)break;
        }

        if(ans==1e9)cout << ":(" << endl;
        else cout << ans << endl;
    }

    return 0;
}
