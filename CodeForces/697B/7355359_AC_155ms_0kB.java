//package lab.assignment;
import java.util.*;
import java.math.*;
public class Main {
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner(System.in);
        
        String ar = sc.next();
        
        BigDecimal br = new BigDecimal(ar);
        
        String cr = br.toPlainString();
        
        int d1 = 0 , d2 = cr.length() - 1;
        boolean check = false;
        
        for(int i=0;i<=d2;i++)if(cr.charAt(i)=='.')check=true;
        
        while(cr.charAt(d1)=='0')d1++;
        if(check==true)while(cr.charAt(d2)=='0')d2--;
        
        if(cr.charAt(d2)=='.')d2--;
        if(cr.charAt(d1)=='.')System.out.print(0);
        
        for(;d1<=d2;d1++)System.out.print(cr.charAt(d1));
        System.out.println();
        
    }
} 