// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a;
    cin >> a;
    string in1 , in2;
    int j=0;
    while(a--){
        if(j>0)printf("\n");
        j++;
        map<string,string>marka;
        string name[1000];
        map<string,int>vote;
        int b;
        cin >> b;
        int d=0;
        while(b--){
            scanf("\n");
            getline(cin , in1);
            getline(cin , in2);
            marka[in1]=in2;
            name[d]=in1;d++;
        }

        cin >> b;
        while(b--){
            scanf("\n");
            getline(cin,in1);
            vote[in1]++;

        }
        int max_s=0;
        string final_name;

        for(int i=0;i<d;i++){

            if(max_s<vote[name[i]]){max_s=vote[name[i]];final_name=name[i];}
        }
        int isOnce = 0;

        for(int i=0;i<d;i++){

            if(max_s==vote[name[i]])isOnce++;
        }
        if(isOnce==1)cout << marka[final_name] << endl;
        else cout << "tie" << endl;
    }
    return 0;

}
