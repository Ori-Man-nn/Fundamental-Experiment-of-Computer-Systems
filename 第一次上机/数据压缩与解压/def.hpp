#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cstring>
using namespace std;

#define N 5
char message[510];

struct student {
	char name[8];
	short age;
	float score;
	char remark[200];
}old_s[N], new_s[N];

int pack_student_bytebybyte(student* s, int sno, char* buf);
int pack_student_whole(student* s, int sno, char* buf);
int restore_student(char* buf, int len, student* s);
int coutmessage(char* buf, int len);//Êä³öº¯Êı
