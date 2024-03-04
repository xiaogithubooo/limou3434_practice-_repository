import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int[][] arr_1 = new int[10][];
        for (int i = arr_1.length - 1; i >= 0; i--) {
            arr_1[i] = new int[i + 1];
            for (int j = i; j >= 0; j--) {
                arr_1[i][j] = 10;
            }
        }

        System.out.println(Arrays.deepToString(arr_1));
    }
}