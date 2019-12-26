// In the name of Allah the Most Merciful. 

import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;
import java.math.*;

class Main {
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner(System.in);
        int c = 0;
        
        while(sc.hasNext()){
            
            BigDecimal a = sc.nextBigDecimal();
            BigDecimal b = sc.nextBigDecimal();
            
            System.out.printf("Case %d: ",++c);
            if(a.compareTo(b)<0)System.out.println("Smaller");
            else if(a.compareTo(b)>0)System.out.println("Bigger");
            else System.out.println("Same");
        }
    }
}
