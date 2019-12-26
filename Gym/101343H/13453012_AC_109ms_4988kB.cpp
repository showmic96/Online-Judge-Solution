// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> input , v;
int last[55];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(last , -1 , sizeof(last));

    int n;
    cin >> n;

    for(int i=0;i<n;i++){

        int in;
        cin >> in;
        input.push_back(in);
    }

    for(int i=n-1;i>=0;i--){

        int ans = -1 , mx = n;

        for(int j=input[i]+1;j<=50;j++){

            if(last[j]==-1)continue;

            if(mx>last[j]){

                mx = last[j];
                ans = j;
            }
        }

        last[input[i]] = i;

        v.push_back(ans);
    }

    for(int i=0;i<v.size();i++){

        cout << v[n-i-1] << " ";
    }

    return 0;
}
