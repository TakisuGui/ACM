import java.util.Scanner;
import java.util.Random;

public class test4 {
    public static void main(String[] args) {
        // 创建随机数生成器
        Random random = new Random();
        int numberToGuess = random.nextInt(100) + 1;
        int numberOfTries = 0;
        
        // 创建输入扫描器
        Scanner input = new Scanner(System.in);
        int guess;
        boolean win = false;

        System.out.println("--- Java 环境测试程序 ---");
        System.out.println("我已经想好了一个 1 到 100 之间的数字。");
        System.out.println("试着猜猜看吧！");

        // 游戏主循环
        while (win == false) {
            System.out.print("请输入你猜的数字: ");
            
            // 检查输入是否为整数
            if (input.hasNextInt()) {
                guess = input.nextInt();
                numberOfTries++;

                if (guess == numberToGuess) {
                    win = true;
                } else if (guess < numberToGuess) {
                    System.out.println("太小了！再试一次。");
                } else if (guess > numberToGuess) {
                    System.out.println("太大了！再试一次。");
                }
            } else {
                System.out.println("错误：请输入一个有效的整数！");
                input.next(); // 清除错误输入
            }
        }

        System.out.println("恭喜你！你赢了！");
        System.out.println("数字确实是: " + numberToGuess);
        System.out.println("你总共猜了 " + numberOfTries + " 次。");
        System.out.println("--- 测试结束 ---");
        
        input.close();
    }
}