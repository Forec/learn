package date_8_9;

import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;
import javax.swing.Timer;

public class InnerClass {
	public static void main(String []args){
		TalkingClock clock = new TalkingClock(1000,true);
		clock.start();
		JOptionPane.showMessageDialog(null,"Quit?");
		System.exit(0);
	}
}

class TalkingClock{
	private int interval;
	private boolean beep;
	
	public TalkingClock(int interval,boolean beep){
		this.interval = interval;
		this.beep = beep;
	}
	
	public void start(){
		ActionListener listener = this.new TimePrinter();
		Timer t = new Timer(interval,listener);
		t.start();
	}
	public class TimePrinter implements ActionListener{
		/**
		 * if the field is private , then only in TalkingClock can we construct TimePrinter
		 * if the field is public , then we can also construct TimePrinter in InnerClass2
		 */
		public void actionPerformed(ActionEvent event){
			Date now = new Date();
			System.out.println("At the tone, the tinme is "+now);
			if (TalkingClock.this.beep)
				Toolkit.getDefaultToolkit().beep();
		}
	}
}
