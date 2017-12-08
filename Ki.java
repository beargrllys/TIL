package project;

import java.awt.EventQueue;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.util.Calendar;
import java.util.GregorianCalendar;

import javax.swing.AbstractButton;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;

public class Ki extends JFrame {

	private JPanel contentPane;
	private JTextField year;
	private JTextField month;
	private JTextField date;
	private JTextField hour;
	private JTextField minute;
	private JTextField memo;
	//------------------------------
	private int yeari;
	private int monthi;
	private int datei;
	private int houri;
	private int minutei;
	//------------------------------
	private String memostr;
	private String mass="";
	//------------------------------
	private boolean important = false;
	private boolean should = false;
	private boolean special = false;
	private boolean every = false;
	private boolean gitar = false;
	private boolean codend = false;
	private int[] nodes;



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

	public Ki() {
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 400, 400);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		year = new JTextField();
		year.setBounds(24, 39, 48, 31);
		contentPane.add(year);
		year.setColumns(10);
		
		JLabel lblNewLabel = new JLabel("년");
		lblNewLabel.setFont(new Font("배달의민족 도현", Font.PLAIN, 25));
		lblNewLabel.setBounds(73, 31, 57, 46);
		contentPane.add(lblNewLabel);
		
		month = new JTextField();
		month.setBounds(106, 39, 48, 31);
		contentPane.add(month);
		month.setColumns(10);
		
		JLabel label = new JLabel("월");
		label.setFont(new Font("배달의민족 도현", Font.PLAIN, 25));
		label.setBounds(166, 35, 31, 39);
		contentPane.add(label);
		
		date = new JTextField();
		date.setBounds(195, 39, 48, 31);
		contentPane.add(date);
		date.setColumns(10);
		
		JLabel lblNewLabel_1 = new JLabel("일");
		lblNewLabel_1.setFont(new Font("배달의민족 도현", Font.PLAIN, 25));
		lblNewLabel_1.setBounds(255, 25, 48, 58);
		contentPane.add(lblNewLabel_1);
		
		hour = new JTextField();
		hour.setBounds(24, 94, 48, 31);
		contentPane.add(hour);
		hour.setColumns(10);
		
		JLabel lblNewLabel_2 = new JLabel("시");
		lblNewLabel_2.setFont(new Font("배달의민족 도현", Font.PLAIN, 25));
		lblNewLabel_2.setBounds(73, 87, 57, 46);
		contentPane.add(lblNewLabel_2);
		
		minute = new JTextField();
		minute.setBounds(106, 94, 48, 31);
		contentPane.add(minute);
		minute.setColumns(10);
		
		JLabel lblNewLabel_3 = new JLabel("분");
		lblNewLabel_3.setFont(new Font("배달의민족 도현", Font.PLAIN, 25));
		lblNewLabel_3.setBounds(166, 84, 31, 46);
		contentPane.add(lblNewLabel_3);
		
		JCheckBox chckbxNewCheckBox = new JCheckBox("중요한 거!");
		chckbxNewCheckBox.setFont(new Font("배달의민족 도현", Font.PLAIN, 14));
		chckbxNewCheckBox.setBounds(216, 100, 115, 23);
		contentPane.add(chckbxNewCheckBox);
		
		memo = new JTextField();
		memo.setBounds(24, 193, 307, 92);
		contentPane.add(memo);
		memo.setColumns(10);
		
		JButton btnNewButton_1 = new JButton("취소");
		btnNewButton_1.setFont(new Font("배달의민족 도현", Font.PLAIN, 14));
		btnNewButton_1.setBounds(201, 295, 130, 39);
		contentPane.add(btnNewButton_1);
		btnNewButton_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
			}});
		
		JRadioButton rdbtnNewRadioButton = new JRadioButton("해야하는 일");
		rdbtnNewRadioButton.setBounds(24, 131, 121, 23);
		contentPane.add(rdbtnNewRadioButton);
		rdbtnNewRadioButton.addItemListener(new SelectItemListener());
		
		JRadioButton rdbtnNewRadioButton_1 = new JRadioButton("특별한 행사");
		rdbtnNewRadioButton_1.setBounds(166, 131, 121, 23);
		contentPane.add(rdbtnNewRadioButton_1);
		
		JRadioButton rdbtnNewRadioButton_2 = new JRadioButton("정기적 일정");
		rdbtnNewRadioButton_2.setBounds(24, 164, 121, 23);
		contentPane.add(rdbtnNewRadioButton_2);
		
		JRadioButton rdbtnNewRadioButton_3 = new JRadioButton("기타");
		rdbtnNewRadioButton_3.setBounds(166, 164, 121, 23);
		contentPane.add(rdbtnNewRadioButton_3);
		
		ButtonGroup buttongrp = new ButtonGroup();
		buttongrp.add(rdbtnNewRadioButton);
		buttongrp.add(rdbtnNewRadioButton_1);
		buttongrp.add(rdbtnNewRadioButton_2);
		buttongrp.add(rdbtnNewRadioButton_3);
		
		rdbtnNewRadioButton.addItemListener(new SelectItemListener());
		rdbtnNewRadioButton_1.addItemListener(new SelectItemListener());
		rdbtnNewRadioButton_2.addItemListener(new SelectItemListener());
		rdbtnNewRadioButton_3.addItemListener(new SelectItemListener());
		
		JButton btnNewButton = new JButton("확인");
		btnNewButton.setFont(new Font("배달의민족 도현", Font.PLAIN, 14));
		btnNewButton.setBounds(24, 295, 130, 39);
		contentPane.add(btnNewButton);
		btnNewButton.addActionListener(new ActionListener() {
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
			if(chckbxNewCheckBox.isSelected()) {
				important = true;
			}
			}
		});
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
