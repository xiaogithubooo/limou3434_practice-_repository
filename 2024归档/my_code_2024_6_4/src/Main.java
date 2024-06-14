// 第一种实现方式
class NumberThread extends Thread {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            for (int j = 1; j <= 100; j++) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }
}

class LetterThread extends Thread {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            for (char c = 'A'; c <= 'Z'; c++) {
                System.out.print(c + " ");
            }
            System.out.println();
        }
    }
}

public class Main {
    public static void main(String[] args) {
        NumberThread numberThread = new NumberThread();
        LetterThread letterThread = new LetterThread();

        numberThread.start();
        letterThread.start();
    }
}


// 第二种实现方式
class NumberPrinter implements Runnable {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            for (int j = 1; j <= 100; j++) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }
}

class LetterPrinter implements Runnable {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            for (char c = 'A'; c <= 'Z'; c++) {
                System.out.print(c + " ");
            }
            System.out.println();
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Thread numberThread = new Thread(new NumberPrinter());
        Thread letterThread = new Thread(new LetterPrinter());

        numberThread.start();
        letterThread.start();
    }
}
