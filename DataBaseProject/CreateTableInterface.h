#pragma once
#include "ReadManager.h"
#include "QueryInterface.h"
namespace DataBaseProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	/// <summary>
	/// Summary for CreateTableInterface
	/// </summary>
	public ref class CreateTableInterface : public System::Windows::Forms::Form
	{
	public:
		CreateTableInterface(String^ dataBaseName)
		{
			InitializeComponent();
			this->lbWelcome->Text = "Create table of database " + dataBaseName;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CreateTableInterface()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbWelcome;
	protected:

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ TableName;




	private: System::Windows::Forms::TextBox^ PrimaryKey;









	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ btnConfirm;
	private: System::Windows::Forms::Button^ btnClear;
	private: System::Windows::Forms::ComboBox^ DataTypes;

	private: System::Windows::Forms::Button^ btnAddData;
	private: System::Windows::Forms::Button^ btnImport;
	private: System::DirectoryServices::DirectoryEntry^ directoryEntry1;

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->TableName = (gcnew System::Windows::Forms::TextBox());
			this->PrimaryKey = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnConfirm = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->DataTypes = (gcnew System::Windows::Forms::ComboBox());
			this->btnAddData = (gcnew System::Windows::Forms::Button());
			this->btnImport = (gcnew System::Windows::Forms::Button());
			this->directoryEntry1 = (gcnew System::DirectoryServices::DirectoryEntry());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbWelcome
			// 
			this->lbWelcome->AutoSize = true;
			this->lbWelcome->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbWelcome->Location = System::Drawing::Point(12, 9);
			this->lbWelcome->Name = L"lbWelcome";
			this->lbWelcome->Size = System::Drawing::Size(263, 25);
			this->lbWelcome->TabIndex = 0;
			this->lbWelcome->Text = L"Create Table Interface";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 67);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(134, 23);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Table Name :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 111);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(138, 23);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Primary key  :";
			// 
			// TableName
			// 
			this->TableName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->TableName->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TableName->Location = System::Drawing::Point(152, 66);
			this->TableName->Name = L"TableName";
			this->TableName->Size = System::Drawing::Size(394, 32);
			this->TableName->TabIndex = 6;
			// 
			// PrimaryKey
			// 
			this->PrimaryKey->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->PrimaryKey->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PrimaryKey->Location = System::Drawing::Point(16, 137);
			this->PrimaryKey->Name = L"PrimaryKey";
			this->PrimaryKey->Size = System::Drawing::Size(167, 31);
			this->PrimaryKey->TabIndex = 7;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->btnConfirm, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->btnClear, 1, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 401);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(537, 50);
			this->tableLayoutPanel1->TabIndex = 11;
			// 
			// btnConfirm
			// 
			this->btnConfirm->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnConfirm->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnConfirm->Location = System::Drawing::Point(3, 3);
			this->btnConfirm->Name = L"btnConfirm";
			this->btnConfirm->Size = System::Drawing::Size(262, 44);
			this->btnConfirm->TabIndex = 0;
			this->btnConfirm->Text = L"Confirm";
			this->btnConfirm->UseVisualStyleBackColor = true;
			this->btnConfirm->Click += gcnew System::EventHandler(this, &CreateTableInterface::btnConfirm_Click);
			// 
			// btnClear
			// 
			this->btnClear->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnClear->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnClear->Location = System::Drawing::Point(271, 3);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(263, 44);
			this->btnClear->TabIndex = 1;
			this->btnClear->Text = L"Clear";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &CreateTableInterface::btnClear_Click);
			// 
			// DataTypes
			// 
			this->DataTypes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->DataTypes->Font = (gcnew System::Drawing::Font(L"Lucida Sans Typewriter", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DataTypes->FormattingEnabled = true;
			this->DataTypes->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"INT", L"FLOAT", L"STRING", L"BOOL", L"CHAR" });
			this->DataTypes->Location = System::Drawing::Point(189, 137);
			this->DataTypes->Name = L"DataTypes";
			this->DataTypes->Size = System::Drawing::Size(147, 31);
			this->DataTypes->TabIndex = 14;
			// 
			// btnAddData
			// 
			this->btnAddData->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnAddData->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAddData->Location = System::Drawing::Point(416, 137);
			this->btnAddData->Name = L"btnAddData";
			this->btnAddData->Size = System::Drawing::Size(130, 31);
			this->btnAddData->TabIndex = 13;
			this->btnAddData->Text = L"Add Data";
			this->btnAddData->UseVisualStyleBackColor = true;
			this->btnAddData->Click += gcnew System::EventHandler(this, &CreateTableInterface::btnAddData_Click);
			// 
			// btnImport
			// 
			this->btnImport->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btnImport->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnImport->Location = System::Drawing::Point(17, 354);
			this->btnImport->Name = L"btnImport";
			this->btnImport->Size = System::Drawing::Size(130, 31);
			this->btnImport->TabIndex = 14;
			this->btnImport->Text = L"Import .csv";
			this->btnImport->UseVisualStyleBackColor = true;
			this->btnImport->Click += gcnew System::EventHandler(this, &CreateTableInterface::btnImport_Click);
			// 
			// CreateTableInterface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(562, 470);
			this->Controls->Add(this->btnImport);
			this->Controls->Add(this->btnAddData);
			this->Controls->Add(this->DataTypes);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->PrimaryKey);
			this->Controls->Add(this->TableName);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lbWelcome);
			this->MinimumSize = System::Drawing::Size(578, 509);
			this->Name = L"CreateTableInterface";
			this->Text = L"CreateTableInterface";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnConfirm_Click(System::Object^ sender, System::EventArgs^ e) {
		DataBaseProject::QueryInterface^ newForm = gcnew QueryInterface();
		newForm->Show();
		//this->Hide();
	}
	private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
		TableName->Clear();
	}
	private: System::Void btnImport_Click(System::Object^ sender, System::EventArgs^ e) {
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
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al subir el archivo: " + ex->Message);
			}
		}
	}
private: System::Void btnAddData_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
