// In the name of Allah the Most Merciful. 

import java.util.Scanner;
import java.math.BigInteger;

class Main
{
    public static BigInteger fib[] = new BigInteger[205];
    
    public static void pre(){
        
        fib[0] = BigInteger.valueOf(1);
        fib[1] = BigInteger.valueOf(1);

        for(int i=2;i<=200;i++){
            
            fib[i] = fib[i-1];
            fib[i] = fib[i].add(fib[i-2]);
        }
    }
    
    public static BigInteger get(String ar){
        
        int si = ar.length();
        BigInteger temp = new BigInteger("0");
        
        for(int i=0;i<si;i++){
            
            if(ar.charAt(i)=='1'){
                
                temp = temp.add(fib[si-i]);
            }
        }
        
        return temp;
    }
    
    public static void main(String args[]){
        
        pre();
        Scanner sc = new Scanner(System.in);
        boolean blank = false;
        while(sc.hasNext()){
            
            if(blank==true)System.out.println("");
            blank = true;
            
            String ar = sc.next();
            
            BigInteger a = get(ar);

            ar = sc.next();
            
            BigInteger b = get(ar);
            
            a = a.add(b);
            boolean first = false;
            
            for(int i=200;i>=1;i--){
                
                if(a.compareTo(fib[i])>=0){
                    
                    System.out.print("1");
                    a = a.subtract(fib[i]);
                    first = true;
                }
                
                else if(first==true)System.out.print("0");
            }
            if(first==false)System.out.print("0");
            System.out.println("");
            
        }
    }        
}