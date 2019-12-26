// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;

int n , t , data[100] , ans[100];

vector<int>fin[10000];

map<int ,int>mp;

int c = 0;

int f(int i , int value , int len)
{

    if(i==t){

        //c++;
        if(mp[value]!=0)return -1e9;
        c++;
        mp[value] = c;

        for(int j=0;j<len;j++){

            fin[c].push_back(ans[j]);
        }

        return value;
    }

    int value1 = 0 , value2 = 0;

    if(data[i]+value<=n){

        ans[len] = data[i];
        value1 = f(i+1 , value+data[i] , len+1);

    }

    value2 = f(i+1 , value , len);

    return max(value1 , value2);
}

int main(void)
{
    while(cin >> n >> t){

        c = 0;

        mp.clear();

        for(int i=0;i<t;i++){cin >> data[i];}
        for(int i=0;i<10000;i++)fin[i].clear();

        int temp = f(0 , 0 , 0);
        int t = temp;
        temp = mp[temp];

        for(int i=0;i<fin[temp].size();i++){

            cout << fin[temp][i] << " ";
        }

        cout << "sum:" << t << endl;




    }
    return 0;
}
