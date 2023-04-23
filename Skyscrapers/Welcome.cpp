#include "Welcome.h"

using namespace System;
using namespace Skyscrapers;

Void Welcome::program_solver_btn_Click(Object^ sender, EventArgs^ e) {
	Solver^ solver = gcnew Solver(Convert::ToInt16(this->size->Value));
	solver->Show();
}

Void Welcome::show_rules_btn_Click(Object^ sender, EventArgs^ e) {
	MessageBox::Show("�� ��� NxN ������ ����������� ����� ���� ������ ����� �����, ��� � ������� ������������� � ������� ��������������� ���� ���� ������� ������� ����� ���� ����������� (�� 1 �� N ��������, ������� ������������ �������, ������ �� �����������). ����� ���� ������� ���������, ������ ������� ����� ������������, ���� �� ����������� �� ���� ������ �����.", "�������");
}

Void Welcome::hand_solver_btn_Click(Object^ sender, EventArgs^ e) {
	Puzzle^ puzzle = gcnew Puzzle(Convert::ToInt16(this->size->Value));
	puzzle->Show();
}