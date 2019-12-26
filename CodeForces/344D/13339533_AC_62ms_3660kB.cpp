// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string ar;
    cin >> ar;

    stack<char>st;

    for(int i=0;i<ar.size();i++){

        if(st.empty()||st.top()!=ar[i]){

            st.push(ar[i]);
        }
        else st.pop();
    }

    if(st.empty())cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
