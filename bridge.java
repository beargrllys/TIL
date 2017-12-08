package scedule;

public class bridge {
	
	private int nowstart;
	private int howmanydate;
	
	public int getnowstart() {
		return nowstart;
	}
	public void setnowstart(int nowstart) {
		this.nowstart = nowstart;
	}
	
	public int gethowmanydate() {
		return howmanydate;
	}
	public void sethowmanydate(int howmanydate) {
		this.howmanydate = howmanydate;
	}
	
	public bridge(int nowstart, int howmanydate) {
		super();
		this.nowstart = nowstart;
		this.howmanydate = howmanydate;
	}

}
