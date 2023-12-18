import java.awt.*;
import java.awt.event.*;

public class KeyEventsExample extends Frame {
    private Label lblMessage;

    public KeyEventsExample() {
        lblMessage = new Label();
        lblMessage.setBounds(50, 50, 200, 30);
        add(lblMessage);

        addKeyListener(new KeyAdapter() {
            public void keyPressed(KeyEvent e) {
                lblMessage.setText("Key Pressed: " + e.getKeyChar());
            }

            public void keyReleased(KeyEvent e) {
                lblMessage.setText("Key Released: " + e.getKeyChar());
            }
        });

        setSize(300, 200);
        setLayout(null);
        setVisible(true);
    }

    public static void main(String[] args) {
        new KeyEventsExample();
    }
}
