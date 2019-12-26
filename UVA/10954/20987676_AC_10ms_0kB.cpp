// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    priority_queue<int>pq;

    int n , in;
    while(cin >> n){
        if(!n)break;
        for(int i=0;i<n;i++){
            cin >> in;
            pq.push(-in);
        }
        ll ans = 0;
        int temp3;
        while(!pq.empty()){
            int temp1 = -pq.top();
            pq.pop();
            int temp2 = -pq.top();
            pq.pop();
            temp3 = temp1+temp2;
            ans+=temp3;
            if(pq.empty()==true)break;
            pq.push(-temp3);

        }
        cout << ans << endl;
    }

    return 0;
}
