#pragma once
#include "../FilmManager/Headers/Model Headers/Film.h"
#include <fstream>
#include <algorithm>
#include <functional>
#include <array>
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include "InsertMovieForm.h"
#include "UpdateMovieForm.h"
#include "../FilmManager/Headers/Database Headers/Repository.h"
#include <string>
#include <sstream>
#include "../FilmManager/Headers/Database Headers/ConnectionString.h"

namespace FilmManager {
	/// <summary>
	/// Summary for FilmMainForm
	/// </summary>

	public ref class FilmMainForm : public System::Windows::Forms::Form
	{
	public:

		FilmMainForm(void)
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
		~FilmMainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

		System::Windows::Forms::DataGridView^ filmDataGrid;
		System::Windows::Forms::Label^ infoLabel;
		System::Windows::Forms::Button^ exportBtn;
		System::Windows::Forms::Button^ insertFormBtn;
		System::Windows::Forms::Button^ updateFormBtn;
		System::Windows::Forms::Button^ deleteMovieBtn;
		System::Windows::Forms::Button^ listAllBtn;
		System::Windows::Forms::Splitter^ splitter1;
		System::Data::DataTable^ filmsTable;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FilmMainForm::typeid));
			this->filmDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->listAllBtn = (gcnew System::Windows::Forms::Button());
			this->infoLabel = (gcnew System::Windows::Forms::Label());
			this->splitter1 = (gcnew System::Windows::Forms::Splitter());
			this->insertFormBtn = (gcnew System::Windows::Forms::Button());
			this->updateFormBtn = (gcnew System::Windows::Forms::Button());
			this->deleteMovieBtn = (gcnew System::Windows::Forms::Button());
			this->exportBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->filmDataGrid))->BeginInit();
			this->SuspendLayout();
			//
			// filmDataGrid
			//
			this->filmDataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->filmDataGrid->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->filmDataGrid->Location = System::Drawing::Point(12, 74);
			this->filmDataGrid->Name = L"filmDataGrid";
			this->filmDataGrid->ReadOnly = true;
			this->filmDataGrid->Size = System::Drawing::Size(621, 215);
			this->filmDataGrid->TabIndex = 0;
			//
			// listAllBtn
			//
			this->listAllBtn->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->listAllBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->listAllBtn->Font = (gcnew System::Drawing::Font(L"Segoe Print", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listAllBtn->Location = System::Drawing::Point(12, 22);
			this->listAllBtn->Name = L"listAllBtn";
			this->listAllBtn->Size = System::Drawing::Size(145, 30);
			this->listAllBtn->TabIndex = 1;
			this->listAllBtn->Text = L"List all movies";
			this->listAllBtn->UseVisualStyleBackColor = false;
			this->listAllBtn->Click += gcnew System::EventHandler(this, &FilmMainForm::listAllBtn_Click);
			//
			// infoLabel
			//
			this->infoLabel->AutoSize = true;
			this->infoLabel->BackColor = System::Drawing::SystemColors::Info;
			this->infoLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->infoLabel->Location = System::Drawing::Point(12, 333);
			this->infoLabel->Name = L"infoLabel";
			this->infoLabel->Size = System::Drawing::Size(343, 52);
			this->infoLabel->TabIndex = 2;
			this->infoLabel->Text = L"* Delete by choosing a desired movie and clicking DELETE button.\r\n\r\n* Export data"
				L" from vector to .txt in root folder by clicking EXPORT \r\nbutton.";
			//
			// splitter1
			//
			this->splitter1->Location = System::Drawing::Point(0, 0);
			this->splitter1->Name = L"splitter1";
			this->splitter1->Size = System::Drawing::Size(3, 433);
			this->splitter1->TabIndex = 3;
			this->splitter1->TabStop = false;
			//
			// insertFormBtn
			//
			this->insertFormBtn->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->insertFormBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->insertFormBtn->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->insertFormBtn->Location = System::Drawing::Point(398, 385);
			this->insertFormBtn->Name = L"insertFormBtn";
			this->insertFormBtn->Size = System::Drawing::Size(75, 32);
			this->insertFormBtn->TabIndex = 4;
			this->insertFormBtn->Text = L"Add";
			this->insertFormBtn->UseVisualStyleBackColor = false;
			this->insertFormBtn->Click += gcnew System::EventHandler(this, &FilmMainForm::insertFormBtn_Click);
			//
			// updateFormBtn
			//
			this->updateFormBtn->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->updateFormBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->updateFormBtn->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->updateFormBtn->Location = System::Drawing::Point(480, 385);
			this->updateFormBtn->Name = L"updateFormBtn";
			this->updateFormBtn->Size = System::Drawing::Size(75, 32);
			this->updateFormBtn->TabIndex = 5;
			this->updateFormBtn->Text = L"Edit";
			this->updateFormBtn->UseVisualStyleBackColor = false;
			this->updateFormBtn->Click += gcnew System::EventHandler(this, &FilmMainForm::updateFormBtn_Click);
			//
			// deleteMovieBtn
			//
			this->deleteMovieBtn->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->deleteMovieBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->deleteMovieBtn->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->deleteMovieBtn->Location = System::Drawing::Point(561, 385);
			this->deleteMovieBtn->Name = L"deleteMovieBtn";
			this->deleteMovieBtn->Size = System::Drawing::Size(75, 32);
			this->deleteMovieBtn->TabIndex = 6;
			this->deleteMovieBtn->Text = L"Remove";
			this->deleteMovieBtn->UseVisualStyleBackColor = false;
			this->deleteMovieBtn->Click += gcnew System::EventHandler(this, &FilmMainForm::deleteMovieBtn_Click);
			//
			// exportBtn
			//
			this->exportBtn->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->exportBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->exportBtn->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exportBtn->Location = System::Drawing::Point(558, 310);
			this->exportBtn->Name = L"exportBtn";
			this->exportBtn->Size = System::Drawing::Size(75, 35);
			this->exportBtn->TabIndex = 7;
			this->exportBtn->Text = L"Export...";
			this->exportBtn->UseVisualStyleBackColor = false;
			this->exportBtn->Click += gcnew System::EventHandler(this, &FilmMainForm::exportBtn_Click);
			//
			// FilmMainForm
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(645, 433);
			this->Controls->Add(this->exportBtn);
			this->Controls->Add(this->deleteMovieBtn);
			this->Controls->Add(this->updateFormBtn);
			this->Controls->Add(this->insertFormBtn);
			this->Controls->Add(this->splitter1);
			this->Controls->Add(this->infoLabel);
			this->Controls->Add(this->listAllBtn);
			this->Controls->Add(this->filmDataGrid);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(661, 472);
			this->MinimumSize = System::Drawing::Size(661, 472);
			this->Name = L"FilmMainForm";
			this->Text = L"Manager";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->filmDataGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private:

		System::Void listAllBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			//Ocisti grid prije dodavanja da ne bi duplirao elemente kad se vise puta klikne na button.
			clearDataGrid();

			//Ovdje uzimamo trenutni connectionString, citamo iz fajla, metoda getCurrentConnectionString vraca vektor stringova.
			std::vector<std::string> koneksnString = getCurrentConnectionString();
			ConnectionString* con = new ConnectionString(koneksnString[0], koneksnString[1], koneksnString[2], koneksnString[3]);
			Repository* repo = new Repository(*con);
			std::vector<Film> allFilmsVector = repo->getAllFilms();

			//Overload operatora < da sortira filmove po nazivu kad dodajemo nove.
			std::sort(allFilmsVector.begin(), allFilmsVector.end());

			filmDataGrid->Columns->Add(gcnew System::String("id"), gcnew System::String("ID"));
			filmDataGrid->Columns->Add(gcnew System::String("Title"), gcnew System::String("Title"));
			filmDataGrid->Columns->Add(gcnew System::String("Year"), gcnew System::String("Year"));
			filmDataGrid->Columns->Add(gcnew System::String("Length"), gcnew System::String("Length"));
			filmDataGrid->Columns->Add(gcnew System::String("Description"), gcnew System::String("Description"));

			filmDataGrid->Columns[0]->Visible = false;

			setDataGridSize();

			for (int i = 0; i < allFilmsVector.size(); i++) {
				String^ id = allFilmsVector[i].id.ToString();
				String^ title = gcnew String(allFilmsVector[i].title.c_str());
				String^ relYear = gcnew String(allFilmsVector[i].releaseYear.c_str());
				String^ length = gcnew String(allFilmsVector[i].length.c_str());
				String^ description = gcnew String(allFilmsVector[i].description.c_str());

				filmDataGrid->Rows->Add(id, title, relYear, length, description);
			}
		}

		System::Void deleteMovieBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			//Get id of the selected(current) movie.
			DataGridViewRow^ row = gcnew DataGridViewRow();
			row = filmDataGrid->CurrentCell->OwningRow;
			String^ currentRow = row->Cells[0]->Value->ToString();

			//Konvertuj u std::string jer je standard string parametar metode deleteFilm();
			std::string unmanagedCurrentRow = msclr::interop::marshal_as<std::string>(currentRow);

			//Ovdje uzimamo trenutni connectionString, citamo iz fajla, metoda getCurrentConnectionString vraca vektor stringova.
			std::vector<std::string> koneksnString = getCurrentConnectionString();
			ConnectionString* con = new ConnectionString(koneksnString[0], koneksnString[1], koneksnString[2], koneksnString[3]);
			Repository* repo = new Repository(*con);

			repo->deleteFilm(unmanagedCurrentRow);

			MessageBox::Show("Row deleted");

			clearDataGrid();
			ReloadDataGrid();
		}

		System::Void exportBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			std::ofstream myFile;
			myFile.open("filmsOutput.txt");

			//Ovdje uzimamo trenutni connectionString, citamo iz fajla, metoda getCurrentConnectionString vraca vektor stringova.
			std::vector<std::string> koneksnString = getCurrentConnectionString();
			ConnectionString* con = new ConnectionString(koneksnString[0], koneksnString[1], koneksnString[2], koneksnString[3]);
			Repository* repo = new Repository(*con);

			std::vector<Film> allFilmsVector = repo->getAllFilms();

			for (int i = 0; i < allFilmsVector.size(); i++) {
				myFile << allFilmsVector[i].title << " " << allFilmsVector[i].releaseYear << " " << allFilmsVector[i].length << " " << allFilmsVector[i].description << "\n";
			}

			MessageBox::Show("File 'filmOutput.txt' saved to the root folder of the project.");
			myFile.close();
		}

		//Clear and reload
		void clearDataGrid() {
			filmDataGrid->Rows->Clear();
			filmDataGrid->Columns->Clear();
		}

		//Reload, na pocetku clearDataGrid() da reload ne bi popunio grid dodavajuci na postojece podatka
		void ReloadDataGrid() {
			clearDataGrid();

			std::vector<std::string> koneksnString = getCurrentConnectionString();
			ConnectionString* con = new ConnectionString(koneksnString[0], koneksnString[1], koneksnString[2], koneksnString[3]);
			Repository* repo = new Repository(*con);

			std::vector<Film> allFilmsVector = repo->getAllFilms();

			filmDataGrid->Columns->Add(gcnew System::String("id"), gcnew System::String("ID"));
			filmDataGrid->Columns->Add(gcnew System::String("Title"), gcnew System::String("Title"));
			filmDataGrid->Columns->Add(gcnew System::String("Release year"), gcnew System::String("Release year"));
			filmDataGrid->Columns->Add(gcnew System::String("Length"), gcnew System::String("Length"));
			filmDataGrid->Columns->Add(gcnew System::String("Description"), gcnew System::String("Description"));

			filmDataGrid->Columns[0]->Visible = false;
			setDataGridSize();

			std::sort(allFilmsVector.begin(), allFilmsVector.end());

			for (int i = 0; i < allFilmsVector.size(); i++) {
				String^ id = allFilmsVector[i].id.ToString();
				String^ title = gcnew String(allFilmsVector[i].title.c_str());
				String^ relYear = gcnew String(allFilmsVector[i].releaseYear.c_str());
				String^ length = gcnew String(allFilmsVector[i].length.c_str());
				String^ description = gcnew String(allFilmsVector[i].description.c_str());

				filmDataGrid->Rows->Add(id, title, relYear, length, description);
			}
		}

		void setDataGridSize() {
			filmDataGrid->Columns[1]->Width = 190;
			filmDataGrid->Columns[2]->Width = 60;
			filmDataGrid->Columns[3]->Width = 60;
			filmDataGrid->Columns[4]->Width = 251;
		}

		//Update forma ima jedan parametar konstruktora, id, id se uzima iz trenutne kolone koju selektujemo i prosljedjuje u konstruktor,
		//sada u konstruktoru UpdateMovieForm koristimo taj id u metodi koja vrsi update filma
		System::Void updateFormBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			DataGridViewRow^ row = gcnew DataGridViewRow();
			row = filmDataGrid->CurrentCell->OwningRow;
			String^ currentRow = row->Cells[0]->Value->ToString();
			int id = int::Parse(currentRow);

			UpdateMovieForm updateForm(id);

			updateForm.ShowDialog();
			ReloadDataGrid();
		}

		System::Void insertFormBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			InsertMovieForm insertForm;
			insertForm.ShowDialog();
			ReloadDataGrid();
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