// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 9;
int ar[MAX+9] , dis[MAX+9] , dis2[MAX+9];

int main(void)
{
    int n , m;
    cin >> n >> m;

    for(int i=1;i<=n;i++)cin >> ar[i];
    ar[0] = 0;
    dis[0] = 0;
    dis2[0] = 0;

    map<int, int>mp;

    int c = 0;

    for(int i=1;i<=n;i++){

        mp[ar[i]]++;
        if(mp[ar[i]]==1){
            c++;
        }

        dis[i] = c;
    }

    c = 0;

    for(int i=1;i<=n;i++){

        mp[ar[i]]--;

        if(mp[ar[i]]==0){

            c++;
        }

        dis2[i] = c;
    }

    while(m--){

        int in;
        cin >> in;
        cout << dis[n] - dis2[in-1] << endl;
    }

    return 0;
}
