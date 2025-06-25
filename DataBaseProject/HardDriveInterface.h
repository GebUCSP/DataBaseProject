#pragma once
#include "CreateTableInterface.h"
#include "HardDrive.h"

namespace DataBaseProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CreateTableInterface
	/// </summary>
	public ref class HardDriveInterface : public System::Windows::Forms::Form
	{
	public:
		HardDriveInterface(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ CapacityClusters;

	public:
		HardDrive^ hd;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HardDriveInterface()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ DataBaseName;
	private: System::Windows::Forms::TextBox^ Platters;
	private: System::Windows::Forms::TextBox^ Tracks;
	private: System::Windows::Forms::TextBox^ QuantityClusters;







	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ btnConfirm;
	private: System::Windows::Forms::Button^ btnClear;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->DataBaseName = (gcnew System::Windows::Forms::TextBox());
			this->Platters = (gcnew System::Windows::Forms::TextBox());
			this->Tracks = (gcnew System::Windows::Forms::TextBox());
			this->QuantityClusters = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnConfirm = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->CapacityClusters = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(205, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Create Data Base";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 67);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(174, 23);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Data Base Name :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 142);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(99, 23);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Platters  :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(15, 184);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(96, 23);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Tracks   :";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(12, 228);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(99, 23);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Clusters :";
			// 
			// DataBaseName
			// 
			this->DataBaseName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->DataBaseName->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DataBaseName->Location = System::Drawing::Point(194, 66);
			this->DataBaseName->Name = L"DataBaseName";
			this->DataBaseName->Size = System::Drawing::Size(524, 32);
			this->DataBaseName->TabIndex = 6;
			// 
			// Platters
			// 
			this->Platters->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Platters->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Platters->Location = System::Drawing::Point(117, 141);
			this->Platters->Name = L"Platters";
			this->Platters->Size = System::Drawing::Size(244, 32);
			this->Platters->TabIndex = 7;
			// 
			// Tracks
			// 
			this->Tracks->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Tracks->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Tracks->Location = System::Drawing::Point(117, 183);
			this->Tracks->Name = L"Tracks";
			this->Tracks->Size = System::Drawing::Size(244, 32);
			this->Tracks->TabIndex = 8;
			// 
			// QuantityClusters
			// 
			this->QuantityClusters->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->QuantityClusters->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->QuantityClusters->Location = System::Drawing::Point(117, 227);
			this->QuantityClusters->Name = L"QuantityClusters";
			this->QuantityClusters->Size = System::Drawing::Size(244, 32);
			this->QuantityClusters->TabIndex = 10;
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
			this->tableLayoutPanel1->Size = System::Drawing::Size(705, 50);
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
			this->btnConfirm->Size = System::Drawing::Size(346, 44);
			this->btnConfirm->TabIndex = 0;
			this->btnConfirm->Text = L"Confirm";
			this->btnConfirm->UseVisualStyleBackColor = true;
			this->btnConfirm->Click += gcnew System::EventHandler(this, &HardDriveInterface::btnConfirm_Click);
			// 
			// btnClear
			// 
			this->btnClear->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnClear->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnClear->Location = System::Drawing::Point(355, 3);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(347, 44);
			this->btnClear->TabIndex = 1;
			this->btnClear->Text = L"Clear";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &HardDriveInterface::btnClear_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(114, 122);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(69, 16);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Quantity :";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(377, 209);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(69, 16);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Capacity :";
			// 
			// CapacityClusters
			// 
			this->CapacityClusters->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->CapacityClusters->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CapacityClusters->Location = System::Drawing::Point(380, 228);
			this->CapacityClusters->Name = L"CapacityClusters";
			this->CapacityClusters->Size = System::Drawing::Size(244, 32);
			this->CapacityClusters->TabIndex = 14;
			// 
			// HardDriveInterface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(730, 470);
			this->Controls->Add(this->CapacityClusters);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->QuantityClusters);
			this->Controls->Add(this->Tracks);
			this->Controls->Add(this->Platters);
			this->Controls->Add(this->DataBaseName);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MinimumSize = System::Drawing::Size(746, 509);
			this->Name = L"HardDriveInterface";
			this->Text = L"CreateTableInterface";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnConfirm_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ name = DataBaseName->Text;
		String^ platters = Platters->Text;
		String^ tracks = Tracks->Text;
		String^ quantityClusters = QuantityClusters->Text;
		String^ capacityClusters = CapacityClusters->Text;

		if (String::IsNullOrWhiteSpace(name) || String::IsNullOrWhiteSpace(platters) ||
			String::IsNullOrWhiteSpace(tracks) || String::IsNullOrWhiteSpace(capacityClusters) ||
			String::IsNullOrWhiteSpace(quantityClusters)) {
			MessageBox::Show("All fields must be filled!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		int valPlatters, valTracks, capClusters, valClusters;

		try
		{
			valPlatters = Convert::ToInt32(Platters->Text);
			valTracks = Convert::ToInt32(Tracks->Text);
			capClusters = Convert::ToInt32(CapacityClusters->Text);
			valClusters = Convert::ToInt32(QuantityClusters->Text);

			if (valPlatters <= 0 || valTracks <= 0 || capClusters <= 0 || valClusters <= 0)
			{
				MessageBox::Show("All numeric values must be greater than 0.");
				return;
			}
		}
		catch (FormatException^)
		{
			MessageBox::Show("All numeric fields must contain valid integers.");
			return;
		}
		catch (OverflowException^)
		{
			MessageBox::Show("One or more values are too large.");
			return;
		}

		MessageBox::Show("Database created successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		hd = gcnew HardDrive(valPlatters, valTracks, capClusters, valClusters);
		hd->ShowInfo();
		DataBaseProject::CreateTableInterface^ newForm = gcnew CreateTableInterface(name);
		newForm->Show();
		//this->Hide();
	}
	private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
		DataBaseName->Clear();
		Platters->Clear();
		Tracks->Clear();
		CapacityClusters->Clear();
		QuantityClusters->Clear();
	}
	};
}
