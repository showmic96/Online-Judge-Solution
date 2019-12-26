
import java.util.*;
import java.io.*;
public class Main {
    
    public static void main(String arg[]){
        
        Scanner sc = new Scanner(System.in);
        
        String ar = sc.next();
        String br = sc.next();
        
        int a = ar.toLowerCase().compareTo(br.toLowerCase());
        if(a>0)a=1;
        if(a<0)a=-1;
        
        System.out.println(a);
    }
    
}
