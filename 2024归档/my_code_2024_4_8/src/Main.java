import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Main {
    public static void printSchoolSongFromFile(String filename) {
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            System.out.println(":");
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            System.err.println("读取文件时出错：" + e.getMessage());
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        printSchoolSongFromFile("D:\\GitWork\\limou-c-test-code\\2024归档\\my_code_2024_4_8\\src\\test.txt");
    }
}
