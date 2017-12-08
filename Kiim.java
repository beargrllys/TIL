package scedule;

import java.awt.BorderLayout;
import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JTextField;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.JCheckBox;
import javax.swing.JRadioButton;

public class Kiim extends JDialog {

	private final JPanel contentPanel = new JPanel();
	private JTextField year;
	private JTextField month;
	private JTextField date;
	private JTextField textField_3;
	private JTextField textField;
	private JTextField textField_1;
	

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		try {
			Kiim dialog = new Kiim();
			dialog.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
			dialog.setVisible(true);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	/**
	 * Create the dialog.
	 */
	public Kiim() {
		setBounds(100, 100, 378, 348);
		getContentPane().setLayout(new BorderLayout());
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane().add(contentPanel, BorderLayout.CENTER);
		contentPanel.setLayout(null);
		
		year = new JTextField();
		year.setBounds(12, 14, 75, 39);
		contentPanel.add(year);
		year.setColumns(10);
		
		JLabel lblNewLabel = new JLabel("년");
		lblNewLabel.setFont(new Font("스웨거 TTF", Font.PLAIN, 25));
		lblNewLabel.setBounds(90, 10, 28, 50);
		contentPanel.add(lblNewLabel);
		
		month = new JTextField();
		month.setBounds(112, 14, 34, 39);
		contentPanel.add(month);
		month.setColumns(10);
		
		JLabel lblNewLabel_1 = new JLabel("월");
		lblNewLabel_1.setFont(new Font("스웨거 TTF", Font.PLAIN, 25));
		lblNewLabel_1.setBounds(146, 12, 28, 41);
		contentPanel.add(lblNewLabel_1);
		
		date = new JTextField();
		date.setBounds(171, 14, 28, 39);
		contentPanel.add(date);
		date.setColumns(10);
		
		JLabel lblNewLabel_2 = new JLabel("일");
		lblNewLabel_2.setFont(new Font("스웨거 TTF", Font.PLAIN, 25));
		lblNewLabel_2.setBounds(200, 14, 28, 39);
		contentPanel.add(lblNewLabel_2);
		
		JCheckBox chckbxNewCheckBox = new JCheckBox("중요한 일!");
		chckbxNewCheckBox.setFont(new Font("스웨거 TTF", Font.PLAIN, 18));
		chckbxNewCheckBox.setBounds(12, 69, 115, 23);
		contentPanel.add(chckbxNewCheckBox);
		
		JRadioButton rdbtnNewRadioButton = new JRadioButton("특별한 일");
		rdbtnNewRadioButton.setBounds(22, 94, 121, 23);
		contentPanel.add(rdbtnNewRadioButton);
		
		JRadioButton rdbtnNewRadioButton_1 = new JRadioButton("해야하는 일");
		rdbtnNewRadioButton_1.setBounds(22, 121, 121, 23);
		contentPanel.add(rdbtnNewRadioButton_1);
		
		JRadioButton rdbtnNewRadioButton_2 = new JRadioButton("정기적인 일");
		rdbtnNewRadioButton_2.setBounds(183, 94, 121, 23);
		contentPanel.add(rdbtnNewRadioButton_2);
		
		JRadioButton rdbtnNewRadioButton_3 = new JRadioButton("기타");
		rdbtnNewRadioButton_3.setBounds(183, 121, 121, 23);
		contentPanel.add(rdbtnNewRadioButton_3);
		
		textField_3 = new JTextField();
		textField_3.setBounds(12, 150, 338, 90);
		contentPanel.add(textField_3);
		textField_3.setColumns(10);
		
		textField = new JTextField();
		textField.setBounds(223, 14, 28, 39);
		contentPanel.add(textField);
		textField.setColumns(10);
		
		JLabel lblNewLabel_3 = new JLabel("시");
		lblNewLabel_3.setFont(new Font("스웨거 TTF", Font.PLAIN, 25));
		lblNewLabel_3.setBounds(252, 14, 28, 39);
		contentPanel.add(lblNewLabel_3);
		
		JLabel lblNewLabel_4 = new JLabel("분");
		lblNewLabel_4.setFont(new Font("스웨거 TTF", Font.PLAIN, 25));
		lblNewLabel_4.setBounds(319, 14, 33, 39);
		contentPanel.add(lblNewLabel_4);
		
		textField_1 = new JTextField();
		textField_1.setBounds(273, 14, 41, 39);
		contentPanel.add(textField_1);
		textField_1.setColumns(10);
		{
			JPanel buttonPane = new JPanel();
			buttonPane.setLayout(new FlowLayout(FlowLayout.RIGHT));
			getContentPane().add(buttonPane, BorderLayout.SOUTH);
		}
	}
}
