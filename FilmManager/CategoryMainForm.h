#pragma once
#include <msclr\marshal_cppstd.h>
#include <vector>
#include <iostream>
#include <fstream>
#include "../FilmManager/Headers/Model Headers/Category.h"
#include "../FilmManager/Headers/Database Headers/Repository.h"

namespace FilmManager {
	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CategoryMainForm
	/// </summary>
	public ref class CategoryMainForm : public System::Windows::Forms::Form
	{
	public:

		CategoryMainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	private:

		System::Windows::Forms::Label^ descriptionLbl;
		System::Windows::Forms::Button^ clearDataGridBtn;
		System::Windows::Forms::Button^ movies_categoryBtn;
		System::Windows::Forms::Button^ listAllCategoryBtn;
		System::Windows::Forms::Button^ exportToTxt;
		System::Windows::Forms::DataGridView^ mov_categoryDataGrid;
		System::Windows::Forms::DataGridView^ categoryDataGrid;
		System::Windows::Forms::DataGridViewRow^ row;

	public:
		//declare a vector  put * to keep native class member in CLR class. This is not allowed directly as well, but you can keep pointer to native class as a member

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CategoryMainForm()
		{
			if (components)
			{
				delete components;
			}
		}

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CategoryMainForm::typeid));
			this->listAllCategoryBtn = (gcnew System::Windows::Forms::Button());
			this->categoryDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->movies_categoryBtn = (gcnew System::Windows::Forms::Button());
			this->clearDataGridBtn = (gcnew System::Windows::Forms::Button());
			this->descriptionLbl = (gcnew System::Windows::Forms::Label());
			this->exportToTxt = (gcnew System::Windows::Forms::Button());
			this->mov_categoryDataGrid = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->categoryDataGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mov_categoryDataGrid))->BeginInit();
			this->SuspendLayout();
			//
			// listAllCategoryBtn
			//
			this->listAllCategoryBtn->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->listAllCategoryBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->listAllCategoryBtn->Font = (gcnew System::Drawing::Font(L"Segoe Print", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listAllCategoryBtn->Location = System::Drawing::Point(12, 26);
			this->listAllCategoryBtn->Name = L"listAllCategoryBtn";
			this->listAllCategoryBtn->Size = System::Drawing::Size(122, 30);
			this->listAllCategoryBtn->TabIndex = 3;
			this->listAllCategoryBtn->Text = L"List all categories";
			this->listAllCategoryBtn->UseVisualStyleBackColor = false;
			this->listAllCategoryBtn->Click += gcnew System::EventHandler(this, &CategoryMainForm::listAllCategoryBtn_Click);
			//
			// categoryDataGrid
			//
			this->categoryDataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->categoryDataGrid->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->categoryDataGrid->Location = System::Drawing::Point(12, 82);
			this->categoryDataGrid->Name = L"categoryDataGrid";
			this->categoryDataGrid->ReadOnly = true;
			this->categoryDataGrid->Size = System::Drawing::Size(254, 207);
			this->categoryDataGrid->TabIndex = 6;
			//
			// movies_categoryBtn
			//
			this->movies_categoryBtn->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->movies_categoryBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->movies_categoryBtn->Font = (gcnew System::Drawing::Font(L"Segoe Print", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->movies_categoryBtn->Location = System::Drawing::Point(309, 26);
			this->movies_categoryBtn->Name = L"movies_categoryBtn";
			this->movies_categoryBtn->Size = System::Drawing::Size(126, 30);
			this->movies_categoryBtn->TabIndex = 12;
			this->movies_categoryBtn->Text = L"Get Movies";
			this->movies_categoryBtn->UseVisualStyleBackColor = false;
			this->movies_categoryBtn->Click += gcnew System::EventHandler(this, &CategoryMainForm::movies_categoryBtn_Click);
			//
			// clearDataGridBtn
			//
			this->clearDataGridBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->clearDataGridBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->clearDataGridBtn->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clearDataGridBtn->Location = System::Drawing::Point(488, 307);
			this->clearDataGridBtn->Name = L"clearDataGridBtn";
			this->clearDataGridBtn->Size = System::Drawing::Size(75, 34);
			this->clearDataGridBtn->TabIndex = 14;
			this->clearDataGridBtn->Text = L"Clear";
			this->clearDataGridBtn->UseVisualStyleBackColor = false;
			this->clearDataGridBtn->Click += gcnew System::EventHandler(this, &CategoryMainForm::clearDataGridBtn_Click);
			//
			// descriptionLbl
			//
			this->descriptionLbl->AutoSize = true;
			this->descriptionLbl->BackColor = System::Drawing::SystemColors::Info;
			this->descriptionLbl->Location = System::Drawing::Point(9, 371);
			this->descriptionLbl->Name = L"descriptionLbl";
			this->descriptionLbl->Size = System::Drawing::Size(325, 39);
			this->descriptionLbl->TabIndex = 15;
			this->descriptionLbl->Text = L"* To list movies associated to particular category, mark the category\r\nand click "
				L"getMovies button.\r\n* To clear text box and select another list of movies click C"
				L"LEAR";
			//
			// exportToTxt
			//
			this->exportToTxt->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->exportToTxt->Cursor = System::Windows::Forms::Cursors::Hand;
			this->exportToTxt->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exportToTxt->Location = System::Drawing::Point(12, 307);
			this->exportToTxt->Name = L"exportToTxt";
			this->exportToTxt->Size = System::Drawing::Size(75, 34);
			this->exportToTxt->TabIndex = 16;
			this->exportToTxt->Text = L"Export";
			this->exportToTxt->UseVisualStyleBackColor = false;
			this->exportToTxt->Click += gcnew System::EventHandler(this, &CategoryMainForm::exportToTxt_Click);
			//
			// mov_categoryDataGrid
			//
			this->mov_categoryDataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->mov_categoryDataGrid->Location = System::Drawing::Point(309, 82);
			this->mov_categoryDataGrid->Name = L"mov_categoryDataGrid";
			this->mov_categoryDataGrid->Size = System::Drawing::Size(254, 207);
			this->mov_categoryDataGrid->TabIndex = 17;
			//
			// CategoryMainForm
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(577, 431);
			this->Controls->Add(this->mov_categoryDataGrid);
			this->Controls->Add(this->exportToTxt);
			this->Controls->Add(this->descriptionLbl);
			this->Controls->Add(this->clearDataGridBtn);
			this->Controls->Add(this->movies_categoryBtn);
			this->Controls->Add(this->categoryDataGrid);
			this->Controls->Add(this->listAllCategoryBtn);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(593, 470);
			this->MinimumSize = System::Drawing::Size(587, 470);
			this->Name = L"CategoryMainForm";
			this->Text = L"Manager";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->categoryDataGrid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mov_categoryDataGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private:

		System::Void listAllCategoryBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			clearDataGrid();

			//Ovdje uzimamo trenutni connectionString, citamo iz fajla, metoda getCurrentConnectionString vraca vektor stringova.
			std::vector<std::string> koneksnString = getCurrentConnectionString();
			ConnectionString* con = new ConnectionString(koneksnString[0], koneksnString[1], koneksnString[2], koneksnString[3]);
			Repository* repo = new Repository(*con);

			std::vector<Category> catVector = repo->getAllCategories();

			categoryDataGrid->Columns->Add(gcnew System::String("name"), gcnew System::String("Genre"));
			categoryDataGrid->Columns->Add(gcnew System::String("category_id"), gcnew System::String("ID"));
			categoryDataGrid->Columns->Add(gcnew System::String("film_id"), gcnew System::String("Film_ID"));

			categoryDataGrid->Columns[0]->Width = 195;

			categoryDataGrid->Columns[1]->Visible = false;
			categoryDataGrid->Columns[2]->Visible = false;

			for (int i = 0; i < catVector.size(); i++) {
				String^ genre = gcnew String(catVector[i].name.c_str());
				String^ film_id = catVector[i].film_id.ToString();
				String^ id = catVector[i].id.ToString();

				categoryDataGrid->Rows->Add(genre, id, film_id);
			}
		}

		System::Void movies_categoryBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			//Uzimamo trenutni row, to string i proslijedimo repo metodi kao parametar id kao filter u nasem upitu
			row = categoryDataGrid->CurrentCell->OwningRow;
			String^ currentRow = row->Cells[1]->Value->ToString();

			//S obzirom da je klasa unmanaged metoda uzima std::string te ovdje konvertujemo nas System::String u njega
			std::string unmanagedID = msclr::interop::marshal_as<std::string>(currentRow);

			std::vector<std::string> koneksnString = getCurrentConnectionString();
			ConnectionString* con = new ConnectionString(koneksnString[0], koneksnString[1], koneksnString[2], koneksnString[3]);
			Repository* repo = new Repository(*con);

			std::vector<Film> filmVector = repo->getAllFilms_Category(unmanagedID);

			mov_categoryDataGrid->Columns->Add(gcnew System::String("title"), gcnew System::String("Movies"));
			mov_categoryDataGrid->Columns[0]->Width = 195;

			for (int i = 0; i < filmVector.size(); i++) {
				String^ name = gcnew String(filmVector[i].title.c_str());

				mov_categoryDataGrid->Rows->Add(name);
			}
		}

		void clearDataGrid() {
			mov_categoryDataGrid->Rows->Clear();
			mov_categoryDataGrid->Columns->Clear();
		}

		System::Void clearDataGridBtn_Click(System::Object^ sender, System::EventArgs^ e) {
			clearDataGrid();
		}

		System::Void exportToTxt_Click(System::Object^ sender, System::EventArgs^ e) {
			std::vector<std::string> koneksnString = getCurrentConnectionString();
			ConnectionString* con = new ConnectionString(koneksnString[0], koneksnString[1], koneksnString[2], koneksnString[3]);
			Repository* repo = new Repository(*con);

			std::vector<Category> categoryVector = repo->getAllCategories();

			std::vector<Category>::iterator it;

			std::ofstream myFile;
			myFile.open("categoryOutput.txt");

			for (it = categoryVector.begin(); it != categoryVector.end(); ++it)

			{
				myFile << it->name << " " << "\n";
			}

			MessageBox::Show("File 'categoryOutput.txt' saved to the root folder of the project.");
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
	};
}