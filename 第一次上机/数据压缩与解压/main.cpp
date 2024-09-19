#include "def.hpp"
#define _CRT_SECURE_NO_WARNINGS 1

int main(void) {
    int stu = 0;
    /*
    strcpy(old_s[0].name, "lry");
    old_s[0].age = 20;
    old_s[0].score = 57;
    strcpy(old_s[0].remark, "hh");

    strcpy(old_s[1].name, "yyy");
    old_s[1].age = 19;
    old_s[1].score = 233;
    strcpy(old_s[1].remark, "hh");

    strcpy(old_s[2].name, "lll");
    old_s[2].age = 20;
    old_s[2].score = 231;
    strcpy(old_s[2].remark, "hh"); 

    strcpy(old_s[3].name, "mmm");
    old_s[3].age = 19;
    old_s[3].score = 13;
    strcpy(old_s[3].remark, "hh");

    strcpy(old_s[4].name, "nn");
    old_s[4].age = 20;
    old_s[4].score = 522;
    strcpy(old_s[4].remark, "hh");、
    */

    cout << "请依次输入 5 名同学的姓名、年龄、得分和备注：";
    cout << endl;

	for (int i = 0; i < N; i++) {
		cin >> old_s[i].name >> old_s[i].age >> old_s[i].score >> old_s[i].remark;
	}

    cout << endl;
    cout << "压缩前信息为：\n";
    for (int i = 0; i < N; i++) {
        cout << old_s[i].name << "\t" << old_s[i].age << "\t";
        cout << fixed << old_s[i].score << "\t";
        cout << old_s[i].remark << "\n";
    }
    cout << endl;
    cout << "压缩前数据长度为：" << sizeof(student) * N<<"\n";
    cout << endl;

    int stubuf = pack_student_bytebybyte(old_s, 2, message);
    stubuf += pack_student_whole(old_s + 2, 3, message + stubuf);
    stubuf -=1;
    cout << "压缩后数据长度为：" << stubuf << "\n";
    cout << endl;

    cout << "压缩后的前二十位数据地址为：\n";
    for (int i = 0; i < 20; i++) {
        cout << &message + i;
        cout << endl;
    }
    cout << endl;

    int ant = restore_student(message, stubuf, new_s);
    cout << "解压后信息为：" << endl;
    for (int i = 0; i < 5; i++) {
        cout << new_s[i].name <<"\t" << new_s[i].age<<"\t";
        cout << fixed << new_s[i].score << "\t";
        cout << new_s[i].remark<<"\n";
    }
    return 0;
}

int pack_student_bytebybyte(student* s, int sno, char* buf) {
    int st = 0, stname = 0, stremark = 0, stubuf = 0;
    char* p = buf;
    char* pp = (char*)s;
    for (int i = 0; i < sno; i++) {
        if (i != 0){
            pp = (char*)(s + 1);
        }
        stname = 0;  //输入 name 部分
        while (stname < 8) {
            if (*pp) {
                *p = *pp;
                stname++;
                stubuf++; pp++; p++;
            }
            else {
                *p = 0;  // 用 0 来表示一段数据的结束
                pp += (8 - stname);
                stubuf++; p++;
                break;
            }
        }
        for (int m = 0; m < 2; m++) {    // 输入 short 类型 2 字节
            *p = *pp;
            p++; pp++; stubuf++;
        }
        pp += 2;
        for (int n = 0; n < 4; n++) {   // 输入 float 类型 4 字节
            *p = *pp;
            p++; pp++; stubuf++;
        }
        stremark = 0;
        while (stremark < 200) {
            if (*pp) {
                *p = *pp;
                p++; pp++; stubuf++;
                stremark++;
            }
            else {
                *p = 0;
                *pp += (200 - stremark);
                stubuf++; p++;
                break;
            }
        }
    }
    return stubuf;
}

int pack_student_whole(student* s, int sno, char* buf) {
    int stubuf = 0;
    char* p = buf;
    char* pp = NULL;

    for (int i = 0; i < 3; i++) {

        pp = s[i].name;
        strcpy(p, pp);
        p += (strlen(pp) + 1);

        pp = (char*)&s[i].age;
        *((short*)p) = *((short*)pp);
        p += 2;

        pp = (char*)&s[i].score;
        *((float*)p) = *((float*)pp);
        p += 4;

        pp = s[i].remark;
        strcpy(p, pp);
        p += (strlen(pp) + 1);
    }
    return p - buf;
}

int restore_student(char* buf, int len, student* s) {
    int stu = 0, stname = 0, stremark = 0;
    char* p = buf;
    char* pp = (char*)s;
    while (stu<5) {
        strcpy(s[stu].name, p);
        p += (strlen(s[stu].name) + 1);
        s[stu].age = *((short*)p);
        p += 2;
        s[stu].score = *((float*)p);
        p+=4;
        strcpy(s[stu].remark, p);
        p += (strlen(s[stu].remark) + 1);
        stu++;
    }
    return stu;
}