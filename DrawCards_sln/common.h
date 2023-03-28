#ifndef COMMON_H
#define COMMON_H
/* 公用文件，存放一些公用的宏、头文件、临界区等等
 * */
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <windows.h>
#include <conio.h>
#include <easyx.h>

/* 人物数据区，存放名称、编号之类的，
 * 之后跟结构体相连接
 * */
#define ROLE_NUMBER 10
char RoleNames[ROLE_NUMBER][10] = {"A1", "B2", "C3", "D4"};




#endif //COMMON_H
