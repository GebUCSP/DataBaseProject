#pragma once
#include "QueryInterface.h"
#include "ReadManager.h"
#include "HardDrive.h"
namespace DataBaseProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for InsertInterface
	/// </summary>
	public ref class InsertInterface : public System::Windows::Forms::Form
	{
	public:
		InsertInterface(String^ tableName)
		{
			InitializeComponent();
			this->lbWelcome->Text = "Insert data into the " + tableName + " table";
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~InsertInterface()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbWelcome;
	private: System::Windows::Forms::Button^ btnImportInsert;


	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbWelcome = (gcnew System::Windows::Forms::Label());
			this->btnImportInsert = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lbWelcome
			// 
			this->lbWelcome->AutoSize = true;
			this->lbWelcome->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbWelcome->Location = System::Drawing::Point(12, 9);
			this->lbWelcome->Name = L"lbWelcome";
			this->lbWelcome->Size = System::Drawing::Size(185, 25);
			this->lbWelcome->TabIndex = 0;
			this->lbWelcome->Text = L"Insert Interface";
			// 
			// btnImportInsert
			// 
			this->btnImportInsert->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btnImportInsert->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnImportInsert->Location = System::Drawing::Point(12, 429);
			this->btnImportInsert->Name = L"btnImportInsert";
			this->btnImportInsert->Size = System::Drawing::Size(116, 29);
			this->btnImportInsert->TabIndex = 1;
			this->btnImportInsert->Text = L"Import .csv";
			this->btnImportInsert->UseVisualStyleBackColor = true;
			this->btnImportInsert->Click += gcnew System::EventHandler(this, &InsertInterface::btnImportInsert_Click);
			// 
			// InsertInterface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(730, 470);
			this->Controls->Add(this->btnImportInsert);
			this->Controls->Add(this->lbWelcome);
			this->Name = L"InsertInterface";
			this->Text = L"InsertInterface";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnImportInsert_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
		openFileDialog->Filter = "Archivos CSV (*.csv)|*.csv";

		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ filePath = openFileDialog->FileName;
			String^ destinationPath = Path::Combine(Application::StartupPath, Path::GetFileName(filePath));

			try {
				File::Copy(filePath, destinationPath, true);
				ReadManager::LastImportedFilePath = destinationPath;

				MessageBox::Show("Archivo CSV subido exitosamente a: " + destinationPath);

				ReadManager::ReadCSV();

				HardDrive::Instance->ShowAllData();
				HardDrive::instance->ShowDataAsTable();
				DataBaseProject::QueryInterface^ newForm = gcnew QueryInterface();
				newForm->Show();
				//this->Hide();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al subir el archivo: " + ex->Message);
			}
		}
	}
	};
}
