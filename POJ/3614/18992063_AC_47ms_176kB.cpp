// In the name of Allah the Lord of the Worlds.

#include<iostream>
#include<vector>
#include<stdio.h>
#include<queue>
#include<math.h>
#include<algorithm>
#include<set>
using namespace std;

typedef long long ll;
multiset<int>st;

int main(void)
{
    int n , m , cur = 0 , ans = 0;
    scanf("%d %d",&n , &m);
    vector<pair<int,int> > v1(n) , v2(m);
    for(int i=0;i<n;i++)scanf("%d %d",&v1[i].first , &v1[i].second);
    for(int i=0;i<m;i++)scanf("%d %d",&v2[i].first , &v2[i].second);
    sort(v1.begin() , v1.end());
    sort(v2.begin() , v2.end());
    for(int i=0;i<m;i++){
        for(int j=cur;j<n;j++){
            if(v2[i].first<v1[j].first)break;
            st.insert(v1[j].second);
            cur = j+1;
        }
        while(v2[i].second>0){
            if(st.empty())break;
            int now = *st.begin();
            st.erase(st.begin());
            if(now<v2[i].first)continue;
            ans++;
            v2[i].second--;
        }
    }
    printf("%d\n",ans);
    return 0;
}
