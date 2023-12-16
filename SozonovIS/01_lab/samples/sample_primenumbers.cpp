#include "tset.h"
#include <iostream>

using namespace std;

int main() {
	size_t n;
	cout << "Enter the maximum integer: ";	
	cin >> n;
	cout << endl;

	TSet s(n + 1);
	// ����������
	for (size_t i = 2; i <= n; i++)
		s.InsElem(i);
	// �������� �� sqrt(n) � �������� �������
	for (size_t i = 2; i * i <= n; i++)
		// ���� i � s, �������� �������
		if (s.IsMember(i))
			for (size_t k = 2 * i; k <= n; k += i)
				if (s.IsMember(k))
					s.DelElem(k);
	// ���������� � s �������� - ������� �����
	cout << "Prime numbers: " << s << endl;
	return 0;
}
