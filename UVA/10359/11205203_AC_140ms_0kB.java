// In the name of Allah the Lord of the Worlds. 

import java.io.*;
import java.util.*;
import java.math.*;

class Main {
    
    public static BigInteger dp [] = new BigInteger [300];
    public static BigInteger cmp = new BigInteger("-1");
    
    public static BigInteger f(int i){
        
        if(i==0)return BigInteger.ONE;
        if(i<0)return BigInteger.ZERO;
        
        if(dp[i].compareTo(cmp)!=0)return dp[i];
        
        BigInteger value = new BigInteger("0");
        
        value = value.add(f(i-1));
        value = value.add(f(i-2).multiply(BigInteger.valueOf(2)));
        
        return dp[i] = value;
    }

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        for(int i=0;i<300;i++){
            
            dp[i] = new BigInteger("-1");
        }
        
        while(sc.hasNext()){
            
            int a = sc.nextInt();
            System.out.println(f(a));
        }
        
    }
}