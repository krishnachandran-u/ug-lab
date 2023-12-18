import javax.swing.*;
import java.awt.*;

public class LinesRectsOvals extends JFrame {
    public LinesRectsOvals() {
        setTitle("Lines, Rectangles, and Ovals");
        setSize(400, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
    }

    public void paint(Graphics g) {
        super.paint(g);
        g.setColor(Color.red);
        g.drawLine(5, 30, 350, 30);
        g.setColor(Color.blue);
        g.drawRect(5, 40, 90, 55);
        g.fillRect(100, 40, 90, 55);
        g.setColor(Color.cyan);
        g.fillRoundRect(195, 40, 90, 55, 50, 50);
        g.drawRoundRect(290, 40, 90, 55, 20, 20);
        g.setColor(Color.yellow);
        g.draw3DRect(5, 100, 90, 55, true);
        g.fill3DRect(100, 100, 90, 55, false);
        g.setColor(Color.magenta);
        g.drawOval(195, 100, 90, 55);
        g.fillOval(290, 100, 90, 55);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            LinesRectsOvals linesRectsOvals = new LinesRectsOvals();
            linesRectsOvals.setVisible(true);
        });
    }
}
