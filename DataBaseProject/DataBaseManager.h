#pragma once
#include "HardDriveInterface.h"
#include "Storage.h"

using namespace System;
using namespace System::Windows::Forms;

namespace DataBaseProject {

	public ref class DataBaseManager
	{
	private:
		HardDrive^ hd;
		Disk^ disk;
	public:
		DataBaseManager();
	};
}
