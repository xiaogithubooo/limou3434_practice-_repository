#define _CRT_SECURE_NO_WARNINGS 1
 #if (define(宏1) && define(宏2))//最外层的括号最好加上，更加严谨   
//code1 
#else   
//code2 
#endif   
//4.检测两个以上的宏中的其中一个是否没被定义 
#if !(define(宏1) && define(宏2))//最外层的括号最好加上，更加严谨   
//code1 
#else   
//code2 
#endif   
//5.检测两个以上的宏的其中一个
//1.检测宏是否被定义
#ifdef #if define(宏名) 
//某些code 
#else   
//某些code 
#endif   
//2.测宏是否没被定义#ifndef 
#if !define(宏名)   
//某些code 
#else   
//某些code 
#endif   
//3.检测两个以上的宏是否都被定义是否被定义 
#if (define(宏1) || define(宏2))//最外层的括号最好加上，更加严谨   
//code1 
#else   
//code2 
#endif