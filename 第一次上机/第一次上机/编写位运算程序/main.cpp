#include "def.hpp"

int main(void) {
	int op = 0;
	cout << "请输入想使用的功能编号：" << endl<<endl;
	cout << "1.求绝对值    2.求负数    3.求 & 结果    4.求 | 结果" << endl << endl;
	cout << "5.求 ^ 结果    6.判断最大整数    7.统计二进制中 1 的个数\n\n";
	cout << "8.指定二进制位置为 1 的数    9.判断溢出    10.交换字节 \n\n";
	cout << "0.退出\n\n";
	cin >> op;
	int x, y, n, m;
	while (op) {
		switch (op) {
		case 1:
			cout << "请输入整数：";
			cin >> x;
			cout << "结果为：" << absVal(x) << "\n检验结果：" << absVal_standard(x);
			cout << endl;
			break;
		case 2:
			cout << "请输入负数：";
			cin >> x;
			cout << "结果为：" << negate(x) << "\n检验结果：" << negate_standard(x);
			cout << endl;
			break;
		case 3:
			cout << "请输入两个整数：";
			cin >> x >> y;
			cout << "结果为：" << bitAnd(x, y) << "\n检验结果：" << bitAnd_standard(x, y);
			cout << endl;
			break;
		case 4:
			cout << "请输入两个整数：";
			cin >> x >> y;
			cout << "结果为：" << bitOr(x, y) << "\n检验结果：" << bitOr_standard(x, y);
			cout << endl;
			break;
		case 5:
			cout << "请输入两个整数：";
			cin >> x >> y;
			cout << "结果为：" << bitXor(x, y) << "\n检验结果：" << bitXor_standard(x, y);
			cout << endl;
			break;
		case 6:
			cout << "请输入整数：";
			cin >> x;
			if (isTmax(x)) cout << "是最大整数";
			else cout << "不是最大整数";
			cout << "\n检验结果：";
			if (isTmax_standard(x)) cout << "是最大整数";
			else cout << "不是最大整数";
			cout << endl;
			break;
		case 7:
			cout << "请输入整数：";
			cin >> x;
			cout << "1 的个数是：" << bitCount(x) << "\n检验结果：" << bitCount_standard(x);
			cout << endl;
			break;
		case 8:
			cout << "请输入高位和底位：";
			cin >> x >> y;
			cout << "结果为：" << bitMask(x, y) << "\n检验结果：" << bitMask_standard(x, y);
			cout << endl;
			break;
		case 9:
			cout << "请输入两个整数：";
			cin >> x >> y;
			if (addOK(x,y)) cout << "未溢出";
			else cout << "溢出";
			cout << "\n检验结果：";
			if (addOK_standard(x,y)) cout << "未溢出";
			else cout << "溢出";
			cout << endl;
			break;
		case 10:
			cout << "请输入整数：";
			cin >> x;
			cout << "请输入要交换的字节位数：";
			cin >> n >> m;
			cout << "结果为：" << byteSwap(x, n, m) << "\n检验结果：" << byteSwap_standard(x, n, m);
			cout << endl;
			break;

		}
		cin >> op;
	}
	return 0;
}