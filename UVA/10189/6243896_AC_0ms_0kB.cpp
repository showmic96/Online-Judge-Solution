#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void)
{
    int a , b;
    int u=0;

    while(cin >> a >> b){
        if(!a&&!b)break;
        if(u!=0)cout << endl;
        u++;
        string ar[a];
        scanf("\n");
        for(int c=0;c<a;c++)cin >> ar[c];

        printf("Field #%d:\n",u);
        for(int c=0;c<a;c++){

            for(int d=0;d<b;d++){
                int count1=0;
                if(ar[c][d]=='*')cout << "*";

                else{

                    if(c>=0&&c<a&&d+1>=0&&d+1<=b)if(ar[c][d+1]=='*')count1++;
                    if(c>=0&&c<a&&d-1>=0&&d-1<=b)if(ar[c][d-1]=='*')count1++;
                    if(c+1>=0&&c+1<a&&d>=0&&d<=b)if(ar[c+1][d]=='*')count1++;
                    if(c+1>=0&&c+1<a&&d+1>=0&&d+1<=b)if(ar[c+1][d+1]=='*')count1++;
                    if(c+1>=0&&c+1<a&&d-1>=0&&d-1<=b)if(ar[c+1][d-1]=='*')count1++;
                    if(c-1>=0&&c-1<a&&d>=0&&d<=b)if(ar[c-1][d]=='*')count1++;
                    if(c-1>=0&&c-1<a&&d+1>=0&&d+1<=b)if(ar[c-1][d+1]=='*')count1++;
                    if(c-1>=0&&c-1<a&&d-1>=0&&d-1<=b)if(ar[c-1][d-1]=='*')count1++;
                    //if(ar[c][d+1]=='*')count1++;
                    cout << count1;
                }

            }
            cout << endl;

        }

    }
    return 0;
}
