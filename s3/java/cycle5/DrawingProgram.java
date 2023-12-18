import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class DrawingProgram extends JFrame {
    private int startX, startY, endX, endY;
    private ShapeType shapeType;

    public DrawingProgram() {
        setTitle("Drawing Program");
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel canvas = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                drawShape(g);
            }
        };

        canvas.addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                startX = e.getX();
                startY = e.getY();
            }

            @Override
            public void mouseReleased(MouseEvent e) {
                endX = e.getX();
                endY = e.getY();
                repaint();
            }
        });

        JMenuBar menuBar = new JMenuBar();
        JMenu shapeMenu = new JMenu("Shape");
        JMenuItem lineMenuItem = new JMenuItem("Line");
        JMenuItem rectangleMenuItem = new JMenuItem("Rectangle");
        JMenuItem ovalMenuItem = new JMenuItem("Oval");

        lineMenuItem.addActionListener(e -> shapeType = ShapeType.LINE);
        rectangleMenuItem.addActionListener(e -> shapeType = ShapeType.RECTANGLE);
        ovalMenuItem.addActionListener(e -> shapeType = ShapeType.OVAL);

        shapeMenu.add(lineMenuItem);
        shapeMenu.add(rectangleMenuItem);
        shapeMenu.add(ovalMenuItem);
        menuBar.add(shapeMenu);

        setJMenuBar(menuBar);
        add(canvas);
    }

    private void drawShape(Graphics g) {
        if (shapeType == ShapeType.LINE) {
            g.drawLine(startX, startY, endX, endY);
        } else if (shapeType == ShapeType.RECTANGLE) {
            int width = Math.abs(endX - startX);
            int height = Math.abs(endY - startY);
            int x = Math.min(startX, endX);
            int y = Math.min(startY, endY);
            g.drawRect(x, y, width, height);
        } else if (shapeType == ShapeType.OVAL) {
            int width = Math.abs(endX - startX);
            int height = Math.abs(endY - startY);
            int x = Math.min(startX, endX);
            int y = Math.min(startY, endY);
            g.drawOval(x, y, width, height);
        }
    }

    private enum ShapeType {
        LINE, RECTANGLE, OVAL
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            DrawingProgram program = new DrawingProgram();
            program.setVisible(true);
        });
    }
}
