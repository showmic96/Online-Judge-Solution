// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
map<int , vector<pair<int , int> > > mp;
vector<pair<int ,int > >v , temp;
bool cmp(pair<int , int> A , pair<int , int> B)
{
    return A.second<B.second;
}

int main(void)
{
    int n , c = 0;
    scanf("%d",&n);
    vector<int>ar(n);
    for(int i=0;i<n;i++)scanf("%d",&ar[i]);
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum+=ar[j];
            mp[sum].push_back({i+1 , j+1});
        }
    }
    int mx = 0;
    for(auto it:mp){
        v = it.second;
        sort(v.begin() , v.end() , cmp);
        int lst = -1 , counter = 0;
        for(auto now:v){
            if(now.first>lst){
                counter++;
                lst = now.second;
            }
        }
        if(counter>mx){
            mx = counter;
            temp = v;
        }
    }
    printf("%d\n",mx);
    int lst = -1;
    for(auto it:temp){
        if(it.first<=lst)continue;
        lst = it.second;
        printf("%d %d\n",it.first , it.second);
    }
    return 0;
}
