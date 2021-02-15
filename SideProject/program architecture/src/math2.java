import java.text.DecimalFormat;

import javax.swing.JOptionPane;

public class math2 {

	public static void main(String[] args) {
		
		
		String input = JOptionPane.showInputDialog("input x");
		String input2 = JOptionPane.showInputDialog("input y");
		double x= new  Double(input).doubleValue();
		double y= new  Double(input2).doubleValue();
		System.out.println(x);
		System.out.println(y);
		DecimalFormat formatter = new DecimalFormat("0.00000");
		
		JOptionPane.showMessageDialog(null, "abs is"+ formatter.format(Math.abs(x))+" /ceil is "+formatter.format(Math.ceil(x))+" / floor is "+formatter.format(Math.floor(x))+" / max is "+formatter.format(Math.max(x,y))+" / min is "+formatter.format(Math.min(x,y)));

	}

}
