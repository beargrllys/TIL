package project;

import java.awt.Font;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

import javax.swing.JFrame;
import javax.swing.JLabel; 




public class time extends JFrame implements Runnable{  
JFrame f;  
Thread t=null;  
int hours=0, minutes=0, seconds=0;  
String timeString = "";  
JLabel b;  
  
public time(){  
    f=new JFrame();  
      
    t = new Thread(this);  
        t.start();  
      
    b=new JLabel();  
        b.setBounds(0,0,100,50);  
      
    f.add(b);  
    f.setSize(100,50);  
    f.setLayout(null);  
    f.setVisible(true);  
}  
  
 public void run() {  
      try {  
         while (true) {  
  
            Calendar cal = Calendar.getInstance();  
            hours = cal.get( Calendar.HOUR_OF_DAY );  
            if ( hours > 12 ) hours -= 12;  
            minutes = cal.get( Calendar.MINUTE );  
            seconds = cal.get( Calendar.SECOND );  
  
            SimpleDateFormat formatter = new SimpleDateFormat("hh:mm:ss");  
            Date date = cal.getTime();  
            timeString = formatter.format( date );  
  
            printTime();  
  
            t.sleep( 1000 );  // interval given in milliseconds  
         }  
      }  
      catch (Exception e) { }  
 }  
  
public void printTime(){  
	Font font = new Font("Impact", ABORT, 100);
	b.setFont(font);
	b.setText(timeString);  
}  
}  