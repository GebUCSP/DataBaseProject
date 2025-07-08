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
	private: System::Windows::Forms::TextBox^ Value;


	protected:

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ btnConfirm;
	private: System::Windows::Forms::Button^ btnClear;
	private: System::Windows::Forms::ComboBox^ Operator;


	private: System::Windows::Forms::RadioButton^ btnAnd;
	private: System::Windows::Forms::RadioButton^ btnOr;
	private: System::Windows::Forms::ComboBox^ Attribute;

	private: System::Windows::Forms::ComboBox^ LikePosition;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lbLikeMatch;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ AdditionalAttribute;

	private: System::Windows::Forms::ComboBox^ AdditionalOperator;
	private: System::Windows::Forms::TextBox^ AdditionalValue;
	private: System::Windows::Forms::ComboBox^ AdditionalLikePosition;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;
		bool btnAndWasChecked = false;
		bool btnOrWasChecked = false;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbWelcome = (gcnew System::Windows::Forms::Label());
			this->Value = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnConfirm = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->Operator = (gcnew System::Windows::Forms::ComboBox());
			this->btnAnd = (gcnew System::Windows::Forms::RadioButton());
			this->btnOr = (gcnew System::Windows::Forms::RadioButton());
			this->Attribute = (gcnew System::Windows::Forms::ComboBox());
			this->LikePosition = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lbLikeMatch = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->AdditionalAttribute = (gcnew System::Windows::Forms::ComboBox());
			this->AdditionalOperator = (gcnew System::Windows::Forms::ComboBox());
			this->AdditionalValue = (gcnew System::Windows::Forms::TextBox());
			this->AdditionalLikePosition = (gcnew System::Windows::Forms::ComboBox());
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
			// Value
			// 
			this->Value->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Value->Location = System::Drawing::Point(369, 85);
			this->Value->Name = L"Value";
			this->Value->Size = System::Drawing::Size(174, 31);
			this->Value->TabIndex = 7;
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
			this->btnConfirm->Click += gcnew System::EventHandler(this, &QueryInterface::btnConfirm_Click);
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
			// Operator
			// 
			this->Operator->Font = (gcnew System::Drawing::Font(L"Lucida Sans Typewriter", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Operator->FormattingEnabled = true;
			this->Operator->Items->AddRange(gcnew cli::array< System::Object^  >(7) { L"=", L"!=", L"<", L">", L"<=", L">=", L"LIKE" });
			this->Operator->Location = System::Drawing::Point(190, 85);
			this->Operator->Name = L"Operator";
			this->Operator->Size = System::Drawing::Size(173, 31);
			this->Operator->TabIndex = 12;
			this->Operator->SelectedIndexChanged += gcnew System::EventHandler(this, &QueryInterface::Operators_SelectedIndexChanged);
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
			this->btnAnd->CheckedChanged += gcnew System::EventHandler(this, &QueryInterface::btnAnd_CheckedChanged);
			this->btnAnd->Click += gcnew System::EventHandler(this, &QueryInterface::btnAnd_Click);
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
			this->btnOr->CheckedChanged += gcnew System::EventHandler(this, &QueryInterface::btnOr_CheckedChanged);
			this->btnOr->Click += gcnew System::EventHandler(this, &QueryInterface::btnOr_Click);
			// 
			// Attribute
			// 
			this->Attribute->Font = (gcnew System::Drawing::Font(L"Lucida Sans Typewriter", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Attribute->FormattingEnabled = true;
			this->Attribute->Location = System::Drawing::Point(11, 85);
			this->Attribute->Name = L"Attribute";
			this->Attribute->Size = System::Drawing::Size(173, 31);
			this->Attribute->TabIndex = 15;
			this->Attribute->SelectedIndexChanged += gcnew System::EventHandler(this, &QueryInterface::Attribute_SelectedIndexChanged);
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
			this->LikePosition->Visible = false;
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
			// lbLikeMatch
			// 
			this->lbLikeMatch->AutoSize = true;
			this->lbLikeMatch->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbLikeMatch->Location = System::Drawing::Point(549, 64);
			this->lbLikeMatch->Name = L"lbLikeMatch";
			this->lbLikeMatch->Size = System::Drawing::Size(102, 18);
			this->lbLikeMatch->TabIndex = 19;
			this->lbLikeMatch->Text = L"LIKE match :";
			this->lbLikeMatch->Visible = false;
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
			// AdditionalAttribute
			// 
			this->AdditionalAttribute->Font = (gcnew System::Drawing::Font(L"Lucida Sans Typewriter", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->AdditionalAttribute->FormattingEnabled = true;
			this->AdditionalAttribute->Location = System::Drawing::Point(11, 173);
			this->AdditionalAttribute->Name = L"AdditionalAttribute";
			this->AdditionalAttribute->Size = System::Drawing::Size(173, 31);
			this->AdditionalAttribute->TabIndex = 21;
			this->AdditionalAttribute->Visible = false;
			// 
			// AdditionalOperator
			// 
			this->AdditionalOperator->Font = (gcnew System::Drawing::Font(L"Lucida Sans Typewriter", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->AdditionalOperator->FormattingEnabled = true;
			this->AdditionalOperator->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"=", L"!=", L"<", L">", L"<=", L">=",
					L"LIKE"
			});
			this->AdditionalOperator->Location = System::Drawing::Point(190, 173);
			this->AdditionalOperator->Name = L"AdditionalOperator";
			this->AdditionalOperator->Size = System::Drawing::Size(173, 31);
			this->AdditionalOperator->TabIndex = 22;
			this->AdditionalOperator->Visible = false;
			this->AdditionalOperator->SelectedIndexChanged += gcnew System::EventHandler(this, &QueryInterface::AdditionalOperator_SelectedIndexChanged);
			// 
			// AdditionalValue
			// 
			this->AdditionalValue->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AdditionalValue->Location = System::Drawing::Point(369, 173);
			this->AdditionalValue->Name = L"AdditionalValue";
			this->AdditionalValue->Size = System::Drawing::Size(174, 31);
			this->AdditionalValue->TabIndex = 23;
			this->AdditionalValue->Visible = false;
			// 
			// AdditionalLikePosition
			// 
			this->AdditionalLikePosition->Font = (gcnew System::Drawing::Font(L"Lucida Sans Typewriter", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->AdditionalLikePosition->FormattingEnabled = true;
			this->AdditionalLikePosition->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Begin", L"End", L"Include" });
			this->AdditionalLikePosition->Location = System::Drawing::Point(549, 173);
			this->AdditionalLikePosition->Name = L"AdditionalLikePosition";
			this->AdditionalLikePosition->Size = System::Drawing::Size(173, 31);
			this->AdditionalLikePosition->TabIndex = 24;
			this->AdditionalLikePosition->Visible = false;
			// 
			// QueryInterface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(730, 470);
			this->Controls->Add(this->AdditionalLikePosition);
			this->Controls->Add(this->AdditionalValue);
			this->Controls->Add(this->AdditionalOperator);
			this->Controls->Add(this->AdditionalAttribute);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->lbLikeMatch);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->LikePosition);
			this->Controls->Add(this->Attribute);
			this->Controls->Add(this->btnOr);
			this->Controls->Add(this->btnAnd);
			this->Controls->Add(this->Operator);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->Value);
			this->Controls->Add(this->lbWelcome);
			this->MinimumSize = System::Drawing::Size(746, 509);
			this->Name = L"QueryInterface";
			this->Text = L"CreateTableInterface";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Operators_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ selectedOperator = Operator->SelectedItem != nullptr ? Operator->SelectedItem->ToString() : "";

		if (selectedOperator == "LIKE") {
			lbLikeMatch->Visible = true;
			LikePosition->Visible = true; 
		}
		else {
			lbLikeMatch->Visible = false;
			LikePosition->Visible = false;
		}
	}
	
	private: System::Void btnAnd_Click(System::Object^ sender, System::EventArgs^ e) {
		if (btnAnd->Checked && btnAndWasChecked) {
			AdditionalAttribute->SelectedIndex = -1;
			AdditionalOperator->SelectedIndex = -1;
			AdditionalValue->Clear();

			btnAnd->Checked = false; 
		}
		btnAndWasChecked = btnAnd->Checked;
	}

	private: System::Void btnAnd_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (btnAnd->Checked) {
			AdditionalAttribute->SelectedIndex = -1;
			AdditionalOperator->SelectedIndex = -1;
			AdditionalValue->Clear();

			AdditionalAttribute->Visible = true;
			AdditionalOperator->Visible = true;
			AdditionalValue->Visible = true;
		}
		else {
			AdditionalAttribute->Visible = false;
			AdditionalOperator->Visible = false;
			AdditionalValue->Visible = false;
		}
	}
	private: System::Void btnOr_Click(System::Object^ sender, System::EventArgs^ e) {
		if (btnOr->Checked && btnOrWasChecked) {
			AdditionalAttribute->SelectedIndex = -1;
			AdditionalOperator->SelectedIndex = -1;
			AdditionalValue->Clear();

			btnOr->Checked = false;
		}
		btnOrWasChecked = btnOr->Checked;
	}
	private: System::Void btnOr_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (btnOr->Checked) {
			AdditionalAttribute->SelectedIndex = -1;
			AdditionalOperator->SelectedIndex = -1;
			AdditionalValue->Clear();

			AdditionalAttribute->Visible = true;
			AdditionalOperator->Visible = true;
			AdditionalValue->Visible = true;
		}
		else {
			AdditionalAttribute->Visible = false;
			AdditionalOperator->Visible = false;
			AdditionalValue->Visible = false;
		}
	}
	private: System::Void AdditionalOperator_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ selectedOperator = AdditionalOperator->SelectedItem != nullptr ? AdditionalOperator->SelectedItem->ToString() : "";

		if (selectedOperator == "LIKE") {
			AdditionalLikePosition->Visible = true; 
		}
		else {
			AdditionalLikePosition->Visible = false; 
		}
	}
	private: System::Void btnConfirm_Click(System::Object^ sender, System::EventArgs^ e) {
		//Llamar la función de búsqueda
	}
	private: System::Void Attribute_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		//Llamar al read Manager
	}
};
}
