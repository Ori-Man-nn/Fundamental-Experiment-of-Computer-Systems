#include "def.hpp"

int main(void) {
	int op = 0;
	cout << "��������ʹ�õĹ��ܱ�ţ�" << endl<<endl;
	cout << "1.�����ֵ    2.����    3.�� & ���    4.�� | ���" << endl << endl;
	cout << "5.�� ^ ���    6.�ж��������    7.ͳ�ƶ������� 1 �ĸ���\n\n";
	cout << "8.ָ��������λ��Ϊ 1 ����    9.�ж����    10.�����ֽ� \n\n";
	cout << "0.�˳�\n\n";
	cin >> op;
	int x, y, n, m;
	while (op) {
		switch (op) {
		case 1:
			cout << "������������";
			cin >> x;
			cout << "���Ϊ��" << absVal(x) << "\n��������" << absVal_standard(x);
			cout << endl;
			break;
		case 2:
			cout << "�����븺����";
			cin >> x;
			cout << "���Ϊ��" << negate(x) << "\n��������" << negate_standard(x);
			cout << endl;
			break;
		case 3:
			cout << "����������������";
			cin >> x >> y;
			cout << "���Ϊ��" << bitAnd(x, y) << "\n��������" << bitAnd_standard(x, y);
			cout << endl;
			break;
		case 4:
			cout << "����������������";
			cin >> x >> y;
			cout << "���Ϊ��" << bitOr(x, y) << "\n��������" << bitOr_standard(x, y);
			cout << endl;
			break;
		case 5:
			cout << "����������������";
			cin >> x >> y;
			cout << "���Ϊ��" << bitXor(x, y) << "\n��������" << bitXor_standard(x, y);
			cout << endl;
			break;
		case 6:
			cout << "������������";
			cin >> x;
			if (isTmax(x)) cout << "���������";
			else cout << "�����������";
			cout << "\n��������";
			if (isTmax_standard(x)) cout << "���������";
			else cout << "�����������";
			cout << endl;
			break;
		case 7:
			cout << "������������";
			cin >> x;
			cout << "1 �ĸ����ǣ�" << bitCount(x) << "\n��������" << bitCount_standard(x);
			cout << endl;
			break;
		case 8:
			cout << "�������λ�͵�λ��";
			cin >> x >> y;
			cout << "���Ϊ��" << bitMask(x, y) << "\n��������" << bitMask_standard(x, y);
			cout << endl;
			break;
		case 9:
			cout << "����������������";
			cin >> x >> y;
			if (addOK(x,y)) cout << "δ���";
			else cout << "���";
			cout << "\n��������";
			if (addOK_standard(x,y)) cout << "δ���";
			else cout << "���";
			cout << endl;
			break;
		case 10:
			cout << "������������";
			cin >> x;
			cout << "������Ҫ�������ֽ�λ����";
			cin >> n >> m;
			cout << "���Ϊ��" << byteSwap(x, n, m) << "\n��������" << byteSwap_standard(x, n, m);
			cout << endl;
			break;

		}
		cin >> op;
	}
	return 0;
}