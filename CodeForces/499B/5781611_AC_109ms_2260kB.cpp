#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int a , b ,  c , d ,e;
    cin >> a >> b;
    char as1[b+1][11] , bs[a+1][11] , as2[b+1][11];
    for(c=0;c<b;c++) cin >> as1[c] >> as2[c];
    for(c=0;c<a;c++) cin >> bs[c];
    for(c=0;c<a;c++)
        for(d=0;d<b;d++)
    {
        if(strcmp(bs[c],as1[d])==0||strcmp(bs[c],as2[d])==0){if(strlen(as1[d])>strlen(as2[d]))cout << as2[d] << " ";
                                                             else cout << as1[d] << " ";}

}
    cout << endl;

    return 0;
}