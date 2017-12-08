package ProjectFinal;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;

public class Scedule extends JFrame implements Runnable{
	
	private int stddate=1;
	private int stdmonth=11;
	private int stdyear=2017;
	private int stdstart = 3;
	private int nowdate;
	private int nowmonth;
	private int nowyear;
	private int nowstart;
	private int howmanydate;
	private Panel pan;
	private Timegetter tg;
	private JLabel label;
	private String timeString = "";
	private int hours=0, minutes=0, seconds=0;  
	private Thread t=null;  
	
	public Scedule(String title) {
		super(title);
		this.setLayout(null);
		this.setBounds(10,10,550,450);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		tg = new Timegetter();
		nowdate = tg.getdate();
		nowmonth = tg.getmonth();
		nowyear = tg.getyear();
		nowstart = ((stdstart+nowset())%7);
		//현재 년 월 일
		howmanydate = howdate(nowmonth);
		pan = new Panel();
		pan.setstartday(nowstart);
		pan.setdaynum(howmanydate);
		pan.setnowmonth(nowmonth);
		pan.setnowyear(nowyear);
		pan.setnowday(nowdate);
		label=new JLabel();  
		label.setBounds(130,0,300,50);
		t = new Thread(this);  
        t.start(); 
		this.setVisible(true);
		setBackground(Color.white);
		JButton nextMonthButt = new JButton("다음달");
		nextMonthButt.setBounds(400,10,100,30);
		JButton beforeMonthButt = new JButton("이전달");
		beforeMonthButt.setBounds(20,10,100,30);
		
		this.getContentPane().add(nextMonthButt);
		this.getContentPane().add(beforeMonthButt);
		nextMonthButt.addActionListener( new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent k) {
				// 다음달버튼 이벤트 처리
				nowmonth+=1;
				if(nowmonth==13) {
					nowmonth=1;
				}
				nowstart = afterstart(nowmonth);
				System.out.println(nowmonth);
				howmanydate = howdate(nowmonth);
				pan.setstartday(nowstart);
				pan.setdaynum(howmanydate);
				pan.setnowmonth(nowmonth);
				pan.setnowyear(nowyear);
				pan.repaint();
				
				
			}
			
		});
		beforeMonthButt.addActionListener( new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent k) {
				// 다음달버튼 이벤트 처리
				nowmonth-=1;
				if(nowmonth==0) {
					nowmonth=12;
				}
				nowstart = beforestart(nowmonth);
				System.out.println(nowmonth);
				howmanydate = howdate(nowmonth);
				pan.setstartday(nowstart);
				pan.setdaynum(howmanydate);
				pan.setnowmonth(nowmonth);
				pan.setnowyear(nowyear);
				pan.repaint();
				
				
			}
			
		});
		this.getContentPane().add(nextMonthButt);
		this.getContentPane().add(beforeMonthButt);
		this.getContentPane().add(pan);
		this.getContentPane().add(label);
	}
	
	public int howdate (int month) {
		int date;
		if(month==1||month==3||month==5||month==7||month==8||month==10||month==12) {
			date=31;
			return date;
		}
		else if(month==2) {
			if( nowyear%4 == 0) {
				date = 29;
				return date;
			}
			else {
			date = 28;
			return date;}
		}
		else {
			date = 30;
			return date;
		}
	}
	
	public int afterstart(int month) {
		int monthtemp = month-1;
		if(month==1) {
			monthtemp=12;
			nowyear++;
		}
		int start;
		start = nowstart + howdate(monthtemp)-1;

		
		int after = (start%7)+1;
		if(after==7) {
			after=0;
		}
		nowstart = after;
		return after;
		
	}
	
	public int beforestart(int month) {
		int monthtemp = month+1;
		if(monthtemp==13) {
			monthtemp=1;
			nowyear--;
		}
		int start;
		start = howdate(month)-(nowstart);

		
		int before = 8-((start%7)+1);
		if(before == 7) {
			before = 0;
		}
		nowstart = before;
		return before;
		
	}
	
	public int nowset() {
		int days=0;
		int tempyear = stdyear;
		int tempmonth = stdmonth;
		int tempday = stddate;
		while(true) {
			while(tempmonth != 13 && tempday != 32) {
				while(tempday != howdate(tempmonth)+1) {
					tempday++;
					days++;	
					if(tempyear == nowyear && tempmonth == nowmonth && tempday == nowdate) {
						return days-1;
					}
					}
				tempday=1;
				tempmonth++;			
			}
			tempmonth=1;
			tempday=1;
			tempyear++;
		}
	}

	@Override
	public void run() {
		try {  
	         while (true) {  
	  
	            Calendar cal = Calendar.getInstance();  
	            hours = tg.gethour();
	            if ( hours > 12 ) hours -= 12;  
	            minutes = tg.getminute(); 
	            seconds = tg.getsecond(); 
	  
	            SimpleDateFormat formatter = new SimpleDateFormat("yyyy / MM / dd | hh:mm:ss");  
	            Date date = cal.getTime();  
	            timeString = formatter.format( date );  
	  
	            printTime();  
	  
	            t.sleep( 1000 );  // interval given in milliseconds  
	         }  
	      }  
	      catch (Exception e) { }  
		
	}
	public void printTime(){  
		Font font = new Font("Arial Black", ABORT, 20);
		label.setFont(font);
		label.setText(timeString);  
		}  
}