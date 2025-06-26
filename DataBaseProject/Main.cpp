#include "DataBaseManager.h"

[STAThreadAttribute]
int main(array<String^>^ args)
{
	DataBaseProject::DataBaseManager^ dbms = gcnew DataBaseProject::DataBaseManager();
	return 0;
}