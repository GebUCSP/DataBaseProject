#include "DataBaseManager.h"

using namespace DataBaseProject;

DataBaseManager::DataBaseManager()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	form = gcnew HardDriveInterface();
	
	Application::Run(form);
}