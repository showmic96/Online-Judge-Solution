import java.util.Scanner;
import java.math.BigDecimal;
import java.math.*; 
public class Main{
	
	public static void main(String arg[]){
		
		Scanner sc = new Scanner(System.in);
		BigDecimal ar; int a;
		
		String br;
		
		while(sc.hasNext()){
			
			br="";
			
			ar = sc.nextBigDecimal();
			a = sc.nextInt();
			
			br = ar.pow(a).toPlainString();
			int si = br.length();
			
			//if(br.charAt(si-1)=='0');
			
			if(br.charAt(0)=='0'){
				int i =0;
                                int d = si-1;
				while(br.charAt(i)=='0')i++;
				while(br.charAt(d)=='0')d--;
				if(br.charAt(d)=='.')d--;
				for(;i<=d;i++)System.out.print(br.charAt(i));
				System.out.println();
			}
			
			else if(br.charAt(si-1)=='0'){
				
				int i =0;
                                int d = si-1;
				while(br.charAt(i)=='0')i++;
				while(br.charAt(d)=='0')d--;
				if(br.charAt(d)=='.')d--;
				
				for(;i<=d;i++)System.out.print(br.charAt(i));
				System.out.println();
			}
			
			else System.out.println(br);
		}
	}
}