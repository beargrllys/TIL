
import java.text.DecimalFormat;

public class tempperture {

	public static void main(String[] args) {
		double c = new Integer(args[0]).doubleValue();
		double f = ((9.0/5.0)*c)+32;
		System.out.println(c);
		DecimalFormat formatter = new DecimalFormat("0.0");
		System.out.println("Degrees Fahrenheit = "+ formatter.format(f));

	}

}
