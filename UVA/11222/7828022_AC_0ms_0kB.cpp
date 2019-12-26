// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t , f1[101010] , f2[101010] , f3[101010];
    map<int ,int>maping;
    cin >> t;
    for(int i=0;i<t;i++){

        maping.clear();
        int in1 , in2 , in3 , counter1 = 0 , counter2 = 0 , counter3 = 0;
        cin >> in1;

        for(int j=0;j<in1;j++){

            cin >> f1[j];
            maping[f1[j]]++;
        }

        cin >> in2;

        for(int j=0;j<in2;j++){

            cin >> f2[j];
            maping[f2[j]]++;
        }

        cin >> in3;

        for(int j=0;j<in3;j++){

            cin >> f3[j];
            maping[f3[j]]++;
        }

        for(int j=0;j<in1;j++){

            if(maping[f1[j]]==1)counter1++;
        }

        for(int j=0;j<in2;j++){

            if(maping[f2[j]]==1)counter2++;
        }

        for(int j=0;j<in3;j++){

            if(maping[f3[j]]==1)counter3++;
        }

        int mx = max(counter1 , max(counter2 , counter3));

        printf("Case #%d:\n",i+1);

        sort(f1 , f1+in1);
        sort(f2 , f2+in2);
        sort(f3 , f3+in3);

        if(mx==counter1){

            cout << 1 << " " << counter1;

            for(int j=0;j<in1;j++){

                if(maping[f1[j]]==1)cout << " " << f1[j];
            }

            cout << endl;
        }


        if(mx==counter2){

            cout << 2 << " " << counter2;

            for(int j=0;j<in2;j++){

                if(maping[f2[j]]==1)cout << " " << f2[j];
            }

            cout << endl;
        }


        if(mx==counter3){

            cout << 3 << " " << counter3;

            for(int j=0;j<in3;j++){

                if(maping[f3[j]]==1)cout << " " << f3[j];
            }

            cout << endl;
        }

        //cout << "hello world" << endl;

    }
    return 0;
}
