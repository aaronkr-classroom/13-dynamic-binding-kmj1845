// main.cpp
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Core.h"
#include "Grad.h"
#include "Vec.h"
#include "Student_info.h"
#include "median.h"

using namespace std;

int main() {
	vector<Core*> students; // ��ü�� �ƴ� �����͸� ����
	Core* record;
	char ch;
	string::size_type maxlen = 0;

	// ������ �а� �����ϱ�
	while (cin >> ch) { 
		if (ch == 'U')
			record = new Core; // Core ��ü �Ҵ�
		else
			record = new Grad; // Grad ��ü �Ҵ�
		record->read(cin);

		maxlen = max(maxlen, record->getName().size()); // ������
		students.push_back(record);
	}

	// �����ͷ� �����ϴ� compare �Լ��� ����
	sort(students.begin(), students.end(), compare_Core_ptrs);

	// �̸��� ������ ����ϱ�
	for (vector<Core*>::size_type i = 0;
		i != students.size(); ++i) {
		// �Լ��� ȣ���Ϸ��� �������� students[i]�� ������
		cout << students[i]->getName()
			<< string(maxlen + 1
				- students[i]->getName().size(), ' ');

		try {
			double final_grade = students[i]->grade(); // ������
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec) << endl;
		}
		catch (domain_error e) {
			cout << e.what() << endl; // ���� ���
		}

		delete students[i]; // �о� ���� ��ü�� �Ҵ��� ����
	}

	return 0;
}