#pragma once
#include "HardDriveInterface.h"

using namespace System;
using namespace System::Windows::Forms;

namespace DataBaseProject {

	public ref class DataBaseManager
	{
	private:
		HardDriveInterface^ form;
	public:
		DataBaseManager();
	};
}
