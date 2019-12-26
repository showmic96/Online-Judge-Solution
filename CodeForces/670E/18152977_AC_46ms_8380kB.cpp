// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 5e5+9;
int l[MAX] , r[MAX] , v[MAX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , m , p;
    cin >> n >> m >> p;

    string ar , br;
    cin >> ar >> br;

    for(int i=0;i<=n;i++)l[i] = i+1;

    for(int i=n+1;i>=1;i--)r[i] = i-1;

    stack<int> st;

    for(int i=0;i<ar.size();i++){

        if(st.empty()){

            st.push(i+1);
        }
        else{

            if(ar[i]=='(')st.push(i+1);
            else{

                v[st.top()] = i+1;
                v[i+1] = st.top();
                st.pop();
            }
        }
    }
    for(int i=0;i<br.size();i++){
        if(br[i]=='L'){

            p = r[p];
        }
        else if(br[i]=='R'){

            p = l[p];
        }
        else{

            int t = v[p];

            if(t>p){
                l[r[p]] = l[t];
                r[l[t]] = r[p];

                if(l[t]<=n)p = l[t];
                else p = r[p];
            }
            else{

                l[r[t]] = l[p];
                r[l[p]] = r[t];

                if(l[p]<=n)p = l[p];
                else p = r[t];
            }
        }
    }

    for(int i=l[0];i<=n;i = l[i])cout << ar[i-1];
    cout << endl;

    return 0;
}
