import java.util.Scanner;

public class gugu {
	public static void main(String[] args) {
	Scanner scan = new Scanner(System.in);
	int i = scan.nextInt();
	int j = scan.nextInt();
	int k,t;
	
	Mathematics m = new Mathematics();
	
	for (k=i; k<j+1; k++) {
	for(t=1; t<10; t++) {
	int mul = m.mul(k, t);
	System.out.println(k+"*"+t+"="+mul);
	}
	}
	
	

}

}
