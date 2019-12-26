// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string get(int i , int j , string ar , string now)
{
    string temp = "";
    for(int i1=0;i1<i;i1++){

        temp+=ar[i1];
    }

    temp+=now;

    for(int i1=j+1;i1<ar.size();i1++)temp+=ar[i1];

    return temp;
}

int main(void)
{
    int n;
    while(cin >> n){

        cin.ignore();
        if(!n)break;

        vector<string>v1 , v2;

        for(int i=0;i<n;i++){

            string ar , br;
            getline(cin , ar);
            getline(cin , br);
            v1.push_back(ar);
            v2.push_back(br);
        }

        string now;
        getline(cin , now);

        for(int k=0;k<n;k++){

            for(int i=0;i<now.size();i++){

                string temp = "";

                for(int j=i;j<now.size();j++){

                    temp+=now[j];

                    if(temp==v1[k]){

                        now = get(i , j , now , v2[k]);

                        i=-1;

                        break;
                    }
                }
            }
        }

        cout << now << endl;
    }
    return 0;
}
