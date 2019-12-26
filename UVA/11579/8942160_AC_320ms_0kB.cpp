// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){

        vector<double>v;
        int n;
        scanf("%d",&n);

        for(int j=0;j<n;j++){double in;cin >> in;v.push_back(in);}
        sort(v.begin(), v.end());
        reverse(v.begin() , v.end());

        double mi = 0;

        for(int j=0;j<n-2;j++){

            if(v[j]<v[j+1]+v[j+2]){

                double s = v[j] + v[j+1] + v[j+2];
                s/=2;

                double area = sqrt(s*(s-v[j])*(s-v[j+1])*(s-v[j+2]));

                if(area>mi){

                    mi = area;
                }
            }
        }

        printf("%.2f\n",mi);
    }
    return 0;
}
