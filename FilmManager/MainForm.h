#pragma once
#include "ActorMainForm.h"
#include "CategoryMainForm.h"
#include "FilmMainForm.h"
#include "../FilmManager/Headers/Model Headers/CurrentStatistics.h"
#include "../FilmManager/Headers/Database Headers/ConnectionProperties.h"
#include<string>

namespace FilmManager {
	/// <summary>
	/// Summary for MainForm
	/// </summary>

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:

		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

		System::Windows::Forms::Label^ titleLabel;
		System::Windows::Forms::Label^ authorInfoLabel;
		System::Windows::Forms::Label^ totalCountLabe;
		System::Windows::Forms::Label^ mostPopularActorLabel;
		System::Windows::Forms::Label^ navigateLabel;
		System::Windows::Forms::Button^ currentStatsBtn;
		System::Windows::Forms::Button^ actorsBtn;
		System::Windows::Forms::Button^ filmMainFormBtn;
		System::Windows::Forms::Button^ categoryMainFormBtn;
		System::Windows::Forms::TextBox^ totalCountTxtBox;
		System::Windows::Forms::TextBox^ mostPopActorTxtBox;

	private: System::Windows::Forms::Button^ connectionPropertiesBtn;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->navigateLabel = (gcnew System::Windows::Forms::Label());
			this->actorsBtn = (gcnew System::Windows::Forms::Button());
			this->filmMainFormBtn = (gcnew System::Windows::Forms::Button());
			this->categoryMainFormBtn = (gcnew System::Windows::Forms::Button());
			this->totalCountLabe = (gcnew System::Windows::Forms::Label());
			this->mostPopularActorLabel = (gcnew System::Windows::Forms::Label());
			this->totalCountTxtBox = (gcnew System::Windows::Forms::TextBox());
			this->mostPopActorTxtBox = (gcnew System::Windows::Forms::TextBox());
			this->currentStatsBtn = (gcnew System::Windows::Forms::Button());
			this->titleLabel = (gcnew System::Windows::Forms::Label());
			this->authorInfoLabel = (gcnew System::Windows::Forms::Label());
			this->connectionPropertiesBtn = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			//
			// navigateLabel
			//
			this->navigateLabel->AutoSize = true;
			this->navigateLabel->BackColor = System::Drawing::SystemColors::Control;
			this->navigateLabel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->navigateLabel->Font = (gcnew System::Drawing::Font(L"Segoe Print", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->navigateLabel->ForeColor = System::Drawing::SystemColors::ControlText;
			this->navigateLabel->Location = System::Drawing::Point(16, 214);
			this->navigateLabel->Name = L"navigateLabel";
			this->navigateLabel->Size = System::Drawing::Size(87, 23);
			this->navigateLabel->TabIndex = 0;
			this->navigateLabel->Text = L"Navigate to:";
			//
			// actorsBtn
			//
			this->actorsBtn->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->actorsBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->actorsBtn->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->actorsBtn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->actorsBtn->Location = System::Drawing::Point(16, 296);
			this->actorsBtn->Name = L"actorsBtn";
			this->actorsBtn->Size = System::Drawing::Size(87, 36);
			this->actorsBtn->TabIndex = 1;
			this->actorsBtn->Text = L"Actor";
			this->actorsBtn->UseVisualStyleBackColor = false;
			this->actorsBtn->Click += gcnew System::EventHandler(this, &MainForm::actorsBtn_Click);
			//
			// filmMainFormBtn
			//
			this->filmMainFormBtn->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->filmMainFormBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->filmMainFormBtn->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->filmMainFormBtn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->filmMainFormBtn->Location = System::Drawing::Point(14, 254);
			this->filmMainFormBtn->Name = L"filmMainFormBtn";
			this->filmMainFormBtn->Size = System::Drawing::Size(87, 36);
			this->filmMainFormBtn->TabIndex = 2;
			this->filmMainFormBtn->Text = L"Film";
			this->filmMainFormBtn->UseVisualStyleBackColor = false;
			this->filmMainFormBtn->Click += gcnew System::EventHandler(this, &MainForm::filmMainFormBtn_Click);
			//
			// categoryMainFormBtn
			//
			this->categoryMainFormBtn->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->categoryMainFormBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->categoryMainFormBtn->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->categoryMainFormBtn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->categoryMainFormBtn->Location = System::Drawing::Point(14, 338);
			this->categoryMainFormBtn->Name = L"categoryMainFormBtn";
			this->categoryMainFormBtn->Size = System::Drawing::Size(89, 36);
			this->categoryMainFormBtn->TabIndex = 3;
			this->categoryMainFormBtn->Text = L"Category";
			this->categoryMainFormBtn->UseVisualStyleBackColor = false;
			this->categoryMainFormBtn->Click += gcnew System::EventHandler(this, &MainForm::categoryMainFormBtn_Click);
			//
			// totalCountLabe
			//
			this->totalCountLabe->AutoSize = true;
			this->totalCountLabe->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->totalCountLabe->Location = System::Drawing::Point(494, 318);
			this->totalCountLabe->Name = L"totalCountLabe";
			this->totalCountLabe->Size = System::Drawing::Size(110, 19);
			this->totalCountLabe->TabIndex = 6;
			this->totalCountLabe->Text = L"Total movie count:";
			//
			// mostPopularActorLabel
			//
			this->mostPopularActorLabel->AutoSize = true;
			this->mostPopularActorLabel->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mostPopularActorLabel->Location = System::Drawing::Point(675, 318);
			this->mostPopularActorLabel->Name = L"mostPopularActorLabel";
			this->mostPopularActorLabel->Size = System::Drawing::Size(117, 19);
			this->mostPopularActorLabel->TabIndex = 7;
			this->mostPopularActorLabel->Text = L"Most popular actor:";
			//
			// totalCountTxtBox
			//
			this->totalCountTxtBox->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->totalCountTxtBox->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->totalCountTxtBox->Location = System::Drawing::Point(468, 347);
			this->totalCountTxtBox->Name = L"totalCountTxtBox";
			this->totalCountTxtBox->ReadOnly = true;
			this->totalCountTxtBox->Size = System::Drawing::Size(136, 27);
			this->totalCountTxtBox->TabIndex = 8;
			//
			// mostPopActorTxtBox
			//
			this->mostPopActorTxtBox->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mostPopActorTxtBox->Location = System::Drawing::Point(679, 347);
			this->mostPopActorTxtBox->Margin = System::Windows::Forms::Padding(4, 3, 3, 3);
			this->mostPopActorTxtBox->Name = L"mostPopActorTxtBox";
			this->mostPopActorTxtBox->ReadOnly = true;
			this->mostPopActorTxtBox->Size = System::Drawing::Size(136, 27);
			this->mostPopActorTxtBox->TabIndex = 9;
			//
			// currentStatsBtn
			//
			this->currentStatsBtn->BackColor = System::Drawing::Color::SeaShell;
			this->currentStatsBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->currentStatsBtn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->currentStatsBtn->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->currentStatsBtn->Location = System::Drawing::Point(581, 281);
			this->currentStatsBtn->Name = L"currentStatsBtn";
			this->currentStatsBtn->Size = System::Drawing::Size(125, 34);
			this->currentStatsBtn->TabIndex = 12;
			this->currentStatsBtn->Text = L"Current Statistics";
			this->currentStatsBtn->UseVisualStyleBackColor = true;
			this->currentStatsBtn->Click += gcnew System::EventHandler(this, &MainForm::currentStatsBtn_Click);
			//
			// titleLabel
			//
			this->titleLabel->AutoSize = true;
			this->titleLabel->Font = (gcnew System::Drawing::Font(L"Segoe Print", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->titleLabel->Location = System::Drawing::Point(285, 0);
			this->titleLabel->Name = L"titleLabel";
			this->titleLabel->Size = System::Drawing::Size(272, 61);
			this->titleLabel->TabIndex = 4;
			this->titleLabel->Text = L"Film Manager";
			//
			// authorInfoLabel
			//
			this->authorInfoLabel->AutoSize = true;
			this->authorInfoLabel->BackColor = System::Drawing::Color::MistyRose;
			this->authorInfoLabel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->authorInfoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->authorInfoLabel->Location = System::Drawing::Point(423, 141);
			this->authorInfoLabel->Name = L"authorInfoLabel";
			this->authorInfoLabel->Size = System::Drawing::Size(344, 72);
			this->authorInfoLabel->TabIndex = 14;
			this->authorInfoLabel->Text = L"Dejan Tamamovic | Odsjek: Matematika i informatika | Smjer: Opšti\r\n\r\n           "
				L"                             Seminarski rad\r\n\r\n                     Tehnologije:"
				L" C++/CLI, Winforms, MySql";
			//
			// connectionPropertiesBtn
			//
			this->connectionPropertiesBtn->BackColor = System::Drawing::SystemColors::Window;
			this->connectionPropertiesBtn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"connectionPropertiesBtn.BackgroundImage")));
			this->connectionPropertiesBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->connectionPropertiesBtn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->connectionPropertiesBtn->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->connectionPropertiesBtn->ForeColor = System::Drawing::Color::Black;
			this->connectionPropertiesBtn->Location = System::Drawing::Point(753, 45);
			this->connectionPropertiesBtn->Name = L"connectionPropertiesBtn";
			this->connectionPropertiesBtn->Size = System::Drawing::Size(79, 32);
			this->connectionPropertiesBtn->TabIndex = 15;
			this->connectionPropertiesBtn->Text = L"Properties";
			this->connectionPropertiesBtn->UseVisualStyleBackColor = false;
			this->connectionPropertiesBtn->Click += gcnew System::EventHandler(this, &MainForm::connectionPropertiesBtn_Click);
			//
			// pictureBox1
			//
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(107, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(251, 375);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 13;
			this->pictureBox1->TabStop = false;
			//
			// MainForm
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(828, 386);
			this->Controls->Add(this->connectionPropertiesBtn);
			this->Controls->Add(this->authorInfoLabel);
			this->Controls->Add(this->navigateLabel);
			this->Controls->Add(this->totalCountLabe);
			this->Controls->Add(this->totalCountTxtBox);
			this->Controls->Add(this->titleLabel);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->currentStatsBtn);
			this->Controls->Add(this->mostPopActorTxtBox);
			this->Controls->Add(this->mostPopularActorLabel);
			this->Controls->Add(this->categoryMainFormBtn);
			this->Controls->Add(this->filmMainFormBtn);
			this->Controls->Add(this->actorsBtn);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(844, 425);
			this->MinimumSize = System::Drawing::Size(844, 425);
			this->Name = L"MainForm";
			this->Text = L"Manager";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}

#pragma endregion

	private:

		//MainForm currentStats vraca trenutni ukupan broj filmova i najpopularnijeg glumca, metoda getCurrentStats() na repository
		System::Void currentStatsBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			std::vector<std::string> koneksnString = getCurrentConnectionString();
			ConnectionString* con = new ConnectionString(koneksnString[0], koneksnString[1], koneksnString[2], koneksnString[3]);
			Repository* repo = new Repository(*con);

			CurrentStatistics stats = repo->getCurrentStats();

			totalCountTxtBox->Text = stats.brojFilmova.ToString();
			mostPopActorTxtBox->Text = gcnew String(stats.name.c_str()); //c_str konvertuje standardni string u System::String, vraca niz karaktera
		}

		//Forme film, actor, category
		System::Void filmMainFormBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			FilmMainForm filmForm;
			filmForm.ShowDialog();
			this->Show();
		}

		System::Void actorsBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			ActorMainForm actorForm;
			actorForm.ShowDialog();
			this->Show();
		}

		System::Void categoryMainFormBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			CategoryMainForm categoryForm;
			categoryForm.ShowDialog();
			this->Show();
		}
	private: System::Void connectionPropertiesBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ConnectionProperties conProp;
		conProp.ShowDialog();
		this->Show();
	}

			 //create vector from file input and pass elements to create ConnectionString object then initialize repo
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