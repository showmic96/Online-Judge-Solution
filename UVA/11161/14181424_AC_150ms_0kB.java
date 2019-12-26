// In the name of Allah the Most Merciful. 

import java.util.Scanner;
import java.math.BigInteger;

class Main
{
    public static BigInteger [] ar = new BigInteger[10005];
    
    public static void main(String args[]){
               
        Scanner sc = new Scanner(System.in);
        
        for(int i=0;i<10005;i++){
            
            ar[i] = new BigInteger("-1");
        }
        
        int c = 0;
        
        while(sc.hasNext()){
            
            int n = sc.nextInt();
            if(n==0)break;
            
            BigInteger last = new BigInteger("0");
            BigInteger now = new BigInteger("0");
            
            if(n==1){
                
                System.out.printf("Set %d:\n0\n",++c);
                continue;
            }
            
            for(int i=1;i<100000;i++){
                
                now = now.add(f(i));
                
                if(i==n-1)break;
                
                last = now;
            }
            
            last = last.add(BigInteger.valueOf(1));
            
            now = now.add(last);
            now = now.divide(BigInteger.valueOf(2));
            
            System.out.printf("Set %d:\n",++c);
            System.out.println(now);
        
        }
    }
    
    public static BigInteger f(int n){
        
        if(n==1)return BigInteger.ONE;
        if(n==0)return BigInteger.ONE;
        
        if(ar[n].compareTo(BigInteger.valueOf(-1))!=0)return ar[n];
        
        BigInteger pre = f(n-1);
        pre = pre.add(f(n-2));
        
        return ar[n] = pre;
    }
}