// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int a[1000] , n , t;

vector<string>fin;
map<string , int>mp;

void f(int value , int i , string ans)
{

    if(value==t){

        if(mp[ans]==1)return;
        fin.push_back(ans);
        mp[ans] = 1;

        return ;
    }

    if(i>=n)return;

    if(value+a[i]<=t){
        if(ans.size()==0)f(value+a[i] , i+1 , to_string(a[i]));
        else {

            f(value+a[i] , i+1 ,  ans + "+" + to_string(a[i]));
        }

    }

    f(value , i+1 , ans);
}
int main(void)
{
    while(cin >> t >> n){

        if(!t&&!n)break;
        mp.clear();
        fin.clear();

        for(int i=0;i<n;i++){

            cin >> a[i];
        }

        printf("Sums of %d:\n",t);

        f(0 , 0 , "");

        int si = fin.size();

        for(int i=0;i<si;i++){

            cout << fin[i] << endl;
        }

        if(si==0)cout << "NONE" << endl;
    }
    return 0;
}
