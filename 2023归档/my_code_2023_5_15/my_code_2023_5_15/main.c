#define _CRT_SECURE_NO_WARNINGS 1
 #if (define(��1) && define(��2))//������������ü��ϣ������Ͻ�   
//code1 
#else   
//code2 
#endif   
//4.����������ϵĺ��е�����һ���Ƿ�û������ 
#if !(define(��1) && define(��2))//������������ü��ϣ������Ͻ�   
//code1 
#else   
//code2 
#endif   
//5.����������ϵĺ������һ��
//1.�����Ƿ񱻶���
#ifdef #if define(����) 
//ĳЩcode 
#else   
//ĳЩcode 
#endif   
//2.����Ƿ�û������#ifndef 
#if !define(����)   
//ĳЩcode 
#else   
//ĳЩcode 
#endif   
//3.����������ϵĺ��Ƿ񶼱������Ƿ񱻶��� 
#if (define(��1) || define(��2))//������������ü��ϣ������Ͻ�   
//code1 
#else   
//code2 
#endif