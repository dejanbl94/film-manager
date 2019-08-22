#pragma once

namespace FilmManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for InsertActorForm
	/// </summary>
	public ref class InsertActorForm : public System::Windows::Forms::Form
	{
	public:
		InsertActorForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~InsertActorForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ movTitleTxtBox;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
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
			this->movTitleTxtBox = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(72, 19);
			this->label1->TabIndex = 10;
			this->label1->Text = L"First name:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 79);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(69, 19);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Last name:";
			// 
			// movTitleTxtBox
			// 
			this->movTitleTxtBox->Location = System::Drawing::Point(112, 27);
			this->movTitleTxtBox->Name = L"movTitleTxtBox";
			this->movTitleTxtBox->Size = System::Drawing::Size(100, 20);
			this->movTitleTxtBox->TabIndex = 12;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(112, 78);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 13;
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(16, 243);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(110, 31);
			this->button1->TabIndex = 14;
			this->button1->Text = L"Insert";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &InsertActorForm::button1_Click);
			// 
			// InsertActorForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(309, 286);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->movTitleTxtBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"InsertActorForm";
			this->Text = L"InsertActorForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ conString = L"datasource=localhost;port=3306;username=root;password=root"; //probaj ovo staviti u button1 na mainform pa u adapter referencirati staticno
		MySqlConnection^ connection = gcnew MySqlConnection(conString);
		connection->Open();

		MySqlCommand^ command;
		MySqlDataReader^ myReader;

		command = gcnew MySqlCommand("INSERT INTO sakila.actor (first_name,last_name) values('" + this->movTitleTxtBox->Text + "','" + this->textBox1->Text + "');", connection);

		try {

			myReader = command->ExecuteReader();
			MessageBox::Show("Row inserted!");
			while (myReader->Read()) {

			}
		}
		catch (Exception^ ex) {

			MessageBox::Show(ex->Message);
		}
	}




	};

}