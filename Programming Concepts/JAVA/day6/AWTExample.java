package day6;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;

public class AWTExample extends WindowAdapter implements ActionListener{

	Frame f1;
	Label l1,l2,l3;
	TextField t1,t2;
	Button b1;
	
	AWTExample() {
		f1 = new Frame("My Frame");
		l1 = new Label("Label 1");
		l2 = new Label("Label 2");
		l3 = new Label("");
		
		t1 = new TextField("");
		t2 = new TextField("");
		
		b1 = new Button("Click");
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		
	}
	public static void main(String[] args) {
		
		
		
	}

}
