#pragma once
#include <fstream>
#include <msclr\marshal_cppstd.h>

namespace FilmManager {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ConnectionProperties
	/// </summary>
	public ref class ConnectionProperties : public System::Windows::Forms::Form
	{
	public:
		ConnectionProperties(void)
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
		~ConnectionProperties()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ serverNameLbl;
	private: System::Windows::Forms::Label^ usernameLbl;
	private: System::Windows::Forms::Label^ passLbl;
	private: System::Windows::Forms::Button^ exportConStringBtn;
	private: System::Windows::Forms::TextBox^ serverTxtBox;
	private: System::Windows::Forms::TextBox^ usernameTxtBox;
	private: System::Windows::Forms::TextBox^ passwordTxtBox;
	private: System::Windows::Forms::Label^ portLbl;
	private: System::Windows::Forms::TextBox^ portTxtBox;

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ConnectionProperties::typeid));
			this->serverNameLbl = (gcnew System::Windows::Forms::Label());
			this->usernameLbl = (gcnew System::Windows::Forms::Label());
			this->passLbl = (gcnew System::Windows::Forms::Label());
			this->exportConStringBtn = (gcnew System::Windows::Forms::Button());
			this->serverTxtBox = (gcnew System::Windows::Forms::TextBox());
			this->usernameTxtBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordTxtBox = (gcnew System::Windows::Forms::TextBox());
			this->portLbl = (gcnew System::Windows::Forms::Label());
			this->portTxtBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			//
			// serverNameLbl
			//
			this->serverNameLbl->AutoSize = true;
			this->serverNameLbl->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->serverNameLbl->Location = System::Drawing::Point(13, 24);
			this->serverNameLbl->Name = L"serverNameLbl";
			this->serverNameLbl->Size = System::Drawing::Size(47, 19);
			this->serverNameLbl->TabIndex = 0;
			this->serverNameLbl->Text = L"server:";
			//
			// usernameLbl
			//
			this->usernameLbl->AutoSize = true;
			this->usernameLbl->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usernameLbl->Location = System::Drawing::Point(13, 54);
			this->usernameLbl->Name = L"usernameLbl";
			this->usernameLbl->Size = System::Drawing::Size(66, 19);
			this->usernameLbl->TabIndex = 1;
			this->usernameLbl->Text = L"username:";
			//
			// passLbl
			//
			this->passLbl->AutoSize = true;
			this->passLbl->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passLbl->Location = System::Drawing::Point(203, 55);
			this->passLbl->Name = L"passLbl";
			this->passLbl->Size = System::Drawing::Size(64, 19);
			this->passLbl->TabIndex = 2;
			this->passLbl->Text = L"password:";
			this->passLbl->Click += gcnew System::EventHandler(this, &ConnectionProperties::label1_Click);
			//
			// exportConStringBtn
			//
			this->exportConStringBtn->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->exportConStringBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->exportConStringBtn->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exportConStringBtn->Location = System::Drawing::Point(298, 99);
			this->exportConStringBtn->Name = L"exportConStringBtn";
			this->exportConStringBtn->Size = System::Drawing::Size(75, 30);
			this->exportConStringBtn->TabIndex = 3;
			this->exportConStringBtn->Text = L"Save";
			this->exportConStringBtn->UseVisualStyleBackColor = false;
			this->exportConStringBtn->Click += gcnew System::EventHandler(this, &ConnectionProperties::exportConStringBtn_Click);
			//
			// serverTxtBox
			//
			this->serverTxtBox->Location = System::Drawing::Point(81, 24);
			this->serverTxtBox->Name = L"serverTxtBox";
			this->serverTxtBox->Size = System::Drawing::Size(100, 20);
			this->serverTxtBox->TabIndex = 4;
			//
			// usernameTxtBox
			//
			this->usernameTxtBox->Location = System::Drawing::Point(81, 54);
			this->usernameTxtBox->Name = L"usernameTxtBox";
			this->usernameTxtBox->Size = System::Drawing::Size(100, 20);
			this->usernameTxtBox->TabIndex = 5;
			//
			// passwordTxtBox
			//
			this->passwordTxtBox->Location = System::Drawing::Point(273, 55);
			this->passwordTxtBox->Name = L"passwordTxtBox";
			this->passwordTxtBox->Size = System::Drawing::Size(100, 20);
			this->passwordTxtBox->TabIndex = 6;
			//
			// portLbl
			//
			this->portLbl->AutoSize = true;
			this->portLbl->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->portLbl->Location = System::Drawing::Point(203, 25);
			this->portLbl->Name = L"portLbl";
			this->portLbl->Size = System::Drawing::Size(36, 19);
			this->portLbl->TabIndex = 7;
			this->portLbl->Text = L"port:";
			//
			// portTxtBox
			//
			this->portTxtBox->Location = System::Drawing::Point(273, 25);
			this->portTxtBox->Name = L"portTxtBox";
			this->portTxtBox->Size = System::Drawing::Size(100, 20);
			this->portTxtBox->TabIndex = 8;
			//
			// ConnectionProperties
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(398, 141);
			this->Controls->Add(this->portTxtBox);
			this->Controls->Add(this->portLbl);
			this->Controls->Add(this->passwordTxtBox);
			this->Controls->Add(this->usernameTxtBox);
			this->Controls->Add(this->serverTxtBox);
			this->Controls->Add(this->exportConStringBtn);
			this->Controls->Add(this->passLbl);
			this->Controls->Add(this->usernameLbl);
			this->Controls->Add(this->serverNameLbl);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(414, 180);
			this->MinimumSize = System::Drawing::Size(414, 180);
			this->Name = L"ConnectionProperties";
			this->Text = L"ConnectionProperties";
			this->Load += gcnew System::EventHandler(this, &ConnectionProperties::ConnectionProperties_Load);
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void exportConStringBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ serverName = serverTxtBox->Text;
		System::String^ portStr = portTxtBox->Text;
		System::String^ username = usernameTxtBox->Text;
		System::String^ password = passwordTxtBox->Text;

		std::string server = msclr::interop::marshal_as<std::string>(serverName);
		std::string port = msclr::interop::marshal_as<std::string>(portStr);
		std::string user = msclr::interop::marshal_as<std::string>(username);
		std::string pass = msclr::interop::marshal_as<std::string>(password);

		std::ofstream myFile;
		myFile.open("connection_properties.txt");

		myFile << server + "\n";
		myFile << port + "\n";
		myFile << user + "\n";
		myFile << user + "\n";

		MessageBox::Show("Connection string saved to the root folder of the project.");
		myFile.close();
	}
	private: System::Void ConnectionProperties_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}