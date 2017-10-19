import java.util.Scanner;

public class Main1 {
	public static void main(String[] args) {
	Scanner scan = new Scanner(System.in);
	int a = scan.nextInt();
	int b = scan.nextInt();
	
	Mathematics m = new Mathematics();
	
	int sum = m.sum(a,b);
	int sub = m.sub(a, b);
	int mul = m.mul(a, b);
	int div = m.div(a, b);
	System.out.println("sum = " + sum);
	System.out.println("sub = " + sub);
	System.out.println("mul = " + mul);
	System.out.println("div = "+ div);
	
	

}
}
