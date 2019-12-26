// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct s{

    string ss;
    int val;

    s(string _ss , int _val){

        ss = _ss;
        val = _val;
    }
};

vector<s>v;
multiset<int>st;
multiset<int>::iterator it;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    for(int i=0;i<n;i++){

        string ar;
        cin >> ar;

        if(ar=="insert"){

            int in;
            cin >> in;

            v.push_back(s("insert" , in));
            st.insert(in);
        }

        else if(ar=="getMin"){

            int in;
            cin >> in;

            it = st.begin();

            while(st.empty()==false&&*it<in){

                v.push_back(s("removeMin" , 0));
                st.erase(it);
                it = st.begin();
            }

            if(st.empty()||*it>in){v.push_back(s("insert" , in));st.insert(in);}
            v.push_back(s("getMin" , in));
        }

        else{
            if(st.empty()){st.insert(0);v.push_back(s("insert" , 0));}
            it = st.begin();
            st.erase(it);
            v.push_back(s("removeMin", 0));
        }
    }

    int si = v.size();
    cout << si << endl;

    for(int i=0;i<si;i++){

        if(v[i].ss=="removeMin")cout << "removeMin" << endl;
        else cout << v[i].ss << " " << v[i].val << endl;
    }

    return 0;
}
