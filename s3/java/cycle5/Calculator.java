import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Calculator extends JFrame implements ActionListener {
    private JTextField textField;
    private JLabel calculationLabel; // Added label for calculation display
    private JButton[] numberButtons;
    private JButton[] operationButtons;
    private JButton addButton, subtractButton, multiplyButton, divideButton, modulusButton, equalButton, clearButton;
    private JPanel panel;

    private double num1 = 0, num2 = 0, result = 0;
    private char operator;

    public Calculator() {
        setTitle("Calculator");
        setSize(300, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        calculationLabel = new JLabel(); // Initialize calculation label
        calculationLabel.setHorizontalAlignment(JLabel.RIGHT); // Align calculation text to the right
        calculationLabel.setPreferredSize(new Dimension(240, 30)); // Set preferred size for the label

        textField = new JTextField();
        textField.setBounds(30, 70, 240, 30);
        textField.setEditable(false);

        numberButtons = new JButton[10];
        for (int i = 0; i < 10; i++) {
            numberButtons[i] = new JButton(String.valueOf(i));
        }

        operationButtons = new JButton[6];
        addButton = new JButton("+");
        subtractButton = new JButton("-");
        multiplyButton = new JButton("*");
        divideButton = new JButton("/");
        modulusButton = new JButton("%");
        equalButton = new JButton("=");
        clearButton = new JButton("C");

        panel = new JPanel();
        panel.setBounds(30, 120, 240, 220);
        panel.setLayout(new GridLayout(4, 4, 10, 10));

        panel.add(numberButtons[1]);
        panel.add(numberButtons[2]);
        panel.add(numberButtons[3]);
        panel.add(addButton);
        panel.add(numberButtons[4]);
        panel.add(numberButtons[5]);
        panel.add(numberButtons[6]);
        panel.add(subtractButton);
        panel.add(numberButtons[7]);
        panel.add(numberButtons[8]);
        panel.add(numberButtons[9]);
        panel.add(multiplyButton);
        panel.add(numberButtons[0]);
        panel.add(equalButton);
        panel.add(clearButton);
        panel.add(divideButton);

        add(calculationLabel); // Add calculation label to the frame
        add(textField);
        add(panel);

        for (int i = 0; i < 10; i++) {
            numberButtons[i].addActionListener(this);
        }

        addButton.addActionListener(this);
        subtractButton.addActionListener(this);
        multiplyButton.addActionListener(this);
        divideButton.addActionListener(this);
        modulusButton.addActionListener(this);
        equalButton.addActionListener(this);
        clearButton.addActionListener(this);

        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        for (int i = 0; i < 10; i++) {
            if (e.getSource() == numberButtons[i]) {
                textField.setText(textField.getText().concat(String.valueOf(i)));
            }
        }

        if (e.getSource() == addButton) {
            num1 = Double.parseDouble(textField.getText());
            operator = '+';
            calculationLabel.setText(textField.getText() + " +");
            textField.setText("");
        }

        if (e.getSource() == subtractButton) {
            num1 = Double.parseDouble(textField.getText());
            operator = '-';
            calculationLabel.setText(textField.getText() + " -");
            textField.setText("");
        }

        if (e.getSource() == multiplyButton) {
            num1 = Double.parseDouble(textField.getText());
            operator = '*';
            calculationLabel.setText(textField.getText() + " *");
            textField.setText("");
        }

        if (e.getSource() == divideButton) {
            num1 = Double.parseDouble(textField.getText());
            operator = '/';
            calculationLabel.setText(textField.getText() + " /");
            textField.setText("");
        }

        if (e.getSource() == modulusButton) {
            num1 = Double.parseDouble(textField.getText());
            operator = '%';
            calculationLabel.setText(textField.getText() + " %");
            textField.setText("");
        }

        if (e.getSource() == equalButton) {
            num2 = Double.parseDouble(textField.getText());

            try {
                switch (operator) {
                    case '+':
                        result = num1 + num2;
                        break;
                    case '-':
                        result = num1 - num2;
                        break;
                    case '*':
                        result = num1 * num2;
                        break;
                    case '/':
                        if (num2 == 0) {
                            throw new ArithmeticException("Divide by zero error");
                        }
                        result = num1 / num2;
                        break;
                    case '%':
                        result = num1 % num2;
                        break;
                }
                textField.setText(String.valueOf(result));
                calculationLabel.setText("");
            } catch (ArithmeticException ex) {
                textField.setText("Error: " + ex.getMessage());
                calculationLabel.setText("");
            }
        }

        if (e.getSource() == clearButton) {
            textField.setText("");
            calculationLabel.setText("");
        }
    }

    public static void main(String[] args) {
        new Calculator();
    }
}
