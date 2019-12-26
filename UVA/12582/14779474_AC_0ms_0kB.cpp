// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int>edges[26];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t , c = 0;
    cin >> t;
    while(t--){

        string ar;
        cin >> ar;
        stack<char>st;
        set<char>s;

        for(int i=0;i<26;i++)edges[i].clear();

        for(int i=0;i<ar.size();i++){

            s.insert(ar[i]);

            if(st.empty())st.push(ar[i]);
            else if(st.top()==ar[i]){

                st.pop();
            }
            else{

                edges[st.top()-'A'].push_back(ar[i]-'A');
                edges[ar[i]-'A'].push_back(st.top()-'A');
                st.push(ar[i]);

            }
        }

        cout << "Case " << ++c << endl;
        for(set<char>::iterator it = s.begin();it!=s.end();it++){

            cout << *it << " = " << edges[*it-'A'].size() << endl;
        }
    }
    return 0;
}
