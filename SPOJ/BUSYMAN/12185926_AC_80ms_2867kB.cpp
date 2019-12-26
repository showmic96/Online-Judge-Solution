// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

vector<pair<int , int> > v;

bool cmp(pair<int , int>A , pair<int , int> B)
{
    return A.second<B.second;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);

        for(int i=0;i<n;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            v.push_back(make_pair(in1 , in2));
        }

        sort(v.begin() , v.end() , cmp);
        int last = -1 , counter = 0;

        for(int i=0;i<n;i++){

            if(v[i].first>=last){

                counter++;
                last = v[i].second;
            }
        }

        printf("%d\n",counter);

        v.clear();
    }
    return 0;
}
