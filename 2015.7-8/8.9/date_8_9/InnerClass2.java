package date_8_9;

import javax.swing.JOptionPane;
import javax.swing.Timer;

public class InnerClass2 {
	public static void main(String []args){
		TalkingClock jabberer = new TalkingClock(2000,true);
		TalkingClock.TimePrinter listener = jabberer.new TimePrinter();
	//	TimePrinter a = new TimePrinter();
	//	jabberer.start();
	//	TimePrinter newtime = new TimePrinter();
		Timer t = new Timer(1000,listener);
		t.start();
		JOptionPane.showMessageDialog(null,"Quit?");
		System.out.println("test");
	}
}