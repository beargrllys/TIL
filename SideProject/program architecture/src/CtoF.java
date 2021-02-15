import java.text.DecimalFormat;

public class CtoF {

	public static void main(String[] args) {
		int c = new Integer(args[0]).intValue();
		double f = ((9.0/5.0)*c)+32;
		System.out.println("For Celdius degrees "+ c + ",");
		DecimalFormat formatter = new DecimalFormat("0.0");
		System.out.println("Degrees Fahrenheit = "+formatter.format(f));

	}

}
