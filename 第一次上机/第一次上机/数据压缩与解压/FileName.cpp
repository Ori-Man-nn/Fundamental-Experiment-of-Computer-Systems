#include "def.hpp"

int main(void) {
    int cnts = 0;
    strcpy(old_s[0].name, "lwb");
    old_s[0].age = 18;
    old_s[0].score = 100;
    strcpy(old_s[0].remark, "good");
    strcpy(old_s[1].name, "ycx");
    old_s[1].age = 22;
    old_s[1].score = 100;
    strcpy(old_s[1].remark, "nice");
    strcpy(old_s[2].name, "lxy");
    old_s[2].age = 99;
    old_s[2].score = 55;
    strcpy(old_s[2].remark, "aha");

    while (cnts < 3)
    {
        printf("name=%s\n", old_s[cnts].name);
        printf("age=%hd\n", old_s[cnts].age);
        printf("score=%f\n", old_s[cnts].score);
        printf("remark=%s\n", old_s[cnts].remark);
        printf("\n");
        cnts++;
    }//���ѹ��ǰ�Ľ��

    cnts = 0;
    printf("ѹ��ǰ������ݵĳ���Ϊ%u\n\n", sizeof(student) * 3);//���ѹ��ǰ������ݵĳ���

    int cntbuf = pack_student_bytebybyte(old_s, 1, message);//�õ�һ��ѹ������ѹ����һ������

    cntbuf += pack_student_whole(old_s + 1, 2, message + cntbuf);//�õڶ���ѹ������ѹ������������

    coutmessage(message, cntbuf);//���ѹ���������
    printf("\nѹ���������ݵĳ���Ϊ%d\n\n", cntbuf);//���ѹ���������ݵĳ���
    int sno = restore_student(message, cntbuf, new_s);//�ý�ѹ������ѹ����
    printf("�����ѽ�ѹ......�������\n");
    while (cnts < sno)
    {
        printf("name=%s\n", new_s[cnts].name);
        printf("age=%hd\n", new_s[cnts].age);
        printf("score=%f\n", new_s[cnts].score);
        printf("remark=%s\n", new_s[cnts].remark);
        printf("\n\n");
        cnts++;
    }//�����ѹ��Ľ��

    return 0;
}

int  pack_student_bytebybyte(student* s, int sno, char* buf)
{
    int cnts = 0, cntname = 0, cntage = 0, cntscore = 0, cntremark = 0, cntbuf = 0;
    char* p = (char*)s;
    char* p0 = buf;
    while (cnts < sno)
    {
        //����name����
        cntname = 0;
        while (cntname < 8)
        {
            if (*p)
            {
                *p0 = *p;
                cntname++;
                cntbuf++;
                p++;
                p0++;
            }
            else
            {
                *p0 = 0;
                cntbuf++;
                p += (8 - cntname);
                p0++;
                break;
            }
        }
        //����short
        cntage = 0;
        while (cntage < 2)
        {
            *p0 = *p;
            cntage++;
            cntbuf++;
            p++;
            p0++;
        }
        p += 2;
        //����float
        cntscore = 0;
        while (cntscore < 4)
        {
            *p0 = *p;
            cntscore++;
            cntbuf++;
            p++;
            p0++;
        }
        //����remark����
        cntremark = 0;
        while (cntremark < 200)
        {
            if (*p)
            {
                *p0 = *p;
                cntremark++;
                cntbuf++;
                p++;
                p0++;
            }
            else
            {
                *p0 = 0;
                cntbuf++;
                p += (200 - cntremark);
                p0++;
                break;
            }
        }
        cnts++;
    }
    return cntbuf;//����ѹ������ֽ���
}
int  pack_student_whole(student* s, int sno, char* buf)
{
    int cnts = 0;
    char* p0 = buf;
    char* p = NULL;
    while (cnts < sno)
    {
        p = s[cnts].name;
        strcpy(p0, p);
        p0 += (strlen(p) + 1);//����name����

        p = (char*)&s[cnts].age;
        *((short*)p0) = *((short*)p);
        p0 += 2;//����age

        p = (char*)&s[cnts].score;
        *((float*)p0) = *((float*)p);
        p0 += 4;//����score

        p = s[cnts].remark;
        strcpy(p0, p);
        p0 += (strlen(p) + 1);//����remark����

        cnts++;
    }
    return p0 - buf;

}
int  restore_student(char* buf, int len, student* s)
{
    int cnts = 0;
    char* p = buf;//����message����
    while (p - buf < len)//����message�����ж�������ݲ���len
    {
        strcpy(s[cnts].name, p);//����name
        p += strlen(s[cnts].name) + 1;//pָ���ƶ���age��
        s[cnts].age = *((short*)p);//����age
        p += 2;//pָ���ƶ���score��
        s[cnts].score = *((float*)p);//����score
        p += 4;//pָ���ƶ���remark��
        strcpy(s[cnts].remark, p);//����remark
        p += strlen(s[cnts].remark) + 1;//pָ���ƶ�����һname��
        cnts++;//����ѧ����
    }
    return cnts;//����ѧ����
}

int  coutmessage(char* buf, int len)
{
    int cnts = 0;
    char* p = buf;//����message����
    while (p - buf < len)//����message�����ж�������ݲ���len
    {
        printf("%s ", p);
        p += strlen(p) + 1;//pָ���ƶ���age��
        printf("%hd ", *((short*)p));
        p += 2;//pָ���ƶ���score��
        printf("%f ", *((float*)p));
        p += 4;//pָ���ƶ���remark��
        printf("%s\n", p);
        p += strlen(p) + 1;
        cnts++;//����ѧ����
    }
    return cnts;//����ѧ����
}
