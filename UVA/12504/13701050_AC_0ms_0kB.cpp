// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

pair<string , string> split(string ar)
{
    string t1 = "";
    string t2 = "";

    int i=0;
    for(;i<ar.size();i++){

        if(ar[i]==':')break;
        t1+=ar[i];
    }

    for(i++;i<ar.size();i++){

        if(ar[i]==':')break;
        t2+=ar[i];
    }

    return make_pair(t1 , t2);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        string ar , br;
        cin >> ar >> br;

        set<string>st;
        set<string>::iterator it;

        map<string , string>mp1 , mp2;

        string temp = "";

        for(int i=1;i<ar.size()-1;i++){

            if(ar[i]==','){

                pair<string , string> p = split(temp);

                mp1[p.first] = p.second;
                st.insert(p.first);
                temp = "";
            }

            else temp+=ar[i];
        }

        if(temp!=""){
            pair<string , string> p = split(temp);

            mp1[p.first] = p.second;
            st.insert(p.first);
            temp = "";
        }

        for(int i=1;i<br.size()-1;i++){

            if(br[i]==','){

                pair<string , string> p = split(temp);

                mp2[p.first] = p.second;
                st.insert(p.first);
                temp = "";
            }

            else temp+=br[i];
        }

        if(temp!=""){

            pair<string, string> p = split(temp);

            mp2[p.first] = p.second;
            st.insert(p.first);
        }

        bool match = true , check = false;

        for(it=st.begin();it!=st.end();it++){

            string temp = *it;

            if(mp1[temp]==""){

                match = false;
                if(check==false)cout << "+";
                else cout << ",";

                check = true;
                cout << temp;
            }
        }

        if(check)cout << endl;

        check = false;

        for(it=st.begin();it!=st.end();it++){

            string temp = *it;

            if(mp2[temp]==""){

                match = false;
                if(check==false)cout << "-";
                else cout << ",";

                check = true;
                cout << temp;
            }
        }

        if(check)cout << endl;

        check = false;

        for(it=st.begin();it!=st.end();it++){

            string temp = *it;

            if(mp1[temp]!=mp2[temp]){

                if(mp1[temp]=="")continue;
                if(mp2[temp]=="")continue;

                match = false;
                if(check==false)cout << "*";
                else cout << ",";

                check = true;
                cout << temp;
            }
        }

        if(check)cout << endl;

        if(match==true)cout << "No changes" << endl;
        
        cout << endl;
    }

    return 0;
}
