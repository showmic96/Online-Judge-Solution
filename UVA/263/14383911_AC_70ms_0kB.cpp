// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> ntv(int x)
{
    vector<int>temp;
    while(x){

        temp.push_back(x%10);
        x/=10;
    }
    if(temp.size()==0)temp.push_back(0);
    reverse(temp.begin() ,temp.end());
    return temp;
}

int vtn(vector<int>v)
{
    int now = 0;
    for(int i=0;i<v.size();i++){

        now*=10;
        now+=v[i];
    }
    return now;
}

int main(void)
{
    int n , m;
    while(scanf("%d",&n)==1){

        if(n==0)break;
        vector<pair<int , int> > ans;
        map<int , int>mp;
        m = n;

        while(true){

            vector<int>t1 = ntv(n);
            sort(t1.begin() , t1.end());
            int t2 = vtn(t1);

            reverse(t1.begin() , t1.end());
            int t3 = vtn(t1);

            ans.push_back(make_pair(t3 , t2));
            n = t3-t2;

            if(mp.find(n)!=mp.end())break;
            mp[n] = 1;
        }

        printf("Original number was %d\n",m);
        for(int i=0;i<ans.size();i++)printf("%d - %d = %d\n",ans[i].first , ans[i].second , ans[i].first-ans[i].second);
        printf("Chain length %d\n\n",(int)ans.size());
    }

    return 0;
}
