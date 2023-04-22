#include "Welcome.h"

using namespace System;
using namespace Skyscrapers;

Void Welcome::program_solver_btn_Click(Object^ sender, EventArgs^ e) {
	Solver^ solver = gcnew Solver(Convert::ToInt16(this->size->Value));
	solver->Show();
}
