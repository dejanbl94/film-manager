#pragma once
#include"../FilmManager/Headers/Database Headers/Repository.h"
#include "../FilmManager/Headers/Model Headers/Film.h"

namespace FilmManager {
	/// <summary>
	/// Summary for InsertMovieForm
	/// </summary>

	public ref class InsertMovieForm : public System::Windows::Forms::Form
	{
	public:
		InsertMovieForm(void)
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
		~InsertMovieForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

		System::Windows::Forms::TextBox^ movTitleTxtBox;
		System::Windows::Forms::TextBox^ movRelYearTxtBox;
		System::Windows::Forms::TextBox^ movLengthTxtBox;

		System::Windows::Forms::Label^ titleLbl;
		System::Windows::Forms::Label^ lengthLbl;
		System::Windows::Forms::Label^ relYearLbl;
		System::Windows::Forms::Label^ descLbl;
		System::Windows::Forms::Button^ insertMovBtn;
	private: System::Windows::Forms::Label^ infoLbl;
	private: System::Windows::Forms::RichTextBox^ movieDescTxtBox;

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
				 System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InsertMovieForm::typeid));
				 this->movTitleTxtBox = (gcnew System::Windows::Forms::TextBox());
				 this->movRelYearTxtBox = (gcnew System::Windows::Forms::TextBox());
				 this->movLengthTxtBox = (gcnew System::Windows::Forms::TextBox());
				 this->titleLbl = (gcnew System::Windows::Forms::Label());
				 this->lengthLbl = (gcnew System::Windows::Forms::Label());
				 this->relYearLbl = (gcnew System::Windows::Forms::Label());
				 this->descLbl = (gcnew System::Windows::Forms::Label());
				 this->insertMovBtn = (gcnew System::Windows::Forms::Button());
				 this->infoLbl = (gcnew System::Windows::Forms::Label());
				 this->movieDescTxtBox = (gcnew System::Windows::Forms::RichTextBox());
				 this->SuspendLayout();
				 //
				 // movTitleTxtBox
				 //
				 this->movTitleTxtBox->Location = System::Drawing::Point(129, 54);
				 this->movTitleTxtBox->Name = L"movTitleTxtBox";
				 this->movTitleTxtBox->Size = System::Drawing::Size(201, 20);
				 this->movTitleTxtBox->TabIndex = 0;
				 //
				 // movRelYearTxtBox
				 //
				 this->movRelYearTxtBox->Location = System::Drawing::Point(129, 94);
				 this->movRelYearTxtBox->Name = L"movRelYearTxtBox";
				 this->movRelYearTxtBox->Size = System::Drawing::Size(100, 20);
				 this->movRelYearTxtBox->TabIndex = 1;
				 //
				 // movLengthTxtBox
				 //
				 this->movLengthTxtBox->Location = System::Drawing::Point(129, 132);
				 this->movLengthTxtBox->Name = L"movLengthTxtBox";
				 this->movLengthTxtBox->Size = System::Drawing::Size(100, 20);
				 this->movLengthTxtBox->TabIndex = 2;
				 //
				 // titleLbl
				 //
				 this->titleLbl->AutoSize = true;
				 this->titleLbl->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->titleLbl->Location = System::Drawing::Point(26, 54);
				 this->titleLbl->Name = L"titleLbl";
				 this->titleLbl->Size = System::Drawing::Size(34, 19);
				 this->titleLbl->TabIndex = 4;
				 this->titleLbl->Text = L"title:";
				 //
				 // lengthLbl
				 //
				 this->lengthLbl->AutoSize = true;
				 this->lengthLbl->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->lengthLbl->Location = System::Drawing::Point(26, 94);
				 this->lengthLbl->Name = L"lengthLbl";
				 this->lengthLbl->Size = System::Drawing::Size(79, 19);
				 this->lengthLbl->TabIndex = 5;
				 this->lengthLbl->Text = L"release year:";
				 //
				 // relYearLbl
				 //
				 this->relYearLbl->AutoSize = true;
				 this->relYearLbl->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->relYearLbl->Location = System::Drawing::Point(26, 132);
				 this->relYearLbl->Name = L"relYearLbl";
				 this->relYearLbl->Size = System::Drawing::Size(46, 19);
				 this->relYearLbl->TabIndex = 6;
				 this->relYearLbl->Text = L"length:";
				 //
				 // descLbl
				 //
				 this->descLbl->AutoSize = true;
				 this->descLbl->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->descLbl->Location = System::Drawing::Point(26, 174);
				 this->descLbl->Name = L"descLbl";
				 this->descLbl->Size = System::Drawing::Size(73, 19);
				 this->descLbl->TabIndex = 7;
				 this->descLbl->Text = L"description:";
				 //
				 // insertMovBtn
				 //
				 this->insertMovBtn->BackColor = System::Drawing::SystemColors::InactiveBorder;
				 this->insertMovBtn->Cursor = System::Windows::Forms::Cursors::Hand;
				 this->insertMovBtn->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->insertMovBtn->Location = System::Drawing::Point(336, 322);
				 this->insertMovBtn->Name = L"insertMovBtn";
				 this->insertMovBtn->Size = System::Drawing::Size(83, 35);
				 this->insertMovBtn->TabIndex = 9;
				 this->insertMovBtn->Text = L"Save";
				 this->insertMovBtn->UseVisualStyleBackColor = false;
				 this->insertMovBtn->Click += gcnew System::EventHandler(this, &InsertMovieForm::insertMovBtn_Click);
				 //
				 // infoLbl
				 //
				 this->infoLbl->AutoSize = true;
				 this->infoLbl->BackColor = System::Drawing::SystemColors::InactiveBorder;
				 this->infoLbl->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->infoLbl->Location = System::Drawing::Point(12, 19);
				 this->infoLbl->Name = L"infoLbl";
				 this->infoLbl->Size = System::Drawing::Size(107, 19);
				 this->infoLbl->TabIndex = 10;
				 this->infoLbl->Text = L"Insert new movie:";
				 //
				 // movieDescTxtBox
				 //
				 this->movieDescTxtBox->Location = System::Drawing::Point(129, 174);
				 this->movieDescTxtBox->Name = L"movieDescTxtBox";
				 this->movieDescTxtBox->Size = System::Drawing::Size(290, 125);
				 this->movieDescTxtBox->TabIndex = 11;
				 this->movieDescTxtBox->Text = L"";
				 //
				 // InsertMovieForm
				 //
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(441, 378);
				 this->Controls->Add(this->movieDescTxtBox);
				 this->Controls->Add(this->infoLbl);
				 this->Controls->Add(this->insertMovBtn);
				 this->Controls->Add(this->descLbl);
				 this->Controls->Add(this->relYearLbl);
				 this->Controls->Add(this->lengthLbl);
				 this->Controls->Add(this->titleLbl);
				 this->Controls->Add(this->movLengthTxtBox);
				 this->Controls->Add(this->movRelYearTxtBox);
				 this->Controls->Add(this->movTitleTxtBox);
				 this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
				 this->MaximumSize = System::Drawing::Size(640, 480);
				 this->MinimumSize = System::Drawing::Size(325, 325);
				 this->Name = L"InsertMovieForm";
				 this->Text = L"Manager";
				 this->ResumeLayout(false);
				 this->PerformLayout();
			 }
#pragma endregion

	private:

		System::Void insertMovBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			std::string movTitle = msclr::interop::marshal_as<std::string>(gcnew System::String(this->movTitleTxtBox->Text));
			std::string movRelYear = msclr::interop::marshal_as<std::string>(gcnew System::String(this->movRelYearTxtBox->Text));
			std::string movLength = msclr::interop::marshal_as<std::string>(gcnew System::String(this->movLengthTxtBox->Text));
			std::string movDesc = msclr::interop::marshal_as<std::string>(gcnew System::String(this->movieDescTxtBox->Text));

			Film* film = new Film(movTitle, movRelYear, movDesc, movLength);

			std::vector<std::string> koneksnString = getCurrentConnectionString();
			ConnectionString* con = new ConnectionString(koneksnString[0], koneksnString[1], koneksnString[2], koneksnString[3]);
			Repository* repo = new Repository(*con);

			repo->insertFilm(*film);

			MessageBox::Show("Row inserted!");
			this->Close();
		}

		std::vector<std::string> getCurrentConnectionString() {
			std::vector<std::string> test(3);

			std::string server, port, username, password;

			std::string line;
			std::ifstream infile("connection_properties.txt");

			if (!infile)

			{
				server = "localhost";
				port = "3306";
				username = "root";
				password = "root";
			}

			else

			{
				std::getline(infile, line);  //smjesta svaku novu liniju u line i onda citamo line u stringove
				server = line;

				std::getline(infile, line);
				port = line;

				std::getline(infile, line);
				username = line;

				std::getline(infile, line);
				password = line;
			}

			test = { server, port, username, password };

			return test;
		}
	};
}