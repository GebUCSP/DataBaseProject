#include "HardDriveInterface.h"
#include "CreateTableInterface.h"
using namespace System;
using namespace System::Windows::Forms;
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	DataBaseProject::HardDriveInterface form;
	Application::Run(% form);
}

