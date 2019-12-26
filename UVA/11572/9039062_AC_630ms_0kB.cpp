// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while(t--){

        int n;
        cin >> n;

        vector<long long>v;

        for(int i=0;i<n;i++){

            long long in;
            cin >> in;
            v.push_back(in);
        }

        map<long long , int>mp;
        deque<long long>dq;

        int p1 = 0 , p2 = 0;
        int counter = 0;
        for(int i=0;i<n;i++){

            if(mp[v[i]]==1){

                int temp = dq.front();
                dq.pop_front();
                mp[temp] = 0;

                while(temp!=v[i]){
                    //cout << temp << " " << v[i] << endl;
                    temp = dq.front();
                    dq.pop_front();
                    mp[temp] = 0;
                }
            }

            mp[v[i]] = 1;

            dq.push_back(v[i]);
            int si = dq.size();
            counter = max(counter , si);
        }

        cout << counter << endl;

    }
    return 0;
}
