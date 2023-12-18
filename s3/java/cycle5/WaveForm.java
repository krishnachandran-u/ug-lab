import javax.swing.*;
import java.awt.*;

public class WaveForm extends JFrame {

    public WaveForm() {
        setTitle("Wave Form");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);
        Graphics2D g2d = (Graphics2D) g;

        int width = getWidth();
        int height = getHeight();

        g2d.setColor(Color.BLUE);
        int x = 0;
        int y = height / 2;

        for (int i = 0; i < width; i++) {
            int wave = (int) (Math.sin(i * 0.1) * 50);
            g2d.drawLine(i, y, i, y + wave);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            new WaveForm();
        });
    }
}
