#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define True 1
#define False 0

int absVal(int x) {  //���� x ����ֵ
	x = abs(x);
	//if (x < 0) x = -x;
	return x;
}
int absVal_standard(int x) { 
	return (x < 0) ? -x : x;
}

int negate(int x) {    //��ʹ�ø���ʵ�� -x
		if (x < 0) x = abs(x);
		else {
			x = ~x + 1;
		}
		return x;
}
int negate_standard(int x) {
	return -x;
}

int bitAnd(int x, int y) {	//��ʹ�� ~ �� | ,ʵ�� &
	x = ~x;
	y = ~y;
	int z = x | y;
	z = ~z;
	return z;
}
int bitAnd_standard(int x, int y) {
	return x & y;
}

int bitOr(int x, int y){  //��ʹ�� ~ �� & ��ʵ�� |
	x = ~x; y = ~y;
	int z = x & y; z = ~z;
	return z;
}
int bitOr_standard(int x, int y) {
	return x | y;
}

int bitXor(int x, int y) {  //��ʹ�� ~ �� & ��ʵ�� ^
	int z1 = x & y;
	x = ~x; y = ~y;
	int z2 = x & y;
	z1 = ~z1; z2 = ~z2;
	return z1 & z2;
}
int bitXor_standard(int x, int y) {
	return x ^ y;
}

int isTmax(int x){  //�ж�x�Ƿ�Ϊ������������7FFFFFFF����ֻ��ʹ�� !  ~  &  ^  |  +
	if (x < 0) return False;
	if ((x + 1) < 0) return True;
	return False;
}
int isTmax_standard(int x){
	if (x == 0x7fffffff) {
		return True;
	}
	else return 0;
}

int bitCount(int x) {
	// �� x ת��Ϊ�޷�������������ȷ������
	unsigned int ux = static_cast<unsigned int>(x);

	// λ�����߼��������޷�������
	ux = (ux & 0x55555555) + ((ux >> 1) & 0x55555555);
	ux = (ux & 0x33333333) + ((ux >> 2) & 0x33333333);
	ux = (ux & 0x0F0F0F0F) + ((ux >> 4) & 0x0F0F0F0F);
	ux = (ux & 0x00FF00FF) + ((ux >> 8) & 0x00FF00FF);
	ux = (ux & 0x0000FFFF) + ((ux >> 16) & 0x0000FFFF);

	// ����ͳ�Ƴ��� 1 �ĸ���
	return ux;
}
int bitCount_standard(int x) {
	int bit = 0, test = 0, judge = 0;
	if (x == 0) return 0;
	if (x < 0) judge = 1;
	x = abs(x);
	while (x > 1) {
		if ((test = x % 2) == 1) {
			bit++;
		}
		x /= 2;
	}
	if (judge == 0) return bit + 1;
	else return 32 - bit;
}

int bitMask(int highbit, int lowbit) {
	int highMask = (~0 << highbit + 1);
	int lowMask = (~0 << lowbit);
	return ~highMask & lowMask;
}
//������lowbit �� highbit ȫΪ1������λΪ0����
// ����bitMask(5,3) = 0x38 
// Ҫ��ֻʹ�� !  ~  &  ^  |  + <<  >>  ������������� 16��
int bitMask_standard(int highbit, int lowbit) {
	int z = 0;
	for (int i = lowbit; i < highbit + 1; i++) {
		z += pow(2, i);
	}
	return z;
}

int addOK(int x, int y) {  //�� x+y ��������ʱ���� 1 ���򷵻� 0
	int sum = x + y;
	int sign_x = x >> 31;
	int sign_y = y >> 31;
	int sign_sum = sum >> 31;
	if (sign_x == sign_y) {
		if (sign_x == sign_sum) return True;
		else return False;
	}
	return True;
}
int addOK_standard(int x, int y) {
	if ((x > 0 && y > 0) || (x < 0) && (y < 0)) {
		int sum = x + y;
		if ((x > 0 && sum < 0) || (x < 0 && sum > 0)) {
			return False;
		}
		return True;
	}
	return True;
}

int byteSwap(int x, int n, int m) {
	int byte_n = (x >> (n * 8)) & 0xff;
	int byte_m = (x >> (m * 8)) & 0xff;

	x = x & ~(0xff << (n * 8)); 
	x = x & ~(0xff << (m * 8)); 

	x = x | (byte_n << (m * 8));  
	x = x | (byte_m << (n * 8)); 

	return x;
}
//��x�ĵ�n���ֽ����m���ֽڽ��������ؽ�����Ľ���� n��m��ȡֵ�� 0~3֮��
//����byteSwap(0x12345678, 1, 3) = 0x56341278
//byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
//��ʹ�� !  ~  &   ^   |   +   <<   >>  ������������� 25��
int byteSwap_standard(int x, int n, int m) {
	// ������ x ����Ϊ�ֽ����飨����Ϊ 4 �ֽڣ�32 λ��
	unsigned char* bytes = reinterpret_cast<unsigned char*>(&x);
	swap(bytes[n], bytes[m]);
	return x;
}
