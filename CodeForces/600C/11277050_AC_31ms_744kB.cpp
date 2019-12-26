// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string ar;
    cin >> ar;

    int fr[26];

    memset(fr , 0 , sizeof(fr));

    int si = ar.size();

    for(int i=0;i<si;i++){

        fr[ar[i]-'a']++;
    }

    vector<int>store;

    for(int i=0;i<26;i++){

        if(fr[i]%2==1){

            store.push_back(i);
        }
    }

    string ans = "";

    if(store.size()==1&&si%2==1){

        fr[store[0]]--;

        for(int i=0;i<26;i++){

            for(int j=0;j<fr[i]/2;j++){

                ans+='a'+i;
            }

        }

        ans+='a'+store[0];

        for(int i=25;i>=0;i--){

            for(int j=0;j<fr[i]/2;j++){

                ans+='a'+i;
            }
        }
    }

    else if(store.size()==0){

        for(int i=0;i<26;i++){

            for(int j=0;j<fr[i]/2;j++){

                ans+='a'+i;
            }

        }

        for(int i=25;i>=0;i--){

            for(int j=0;j<fr[i]/2;j++){

                ans+='a'+i;
            }
        }

    }

    else{

        si = store.size();

        for(int i=0;i<si/2;i++){

            fr[store[i]]++;
            fr[store[si-i-1]]--;
        }

        for(int i=0;i<26;i++){

            for(int j=0;j<fr[i]/2;j++){

                ans+='a'+i;
            }
        }

        if(ar.size()%2==1)ans+='a'+store[si/2];

        for(int i=25;i>=0;i--){

            for(int j=0;j<fr[i]/2;j++){

                ans+='a'+i;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
