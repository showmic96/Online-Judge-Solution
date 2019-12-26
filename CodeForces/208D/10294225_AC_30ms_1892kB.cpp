// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct myStruct{

    ll value , idx;

} data[5];

bool cmp(myStruct A , myStruct B)
{
    return A.value > B.value;
}

int main(void)
{
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll>v;

    for(int i=0;i<n;i++){

        ll in;
        cin >> in;
        v.push_back(in);
    }

    for(int i=0;i<5;i++){

        cin >> data[i].value;
        data[i].idx = i;
    }

    sort(data , data+5 , cmp);

    ll sum = 0;
    ll ans[5];

    memset(ans , 0 , sizeof(ans));

    for(int i=0;i<n;i++){

        sum+=v[i];

        for(int j=0;j<5;j++){

            while(data[j].value<=sum){

                ll temp = sum/data[j].value;

                sum-=(data[j].value*temp);
                ans[data[j].idx]+=temp;
            }
        }
    }

    for(int i=0;i<5;i++)cout << ans[i] << " ";
    cout << endl;
    cout << sum << endl;

    return 0;
}
