// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    int ar[105];
    memset(ar , 0 , sizeof(ar));
    vector<int>v;

    for(int i=0;i<n;i++){

        int in;
        cin >> in;
        v.push_back(in);
        ar[in]+=1;
    }

    int one = 0 , more = 0;

    for(int i=1;i<=100;i++){

        if(ar[i]==1)one++;
        else if(ar[i]>2)more++;
    }

    if(one%2==0||(one%2==1&&more>=1)){

        cout << "YES" << endl;
        string ans = "";
        for(int i=0;i<n;i++)ans+="A";

        if(one%2==1){

            for(int i=0;i<n;i++){

                if(ar[v[i]]>2){
                    ans[i] = 'B';
                    break;
                }
            }
        }

        one/=2;
        while(one){

            one--;
            for(int i=0;i<n;i++){

                if(ar[v[i]]==1){
                    ans[i] = 'B';
                    ar[v[i]] = 0;
                    break;
                }
            }
        }

        cout << ans << endl;
    }
    else cout << "NO" << endl;

    return 0;
}
