#define _CRT_SECURE_NO_WARNINGS 1
//ʹ������
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//    int* a = (int*)malloc(sizeof(int));
//    if (a == NULL)
//    {
//        printf("����ʧ��\n");
//        printf("%s\n", strerror(errno));
//        exit(-1);//����return 1;
//    }
//    *a = 5;
//    printf("��%p��ַ���洢����ֵ:%d\n", a, *a);
//    free(a);//�ͷŶ�̬�ڴ�
//    a = NULL;//�ÿգ�����Ұָ��ĳ���
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define NUMBER 10
//int main()
//{
//    //1.���붯̬�ڴ�
//    int* arr = (int*)malloc(sizeof(int) * NUMBER);
//    if (arr == NULL)//�Է���ֵָ����м��
//    {
//        printf("����ʧ��\n");
//        printf("%s\n", strerror(errno));
//        exit(-1);//����return 1;
//    }
//
//    //2.ʹ�ö�̬�ڴ�
//    for (int i = 0; i < NUMBER; i++)
//    {
//        arr[i] = i + 1;
//    }
//
//    for (int i = 0; i < NUMBER; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//
//    //3.�ͷŶ�̬�ڴ�
//    free(arr);//�ͷŶ�̬�ڴ�
//    arr = NULL;//�ÿգ�����Ұָ��ĳ���
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define NUMBER 10
//int main()
//{
//    //1.���붯̬�ڴ�
//    int* arr = (int*)calloc(1, NUMBER * sizeof(int));
//    if (arr == NULL)//�Է���ֵָ����м��
//    {
//        printf("����ʧ��\n");
//        printf("%s\n", strerror(errno));
//        exit(-1);//����return 1;
//    }
//
//    //2.ʹ�ö�̬�ڴ�
//    for (int i = 0; i < NUMBER; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//
//    //3.�ͷŶ�̬�ڴ�
//    free(arr);//�ͷŶ�̬�ڴ�
//    arr = NULL;//�ÿգ�����Ұָ��ĳ���
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define NUMBER 10
//int main()
//{
//    //1.���붯̬�ڴ�
//    int* arr = (int*)malloc(NUMBER * sizeof(int));//ע���������е㲻̫һ��
//    if (arr == NULL)//�Է���ֵָ����м��
//    {
//        printf("����ʧ��\n");
//        printf("%s\n", strerror(errno));
//        exit(-1);//����return 1;
//    }
//
//    //2.ʹ�ö�̬�ڴ�
//    //����������
//    for (int i = 0; i < NUMBER; i++)
//    {
//        arr[i] = i * i;
//    }
//    //�ڴ�ӡ����
//    for (int i = 0; i < NUMBER; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    //3.�ٴ�����̬�ڴ�
//    int* arr1 = realloc(arr, sizeof(int) * (NUMBER + 10));
//    if (arr1 == NULL)//�Է���ֵָ����м��
//    {
//        printf("����ʧ��\n");
//        printf("%s\n", strerror(errno));
//        exit(-1);//����return 1;
//    }
//
//    //4.ʹ�������Ķ�̬�ڴ�
//    //�ٲ鿴ԭ�����Ƿ񻹴���
//    for (int i = 0; i < NUMBER; i++)
//    {
//        printf("%d ", arr1[i]);
//    }
//    //�ڲ鿴�Ƿ������������Ŀռ丳���µ�����
//    for (int i = NUMBER; i < NUMBER + 10; i++)
//    {
//        arr1[i] = i * i;
//    }
//    printf("\n");
//    for (int i = 0; i < NUMBER + 10; i++)
//    {
//        printf("%d ", arr1[i]);
//    }
//
//    //5.�ͷŶ�̬�ڴ�
//    free(arr1);//�ͷŶ�̬�ڴ�
//    arr1 = NULL;//�ÿգ�����Ұָ��ĳ���
//    return 0;
//}
//���Ϊ�˴���ı���ͳһ�ԣ�Ҳ������ô��
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define NUMBER 10
//int main()
//{
//    //1.���붯̬�ڴ�
//    int* arr = (int*)malloc(NUMBER * sizeof(int));//ע���������е㲻̫һ��
//    if (arr == NULL)//�Է���ֵָ����м��
//    {
//        printf("����ʧ��\n");
//        printf("%s\n", strerror(errno));
//        exit(-1);//����return 1;
//    }
//
//    //2.ʹ�ö�̬�ڴ�
//    //����������
//    for (int i = 0; i < NUMBER; i++)
//    {
//        arr[i] = i * i;
//    }
//    //�ڴ�ӡ����
//    for (int i = 0; i < NUMBER; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    //3.�ٴ�����̬�ڴ�
//    int* arr1 = realloc(arr, sizeof(int) * (NUMBER + 10));
//    if (arr1 == NULL)//�Է���ֵָ����м��
//    {
//        printf("����ʧ��\n");
//        printf("%s\n", strerror(errno));
//        exit(-1);//����return 1;
//    }
//    else 
//    {
//        arr = arr1;//��������Ĵ���ͻ�ͳһһЩ
//    }
//
//    //4.ʹ�������Ķ�̬�ڴ�
//    for (int i = NUMBER; i < NUMBER + 10; i++)
//    {
//        arr[i] = i * i;
//    }
//    printf("\n");
//
//    for (int i = 0; i < NUMBER + 10; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//
//    //5.�ͷŶ�̬�ڴ�
//    free(arr1);//�ͷŶ�̬�ڴ�
//    arr1 = NULL;//�ÿգ�����Ұָ��ĳ���
//    return 0;
//}
//#include <stdlib.h>
//void test()
//{
//    int i = 0;
//    int* p = (int*)malloc(10 * sizeof(int));
//    if (NULL == p)
//    {
//        return 1;
//    }
//    for (i = 0; i <= 10; i++)
//    {
//        *(p + i) = i;//��i����10��ʱ��ͷ���Խ�����
//    }
//    free(p);
//}
//int main()
//{
//    test();
//    return 0;
//}
//#include <stdlib.h> 
//void test()
//{
//    int a = 10;
//    int* p = &a;
//    free(p);//�ͷ��˷Ƕ�̬�ڴ�
//}
//int main()
//{
//    test();
//}
//#include <stdlib.h>
//void test()
//{
//    int* p = (int*)malloc(100);
//    p++;
//    free(p);//p����ָ��̬�ڴ����ʼλ��
//}
//int main()
//{
//    test();
//    return 0;
//}
//#include <stdlib.h>
//#include <windows.h>
////int main()
////{
////    while (1)
////    {
////        int* p = (int*)malloc(100);
////        Sleep(100);
////    }
////}
//int main()
//{
//	int* a;
//	*a = 10;
//	return 0;
//}
