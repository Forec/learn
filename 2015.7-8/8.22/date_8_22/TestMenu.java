package date_8_22;

import java.awt.BorderLayout;
import java.awt.Component;
import java.awt.EventQueue;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JCheckBoxMenuItem;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JPopupMenu;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import javax.swing.border.EmptyBorder;

import com.seaglasslookandfeel.SeaGlassLookAndFeel;
import javax.swing.ImageIcon;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class TestMenu extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JPopupMenu myMenu;
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					TestMenu frame = new TestMenu();
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
	public TestMenu() {

		try {
			UIManager.setLookAndFeel(new SeaGlassLookAndFeel());
		} catch (UnsupportedLookAndFeelException e1) {
			e1.printStackTrace();
		}
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		
		JMenuBar menuBar = new JMenuBar();
		setJMenuBar(menuBar);
		
		JMenu mnNewMenu = new JMenu("File");
		menuBar.add(mnNewMenu);
		
		JMenuItem mntmOpen = new JMenuItem("Open");
		mntmOpen.setIcon(new ImageIcon(TestMenu.class.getResource("/javax/swing/plaf/metal/icons/ocean/collapsed-rtl.gif")));
		mnNewMenu.add(mntmOpen);
		
		JMenuItem mntmClose = new JMenuItem("Close");
		mntmClose.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		});
		mntmClose.setIcon(new ImageIcon(TestMenu.class.getResource("/javax/swing/plaf/metal/icons/ocean/collapsed.gif")));
		mnNewMenu.add(mntmClose);
		
		JMenu mnEdit = new JMenu("Edit");
		menuBar.add(mnEdit);
		
		JMenuItem mntmPaste = new JMenuItem("Paste");
		mnEdit.add(mntmPaste);
		
		JMenuItem mntmCopy = new JMenuItem("Copy");
		mnEdit.add(mntmCopy);
		
		JMenuItem mntmCut = new JMenuItem("Cut");
		mnEdit.add(mntmCut);
		
		JMenu mnStyle = new JMenu("Style");
		mnEdit.add(mnStyle);
		
		JMenuItem mntmRed = new JMenuItem("Red");
		mnStyle.add(mntmRed);
		
		JMenuItem mntmYellow = new JMenuItem("Yellow");
		mnStyle.add(mntmYellow);
		
		JMenuItem mntmGreen = new JMenuItem("Green");
		mnStyle.add(mntmGreen);
		
		JMenu mnAppend = new JMenu("Append");
		mnEdit.add(mnAppend);
		
		JCheckBoxMenuItem chckbxmntmA = new JCheckBoxMenuItem("A");
		mnAppend.add(chckbxmntmA);
		
		JCheckBoxMenuItem chckbxmntmB = new JCheckBoxMenuItem("B");
		mnAppend.add(chckbxmntmB);
		
		JCheckBoxMenuItem chckbxmntmC = new JCheckBoxMenuItem("C");
		mnAppend.add(chckbxmntmC);
		
		JCheckBoxMenuItem chckbxmntmD = new JCheckBoxMenuItem("D");
		mnAppend.add(chckbxmntmD);
		contentPane = new JPanel();
		contentPane.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				myMenu.show(TestMenu.this,e.getX(),e.getY());
			}
		});
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));
		setContentPane(contentPane);
		// -------------------------------------------

		myMenu = new JPopupMenu();
		JMenuItem item1 = new JMenuItem("File");
		JMenuItem item2 = new JMenuItem("Edit");
		JMenuItem item3 = new JMenuItem("Settings");
		JMenuItem item4 = new JMenuItem("Window");
		JMenuItem item5 = new JMenuItem("Help");
		
		myMenu.add(item1);
		myMenu.add(item2);
		myMenu.addSeparator();
		myMenu.add(item3);
		
		JMenu newMenu = new JMenu("Open");
		newMenu.add(item4);
		newMenu.add(item5);
		myMenu.add(newMenu);
		
	}

	@SuppressWarnings("unused")
	private static void addPopup(Component component, final JPopupMenu popup) {
		component.addMouseListener(new MouseAdapter() {
			public void mousePressed(MouseEvent e) {
				if (e.isPopupTrigger()) {
					showMenu(e);
				}
			}
			public void mouseReleased(MouseEvent e) {
				if (e.isPopupTrigger()) {
					showMenu(e);
				}
			}
			private void showMenu(MouseEvent e) {
				popup.show(e.getComponent(), e.getX(), e.getY());
			}
		});
	}
}
