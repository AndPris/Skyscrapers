#include "Welcome.h"

using namespace System;
using namespace Windows::Forms;
using namespace Skyscrapers;

[STAThreadAttribute]
int main(array <String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	Welcome^ welcome_form = gcnew Welcome;
	Application::Run(welcome_form);

	return 0;
}