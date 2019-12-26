// In the name of Allah the Most Merciful. 

import java.util.Scanner;
import java.math.BigInteger;

class Main
{
    public static BigInteger [] ar = new BigInteger[1005];
    
    public static void main(String args[]){
               
        Scanner sc = new Scanner(System.in);
        
        for(int i=0;i<1005;i++){
            
            ar[i] = new BigInteger("-1");
        }
        
        while(sc.hasNext()){
            
            int n = sc.nextInt();
            if(n==-1)break;
            
            System.out.println(d(n));
        }
    }
    
    public static BigInteger d(int n){
        
        if(n==0)return BigInteger.ONE;
        if(n==1)return BigInteger.ZERO;
        if(n==2)return BigInteger.ONE;
        
        if(ar[n].compareTo(BigInteger.valueOf(-1))!=0)return ar[n];
        
        BigInteger temp = new BigInteger("0");
        BigInteger pre = d(n-1);
        pre = pre.add(d(n-2));
        temp = BigInteger.valueOf(n-1).multiply(pre);
        
        return ar[n] = temp;
    }
}