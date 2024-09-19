#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define True 1
#define False 0

int absVal(int x) {  //返回 x 绝对值
	x = abs(x);
	//if (x < 0) x = -x;
	return x;
}
int absVal_standard(int x) { 
	return (x < 0) ? -x : x;
}

int negate(int x) {    //不使用负号实现 -x
		if (x < 0) x = abs(x);
		else {
			x = ~x + 1;
		}
		return x;
}
int negate_standard(int x) {
	return -x;
}

int bitAnd(int x, int y) {	//仅使用 ~ 和 | ,实现 &
	x = ~x;
	y = ~y;
	int z = x | y;
	z = ~z;
	return z;
}
int bitAnd_standard(int x, int y) {
	return x & y;
}

int bitOr(int x, int y){  //仅使用 ~ 和 & ，实现 |
	x = ~x; y = ~y;
	int z = x & y; z = ~z;
	return z;
}
int bitOr_standard(int x, int y) {
	return x | y;
}

int bitXor(int x, int y) {  //仅使用 ~ 和 & ，实现 ^
	int z1 = x & y;
	x = ~x; y = ~y;
	int z2 = x & y;
	z1 = ~z1; z2 = ~z2;
	return z1 & z2;
}
int bitXor_standard(int x, int y) {
	return x ^ y;
}

int isTmax(int x){  //判断x是否为最大的正整数（7FFFFFFF），只能使用 !  ~  &  ^  |  +
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
	// 将 x 转换为无符号整数，以正确处理负数
	unsigned int ux = static_cast<unsigned int>(x);

	// 位运算逻辑，处理无符号整数
	ux = (ux & 0x55555555) + ((ux >> 1) & 0x55555555);
	ux = (ux & 0x33333333) + ((ux >> 2) & 0x33333333);
	ux = (ux & 0x0F0F0F0F) + ((ux >> 4) & 0x0F0F0F0F);
	ux = (ux & 0x00FF00FF) + ((ux >> 8) & 0x00FF00FF);
	ux = (ux & 0x0000FFFF) + ((ux >> 16) & 0x0000FFFF);

	// 返回统计出的 1 的个数
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
//产生从lowbit 到 highbit 全为1，其他位为0的数
// 例如bitMask(5,3) = 0x38 
// 要求只使用 !  ~  &  ^  |  + <<  >>  运算次数不超过 16次
int bitMask_standard(int highbit, int lowbit) {
	int z = 0;
	for (int i = lowbit; i < highbit + 1; i++) {
		z += pow(2, i);
	}
	return z;
}

int addOK(int x, int y) {  //当 x+y 会产生溢出时返回 1 否则返回 0
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
//将x的第n个字节与第m个字节交换，返回交换后的结果。 n、m的取值在 0~3之间
//例：byteSwap(0x12345678, 1, 3) = 0x56341278
//byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
//仅使用 !  ~  &   ^   |   +   <<   >>  运算次数不超过 25次
int byteSwap_standard(int x, int n, int m) {
	// 将整数 x 解释为字节数组（长度为 4 字节，32 位）
	unsigned char* bytes = reinterpret_cast<unsigned char*>(&x);
	swap(bytes[n], bytes[m]);
	return x;
}
