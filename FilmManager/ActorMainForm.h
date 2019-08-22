#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "../FilmManager/Headers/Model Headers/Actor.h"
#include <msclr\marshal_cppstd.h>
#include "InsertActorForm2.h"
#include "../FilmManager/Headers/Database Headers/Repository.h"

namespace FilmManager {
	/// <summary>
	/// Summary for ActorMainForm
	/// </summary>

	public ref class ActorMainForm : public System::Windows::Forms::Form
	{
	public:

		ActorMainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	private:

		System::Windows::Forms::DataGridView^ mov_actorDataGrid;
		System::Windows::Forms::DataGridView^ actorsDataGrid;
		System::Windows::Forms::Button^ movies_actorBtn;
		System::Windows::Forms::Button^ clearListboxBtn;
		System::Windows::Forms::Button^ exportBtn;
		System::Windows::Forms::Button^ listAllActorsBtn;
		System::Windows::Forms::Label^ descriptionLbl;
		System::Windows::Forms::DataGridViewRow^ row = gcnew DataGridViewRow();
	private: System::Windows::Forms::Label^ label1;

			 /// <summary>
			 /// Required designer variable.
			 /// </summary>
			 System::ComponentModel::Container^ components;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ActorMainForm()
		{
			if (components)
			{
				delete components;
			}
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ActorMainForm::typeid));
			this->listAllActorsBtn = (gcnew System::Windows::Forms::Button());
			this->actorsDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->descriptionLbl = (gcnew System::Windows::Forms::Label());
			this->movies_actorBtn = (gcnew System::Windows::Forms::Button());
			this->clearListboxBtn = (gcnew System::Windows::Forms::Button());
			this->exportBtn = (gcnew System::Windows::Forms::Button());
			this->mov_actorDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->actorsDataGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mov_actorDataGrid))->BeginInit();
			this->SuspendLayout();
			//
			// listAllActorsBtn
			//
			this->listAllActorsBtn->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->listAllActorsBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->listAllActorsBtn->Font = (gcnew System::Drawing::Font(L"Segoe Print", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listAllActorsBtn->Location = System::Drawing::Point(12, 24);
			this->listAllActorsBtn->Name = L"listAllActorsBtn";
			this->listAllActorsBtn->Size = System::Drawing::Size(121, 30);
			this->listAllActorsBtn->TabIndex = 2;
			this->listAllActorsBtn->Text = L"List all actors";
			this->listAllActorsBtn->UseVisualStyleBackColor = false;
			this->listAllActorsBtn->Click += gcnew System::EventHandler(this, &ActorMainForm::listAllActorsBtn_Click);
			//
			// actorsDataGrid
			//
			this->actorsDataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->actorsDataGrid->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->actorsDataGrid->Location = System::Drawing::Point(12, 77);
			this->actorsDataGrid->Name = L"actorsDataGrid";
			this->actorsDataGrid->ReadOnly = true;
			this->actorsDataGrid->Size = System::Drawing::Size(254, 207);
			this->actorsDataGrid->TabIndex = 5;
			//
			// descriptionLbl
			//
			this->descriptionLbl->AutoSize = true;
			this->descriptionLbl->BackColor = System::Drawing::SystemColors::Info;
			this->descriptionLbl->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->descriptionLbl->Location = System::Drawing::Point(22, 347);
			this->descriptionLbl->Name = L"descriptionLbl";
			this->descriptionLbl->Size = System::Drawing::Size(0, 13);
			this->descriptionLbl->TabIndex = 6;
			//
			// movies_actorBtn
			//
			this->movies_actorBtn->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->movies_actorBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->movies_actorBtn->Font = (gcnew System::Drawing::Font(L"Segoe Print", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->movies_actorBtn->Location = System::Drawing::Point(315, 24);
			this->movies_actorBtn->Name = L"movies_actorBtn";
			this->movies_actorBtn->Size = System::Drawing::Size(146, 30);
			this->movies_actorBtn->TabIndex = 11;
			this->movies_actorBtn->Text = L"Get Movies";
			this->movies_actorBtn->UseVisualStyleBackColor = false;
			this->movies_actorBtn->Click += gcnew System::EventHandler(this, &ActorMainForm::movies_actorBtn_Click);
			//
			// clearListboxBtn
			//
			this->clearListboxBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->clearListboxBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->clearListboxBtn->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clearListboxBtn->Location = System::Drawing::Point(480, 299);
			this->clearListboxBtn->Name = L"clearListboxBtn";
			this->clearListboxBtn->Size = System::Drawing::Size(75, 34);
			this->clearListboxBtn->TabIndex = 13;
			this->clearListboxBtn->Text = L"Clear";
			this->clearListboxBtn->UseVisualStyleBackColor = false;
			this->clearListboxBtn->Click += gcnew System::EventHandler(this, &ActorMainForm::clearListboxBtn_Click);
			//
			// exportBtn
			//
			this->exportBtn->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->exportBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->exportBtn->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exportBtn->Location = System::Drawing::Point(12, 300);
			this->exportBtn->Name = L"exportBtn";
			this->exportBtn->Size = System::Drawing::Size(66, 34);
			this->exportBtn->TabIndex = 14;
			this->exportBtn->Text = L"Export...";
			this->exportBtn->UseVisualStyleBackColor = false;
			this->exportBtn->Click += gcnew System::EventHandler(this, &ActorMainForm::exportBtn_Click);
			//
			// mov_actorDataGrid
			//
			this->mov_actorDataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->mov_actorDataGrid->Location = System::Drawing::Point(315, 77);
			this->mov_actorDataGrid->Name = L"mov_actorDataGrid";
			this->mov_actorDataGrid->Size = System::Drawing::Size(240, 207);
			this->mov_actorDataGrid->TabIndex = 15;
			//
			// label1
			//
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::Info;
			this->label1->Location = System::Drawing::Point(12, 360);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(366, 52);
			this->label1->TabIndex = 16;
			this->label1->Text = resources->GetString(L"label1.Text");
			//
			// ActorMainForm
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(571, 431);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->mov_actorDataGrid);
			this->Controls->Add(this->exportBtn);
			this->Controls->Add(this->clearListboxBtn);
			this->Controls->Add(this->movies_actorBtn);
			this->Controls->Add(this->descriptionLbl);
			this->Controls->Add(this->actorsDataGrid);
			this->Controls->Add(this->listAllActorsBtn);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(647, 472);
			this->MinimumSize = System::Drawing::Size(500, 250);
			this->Name = L"ActorMainForm";
			this->Text = L"Manager";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->actorsDataGrid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mov_actorDataGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private:

		System::Void listAllActorsBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			clearDataGrid();

			std::vector<std::string> koneksnString = getCurrentConnectionString();
			ConnectionString* con = new ConnectionString(koneksnString[0], koneksnString[1], koneksnString[2], koneksnString[3]);
			Repository* repo = new Repository(*con);

			std::vector<Actor> allActorsVector = repo->getAllActors();

			//create datagrid columns, first parameter of Add method is col name, second is header text
			actorsDataGrid->Columns->Add(gcnew System::String("idname"), gcnew System::String("ID"));
			actorsDataGrid->Columns->Add(gcnew System::String("fname"), gcnew System::String("First name"));
			actorsDataGrid->Columns->Add(gcnew System::String("lname"), gcnew System::String("Last name"));

			actorsDataGrid->Columns[0]->Visible = false;

			for (int i = 0; i < allActorsVector.size(); i++) {
				String^ name = gcnew String(allActorsVector[i].name.c_str());
				String^ lastName = gcnew String(allActorsVector[i].lastName.c_str());
				String^ id = allActorsVector[i].id.ToString();

				actorsDataGrid->Rows->Add(id, name, lastName);
			}
		}

		System::Void movies_actorBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			//Uzimamo trenutni row, to string i proslijedimo repo metodi kao parametar id kao filter u nasem upitu
			row = actorsDataGrid->CurrentCell->OwningRow;
			String^ currentRow = row->Cells[0]->Value->ToString();

			//S obzirom da je klasa unmanaged metoda uzima std::string te ovdje konvertujemo nas System::String u njega
			std::string unmanagedID = msclr::interop::marshal_as<std::string>(currentRow);

			std::vector<std::string> koneksnString = getCurrentConnectionString();
			ConnectionString* con = new ConnectionString(koneksnString[0], koneksnString[1], koneksnString[2], koneksnString[3]);
			Repository* repo = new Repository(*con);

			std::vector<Film> allActors_Films = repo->getAllFilms_Actor(unmanagedID);

			//Kreiramo dataGrid kolonu i podesavamo joj width
			mov_actorDataGrid->Columns->Add(gcnew System::String("title"), gcnew System::String("Movies"));
			mov_actorDataGrid->Columns[0]->Width = 180;

			for (int i = 0; i < allActors_Films.size(); i++) {
				String^ name = gcnew String(allActors_Films[i].title.c_str());

				mov_actorDataGrid->Rows->Add(name);
			}
		}

		//Iterira kroz vektor i ispisuje u actorsOutput.txt
		System::Void exportBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			std::vector<std::string> koneksnString = getCurrentConnectionString();
			ConnectionString* con = new ConnectionString(koneksnString[0], koneksnString[1], koneksnString[2], koneksnString[3]);
			Repository* repo = new Repository(*con);

			std::vector<Actor> actVector = repo->getAllActors();

			std::vector<Actor>::iterator it;

			std::ofstream myFile;
			myFile.open("actorsOutput.txt");

			for (it = actVector.begin(); it != actVector.end(); ++it)

			{
				myFile << it->name << " " << it->lastName << "\n";
			}

			MessageBox::Show("File 'actorsOutput.txt' saved to the root folder of the project.");
			myFile.close();
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

		void clearDataGrid() {
			mov_actorDataGrid->Rows->Clear();
			mov_actorDataGrid->Columns->Clear();
		}

		System::Void clearListboxBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			clearDataGrid();
		}

		System::Void deleteBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			row = actorsDataGrid->CurrentCell->OwningRow;
			String^ currentRow = row->Cells[0]->Value->ToString();
		}

		System::Void insertActorBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			InsertActorForm insertForm;
			insertForm.ShowDialog();
			this->Show();
		}
	};
}