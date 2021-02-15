import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

public class MyPanels extends JPanel {

	public void paintComponent(Graphics g) {
		g.setColor(Color.red);
		g.fillArc(105,70, 30, 80,100,209);
		
	}

}
