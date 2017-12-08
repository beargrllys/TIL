package scedule;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import project.Ki;

public class Set implements ActionListener{
	
	private Ki ki;
	
	public Set () {
		ki = new Ki();
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		
		String year = ki.getTitle();
		System.out.println(year);
		
	}

}
