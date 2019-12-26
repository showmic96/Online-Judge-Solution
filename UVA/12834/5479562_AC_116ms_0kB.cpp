#include<iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    long long int a , b , c, d ,e ,f,g=0,i,j,k,z;
    cin >> a;
    for(b=0;b<a;b++){
        cin >> c >> k;
        g=0;z=0;
       long long int array1[c],array2[c],array3[c];
        for (d=0;d<c;d++)cin >> array1[d];
        for (d=0;d<c;d++)
        {

        cin >> array2[d];
        array3[d]=(array2[d]-array1[d]);
        if(array1[d]>array2[d]) z+=1;
        }

        //for (d=0;d<c;d++)cout << array3[d] <<endl;
        //for (d=0;d<c;d++) cin >> array2[d];
        //for (d=0;d<c;d++) {array3[d]=array2[d]-array1[d];if(array1[d]>array2[d]) z+=1;}
//        sort(array3);
       // for(e=0;e<c;e++)
        //for (d=0;d<c-1;d++) if(array3[d]<array3[d+1]){i=array3[d+1];array3[d+1]=array3[d];array3[d]=i;}

        sort(array3,array3 + c);
        if(z<k)for (d=c-1;d>=0+z;d--) {g+=array3[d];}
        else for (d=c-1;d>=0+k;d--) g+=array3[d];

        if(g>0)cout <<"Case " << b+1 <<": "<< g << endl;
        else cout <<"Case " << b+1 <<": No Profit" <<endl;

           }
    return 0;
}
