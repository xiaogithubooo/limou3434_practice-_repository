import java.util.Arrays;
import java.util.Random;

public class QuickSort {
    public static void main(String[] args) {
        Random random = new Random();

        int testRuns = 100000; // 测试次数
        int min = -10; // 测试数组中最小的数
        int max = 10; // 测试数组中最大的数

        for (int i = 0; i < testRuns; i++) {
            int arraySize = random.nextInt(10); // 数组大小
            // 生成随机数组
            int[] arr = new int[arraySize];
            for (int j = 0; j < arraySize; j++) {
                arr[j] = random.nextInt(max + 1) + min; // 随机生成 min 到 max 之间的整数
            }
            System.out.println("排序前" + Arrays.toString(arr));
            // 复制数组进行对比
            int[] arrToSort = Arrays.copyOf(arr, arr.length);

            // 使用自定义的快速排序
            quickSort(arr, 0, arr.length - 1);
            System.out.println("自排后" + Arrays.toString(arr));

            // 使用 Java 标准库的排序算法
            Arrays.sort(arrToSort);
            System.out.println("库排后" + Arrays.toString(arr));
            System.out.println("");

            // 比较排序结果
            if (!Arrays.equals(arr, arrToSort)) {
                System.out.println("测试失败");
                System.out.println("原数组: " + Arrays.toString(arrToSort));
                System.out.println("自定义排序结果: " + Arrays.toString(arr));
                return; // 终止程序，方便调试
            }
        }

        System.out.println("所有测试通过！");
    }

    public static void quickSort(int[] arr, int i, int j) {
        int start = i; // 一开始为 arr[0]
        int end = j; // 一开始为 arr[arr.size()]
        int baseNumber = 0;
        if (i < arr.length) {
            baseNumber = arr[i]; // 基准数一开始为数组的 arr[0]
        }

        if (start > end) {
            return;
        }

        while (start != end) { // 只要 start != end 就循环
            // 1.第一次循环, 主要目的是从后面开始找一个数
            while (true) { // 不断循环, 直到找到一个 arr[end] 要小于 baseNumber
                if (end < arr.length && (end <= start || arr[end] < baseNumber)) {
                    break; // 如果本次循环走到这里就是说明找到一个 arr[end] < baseNumber
                }
                end--; // 如果是走到这里, 就说明还没有找到, 那么继续循环继续找
            }
            // 走到这里循环停止
            // (1)要么说明找到一个 arr[end] < baseNumber, 也就是数组中在偏后面的位置找到一个比基准数要小的一个数 arr[end]
            // (2)要么说明 baseNumber 基准数后面的所有数都 >= baseNumber
            // (3)要么说明提前遇到了 end > start 的情况

            // 2.第二次循环, 主要目的是从后面开始找一个数
            while (true) { // 不断循环, 直到找到一个 arr[start] 要大于 baseNumber
                if (start < arr.length && (end <= start || arr[start] > baseNumber)) {
                    break; // 如果本次循环走到这里就是说明找到一个 arr[end] > baseNumber
                }
                start++; // 如果是走到这里, 就说明还没有找到, 那么继续循环继续找
            }
            // 走到这里循环停止
            // (1)要么说明找到一个 arr[start] > baseNumber, 也就是数组中在偏前面的位置找到一个比基准数要大的一个数 arr[start]
            // (2)要么说明 baseNumber 基准数前面的所有数都 <= baseNumber
            // (3)要么说明提前遇到了 end > start 的情况

            // 先简单点, 都只考虑两次循环中各自的第一种情况, 也就是找到 arr[end] < baseNumber, arr[start] >baseNumber
            // 3.交换数据(其实快排的本质是交换数据, 最终达到有序的一种排序算法)

            if (start < arr.length) {
                int temp = arr[start];
                arr[start] = arr[end];
                arr[end] = temp;
            }

            // 上述过程就把 arr[end] 和 arr[start] 所携带的值互相交互了

            // 会发现, 这里实现了三个步骤, 第一次循环找 arr[end], 第二次循环找 arr[start], 最后交换 arr[end] 和 arr[start] 中携带的数据
        }
        // 而只要 start != end, 也就是两个下标没有重合, 就会一直执行上述的 "循环, 循环, 交换" 这就完成了一次小的快速排序, 俗称"一趟快排"

        // 经过一趟快排后, 可以先观察一下 { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 } 此时的结果, 下面文字描述是对上面代码的伪代码描述(也就是说人话描述...)
        // { arr[0]=6, arr[1]=1, arr[2]=2, arr[3]=7, arr[4]=9, arr[5]=3, arr[6]=4, arr[7]=5, arr[8]=10, arr[9]=8 }
        // 一开始的基准数是 6
        // 第一次循环, 找到 arr[end] < 6, 也就是 arr[end] == 5, 此时 end == 7
        // 第二次循环, 找到 arr[start] > 6, 也就是 arr[start] == 7 , 此时 start == 3
        // 做交互, 此时数组就变成
        // { arr[0]=6, arr[1]=1, arr[2]=2, arr[3]=5, arr[4]=9, arr[5]=3, arr[6]=4, arr[7]=7, arr[8]=10, arr[9]=8 }
        //                                   start                                    end
        // 而只要 start != end, 就不断使用基准数来交互元素, 直到 start == end 停止, 因此数组就会变成下面这样的结果
        // { arr[0]=6, arr[1]=1, arr[2]=2, arr[3]=5, arr[4]=4, arr[5]=3, arr[6]=9, arr[7]=7, arr[8]=10, arr[9]=8 }
        //                                             start                end
        // { arr[0]=6, arr[1]=1, arr[2]=2, arr[3]=5, arr[4]=4, arr[5]=3, arr[6]=9, arr[7]=7, arr[8]=10, arr[9]=8 }
        //                                                    start==end

        if (start < arr.length) {
            int temp = arr[start]; // 此时 start == end == 5
            arr[start] = arr[i];
            arr[i] = temp;
        }

        // 把基准数和 start == end 下表重叠的数进行交互, 也就是说数组变成下面这样
        // { arr[0]=3, arr[1]=1, arr[2]=2, arr[3]=5, arr[4]=4, arr[5]=6, arr[6]=9, arr[7]=7, arr[8]=10, arr[9]=8 }
        //                                                    基准数在上面这里
        // 此时你就会发现, 基准数左侧的数一定比基准数要小, 基准数左侧的数一定要比基准数要大


        // 到这里就完成了第一次快排
        // 那么如果我们把快排后的结果当作三部分来看, 数据可以被分割为 [ 小于基准数的数 ][ 基准数自己 ][ 大于基准数的数 ]
        // 根据递归的思想, 分而治之进行处理
        quickSort(arr, i, start - 1); // 把左侧 [ 小于基准数的数 ] 也当作是一个子数组进行快速排序
        quickSort(arr, start + 1, j); // 把右侧 [ 大于基准数的数 ] 也当作是一个子数组进行快速排序
    }
}