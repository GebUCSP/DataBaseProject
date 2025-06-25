#include "DataBaseManager.h"

using namespace DataBaseProject;

DataBaseManager::DataBaseManager()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	HardDriveInterface^ form = gcnew HardDriveInterface();
	hd = form->hd;
	Application::Run(form);
}