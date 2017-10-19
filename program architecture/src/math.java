import java.text.DecimalFormat;

import javax.swing.JOptionPane;

public class math {

	public static void main(String[] args) {
		
		
		String input = JOptionPane.showInputDialog("input x");
		String input2 = JOptionPane.showInputDialog("input y");
		double x= new  Double(input).doubleValue();
		double y= new  Double(input2).doubleValue();
		DecimalFormat formatter = new DecimalFormat("0.0000");
		
		JOptionPane.showMessageDialog(null, formatter.format(Math.abs(x))+" / "+formatter.format(Math.ceil(x))+" / "+formatter.format(Math.floor(x))+" / "+formatter.format(Math.max(x,y))+" / "+formatter.format(Math.min(x,y)));

	}

}
