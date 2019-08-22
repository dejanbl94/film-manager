#include "stdafx.h"
#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

int main(array<System::String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	FilmManager::MainForm main_form;
	Application::Run(% main_form);
}