package io.github.forec.videoplayer.main;

import io.github.forec.videoplayer.views.MainWindow;

import java.awt.EventQueue;
import java.io.File;

import javax.swing.JFileChooser;
import javax.swing.SwingWorker;

import uk.co.caprica.vlcj.binding.LibVlc;
import uk.co.caprica.vlcj.runtime.RuntimeUtil;

import com.sun.jna.Native;
import com.sun.jna.NativeLibrary;


public class PlayerMain {

	static MainWindow frame;
	public static void main(String[] args) {  
		if (RuntimeUtil.isWindows()){
			NativeLibrary.addSearchPath(
				RuntimeUtil.getLibVlcLibraryName(),
				"E:\\Program Files\\VLC");
		}
		Native.loadLibrary(RuntimeUtil.getLibVlcLibraryName(), LibVlc.class);
		
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					frame = new MainWindow();
					frame.setTitle("常常播放器");
					frame.setVisible(true);
					frame.getMediaPlayer().prepareMedia(frame.getLocate());
					new SwingWorker<String, Integer>() {

						@Override
						protected String doInBackground() throws Exception {
							while(true){
								long total = frame.getMediaPlayer().getLength();
								long curr = frame.getMediaPlayer().getTime();
								float percent = (float)curr/total;
								publish((int)(percent*100));
						//		System.out.println((int)percent*100);
								Thread.sleep(100);
							}						
						}
						protected void process(java.util.List<Integer> chunks) {
							for (int v:chunks){
								frame.getProgressBar().setValue(v);
							}
						};
					}.execute();
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	public static void play(){
		frame.getMediaPlayer().play();
	}
	public static void pause(){
		frame.getMediaPlayer().pause();
	}
	public static void stop(){
		frame.getMediaPlayer().stop();
	}
	public static void jump(float to){
		frame.getMediaPlayer().setTime((long)(to*frame.getMediaPlayer().getLength()));
	}
	public static void openVideo(){
		JFileChooser chose = new JFileChooser();
		int value = chose.showOpenDialog(frame);
		if (value == JFileChooser.APPROVE_OPTION){
			File file = chose.getSelectedFile();
			frame.setLocate(file.getAbsolutePath());
			frame.getMediaPlayer().prepareMedia(file.getAbsolutePath());
		}
	}
	public static void openSubtitle(){
		JFileChooser chose = new JFileChooser();
		int value = chose.showOpenDialog(frame);
		if (value == JFileChooser.APPROVE_OPTION){
			File file = chose.getSelectedFile();
			frame.getMediaPlayer().setSubTitleFile(file);
		}
	}
	public static void exit(){
		frame.getMediaPlayer().release();
		System.exit(0);
	}
	public static void setVol(int v){
		frame.getMediaPlayer().setVolume(v);
	}
}
