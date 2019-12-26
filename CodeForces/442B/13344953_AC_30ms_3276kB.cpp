// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

vector<double>v;

int main(void)
{
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){

        double in;
        scanf("%lf",&in);
        v.push_back(in);
    }

    sort(v.begin() , v.end());
    reverse(v.begin() , v.end());

    double ans = 0;
    vector<double>temp;

    for(int i=0;i<n;i++){

        temp.push_back(v[i]);
        double counter = 0;

        for(int j=0;j<temp.size();j++){

            double c = 1;

            for(int k=0;k<temp.size();k++){

                if(j==k)c*=temp[k];
                else c*=(1-temp[k]);
            }
            counter+=c;
        }

        if(counter<=1)ans = max(ans , counter);
        else break;
    }

    printf("%.14f\n",ans);

    return 0;
}
