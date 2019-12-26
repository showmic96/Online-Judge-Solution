// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

char x[200000+5];

int main(void)
{
    int n;
    scanf("%d",&n);

    vector<int>v;

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        v.push_back(in);
    }

    scanf("%s",&x);

    string ar(x);

    int last = -1;
    int counter = 0;

    for(int i=0;i<ar.size();i++){

        if(ar[i]=='1'&&last==-1){

            last = i;
            counter = 1;
        }

        else if(ar[i]=='1'){

            counter++;
        }

        else{

            sort(v.begin()+last , v.begin()+last+counter+1);

            last = -1;
            counter = 0;
        }
    }

    if(last!=-1)sort(v.begin()+last , v.begin()+last+counter+1);

    bool check = true;

    for(int i=0;i<n-1;i++){

        if(v[i]>v[i+1])check = false;
    }

    if(check)printf("YES\n");
    else printf("NO\n");

    return 0;
}
