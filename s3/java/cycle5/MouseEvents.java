import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MouseEvents extends JFrame implements MouseListener {
    private JLabel label;

    public MouseEvents() {
        setTitle("Mouse Events Example");
        setSize(300, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        label = new JLabel("No mouse event yet");
        label.setHorizontalAlignment(JLabel.CENTER);
        add(label);

        addMouseListener(this);
    }

    public void mouseClicked(MouseEvent e) {
        label.setText("Mouse Clicked");
    }

    public void mousePressed(MouseEvent e) {
        label.setText("Mouse Pressed");
    }

    public void mouseReleased(MouseEvent e) {
        label.setText("Mouse Released");
    }

    public void mouseEntered(MouseEvent e) {
        label.setText("Mouse Entered");
    }

    public void mouseExited(MouseEvent e) {
        label.setText("Mouse Exited");
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            MouseEvents mouseEvents = new MouseEvents();
            mouseEvents.setVisible(true);
        });
    }
}
