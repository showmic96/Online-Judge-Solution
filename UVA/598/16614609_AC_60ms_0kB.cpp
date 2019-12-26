// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , m , k;
vector<string>v;
map<string , int>mp;
map<int , string>ump;
vector<int>rival[25] , st;

bool cmp(string A , string B)
{
    if(A.size()==B.size()){

        return A<B;
    }
    return A.size()>B.size();
}

void f(int u , int i , int c)
{
    if(i==n+1){

        if(c==k){

            string temp = ump[u];
            for(int j=0;j<temp.size();j++)cout << temp[j];
            for(int i1=1;i1<k;i1++){

                cout << ", ";
                temp = ump[st[i1]];
                for(int j=0;j<temp.size();j++)cout << temp[j];
            }

            cout << endl;
        }
        return ;
    }

    if(u==i){

        f(u , i+1 , c);
        return ;
    }

    st.push_back(i);
    if(c+1<=k)f(u , i+1 , c+1);
    st.erase(st.begin()+st.size()-1);

    f(u , i+1 , c);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t , c = 0;
    string ar; bool blank = false;
    cin >> t;
    cin.ignore();
    cin.ignore();

    while(t--){

        if(blank==true)cout << endl;blank = true;
        v.clear();mp.clear();ump.clear();

        getline(cin , ar);
        vector<int>sz;
        int now;

        stringstream ss(ar);
        int in1 , in2;

        if(ar[0]=='*')in1 = 1 , in2 = 30;
        else{
            while(ss >> now){

                sz.push_back(now);
            }

            if(sz.size()==1)in1 = sz[0] , in2 = sz[0];
            else in1 = sz[0] , in2 = sz[1];
        }

        sz.clear();

        for(int i=in1;i<=in2;i++)sz.push_back(i);

        while(getline(cin , ar)){

            if(ar=="")break;
            v.push_back(ar);
        }
        n = v.size();
        for(int i=0;i<v.size();i++){

            mp[v[i]] = i+1;
            ump[i+1] = v[i];
        }

        for(int i1=0;i1<sz.size();i1++){

            if(sz[i1]>n)break;

            st.clear();
            k = sz[i1];
            cout << "Size " << k << endl;

            st.push_back(1);
            for(int i=1;i<=n;i++){

                st[0] = i;
                f(i , i+1 , 1);
            }
            cout << endl;
        }
    }
    return 0;
}
