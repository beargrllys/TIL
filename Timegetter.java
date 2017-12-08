package ProjectFinal;

import java.util.Calendar;
import java.util.GregorianCalendar;

public class Timegetter{
	
	private int nowhour = 0;
	private int nowminute = 0;
	private int nowsecond = 0;
	private int nowdate;
	private int nowmonth;
	private int nowyear;
	
	public Timegetter() {
		getrealtime();
	}
	

	
	public void getrealtime() {
		GregorianCalendar gc = new GregorianCalendar();
		nowdate = gc.get(Calendar.DATE);
		nowmonth = gc.get(Calendar.MONTH)+1;
		nowyear = gc.get(Calendar.YEAR);
		nowhour = gc.get(Calendar.HOUR);
		nowminute = gc.get(Calendar.MINUTE);
		nowsecond = gc.get(Calendar.SECOND);
	}
	
	public int getsecond() {
		return nowsecond;
	}
	
	public int getminute() {
		return nowminute;
	}
	
	public int gethour() {
		return nowhour;
	}
	
	public int getdate() {
		return nowdate;
	}
	
	public int getmonth() {
		return nowmonth;
	}
	
	public int getyear() {
		return nowyear;
	}

}
