package scedule;

import java.awt.BorderLayout;
import java.awt.FlowLayout;

import javax.swing.AbstractButton;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.util.Calendar;
import java.util.GregorianCalendar;

import javax.swing.JCheckBox;
import javax.swing.JRadioButton;

public class vtrb extends JDialog {

	private final JPanel contentPanel = new JPanel();
	private JTextField year;
	private JTextField month;
	private JTextField date;
	private JTextField hour;
	private JTextField minute;
	private JTextField memo;
	private int yeari;
	private int monthi;
	private int datei;
	private int houri;
	private int minutei;
	//------------------------------
	private String memostr;
	private String mass="";
	private JCheckBox ckbx;
	//------------------------------
	private boolean important = false;
	private boolean should = false;
	private boolean special = false;
	private boolean every = false;
	private boolean gitar = false;
	private boolean codend = false;
	private int[] nodes;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		try {
			vtrb dialog = new vtrb();
			dialog.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
			dialog.setVisible(true);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public String getMemostr() {
		return memostr;
	}
	
	public int[] getnode() {
		return nodes;
	}
	public int isImportant() {
		if(important == true) {
			return 1;
		}
		else {
			return 0;
		}
	}

	public int getMode() {
		if(should==true) {
			return 1;
		}
		else if(special==true) {
			return 2;
		}
		else if(every==true) {
			return 3;
		}
		else if(gitar==true) {
			return 4;
		}
		else {
			return 5;
		}
	}
	public vtrb() {
		setBounds(100, 100, 450, 300);
		getContentPane().setLayout(new BorderLayout());
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane().add(contentPanel, BorderLayout.CENTER);
		contentPanel.setLayout(null);
		{
			year = new JTextField();
			year.setBounds(12, 10, 78, 30);
			contentPanel.add(year);
			year.setColumns(10);
		}
		{
			JLabel label = new JLabel("년");
			label.setFont(new Font("스웨거 TTF", Font.PLAIN, 25));
			label.setBounds(93, 10, 25, 30);
			contentPanel.add(label);
		}
		{
			month = new JTextField();
			month.setColumns(10);
			month.setBounds(114, 10, 37, 30);
			contentPanel.add(month);
		}
		{
			JLabel label = new JLabel("월");
			label.setFont(new Font("스웨거 TTF", Font.PLAIN, 25));
			label.setBounds(153, 10, 25, 30);
			contentPanel.add(label);
		}
		{
			date = new JTextField();
			date.setColumns(10);
			date.setBounds(174, 10, 37, 30);
			contentPanel.add(date);
		}
		{
			hour = new JTextField();
			hour.setColumns(10);
			hour.setBounds(266, 10, 37, 30);
			contentPanel.add(hour);
		}
		{
			minute = new JTextField();
			minute.setColumns(10);
			minute.setBounds(342, 10, 37, 30);
			contentPanel.add(minute);
		}
		{
			JLabel label = new JLabel("일");
			label.setFont(new Font("스웨거 TTF", Font.PLAIN, 25));
			label.setBounds(214, 10, 25, 30);
			contentPanel.add(label);
		}
		{
			JLabel label = new JLabel("시");
			label.setFont(new Font("스웨거 TTF", Font.PLAIN, 25));
			label.setBounds(308, 10, 25, 30);
			contentPanel.add(label);
		}
		{
			JLabel label = new JLabel("분");
			label.setFont(new Font("스웨거 TTF", Font.PLAIN, 25));
			label.setBounds(385, 10, 25, 30);
			contentPanel.add(label);
		}
		{
			JCheckBox chckbxNewCheckBox = new JCheckBox("중요한 일!");
			chckbxNewCheckBox.setFont(new Font("스웨거 TTF", Font.PLAIN, 22));
			chckbxNewCheckBox.setBounds(12, 63, 115, 23);
			contentPanel.add(chckbxNewCheckBox);
			ckbx = chckbxNewCheckBox;
		}
		{
			JRadioButton special = new JRadioButton("특별한 일");
			special.setFont(new Font("스웨거 TTF", Font.PLAIN, 18));
			special.setBounds(12, 103, 121, 23);
			contentPanel.add(special);
		}
		{
			JRadioButton every = new JRadioButton("정기적인 일");
			every.setFont(new Font("스웨거 TTF", Font.PLAIN, 18));
			every.setBounds(12, 126, 121, 23);
			contentPanel.add(every);
		}
		{
			JRadioButton should = new JRadioButton("해야하는 일");
			should.setFont(new Font("스웨거 TTF", Font.PLAIN, 18));
			should.setBounds(12, 151, 121, 23);
			contentPanel.add(should);
		}
		{
			JRadioButton gitar = new JRadioButton("기타");
			gitar.setFont(new Font("스웨거 TTF", Font.PLAIN, 18));
			gitar.setBounds(12, 176, 121, 23);
			contentPanel.add(gitar);
		}
		{
			memo = new JTextField();
			memo.setBounds(139, 93, 271, 108);
			contentPanel.add(memo);
			memo.setColumns(10);
		}
		{
			JPanel buttonPane = new JPanel();
			buttonPane.setLayout(new FlowLayout(FlowLayout.RIGHT));
			getContentPane().add(buttonPane, BorderLayout.SOUTH);
			{
				
				JButton okButton = new JButton("OK");
				okButton.setActionCommand("OK");
				buttonPane.add(okButton);
				getRootPane().setDefaultButton(okButton);
				okButton.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
						boolean save = true;
						int temp;
						
						
						try{
							temp = Integer.parseInt(year.getText());
							yeari = temp;
							}
						catch(NumberFormatException e1) {
							temp = -1;
						}
						if(temp<=0) {
							if(temp == -1) {
								mass = mass + "year ";

							}
							else {
								JOptionPane.showMessageDialog(null, "Invaild year");
							}
							save = false;
							}
							
							
						try{
							temp = Integer.parseInt(month.getText());
							monthi = temp;
							}
						catch(NumberFormatException e1) {
							temp = -1;
						}
						if(temp<0 || temp>12) {
							if(temp == -1) {
								mass = mass + "month ";

							}
							else {
								JOptionPane.showMessageDialog(null, "Invaild month");
							}
							save = false;
							}
							
						try{
							temp = Integer.parseInt(date.getText());
							datei = temp;
							}
						catch(NumberFormatException e1) {
							temp = -1;
						}
						if(temp<0 || temp > howdate(Integer.parseInt(month.getText()))) {
							if(temp == -1) {
								mass = mass + "date ";
								
							}
							else{
								JOptionPane.showMessageDialog(null, "Invaild date");
							}
							save = false;
							}
							
							
							
						try{
							temp = Integer.parseInt(hour.getText());
							houri = temp;
							}
						catch(NumberFormatException e1) {
							temp = -1;
						}
						if(temp<0 || temp>24) {
							if(temp == -1) {
								mass = mass + "hour ";				}
							else {
								JOptionPane.showMessageDialog(null, "Invaild hour");
								save = false;
							}
							}
							
							
							
						try{
							temp = Integer.parseInt(minute.getText());
							minutei = temp;
							}
						catch(NumberFormatException e1) {
							temp = -1;
						}
						if(temp<0||temp>59) {
							if(temp == -1) {
								mass = mass + "minute ";
							}
							else  {
								JOptionPane.showMessageDialog(null, "Invaild minute");
								save = false;
							}
							}
						memostr = memo.getText();
						if(save) {
							if(mass=="") {
								int[] node=  new int [10];
								node[0] = yeari;
								node[1] = monthi;
								node[2] = datei;
								node[3] = houri;
								node[4] = minutei;
								node[5] = isImportant();
								node[6] = getMode();
								nodes = node;
								codend = true;
								System.out.println("mwoe");
							}
						}
						else {
							yeari = 0;
							monthi = 0;
							datei = 0;
							houri = 0;
							minutei = 0;
							year.setText("");
							month.setText("");
							date.setText("");
							hour.setText("");
							minute.setText("");
							memo.setText("");
							if(mass != "") {
							JOptionPane.showMessageDialog(null, "Must input "+ mass);
							}
						}
						if(ckbx.isSelected()) {
							important = true;
						}
						}
					});
				
			}
			{
				JButton cancelButton = new JButton("Cancel");
				cancelButton.setActionCommand("Cancel");
				buttonPane.add(cancelButton);
				cancelButton.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
						dispose();
					}});
			}
			
		}
		
	}
	class SelectItemListener implements ItemListener{

		@Override
		public void itemStateChanged(ItemEvent e) {
			AbstractButton sel = (AbstractButton)e.getItemSelectable();
			if(e.getStateChange() == ItemEvent.SELECTED) {
				if (sel.getText().equals("해야하는 일")) {
					should = true;
					special = false;
					every = false;
					gitar = false;
				}
				else if (sel.getText().equals("특별한 행사")) {
					should = false;
					special = true;
					every = false;
					gitar = false;
				}
				else if (sel.getText().equals("정기적 일정")) {
					should = false;
					special = false;
					every = true;
					gitar = false;
				}
				else if (sel.getText().equals("기타")) {
					should = false;
					special = false;
					every = false;
					gitar = true;
				}
			}
		}
		
	}

	public int howdate (int month) {
		int date;
		if(month==1||month==3||month==5||month==7||month==8||month==10||month==12) {
			date=31;
			return date;
		}
		else if(month==2) {
			if( new GregorianCalendar().get(Calendar.YEAR)%4 == 0) {
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

}
