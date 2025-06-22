#pragma once
namespace DataBaseProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	/// <summary>
	/// Summary for QueryInterface
	/// </summary>
	public ref class QueryInterface : public System::Windows::Forms::Form
	{
	public:
		QueryInterface()
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~QueryInterface()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbWelcome;
	private: System::Windows::Forms::TextBox^ SearchValue;

	protected:


















	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ btnConfirm;
	private: System::Windows::Forms::Button^ btnClear;
	private: System::Windows::Forms::ComboBox^ Operators;

	private: System::Windows::Forms::RadioButton^ btnAnd;
	private: System::Windows::Forms::RadioButton^ btnOr;
	private: System::Windows::Forms::ComboBox^ Attributes;
	private: System::Windows::Forms::ComboBox^ LikePosition;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;










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
			this->lbWelcome = (gcnew System::Windows::Forms::Label());
			this->SearchValue = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnConfirm = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->Operators = (gcnew System::Windows::Forms::ComboBox());
			this->btnAnd = (gcnew System::Windows::Forms::RadioButton());
			this->btnOr = (gcnew System::Windows::Forms::RadioButton());
			this->Attributes = (gcnew System::Windows::Forms::ComboBox());
			this->LikePosition = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
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
			this->lbWelcome->Size = System::Drawing::Size(186, 25);
			this->lbWelcome->TabIndex = 0;
			this->lbWelcome->Text = L"Query Interface";
			// 
			// SearchValue
			// 
			this->SearchValue->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SearchValue->Location = System::Drawing::Point(369, 85);
			this->SearchValue->Name = L"SearchValue";
			this->SearchValue->Size = System::Drawing::Size(174, 31);
			this->SearchValue->TabIndex = 7;
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
			// 
			// Operators
			// 
			this->Operators->Font = (gcnew System::Drawing::Font(L"Lucida Sans Typewriter", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Operators->FormattingEnabled = true;
			this->Operators->Items->AddRange(gcnew cli::array< System::Object^  >(7) { L"=", L"!=", L"<", L">", L"<=", L">=", L"LIKE" });
			this->Operators->Location = System::Drawing::Point(190, 85);
			this->Operators->Name = L"Operators";
			this->Operators->Size = System::Drawing::Size(173, 31);
			this->Operators->TabIndex = 12;
			// 
			// btnAnd
			// 
			this->btnAnd->AutoSize = true;
			this->btnAnd->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAnd->Location = System::Drawing::Point(13, 140);
			this->btnAnd->Name = L"btnAnd";
			this->btnAnd->Size = System::Drawing::Size(69, 27);
			this->btnAnd->TabIndex = 13;
			this->btnAnd->TabStop = true;
			this->btnAnd->Text = L"AND";
			this->btnAnd->UseVisualStyleBackColor = true;
			// 
			// btnOr
			// 
			this->btnOr->AutoSize = true;
			this->btnOr->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOr->Location = System::Drawing::Point(126, 140);
			this->btnOr->Name = L"btnOr";
			this->btnOr->Size = System::Drawing::Size(55, 27);
			this->btnOr->TabIndex = 14;
			this->btnOr->TabStop = true;
			this->btnOr->Text = L"OR";
			this->btnOr->UseVisualStyleBackColor = true;
			// 
			// Attributes
			// 
			this->Attributes->Font = (gcnew System::Drawing::Font(L"Lucida Sans Typewriter", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Attributes->FormattingEnabled = true;
			this->Attributes->Location = System::Drawing::Point(11, 85);
			this->Attributes->Name = L"Attributes";
			this->Attributes->Size = System::Drawing::Size(173, 31);
			this->Attributes->TabIndex = 15;
			// 
			// LikePosition
			// 
			this->LikePosition->Font = (gcnew System::Drawing::Font(L"Lucida Sans Typewriter", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LikePosition->FormattingEnabled = true;
			this->LikePosition->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Begin", L"End", L"Include" });
			this->LikePosition->Location = System::Drawing::Point(549, 85);
			this->LikePosition->Name = L"LikePosition";
			this->LikePosition->Size = System::Drawing::Size(173, 31);
			this->LikePosition->TabIndex = 16;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(8, 64);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 18);
			this->label1->TabIndex = 17;
			this->label1->Text = L"Field :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(187, 64);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(83, 18);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Operator :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(549, 64);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(102, 18);
			this->label3->TabIndex = 19;
			this->label3->Text = L"LIKE match :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(366, 64);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(61, 18);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Value :";
			// 
			// QueryInterface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(730, 470);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->LikePosition);
			this->Controls->Add(this->Attributes);
			this->Controls->Add(this->btnOr);
			this->Controls->Add(this->btnAnd);
			this->Controls->Add(this->Operators);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->SearchValue);
			this->Controls->Add(this->lbWelcome);
			this->Name = L"QueryInterface";
			this->Text = L"CreateTableInterface";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
};
}
