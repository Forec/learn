package date_8_22;

import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;

import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JProgressBar;
import javax.swing.LayoutStyle.ComponentPlacement;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import javax.swing.plaf.nimbus.NimbusLookAndFeel;
import java.awt.Font;

public class LearnFrame extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private MyPanel myPanel;
	private int mx,my,jfx,jfy;
	private JButton btnMin;
	private JButton btnMax;
	private JButton btnExit;
	private JProgressBar progressBar;
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		try {
			UIManager.setLookAndFeel(new NimbusLookAndFeel());
		} catch (UnsupportedLookAndFeelException e1) {
			e1.printStackTrace();
		}
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					LearnFrame frame = new LearnFrame();
					Image image = new ImageIcon("test.png").getImage();
					frame.setIconImage(image);
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/** 
	 * Create the frame.
	 */
	public LearnFrame() {
		setUndecorated(true);
		setBackground(new Color(0,0,0,0));
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		myPanel = new MyPanel();
		myPanel.addMouseMotionListener(new MouseMotionAdapter() {
			@Override
			public void mouseDragged(MouseEvent e) {
				setLocation(jfx+e.getXOnScreen()-mx, jfy+e.getYOnScreen()-my);
			}
		});
		myPanel.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				mx = e.getXOnScreen();
				my = e.getYOnScreen();
				jfx = getX();
				jfy = getY();
			}
		});
		myPanel.setOpaque(false);
		setContentPane(myPanel);
		
		JPanel panel = new JPanel();
		panel.setOpaque(false);
		panel.setBounds(0, 30, 450, 270);
		myPanel.setLayout(null);
		myPanel.add(panel);
		
		btnExit = new JButton("EXIT");
		btnExit.setUI(new MyButtonUI());
		btnExit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			}
		});
		
		btnMax = new JButton("MAX");
		btnMax.setUI(new MyButtonUI());
		btnMax.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				if (getExtendedState()==JFrame.MAXIMIZED_BOTH){
					setExtendedState(JFrame.NORMAL);
					btnMax.setText("MAX");
				}
				else{
					setExtendedState(JFrame.MAXIMIZED_BOTH);
					btnMax.setText("Re");
				}
			}
		});
		
		btnMin = new JButton("MIN");
		btnMin.setUI(new MyButtonUI());
		btnMin.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				setExtendedState(JFrame.ICONIFIED);
			}
		});
		btnMin.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				
			}
		});
		
		progressBar = new JProgressBar();
		progressBar.setFont(new Font("Courier New", Font.BOLD, 15));
		progressBar.setStringPainted(true);
		
		JButton btnNewButton = new JButton("New button");
		btnNewButton.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				
					new Thread(){
						public void run(){
							for (int i = 0 ; i <= 100 ; i ++){					
								progressBar.setValue(i);
								try {
									Thread.sleep(500);
								} catch (InterruptedException e) {
									e.printStackTrace();
								}
							}
						}
					}.start();
				}
		});
		GroupLayout gl_panel = new GroupLayout(panel);
		gl_panel.setHorizontalGroup(
			gl_panel.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_panel.createSequentialGroup()
					.addContainerGap()
					.addGroup(gl_panel.createParallelGroup(Alignment.LEADING)
						.addGroup(Alignment.TRAILING, gl_panel.createSequentialGroup()
							.addComponent(btnMin)
							.addPreferredGap(ComponentPlacement.UNRELATED)
							.addComponent(btnMax)
							.addPreferredGap(ComponentPlacement.RELATED)
							.addComponent(btnExit)
							.addGap(40))
						.addGroup(Alignment.TRAILING, gl_panel.createSequentialGroup()
							.addComponent(btnNewButton)
							.addGap(84))
						.addGroup(gl_panel.createSequentialGroup()
							.addComponent(progressBar, GroupLayout.DEFAULT_SIZE, 438, Short.MAX_VALUE)
							.addContainerGap())))
		);
		gl_panel.setVerticalGroup(
			gl_panel.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_panel.createSequentialGroup()
					.addContainerGap()
					.addGroup(gl_panel.createParallelGroup(Alignment.BASELINE)
						.addComponent(btnMin)
						.addComponent(btnMax)
						.addComponent(btnExit))
					.addGap(42)
					.addComponent(progressBar, GroupLayout.PREFERRED_SIZE, 29, GroupLayout.PREFERRED_SIZE)
					.addPreferredGap(ComponentPlacement.UNRELATED)
					.addComponent(btnNewButton)
					.addContainerGap(135, Short.MAX_VALUE))
		);
		panel.setLayout(gl_panel);
		btnExit.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				System.exit(0);
			}
		});
	}
}
