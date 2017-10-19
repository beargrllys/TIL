import javax.swing.JFrame;

public class Tempmain {

	public static void main(String[] args) {
		MyPanels r = new MyPanels();
		JFrame f = new JFrame();
		f.getContentPane().add(r);
		f.setSize(300, 200);
		f.setVisible(true);

	}

}
