import java.text.DecimalFormat;
import java.util.Scanner;

public class Three {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		double half;
		double height;
		
		
		half=scan.nextDouble();
		height=scan.nextDouble();
		DecimalFormat formatter = new DecimalFormat("0.0");
		
		System.out.println(formatter.format(half*half*Math.PI*height));
		System.out.println(formatter.format((Math.PI*half*half*height)/3));

	}

}
