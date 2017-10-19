import java.awt.Color;
import java.awt.Graphics;
import java.util.Calendar;
import java.util.GregorianCalendar;

import javax.swing.JFrame;
import javax.swing.JPanel;

public class Clock extends JPanel {
	private int second=Calendar.SECOND;
	private int minute=Calendar.MINUTE;
	private int hour=Calendar.HOUR;
	
	
	public Clock() {
		int width = 200;
		JFrame f = new JFrame();
		f.getContentPane().add(this);
		f.setTitle("Clock");
		f.setSize(width,width);
		f.setVisible(true);
	}
	
	public void paintComponent(Graphics g) {
		GregorianCalendar time = new GregorianCalendar();
		int s_angle = 90 - (time.get(second)*6);
		int m_angle = 90 - (time.get(minute)*6);
		int h_angle = 90 - (time.get(hour)*30);
		int width = 200;
		int gap = 50;
		int d = 100;
		g.setColor(Color.white);
		g.fillRect(0, 0, width, width);
		g.setColor(Color.black);
		g.drawOval(gap, gap, d, d);
		g.setColor(Color.blue);
		g.fillArc(gap+25, gap+25, d-50, d-50, h_angle, 8);
		g.setColor(Color.red);
		g.fillArc(gap+5, gap+5, d-10, d-10, m_angle, 5);
		g.setColor(Color.black);
		g.fillArc(gap+10, gap+10, d-20, d-20, s_angle, -3);
	}
	
	public void timeisrun(){
		second=Calendar.SECOND;
		minute = Calendar.MINUTE;
		hour = Calendar.HOUR;
		this.Clock();
	}
	
	public static void main(String [] args) {
		int sleeptime=10;
		Clock c = new Clock();
		while(true) {
			c.paintComponent();
			try {
				Thread.sleep(sleeptime);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}

}
