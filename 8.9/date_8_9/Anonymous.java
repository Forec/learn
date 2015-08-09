package date_8_9;

import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.Timer;

public class Anonymous {
	public static void main(String []args){
		TalkingClock2 clock = new TalkingClock2();
		clock.start(1000,true);
		JOptionPane.showMessageDialog(null, "Quit?");
		System.exit(0);
	}
}

class TalkingClock2{
	public void start(int interval,final boolean beep){
		ActionListener listener = new ActionListener(){
			public void actionPerformed(ActionEvent event){
				Date now = new Date();
				System.out.println("The time is "+now);
				if (beep)
					Toolkit.getDefaultToolkit().beep();
			}
		};
		Timer t= new Timer(interval,listener);
		t.start();
	}
}


/**
 * 1.双括号初始化
 * invite(new ArrayList<String>() {{ add("Harry"); add("Tony"); }}
 * 2.对于equals方法，使用getClass() == other.getClass() 对匿名子类会失败
 * 3.对于静态方法，没有this，所以不能直接调用getClass()，应该new Object(){}.getClass().getEnclosingClass()
 *   其中new Object(){}建立Object的一个匿名子类的一个匿名对象，getEnclosingClass得到其外部类，即包含这个静态方法的类
 */
