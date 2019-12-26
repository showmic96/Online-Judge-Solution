// In the name of Allah the Most Merciful. 

import java.io.*;
import java.util.*;
import java.math.*;

class Main {
    
    static BigInteger dp[][] = new BigInteger[12345][4];
    static int n;
    
    static void setUp(){
        
        for(int i=0;i<12345;i++){
            
            for(int j=0;j<4;j++){
            
                dp[i][j] = new BigInteger("-1");
            }
        }
    }
    
    static BigInteger f (int i , int pre){
        
        if(i==n)return BigInteger.ONE;
        if(i>n)return BigInteger.ZERO;
        
        if(dp[i][pre].compareTo(BigInteger.valueOf(-1))!=0)return dp[i][pre];
        
        BigInteger temp = new BigInteger("0");
        
        if(pre==0){
            
            temp = temp.add(f(i+1, 1));
        }
        
        else{
            
            temp = temp.add(f(i+1, 0));
            temp = temp.add(f(i+1, 1));
        }
        
        return dp[i][pre] = temp;
    }
    
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        while(sc.hasNext()){
            
            n = sc.nextInt();
            
            setUp();
            
            System.out.println(f(0 , 1));
        }
    }
}