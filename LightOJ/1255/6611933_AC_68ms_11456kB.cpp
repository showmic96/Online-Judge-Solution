#include<bits/stdc++.h>
using namespace std;

#define si 1000010

char ar[si];
char br[si];

int countValue[si];
int searchValue[si];

int counter = 0;

void kmpProcessing()
{
    int i=0 ,j=-1;
    int m = strlen(ar);

    countValue[i]=j;

    while(i<m){

        while(j>=0&&ar[i]!=ar[j])j=countValue[j];
        i++;j++;
        countValue[i]=j;
    }

}

void kmpSearch()
{
    int i=0 , j=0;
    int m = strlen(br);
    int k = strlen(ar);

    //searchValue[i]=j;

    while(i<m){

        while(j>=0&&br[i]!=ar[j])j=countValue[j];
        i++;
        j++;

        if(j==k){
            counter++;
            j=countValue[j];
        }
    }
}


int main(void)
{
    int a;
    cin >> a;

    for(int i=0;i<a;i++){
        getchar();
        gets(br);
        getchar();
        gets(ar);
        kmpProcessing();
        kmpSearch();
        printf("Case %d: ",i+1);
        cout << counter << endl;
        memset(ar,'\0',sizeof(ar));
        memset(br,'\0',sizeof(br));
        counter =0;
    }

    return 0;
}
