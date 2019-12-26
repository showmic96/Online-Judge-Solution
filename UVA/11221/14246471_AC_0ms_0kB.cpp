// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string br[10005];

string make(string ar)
{
    string temp = "";
    for(int i=0;i<ar.size();i++){

        if(ar[i]>='a'&&ar[i]<='z')temp+=ar[i];
    }
    return temp;
}

bool check(int n)
{
    string t1 = "" , t2 = "" , t3 = "" , t4 = "";

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            t1+=br[i][j];
        }
    }

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            t2+=br[j][i];
        }
    }

    for(int i=n-1;i>=0;i--){

        for(int j=n-1;j>=0;j--){

            t3+=br[i][j];
        }
    }

    for(int i=n-1;i>=0;i--){

        for(int j=n-1;j>=0;j--){

            t4+=br[j][i];
        }
    }

    if(t1==t2&&t2==t3&&t3==t4)return true;
    return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t , c = 0;
    cin >> t;

    cin.ignore();

    while(t--){

        string ar;
        getline(cin , ar);
        ar = make(ar);

        double sz = sqrt(ar.size());

        cout << "Case #" << ++c << ":" << endl;

        if((int)sz!=sz)cout << "No magic :(" << endl;
        else{

            int si = sz , now = 0;
            for(int i=0;i<si;i++){

                br[i] = "";
                for(int j=0;j<si;j++){

                    br[i]+=ar[now];
                    now++;
                }
            }

            if(check(si)==true)cout << si << endl;
            else cout << "No magic :(" << endl;
        }
    }

    return 0;
}
