import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class SimplePong extends JPanel implements ActionListener, KeyListener {
    int ballX = 400, ballY = 300, ballDX = 7, ballDY = 7;
    int paddleX = 25, paddleY = 250;
    int paddle2X = 750, paddle2Y = 250;
    Timer timer = new Timer(5, this);

    public SimplePong() {
        JFrame frame = new JFrame("Simple Pong");
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(this);
        frame.addKeyListener(this);
        frame.setVisible(true);
        timer.start();
    }

    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.fillRect(ballX, ballY, 20, 20); // Draw the ball
        g.fillRect(paddleX, paddleY, 10, 100); // Draw the paddle
        g.fillRect(paddle2X, paddle2Y, 10, 100);
    }

    public void actionPerformed(ActionEvent e) {
        ballX += ballDX;
        ballY += ballDY;
        if (ballX < 0 || ballX > getWidth() - 20) ballDX *= -1; // Bounce ball off walls
        if (ballY < 0 || ballY > getHeight() - 20) ballDY *= -1; // Bounce ball off top/bottom
        if (ballY > paddleY - 25 && ballX + 250 > paddleX && ballX < paddleX + 10) ballDX *= -1; // Bounce ball off paddle
        if (ballY > paddle2Y - 100 && ballX + 250 > paddle2X && ballX < paddle2X + 10) ballDX *= -1;
        repaint();
    }

    public void keyPressed(KeyEvent e) {
        if (e.getKeyCode() == KeyEvent.VK_W && paddleX > 0) paddleY -= 40; // Move paddle up
        if (e.getKeyCode() == KeyEvent.VK_S && paddleX < getWidth() - 60) paddleY += 40; // Move paddle down

        if (e.getKeyCode() == KeyEvent.VK_UP && paddle2X > 0) paddle2Y -= 40; // Move paddle up
        if (e.getKeyCode() == KeyEvent.VK_DOWN && paddle2X < getWidth() - 60) paddle2Y += 40; // Move paddle down
    }

    public void keyReleased(KeyEvent e) {}
    public void keyTyped(KeyEvent e) {}

    public static void main(String[] args) {
        SwingUtilities.invokeLater(SimplePong::new);
    }
}
