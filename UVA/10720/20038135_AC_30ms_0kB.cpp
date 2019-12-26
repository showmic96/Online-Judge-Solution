// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    while(cin >> n){
        if(!n)break;
        bool possible = true;
        priority_queue<int>pq;
        vector<int>v;
        for(int i=0;i<n;i++){
            int in;
            cin >> in;
            if(in>0)pq.push(in);
        }
        while(!pq.empty()){
            int now = pq.top();
            pq.pop();
            if(now>pq.size()){
                possible = false;
                break;
            }
            v.clear();
            for(int i=0;i<now;i++){
                v.push_back(pq.top()-1);
                pq.pop();
            }
            for(int i=0;i<now;i++){
                if(v[i]>0)pq.push(v[i]);
            }
        }
        if(possible)cout << "Possible" << endl;
        else cout << "Not possible" << endl;
    }
    return 0;
}
