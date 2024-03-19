import java.util.Scanner;
import java.util.Random;

public class Calculator {
    // 生成随机运算符
    public static char GenerateOperator() {
        char[] operators = {'+', '-', '*', '/'};
        Random random = new Random();
        return operators[random.nextInt(operators.length)]; // 随机返回一个运算字符
    }

    // 计算正确答案
    public static int CalculateAnswer(int num1, int num2, char operator) {
        switch (operator) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                return num1 / num2;
            default:
                throw new IllegalArgumentException("Invalid operator: " + operator); //抛出错误
        }
    }

//        Random random = new Random();
//
//        while (true) {
//            // 生成两个随机两位数和一个随机运算符
//            int num1 = random.nextInt(90) + 10; // +10 可以保证是两位数
//            int num2 = random.nextInt(90) + 10; // +10 可以保证是两位数
//            char operator = GenerateOperator();
//
//            // 输出题目
//            System.out.print("题目：" + num1 + " " + operator + " " + num2 + " = ");
//
//            // 读取用户输入的答案
//            int userAnswer = scanner.nextInt();
//
//            // 计算正确答案
//            int correctAnswer = CalculateAnswer(num1, num2, operator);
//
//            // 判断用户答案是否正确
//            if (userAnswer == correctAnswer) {
//                System.out.println("答案正确！");
//            } else {
//                System.out.println("答案错误");
//            }
//
//            // 询问用户是否继续
//            System.out.print("是否继续？（输入 y 继续，其他键退出）：");
//            String choice = scanner.next();
//            if (!choice.equalsIgnoreCase("y")) {
//                break;
//            }
//        }
//
//        // 结束练习
//        System.out.println("练习结束");
//        scanner.close();
//    }
}