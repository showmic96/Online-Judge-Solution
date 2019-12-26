// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string ar;
    cin >> ar;

    int si = ar.size();

    int counter = 0;

    stack<char>st;

    for(int i=0;i<si;i++){

        if(ar[i]=='(')st.push(ar[i]);
        else{

            if(st.empty())continue;
            counter++;
            st.pop();
        }
    }

    cout << counter*2 << endl;

    return 0;
}
