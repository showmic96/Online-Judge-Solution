// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

pair<int, string > dp[111][999];
int n , s;
string ans;

void setUp()
{
    for(int i=0;i<111;i++){

        for(int j=0;j<999;j++){

            dp[i][j].first = -1;
        }
    }
}

pair <int , string > f(int i , int value , string ar)
{
    //cout << ar << endl;
    if(i>0&&value==0)return make_pair(-1234 , "");
    if(i==n){

        if(value==s){

            if(ar<ans) return make_pair(-1234 ,"");
            //cout << ans << " " << ar << endl;
            ans = ar;

            return make_pair(value , ar);
        }

        else return make_pair(-1234 , "");
    }

    if(dp[i][value].first!=-1)return dp[i][value];

    //cout << ar << endl;

    pair<int ,string>v , temp;
    int mx = 0;

    for(int j=9;j>=0;j--){

        string t = "";
        t+=('0'+j);

        if(value+j<=s)temp = f(i+1 , value+j , ar+t);

        if(temp.first>mx){

            mx = temp.first;
            v = temp;
        }
    }

    return dp[i][value] = v;
}

pair <int , string > f2(int i , int value , string ar)
{
    if(i>0&&value==0)return make_pair(1234 , "");
    if(i==n){

        if(value==s){
            //cout << value << endl;
            return make_pair(value , ar);
        }

        else return make_pair(1234 , "");
    }

    if(dp[i][value].first!=-1)return dp[i][value];

    pair<int ,string>v , temp;
    int mx = 12345;

    for(int j=0;j<=9;j++){

        string t = "";
        t+=('0'+j);

        temp = f2(i+1 , value+j , ar+t);

        if(temp.first<mx){

            mx = temp.first;
            v = temp;
        }
    }

    return dp[i][value] = v;
}

int main(void)
{
    setUp();
    cin >> n >> s;

    pair<int , string > temp , temp2;

    ans = "";
    temp = f(0 , 0 , "");
    setUp();
    temp2 = f2(0 , 0 , "");

    string ar = temp2.second;
    //string br = temp2.second;

    if(n==1&&s==0)cout << 0 << " " << 0 << endl;
    else if(temp.first==s&&s!=0)cout << ar << " " << ans << endl;
    else cout << -1 << " " << -1 << endl;

    return 0;
}
