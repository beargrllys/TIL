package ProjectFinal;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;

import javax.swing.JPanel;

public class Panel extends JPanel{
	
	private int startday;
	private int daynum;
	private int margin = 70;
	private int nowyear = 0;
	private int nowmonth = 0;
	private int nowday = 0;
	private int year;
	private int month;
	private int date;
	private int hour;
	private int minute;
	private int second;

	private Timegetter tg;
	
	
	public Panel(){
		this.setBounds(10, 60, 600, 500);
		tg = new Timegetter();
	}
	
	public void paintComponent (Graphics g) {
		super.paintComponent(g);
		int i=1;
		int startdaytm = startday+1;
		int week=1;
		int heigth = 40;
		int sethi = 100;
		Graphics2D g2=(Graphics2D)g;
		g2.setColor(Color.yellow);
		g.setFont(new Font("Britannic Bold", Font.BOLD, 20));
		g.setColor(Color.red);
		g.fillRect(10, 150-sethi, 60, 30);
		g.setColor(Color.black);
		g.drawString(nowyear+" / "+ nowmonth, 190,120-sethi+10);
		g.setFont(new Font("1훈떡볶이 R", Font.BOLD, 15));
		g.drawRect(10, 150-sethi, 60, 30);
		g.drawString("일",35, 170-sethi);
		g.setColor(Color.gray);
		g.fillRect(10+(margin*1), 150-sethi, 60, 30);
		g.fillRect(10+(margin*2), 150-sethi, 60, 30);
		g.fillRect(10+(margin*3), 150-sethi, 60, 30);
		g.fillRect(10+(margin*4), 150-sethi, 60, 30);
		g.fillRect(10+(margin*5), 150-sethi, 60, 30);
		g.setColor(Color.black);
		g.drawRect(10+(margin*1), 150-sethi, 60, 30);
		g.drawRect(10+(margin*2), 150-sethi, 60, 30);
		g.drawRect(10+(margin*3), 150-sethi, 60, 30);
		g.drawRect(10+(margin*4), 150-sethi, 60, 30);
		g.drawRect(10+(margin*5), 150-sethi, 60, 30);
		g.drawString("월", 35+(margin*1), 170-sethi);
		g.drawString("화", 35+(margin*2), 170-sethi);
		g.drawString("수", 35+(margin*3), 170-sethi);
		g.drawString("목", 35+(margin*4), 170-sethi);
		g.drawString("금", 35+(margin*5), 170-sethi);
		String years = String.valueOf(tg.getyear());
		String months = String.valueOf(tg.getmonth());
		String dates = String.valueOf(tg.getdate());
		String hours = String.valueOf(tg.gethour());
		String minutes = String.valueOf(tg.getminute());
		String seconds = String.valueOf(tg.getsecond());
		g.drawString(years+" / "+months+" / "+dates+" / "+hours+":"+minutes+":"+seconds,0,0);
		g.setColor(Color.blue);
		g.fillRect(10+(margin*6), 150-sethi, 60, 30);
		g.setColor(Color.black);
		g.drawRect(10+(margin*6), 150-sethi, 60, 30);
		g.setColor(Color.white);
		g.drawString("토", 35+(margin*6), 170-sethi);
		g.setColor(Color.CYAN);
		g.setColor(Color.gray);
		g.setFont(new Font("Britannic Bold", Font.BOLD, 15));
		g2.setStroke(new BasicStroke(6,BasicStroke.CAP_ROUND,0));
		while(i<=daynum) {
			
			String istr = Integer.toString(i);
			if(startdaytm!=8) {
				g.setColor(Color.gray);
				g.fillRect(10+(margin*(startdaytm-1)), 150+(heigth*week)-sethi, 60, 30);
				if(isnow(i,nowmonth,nowyear)) { 
					g.setColor(Color.yellow);
			        g.drawRect(10+(margin*(startdaytm-1)), 150+(heigth*week)-sethi, 60, 30);
			        g.setColor(Color.gray);
				}
				g.setColor(Color.black);
				g.drawString(istr,10+(margin*(startdaytm-1))+25, 150+(heigth*week)+20-sethi);
				}
			else {
				startdaytm=1;
				week++;
				g.setColor(Color.gray);
				g.fillRect(10+(margin*(startdaytm-1)), 150+(heigth*week)-sethi, 60, 30);
				g.setColor(Color.black);
				g.drawString(istr,10+(margin*(startdaytm-1))+25, 150+(heigth*week)+20-sethi);
			}
			startdaytm++;
			i++;
		}
		g.setFont(new Font("스웨거TTF", Font.BOLD, 13));
		g.drawString("Made by 2017013072 윤지상",340,340);
		/*try {
			Thread.sleep(10);
			this.repaint();
		} catch(InterruptedException e) {
			e.printStackTrace();
		}*/
		
	}
	
	public boolean isnow(int date, int month, int year) {
		if(year==tg.getyear()) {
			if(month==tg.getmonth()) {
				if(date==tg.getdate()) {
					return true;
				}
				return false;
			}
			return false;
		}
		return false;
		
	}
	
	public int getstartday() {
		return startday;
	}
	public void setstartday(int nowstart) {
		this.startday = nowstart;
	}
	
	public int getdaynum() {
		return daynum;
	}
	public void setdaynum(int howmanydate) {
		this.daynum = howmanydate;
	}
	
	public int getnowyear() {
		return nowyear;
	}
	public void setnowyear(int nowyear) {
		this.nowyear = nowyear;
	}
	
	public int getnowmonth() {
		return nowmonth;
	}
	public void setnowmonth(int nowmonth) {
		this.nowmonth = nowmonth;
	}
	
	public int getnowday() {
		return nowday;
	}
	public void setnowday(int nowday) {
		this.nowday = nowday;
	}
	

}
