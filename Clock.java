package scedule;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;

import javax.swing.JPanel;

import ProjectFinal.Timegetter;

public class Clock extends JPanel implements Runnable{
	private String year;
	private String month;
	private String date;
	private String hour;
	private String minute;
	private String second;
	
	private Timegetter tg;
	
	public Clock() {
		this.setBounds(0, 0, 1, 1);
	}
	
	public void paintComponent(Graphics g) {
		g.setColor(Color.red);
		g.fillRect(0, 0, 500, 500);
		System.out.println("dddd");
		g.drawString("nfsid;fnd",0,0);
		//g.setFont(new Font("Arial", Font.BOLD, 15));
		g.drawString(year+" / "+month+" / "+date+" / "+hour+":"+minute+":"+second,0,0);
		
	}

	@Override
	public void run() {
		tg = new Timegetter();
		Clock c = new Clock();
		int year = tg.getyear();
		int month = tg.getmonth();
		int date = tg.getdate();
		int hour = tg.gethour();
		int minute = tg.getminute();
		int second = tg.getsecond();
		this.setBounds(175,50, 150, 50);
		this.year = String.valueOf(year);
		this. month = String.valueOf(month);
		this. date = String.valueOf(date);
		this. hour = String.valueOf(hour);
		this. minute = String.valueOf(minute);
		this. second = String.valueOf(second);
		try {
			Thread.sleep(1000);
			c.repaint();
		} catch(InterruptedException e) {
			e.printStackTrace();
		}
	}
}
