#include "Welcome.h"

using namespace System;
using namespace Skyscrapers;

Void Welcome::program_solver_btn_Click(Object^ sender, EventArgs^ e) {
	Solver^ solver = gcnew Solver(Convert::ToInt16(this->size->Value));
	solver->Show();
}

Void Welcome::show_rules_btn_Click(Object^ sender, EventArgs^ e) {
	MessageBox::Show("На полі NxN повинні розміститися будівлі різної висоти таким чином, щоб в кожному вертикальному і кожному горизонтальному ряду були присутні будинки тільки різної поверховості (від 1 до N поверхів, будинки позначаються числами, рівними їх поверховості). Числа поза діаграми показують, скільки будинків видно спостерігачеві, якщо він знаходиться на місці даного числа.", "Правила");
}

Void Welcome::hand_solver_btn_Click(Object^ sender, EventArgs^ e) {
	Puzzle^ puzzle = gcnew Puzzle(Convert::ToInt16(this->size->Value));
	puzzle->Show();
}