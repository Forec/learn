package date_8_22;

import java.awt.Color;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Rectangle;

import javax.swing.AbstractButton;
import javax.swing.ButtonModel;
import javax.swing.JComponent;
import javax.swing.LookAndFeel;
import javax.swing.plaf.basic.BasicButtonUI;

import sun.swing.SwingUtilities2;

public class MyButtonUI extends BasicButtonUI {
	
	@Override
	protected void installDefaults(AbstractButton b) {
		// TODO Auto-generated method stub
		super.installDefaults(b);
		LookAndFeel.installProperty(b, "opaque", Boolean.FALSE);
	}
	@Override
	protected void paintButtonPressed(Graphics g, AbstractButton b) {
		// TODO Auto-generated method stub
		g.setColor(new Color(255, 255, 0));
		g.fillRoundRect(0, 0, b.getWidth(), b.getHeight(), 10, 10);
	}
	@Override
	protected void paintIcon(Graphics g, JComponent c, Rectangle iconRect) {
		// TODO Auto-generated method stub
		super.paintIcon(g, c, iconRect);
	}
	@Override
	protected void paintText(Graphics g, AbstractButton b, Rectangle textRect,
			String text) {
		// TODO Auto-generated method stub
		super.paintText(g, b, textRect, text);
	}
	@Override
	protected void paintText(Graphics g, JComponent c, Rectangle textRect,
			String text) {
		AbstractButton b = (AbstractButton) c;
        ButtonModel model = b.getModel();
        FontMetrics fm = SwingUtilities2.getFontMetrics(c, g);
        int mnemonicIndex = b.getDisplayedMnemonicIndex();

        /* Draw the Text */
        if(model.isEnabled()) {
            /*** paint the text normally */
//            g.setColor(b.getForeground());
            g.setColor(Color.white);
            SwingUtilities2.drawStringUnderlineCharAt(c, g,text, mnemonicIndex,
                                          textRect.x + getTextShiftOffset(),
                                          textRect.y + fm.getAscent() + getTextShiftOffset());
        }
        else {
            /*** paint the text disabled ***/
            g.setColor(b.getBackground().brighter());
            SwingUtilities2.drawStringUnderlineCharAt(c, g,text, mnemonicIndex,
                                          textRect.x, textRect.y + fm.getAscent());
            g.setColor(b.getBackground().darker());
            SwingUtilities2.drawStringUnderlineCharAt(c, g,text, mnemonicIndex,
                                          textRect.x - 1, textRect.y + fm.getAscent() - 1);
        }
	}
	@Override
	protected void paintFocus(Graphics g, AbstractButton b, Rectangle viewRect,
			Rectangle textRect, Rectangle iconRect) {
		// TODO Auto-generated method stub
		super.paintFocus(g, b, viewRect, textRect, iconRect);
	}
	@Override
	public void paint(Graphics g, JComponent c) {
		// TODO Auto-generated method stub
		g.setColor(new Color(255, 0, 0,150));
		g.fillRoundRect(0, 0, c.getWidth(), c.getHeight(), 10, 10);
		super.paint(g, c);
	}
}
