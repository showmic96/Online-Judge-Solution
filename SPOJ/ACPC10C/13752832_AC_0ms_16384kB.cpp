// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int Find(string ar)
{
    stack<char>st;
    int counter = 0 , mx = 0;

    for(int i=0;i<ar.size();i++){

        if(ar[i]==')'){

            char cur = st.top();
            st.pop();

            if(cur!='('){

                while(st.top()!='('){

                    char x = st.top();
                    st.pop();
                }

                st.pop();
                counter--;
                st.push(cur);
            }
        }

        else{

            st.push(ar[i]);
            if(ar[i]=='(')counter++;
            mx = max(mx , counter);
        }
    }

    return mx%2;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int c = 0;
    string ar;
    while(cin >> ar){

        if(ar=="()")break;

        stack<char>st;
        int counter = 0;
        int f = Find(ar);

        for(int i=0;i<ar.size();i++){

            if(ar[i]==')'){

                char cur = st.top();
                st.pop();

                if(cur!='('){

                    while(st.top()!='('){

                        char x = st.top();
                        st.pop();

                        if(counter%2!=f){

                            if(cur=='T'||x=='T')cur = 'T';
                            else cur = 'F';
                        }
                        else{

                            if(cur=='F'||x=='F')cur = 'F';
                            else cur = 'T';
                        }
                    }

                    st.pop();
                    counter--;
                    st.push(cur);
                }
            }

            else{

                st.push(ar[i]);
                if(ar[i]=='(')counter++;
            }
        }

        if(st.top()=='T')cout << ++c << ". true" << endl;
        else cout << ++c << ". false" << endl;
    }

    return 0;
}
