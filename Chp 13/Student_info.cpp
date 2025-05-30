//Student_info.cpp
#include <iostream>

#include "Student_info.h"
#include "Core.h"
#include "Grad.h"
#include "grade.h"

using namespace std;

// ������!
// �� ������
Student_info::Student_info(const Student_info& s) : cp(0) {
	if (s.cp) cp = s.cp->clone();
}

istream& Student_info::read(istream& is) {
	delete cp; // ���� ��ü ������ ����

	char ch;
	is >> ch; // record Ÿ�� �Է�

	// record Ÿ�� Ȯ��
	if (ch == 'U') {
		cp = new Core(is);
	}
	else {
		cp = new Grad(is);
	}

	return is;
}

Student_info& Student_info::operator=(const Student_info& s) {
	if (&s != this) {
		delete cp;
		if (s.cp)
			cp = s.cp->clone();
		else
			cp = 0;
	}
}

// cin�� �о� Student_info�� �ʱ�ȭ
// Student_info::Student_info(istream& is) { read(is); }

/*
bool compare(const Student_info& x, const Student_info& y) {
	return x.get_name() < y.get_name(); // A < Z�� �� �� ��ȯ, Z < A�� �� ���� ��ȯ
}

double Student_info::grade() const {
	return ::grade(midterm, final, homework);
}

istream& read_hw(istream& in, Vec<double>& hw) {
	if (in) {
		// ���� ������ ����
		hw.clear();
		
		// �Է��� ���� ����
		double x; // cin���� ����ϱ�
		
		// �Է¹��� ������ ���� sum
		while (in >> x) {
			hw.push_back(x);
		}

		//���� �л��� ���� �Է� �۾��� ����� ��Ʈ���� ����
		in.clear();

	}
	return in;
}
*/




