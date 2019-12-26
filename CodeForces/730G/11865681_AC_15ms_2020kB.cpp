// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n;
    scanf("%d",&n);

    vector<pair<ll , ll > > v;
    v.push_back(make_pair(0 , 0));

    for(int i=0;i<n;i++){

        sort(v.begin() , v.end());

        ll in1 , in2;
        scanf("%lld %lld",&in1 , &in2);

        bool check = true;

        ll temp1 = in1 , temp2 = in1+in2-1;

        int si = v.size();

        for(int i=0;i<si;i++){

            if(v[i].first>=temp1&&v[i].first<=temp2)check = false;
            if(v[i].second>=temp1&&v[i].second<=temp2)check = false;
            if(temp1>=v[i].first&&temp1<=v[i].second)check = false;
            if(temp2>=v[i].first&&temp2<=v[i].second)check = false;
        }

        if(check==true){

            printf("%lld %lld\n",temp1 , temp2);
            v.push_back(make_pair(temp1 , temp2));
        }

        else{


            for(int j=0;j<si;j++){

                temp1 = v[j].second+1;
                temp2 = temp1+in2-1;
                check = true;

                for(int i=j+1;i<si;i++){

                    if(v[i].first>=temp1&&v[i].first<=temp2)check = false;
                    if(v[i].second>=temp1&&v[i].second<=temp2)check = false;
                    if(temp1>=v[i].first&&temp1<=v[i].second)check = false;
                    if(temp2>=v[i].first&&temp2<=v[i].second)check = false;
                }

                if(check==true){

                    printf("%lld %lld\n",temp1 , temp2);
                    v.push_back(make_pair(temp1 , temp2));
                    break;
                }
            }
        }
    }

    return 0;
}
