//使用三字母词
#include <stdio.h>
int main()
{
    //由于三字母词的存在，打印出 (are you ok]
    printf("(are you ok??)");
    printf("\n"); //换行

    //因此利用 \? 防止识别为三字母词，正常打印 (are you ok??)
    printf("(are you ok\?\?)");
    printf("\n"); //换行

    //printf("""); //打印失败，会报错
    printf("\""); //使用反义字符就可以打印出单个 "
    printf("\n"); //换行
	return 0;
}

/* 输出结果
(are you ok]
(are you ok??)
"
*/
