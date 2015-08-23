package date_8_23;

import java.awt.EventQueue;

import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.SwingWorker;
import javax.swing.LayoutStyle.ComponentPlacement;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import javax.swing.border.EmptyBorder;

import com.seaglasslookandfeel.SeaGlassLookAndFeel;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;
import java.util.List;
import java.util.concurrent.ExecutionException;
import javax.swing.JScrollPane;

public class SwingWorkerTest extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextArea textArea;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					SwingWorkerTest frame = new SwingWorkerTest();
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
	public SwingWorkerTest() {
		try {
			UIManager.setLookAndFeel(new SeaGlassLookAndFeel());
		} catch (UnsupportedLookAndFeelException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 451, 335);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		
		JButton btnGet = new JButton("Get");
		btnGet.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				new SwingWorker<StringBuilder, String>() {

					@Override
					protected StringBuilder doInBackground() throws Exception {
						URL url = new  URL("http://www.apache.org");
						URLConnection connection = url.openConnection();
						BufferedReader br = new BufferedReader(new InputStreamReader(connection.getInputStream(), "UTF-8"));
						StringBuilder builder = new StringBuilder();
						String line = null;
						while ((line = br.readLine())!=null){
							builder.append(line).append("\n");
						}
						return builder;
					}
					@Override
					protected void done() {
						try {
							textArea.setText(get().toString());
						} catch (InterruptedException e) {
							e.printStackTrace();
						} catch (ExecutionException e) {
							e.printStackTrace();
						}
						super.done();
					}
					@Override
					protected void process(List<String> chunks) {
						for (String line : chunks){
							textArea.append(line+"\n");
						}
						super.process(chunks);
					}
				}.execute();
			}
		});
		
		JScrollPane scrollPane = new JScrollPane();
		GroupLayout gl_contentPane = new GroupLayout(contentPane);
		gl_contentPane.setHorizontalGroup(
			gl_contentPane.createParallelGroup(Alignment.LEADING)
				.addComponent(scrollPane, GroupLayout.DEFAULT_SIZE, 425, Short.MAX_VALUE)
				.addComponent(btnGet, GroupLayout.DEFAULT_SIZE, 425, Short.MAX_VALUE)
		);
		gl_contentPane.setVerticalGroup(
			gl_contentPane.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addComponent(btnGet)
					.addPreferredGap(ComponentPlacement.UNRELATED)
					.addComponent(scrollPane, GroupLayout.DEFAULT_SIZE, 253, Short.MAX_VALUE))
		);
		
		textArea = new JTextArea();
		scrollPane.setViewportView(textArea);
		contentPane.setLayout(gl_contentPane);
	}
}
