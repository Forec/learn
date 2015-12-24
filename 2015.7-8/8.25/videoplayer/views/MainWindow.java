package io.github.forec.videoplayer.views;

import io.github.forec.videoplayer.main.PlayerMain;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JProgressBar;
import javax.swing.JSlider;
import javax.swing.LayoutStyle.ComponentPlacement;
import javax.swing.border.EmptyBorder;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

import uk.co.caprica.vlcj.component.EmbeddedMediaPlayerComponent;
import uk.co.caprica.vlcj.player.embedded.EmbeddedMediaPlayer;

public class MainWindow extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private EmbeddedMediaPlayerComponent playerComponent;
	private JPanel contentPane;
	private String locate="";
	private JProgressBar progress;
	public String getLocate(){
		return locate;
	}
	public void setLocate(String s){
		this.locate = s;
	}

	/**
	 * Launch the application.
	 */

	/**
	 * Create the frame.
	 */
	public MainWindow() {
		addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				int value =JOptionPane.showConfirmDialog(MainWindow.this, "Sure?","Quit?",JOptionPane.OK_CANCEL_OPTION);
				if (value==JOptionPane.OK_OPTION){
					System.exit(0);
				}
			}
		});
	/*	try {
			UIManager.setLookAndFeel(new SeaGlassLookAndFeel());
		} catch (UnsupportedLookAndFeelException e1) {
			e1.printStackTrace();
		}*/
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 771, 484);
		
		JMenuBar menuBar = new JMenuBar();
		setJMenuBar(menuBar);
		
		JMenu mnFile = new JMenu("File");
		menuBar.add(mnFile);
		
		JMenu mnOpen = new JMenu("Open");
		mnFile.add(mnOpen);
		
		JMenuItem mntmMedia = new JMenuItem("Media");
		mntmMedia.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				PlayerMain.openVideo();
			}
		});
		mnOpen.add(mntmMedia);
		
		JMenuItem mntmSubtitle = new JMenuItem("SubTitle");
		mntmSubtitle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				PlayerMain.openSubtitle();
			}
		});
		mnOpen.add(mntmSubtitle);
		
		JMenuItem mntmExit = new JMenuItem("Exit");
		mntmExit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				PlayerMain.exit();
			}
		});
		mnFile.add(mntmExit);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		
		JPanel VedioPane = new JPanel();
		
		playerComponent = new EmbeddedMediaPlayerComponent();
		GroupLayout gl_VedioPane = new GroupLayout(VedioPane);
		gl_VedioPane.setHorizontalGroup(
			gl_VedioPane.createParallelGroup(Alignment.LEADING)
				.addComponent(playerComponent, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
		);
		gl_VedioPane.setVerticalGroup(
			gl_VedioPane.createParallelGroup(Alignment.TRAILING)
				.addComponent(playerComponent, GroupLayout.DEFAULT_SIZE, 332, Short.MAX_VALUE)
		);
		VedioPane.setLayout(gl_VedioPane);
		
		JPanel panel = new JPanel();
		GroupLayout gl_contentPane = new GroupLayout(contentPane);
		gl_contentPane.setHorizontalGroup(
			gl_contentPane.createParallelGroup(Alignment.LEADING)
				.addComponent(panel, GroupLayout.DEFAULT_SIZE, 745, Short.MAX_VALUE)
				.addComponent(VedioPane, GroupLayout.DEFAULT_SIZE, 745, Short.MAX_VALUE)
		);
		gl_contentPane.setVerticalGroup(
			gl_contentPane.createParallelGroup(Alignment.TRAILING)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addComponent(VedioPane, GroupLayout.DEFAULT_SIZE, 355, Short.MAX_VALUE)
					.addPreferredGap(ComponentPlacement.UNRELATED)
					.addComponent(panel, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE))
		);
		
		JPanel Control = new JPanel();
		
		JButton btnPlay = new JButton("Play");
		Control.add(btnPlay);
		
		JButton btnStop = new JButton("Stop");
		Control.add(btnStop);
		btnStop.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				PlayerMain.stop();
				btnPlay.setText("Play");
			}
		});
		btnPlay.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				if (btnPlay.getText().equals("Play")){
					PlayerMain.play();
					btnPlay.setText("Pause");
				}
				else {
					PlayerMain.pause();
					btnPlay.setText("Play");
				}
			}
		});
		panel.setLayout(new BorderLayout(0, 0));
		panel.add(Control);
		
		JSlider slider = new JSlider();
		slider.addChangeListener(new ChangeListener() {
			public void stateChanged(ChangeEvent e) {
				PlayerMain.setVol(slider.getValue());
			}
		});

		Control.add(slider);
		
		progress = new JProgressBar();
		progress.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				int x = e.getX();
				PlayerMain.jump((float)x/(progress.getWidth()));
			}
		});
		progress.setStringPainted(true);
		panel.add(progress, BorderLayout.NORTH);
		contentPane.setLayout(gl_contentPane);
	}
	
	public EmbeddedMediaPlayer getMediaPlayer(){
		return playerComponent.getMediaPlayer();
	}
	public JProgressBar getProgressBar(){
		return progress;
	}
}
