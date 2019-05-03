package UVA_BIGINTEGER_PROBLEM;

import java.math.BigInteger;
import java.util.Scanner;
/// 10523 - Very Easy !!!
/// Solved

public class VeryEasy {
	public static void main(String []args){
		Scanner num=new Scanner(System.in);
		int n, a, i;
		while(num.hasNext()){
			n=num.nextInt();
			a=num.nextInt();
			BigInteger sum=BigInteger.ZERO;
			BigInteger temp=BigInteger.ONE;
			BigInteger res=BigInteger.ZERO;
			temp=temp.multiply(BigInteger.valueOf(a));
			for(i=1; i<=n; i++){
				res=temp.pow(i);
				res=res.multiply(BigInteger.valueOf(i));
				sum=sum.add(res);
	            
	        }
			
			System.out.println(sum);
		}
		
		num.close();
		
	}
}

