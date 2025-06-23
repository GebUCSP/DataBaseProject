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
			fieldNames = gcnew System::Collections::Generic::List<System::Windows::Forms::TextBox^>();
			fieldTypes = gcnew System::Collections::Generic::List<System::Windows::Forms::ComboBox^>();
			currentRow = 0;

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

	private: System::Windows::Forms::TextBox^ TableName;















	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;



	private: System::Windows::Forms::Button^ btnAddField;



	private: System::Windows::Forms::Button^ btnImport;
	private: System::DirectoryServices::DirectoryEntry^ directoryEntry1;

	private:
		System::Collections::Generic::List<System::Windows::Forms::TextBox^>^ fieldNames;
		System::Collections::Generic::List<System::Windows::Forms::ComboBox^>^ fieldTypes;
		int currentRow;
		bool isFirstField = true;

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
			this->TableName = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnAddField = (gcnew System::Windows::Forms::Button());
			this->btnImport = (gcnew System::Windows::Forms::Button());
			this->directoryEntry1 = (gcnew System::DirectoryServices::DirectoryEntry());
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
			// TableName
			// 
			this->TableName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->TableName->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TableName->Location = System::Drawing::Point(152, 66);
			this->TableName->Name = L"TableName";
			this->TableName->Size = System::Drawing::Size(512, 32);
			this->TableName->TabIndex = 6;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->AutoSize = true;
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(17, 160);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(496, 36);
			this->tableLayoutPanel1->TabIndex = 11;
			// 
			// btnAddField
			// 
			this->btnAddField->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnAddField->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAddField->Location = System::Drawing::Point(17, 123);
			this->btnAddField->Name = L"btnAddField";
			this->btnAddField->Size = System::Drawing::Size(130, 31);
			this->btnAddField->TabIndex = 13;
			this->btnAddField->Text = L"Add Field";
			this->btnAddField->UseVisualStyleBackColor = true;
			this->btnAddField->Click += gcnew System::EventHandler(this, &CreateTableInterface::btnAddData_Click);
			// 
			// btnImport
			// 
			this->btnImport->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btnImport->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnImport->Location = System::Drawing::Point(534, 427);
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
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(680, 470);
			this->Controls->Add(this->btnImport);
			this->Controls->Add(this->btnAddField);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->TableName);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lbWelcome);
			this->MinimumSize = System::Drawing::Size(578, 509);
			this->Name = L"CreateTableInterface";
			this->Text = L"CreateTableInterface";
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
	private: System::Void btnAddData_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (isFirstField)
		{
			Label^ lblFile = gcnew Label();
			lblFile->Text = "File:";
			lblFile->Font = gcnew System::Drawing::Font("Lucida Sans Unicode", 11);
			lblFile->Anchor = AnchorStyles::Left;
			lblFile->AutoSize = true;

			// Agregar "File:" en la primera fila, primera columna
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::AutoSize));
			this->tableLayoutPanel1->Controls->Add(lblFile, 0, 0);

			isFirstField = false; // Solo lo agregamos una vez
		}

		// Crear controles
		TextBox^ txtField = gcnew TextBox();
		txtField->Anchor = AnchorStyles::Left | AnchorStyles::Right;
		txtField->Font = gcnew System::Drawing::Font("Lucida Sans Unicode", 11);
		txtField->Width = 200;

		ComboBox^ cmbType = gcnew ComboBox();
		cmbType->Anchor = AnchorStyles::Left | AnchorStyles::Right;
		cmbType->Font = gcnew System::Drawing::Font("Lucida Sans Unicode", 11);
		cmbType->Items->AddRange(gcnew array<Object^>{ "INT", "VARCHAR", "FLOAT", "BOOLEAN" });
		cmbType->SelectedIndex = 0;
		cmbType->DropDownStyle = ComboBoxStyle::DropDownList;
		cmbType->Width = 150;

		// Nueva fila
		int newRow = this->tableLayoutPanel1->RowCount;
		this->tableLayoutPanel1->RowCount += 1;
		this->tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::AutoSize));

		// Agregar controles en la fila
		this->tableLayoutPanel1->Controls->Add(txtField, 0, newRow);
		this->tableLayoutPanel1->Controls->Add(cmbType, 1, newRow);
	}



};
}
