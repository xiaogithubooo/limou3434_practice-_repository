#include <stdio.h>

struct book
{
    char title[30];
    char author[30];
    float value;
};


int main()
{
    struct book books[3] = {
    [0] {
        .value = 19.8,
        .title = "语文",
        .author = "张三"
    },
    [1] {
        .title = "数学",
        .value = 21.3,
        .author = "李四"
    },
    [2] {
        .title = "英语",
        .value = 16.8,
        .author = "王五"
    },
    };

    printf("%s %s %f\r\n",books[0].title,books[0].author,books[0].value); 
    printf("%s %s %f\r\n",books[1].title,books[1].author,books[1].value); 
    printf("%s %s %f\r\n",books[2].title,books[2].author,books[2].value); 


    return 0;
}