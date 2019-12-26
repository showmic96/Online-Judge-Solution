#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a;
    cin >> a;
    for(int b=0;b<a;b++){
        int c;
        cin >> c;
        printf("Case %d:\n",b+1);
        for(int d=0;d<c+c/2;d++){

            for(int e=0;e<c+c/2;e++){
                if((d==0||d==c-1)&&e<c&&e!=c-1+c/2)cout << "#";
                else if(d>0&&d<c-1&&(e==0||e==c-1))cout << "#";
                else if(e>=c/2&&(d==c/2||d==c-1+c/2))cout << "#";
                else if(d>c/2&&d<c-1+c/2&&(e==c/2||e==c-1+c/2))cout << "#";
                else cout << " ";

            }

            cout << endl;

        }
    }
    return 0;
}
