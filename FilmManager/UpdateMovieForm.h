#pragma once
#include<iostream>
#include"../FilmManager/Headers/Database Headers/Repository.h"

namespace FilmManager {
	/// <summary>
	/// Summary for UpdateMovieForm
	/// </summary>
	public ref class UpdateMovieForm : public System::Windows::Forms::Form
	{
	public:

		UpdateMovieForm(int id) //U FilmMainForm proslijedjujemo id filma iz current row-a
		{
			InitializeComponent();
			std::vector<std::string> koneksnString = getCurrentConnectionString();
			ConnectionString* con = new ConnectionString(koneksnString[0], koneksnString[1], koneksnString[2], koneksnString[3]);
			Repository* repo = new Repository(*con);
			Film film = repo->getFilmById(std::to_string(id));

			titleTxtBox->Text = gcnew System::String((film.title).c_str());
			lengthTxtBox->Text = gcnew System::String((film.length).c_str());
			releasedTxtBox->Text = gcnew System::String((film.releaseYear).c_str());
			descriptionRichTxtBox->Text = gcnew System::String((film.description).c_str());
			idTxtBox->Text = film.id.ToString();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UpdateMovieForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

		System::Windows::Forms::RichTextBox^ descriptionRichTxtBox;
		System::Windows::Forms::TextBox^ idTxtBox;
		System::Windows::Forms::TextBox^ titleTxtBox;
		System::Windows::Forms::TextBox^ lengthTxtBox;
		System::Windows::Forms::TextBox^ releasedTxtBox;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Label^ movTitleBox;
		System::Windows::Forms::Label^ movLengthBox;
		System::Windows::Forms::Label^ movReleasedBox;
		System::Windows::Forms::Label^ movDescBox;
		System::Windows::Forms::Button^ updateBtn;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UpdateMovieForm::typeid));
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->titleTxtBox = (gcnew System::Windows::Forms::TextBox());
			this->lengthTxtBox = (gcnew System::Windows::Forms::TextBox());
			this->releasedTxtBox = (gcnew System::Windows::Forms::TextBox());
			this->movTitleBox = (gcnew System::Windows::Forms::Label());
			this->movLengthBox = (gcnew System::Windows::Forms::Label());
			this->movReleasedBox = (gcnew System::Windows::Forms::Label());
			this->movDescBox = (gcnew System::Windows::Forms::Label());
			this->updateBtn = (gcnew System::Windows::Forms::Button());
			this->descriptionRichTxtBox = (gcnew System::Windows::Forms::RichTextBox());
			this->idTxtBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			//
			// label3
			//
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(127, 19);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Update movie details:";
			//
			// titleTxtBox
			//
			this->titleTxtBox->Location = System::Drawing::Point(115, 44);
			this->titleTxtBox->Name = L"titleTxtBox";
			this->titleTxtBox->Size = System::Drawing::Size(240, 20);
			this->titleTxtBox->TabIndex = 6;
			//
			// lengthTxtBox
			//
			this->lengthTxtBox->Location = System::Drawing::Point(115, 83);
			this->lengthTxtBox->Name = L"lengthTxtBox";
			this->lengthTxtBox->Size = System::Drawing::Size(75, 20);
			this->lengthTxtBox->TabIndex = 7;
			//
			// releasedTxtBox
			//
			this->releasedTxtBox->Location = System::Drawing::Point(115, 121);
			this->releasedTxtBox->Name = L"releasedTxtBox";
			this->releasedTxtBox->Size = System::Drawing::Size(75, 20);
			this->releasedTxtBox->TabIndex = 8;
			//
			// movTitleBox
			//
			this->movTitleBox->AutoSize = true;
			this->movTitleBox->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->movTitleBox->Location = System::Drawing::Point(27, 44);
			this->movTitleBox->Name = L"movTitleBox";
			this->movTitleBox->Size = System::Drawing::Size(34, 19);
			this->movTitleBox->TabIndex = 10;
			this->movTitleBox->Text = L"title:";
			//
			// movLengthBox
			//
			this->movLengthBox->AutoSize = true;
			this->movLengthBox->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->movLengthBox->Location = System::Drawing::Point(27, 83);
			this->movLengthBox->Name = L"movLengthBox";
			this->movLengthBox->Size = System::Drawing::Size(46, 19);
			this->movLengthBox->TabIndex = 11;
			this->movLengthBox->Text = L"length:";
			//
			// movReleasedBox
			//
			this->movReleasedBox->AutoSize = true;
			this->movReleasedBox->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->movReleasedBox->Location = System::Drawing::Point(27, 121);
			this->movReleasedBox->Name = L"movReleasedBox";
			this->movReleasedBox->Size = System::Drawing::Size(57, 19);
			this->movReleasedBox->TabIndex = 12;
			this->movReleasedBox->Text = L"released:";
			//
			// movDescBox
			//
			this->movDescBox->AutoSize = true;
			this->movDescBox->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->movDescBox->Location = System::Drawing::Point(27, 203);
			this->movDescBox->Name = L"movDescBox";
			this->movDescBox->Size = System::Drawing::Size(73, 19);
			this->movDescBox->TabIndex = 13;
			this->movDescBox->Text = L"description:";
			//
			// updateBtn
			//
			this->updateBtn->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->updateBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->updateBtn->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->updateBtn->Location = System::Drawing::Point(331, 297);
			this->updateBtn->Name = L"updateBtn";
			this->updateBtn->Size = System::Drawing::Size(83, 35);
			this->updateBtn->TabIndex = 14;
			this->updateBtn->Text = L"Save";
			this->updateBtn->UseVisualStyleBackColor = false;
			this->updateBtn->Click += gcnew System::EventHandler(this, &UpdateMovieForm::updateBtn_Click);
			//
			// descriptionRichTxtBox
			//
			this->descriptionRichTxtBox->Location = System::Drawing::Point(115, 163);
			this->descriptionRichTxtBox->Name = L"descriptionRichTxtBox";
			this->descriptionRichTxtBox->Size = System::Drawing::Size(299, 111);
			this->descriptionRichTxtBox->TabIndex = 15;
			this->descriptionRichTxtBox->Text = L"";
			//
			// idTxtBox
			//
			this->idTxtBox->Location = System::Drawing::Point(386, 43);
			this->idTxtBox->Name = L"idTxtBox";
			this->idTxtBox->ReadOnly = true;
			this->idTxtBox->Size = System::Drawing::Size(28, 20);
			this->idTxtBox->TabIndex = 16;
			//
			// UpdateMovieForm
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(441, 352);
			this->Controls->Add(this->idTxtBox);
			this->Controls->Add(this->descriptionRichTxtBox);
			this->Controls->Add(this->updateBtn);
			this->Controls->Add(this->movDescBox);
			this->Controls->Add(this->movReleasedBox);
			this->Controls->Add(this->movLengthBox);
			this->Controls->Add(this->movTitleBox);
			this->Controls->Add(this->releasedTxtBox);
			this->Controls->Add(this->lengthTxtBox);
			this->Controls->Add(this->titleTxtBox);
			this->Controls->Add(this->label3);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(664, 533);
			this->MinimumSize = System::Drawing::Size(330, 250);
			this->Name = L"UpdateMovieForm";
			this->Text = L"Manager";
			this->ResumeLayout(false);
			this->PerformLayout();
		}//ovu metodu za update odradi
#pragma endregion

		System::Void updateBtn_Click(System::Object^ sender, System::EventArgs^ e)

		{
			std::string unmanagedTitle = msclr::interop::marshal_as<std::string>(titleTxtBox->Text);
			std::string unmanagedRelYear = msclr::interop::marshal_as<std::string>(releasedTxtBox->Text);
			std::string unmanagedLength = msclr::interop::marshal_as<std::string>(lengthTxtBox->Text);
			std::string unmanagedDesc = msclr::interop::marshal_as<std::string>(descriptionRichTxtBox->Text);
			int id = int::Parse(idTxtBox->Text);

			Film* film = new Film(id, unmanagedTitle, unmanagedRelYear, unmanagedDesc, unmanagedLength);

			std::vector<std::string> koneksnString = getCurrentConnectionString();
			ConnectionString* con = new ConnectionString(koneksnString[0], koneksnString[1], koneksnString[2], koneksnString[3]);
			Repository* repo = new Repository(*con);

			repo->updateFilm(*film);

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

			else {
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