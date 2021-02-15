import java.text.DecimalFormat;

import javax.swing.JOptionPane;

public class GraphCtoF {
	public static void main(String[] args) {
		String input = JOptionPane.showInputDialog("Type an integer Celsius temperture");
		int c = new Integer(input).intValue();
		double f = ((9.0/5.0)*c)+32;
		DecimalFormat formatter = new DecimalFormat("0.0");
		JOptionPane.showMessageDialog(null,c+"Celsius is "+formatter.format(f)+" Fahrenheit");
	}

}
