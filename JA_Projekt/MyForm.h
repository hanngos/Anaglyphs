#pragma once
#include "LibraryHandler.h"
#include "BMP.h"
#include <chrono>
#include <iostream>

extern "C" void asmbinarization(BYTE * binary, int width, int height, BYTE * BMPData);

namespace JAProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Threading;
	using namespace System::Threading::Tasks;
	using namespace std;
	using namespace std::chrono;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

	public:

	public:

	private: System::Windows::Forms::GroupBox^ runGroup;


	public:
		BMP^ LeftBMP, ^ RightBMP;
		LibraryHandler^ libHandler;
	private: System::Windows::Forms::Label^ leftLabel;
	private: System::Windows::Forms::Button^ ChooseR;

	public:

	public:

	private: System::Windows::Forms::TextBox^ rightTextBox;

	private: System::Windows::Forms::Label^ rightLabel;

	public:
		MyForm(void)
		{
			InitializeComponent();
			threadsNumericUpDown->Value = Environment::ProcessorCount;
			noOfThreadsLabel->Text = L"Zalecana liczba watkow: " + Environment::ProcessorCount.ToString();
			//klasy lib handler i bmp
			LeftBMP = gcnew BMP();
			RightBMP = gcnew BMP();
			libHandler = gcnew LibraryHandler();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyForm()
		{
			//usunacie bmp
			if (components)
			{
				delete components;
				LeftBMP->clear();
				RightBMP->clear();
			}
		}
	private: System::Windows::Forms::TextBox^ leftTextBox;
	protected:


	private: System::Windows::Forms::Button^ runButton;


	private: System::Windows::Forms::RadioButton^ cppRadioButton;
	private: System::Windows::Forms::RadioButton^ asmRadioButton;
	private: System::Windows::Forms::GroupBox^ threadsGroup;
	private: System::Windows::Forms::GroupBox^ libGroup;
	private: System::Windows::Forms::GroupBox^ imageGroup;


	private: System::Windows::Forms::NumericUpDown^ threadsNumericUpDown;





	private: System::Windows::Forms::Label^ timeLabel;
	private: System::Windows::Forms::Label^ noOfThreads;
	private: System::Windows::Forms::Button^ ChooseL;


	private: System::Windows::Forms::Label^ noOfThreadsLabel;






	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->leftTextBox = (gcnew System::Windows::Forms::TextBox());
			this->runButton = (gcnew System::Windows::Forms::Button());
			this->cppRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->asmRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->threadsGroup = (gcnew System::Windows::Forms::GroupBox());
			this->noOfThreadsLabel = (gcnew System::Windows::Forms::Label());
			this->threadsNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->noOfThreads = (gcnew System::Windows::Forms::Label());
			this->libGroup = (gcnew System::Windows::Forms::GroupBox());
			this->imageGroup = (gcnew System::Windows::Forms::GroupBox());
			this->rightLabel = (gcnew System::Windows::Forms::Label());
			this->leftLabel = (gcnew System::Windows::Forms::Label());
			this->ChooseR = (gcnew System::Windows::Forms::Button());
			this->rightTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ChooseL = (gcnew System::Windows::Forms::Button());
			this->timeLabel = (gcnew System::Windows::Forms::Label());
			this->runGroup = (gcnew System::Windows::Forms::GroupBox());
			this->threadsGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->threadsNumericUpDown))->BeginInit();
			this->libGroup->SuspendLayout();
			this->imageGroup->SuspendLayout();
			this->runGroup->SuspendLayout();
			this->SuspendLayout();
			// 
			// leftTextBox
			// 
			this->leftTextBox->Location = System::Drawing::Point(56, 29);
			this->leftTextBox->Margin = System::Windows::Forms::Padding(4);
			this->leftTextBox->Name = L"leftTextBox";
			this->leftTextBox->Size = System::Drawing::Size(138, 22);
			this->leftTextBox->TabIndex = 1;
			this->leftTextBox->Text = L"left.bmp";
			// 
			// runButton
			// 
			this->runButton->Location = System::Drawing::Point(45, 22);
			this->runButton->Margin = System::Windows::Forms::Padding(4);
			this->runButton->Name = L"runButton";
			this->runButton->Size = System::Drawing::Size(116, 30);
			this->runButton->TabIndex = 2;
			this->runButton->Text = L"Stworz";
			this->runButton->UseVisualStyleBackColor = true;
			this->runButton->Click += gcnew System::EventHandler(this, &MyForm::runButton_Click);
			// 
			// cppRadioButton
			// 
			this->cppRadioButton->AutoSize = true;
			this->cppRadioButton->Checked = true;
			this->cppRadioButton->Location = System::Drawing::Point(19, 23);
			this->cppRadioButton->Margin = System::Windows::Forms::Padding(4);
			this->cppRadioButton->Name = L"cppRadioButton";
			this->cppRadioButton->Size = System::Drawing::Size(54, 21);
			this->cppRadioButton->TabIndex = 7;
			this->cppRadioButton->TabStop = true;
			this->cppRadioButton->Text = L"C++";
			this->cppRadioButton->UseVisualStyleBackColor = true;
			// 
			// asmRadioButton
			// 
			this->asmRadioButton->AutoSize = true;
			this->asmRadioButton->Location = System::Drawing::Point(19, 52);
			this->asmRadioButton->Margin = System::Windows::Forms::Padding(4);
			this->asmRadioButton->Name = L"asmRadioButton";
			this->asmRadioButton->Size = System::Drawing::Size(95, 21);
			this->asmRadioButton->TabIndex = 8;
			this->asmRadioButton->TabStop = true;
			this->asmRadioButton->Text = L"Assembler";
			this->asmRadioButton->UseVisualStyleBackColor = true;
			// 
			// threadsGroup
			// 
			this->threadsGroup->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->threadsGroup->Controls->Add(this->noOfThreadsLabel);
			this->threadsGroup->Controls->Add(this->threadsNumericUpDown);
			this->threadsGroup->Location = System::Drawing::Point(16, 147);
			this->threadsGroup->Margin = System::Windows::Forms::Padding(4);
			this->threadsGroup->Name = L"threadsGroup";
			this->threadsGroup->Padding = System::Windows::Forms::Padding(4);
			this->threadsGroup->Size = System::Drawing::Size(298, 58);
			this->threadsGroup->TabIndex = 9;
			this->threadsGroup->TabStop = false;
			this->threadsGroup->Text = L"Wielowatkowosc";
			// 
			// noOfThreadsLabel
			// 
			this->noOfThreadsLabel->AutoSize = true;
			this->noOfThreadsLabel->Location = System::Drawing::Point(8, 25);
			this->noOfThreadsLabel->Name = L"noOfThreadsLabel";
			this->noOfThreadsLabel->Size = System::Drawing::Size(160, 17);
			this->noOfThreadsLabel->TabIndex = 9;
			this->noOfThreadsLabel->Text = L"Zalecana liczba watkow:";
			// 
			// threadsNumericUpDown
			// 
			this->threadsNumericUpDown->Location = System::Drawing::Point(221, 20);
			this->threadsNumericUpDown->Margin = System::Windows::Forms::Padding(4);
			this->threadsNumericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 64, 0, 0, 0 });
			this->threadsNumericUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->threadsNumericUpDown->Name = L"threadsNumericUpDown";
			this->threadsNumericUpDown->ReadOnly = true;
			this->threadsNumericUpDown->Size = System::Drawing::Size(69, 22);
			this->threadsNumericUpDown->TabIndex = 8;
			this->threadsNumericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// noOfThreads
			// 
			this->noOfThreads->Location = System::Drawing::Point(0, 0);
			this->noOfThreads->Name = L"noOfThreads";
			this->noOfThreads->Size = System::Drawing::Size(100, 23);
			this->noOfThreads->TabIndex = 0;
			// 
			// libGroup
			// 
			this->libGroup->Controls->Add(this->asmRadioButton);
			this->libGroup->Controls->Add(this->cppRadioButton);
			this->libGroup->Location = System::Drawing::Point(321, 16);
			this->libGroup->Margin = System::Windows::Forms::Padding(4);
			this->libGroup->Name = L"libGroup";
			this->libGroup->Padding = System::Windows::Forms::Padding(4);
			this->libGroup->Size = System::Drawing::Size(200, 84);
			this->libGroup->TabIndex = 10;
			this->libGroup->TabStop = false;
			this->libGroup->Text = L"Biblioteka";
			// 
			// imageGroup
			// 
			this->imageGroup->Controls->Add(this->rightLabel);
			this->imageGroup->Controls->Add(this->leftLabel);
			this->imageGroup->Controls->Add(this->ChooseR);
			this->imageGroup->Controls->Add(this->rightTextBox);
			this->imageGroup->Controls->Add(this->ChooseL);
			this->imageGroup->Controls->Add(this->leftTextBox);
			this->imageGroup->Location = System::Drawing::Point(16, 16);
			this->imageGroup->Margin = System::Windows::Forms::Padding(4);
			this->imageGroup->Name = L"imageGroup";
			this->imageGroup->Padding = System::Windows::Forms::Padding(4);
			this->imageGroup->Size = System::Drawing::Size(298, 123);
			this->imageGroup->TabIndex = 11;
			this->imageGroup->TabStop = false;
			this->imageGroup->Text = L"Obraz";
			// 
			// rightLabel
			// 
			this->rightLabel->AutoSize = true;
			this->rightLabel->Location = System::Drawing::Point(5, 77);
			this->rightLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->rightLabel->Name = L"rightLabel";
			this->rightLabel->Size = System::Drawing::Size(46, 17);
			this->rightLabel->TabIndex = 5;
			this->rightLabel->Text = L"Prawy";
			// 
			// leftLabel
			// 
			this->leftLabel->AutoSize = true;
			this->leftLabel->Location = System::Drawing::Point(8, 32);
			this->leftLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->leftLabel->Name = L"leftLabel";
			this->leftLabel->Size = System::Drawing::Size(40, 17);
			this->leftLabel->TabIndex = 4;
			this->leftLabel->Text = L"Lewy";
			// 
			// ChooseR
			// 
			this->ChooseR->Location = System::Drawing::Point(207, 70);
			this->ChooseR->Name = L"ChooseR";
			this->ChooseR->Size = System::Drawing::Size(84, 30);
			this->ChooseR->TabIndex = 4;
			this->ChooseR->Text = L"Wybierz...";
			this->ChooseR->UseVisualStyleBackColor = true;
			this->ChooseR->Click += gcnew System::EventHandler(this, &MyForm::ChooseR_Click);
			// 
			// rightTextBox
			// 
			this->rightTextBox->Location = System::Drawing::Point(56, 74);
			this->rightTextBox->Margin = System::Windows::Forms::Padding(4);
			this->rightTextBox->Name = L"rightTextBox";
			this->rightTextBox->Size = System::Drawing::Size(138, 22);
			this->rightTextBox->TabIndex = 3;
			this->rightTextBox->Text = L"right.bmp";
			// 
			// ChooseL
			// 
			this->ChooseL->Location = System::Drawing::Point(207, 25);
			this->ChooseL->Name = L"ChooseL";
			this->ChooseL->Size = System::Drawing::Size(84, 30);
			this->ChooseL->TabIndex = 2;
			this->ChooseL->Text = L"Wybierz...";
			this->ChooseL->UseVisualStyleBackColor = true;
			this->ChooseL->Click += gcnew System::EventHandler(this, &MyForm::ChooseL_Click);
			// 
			// timeLabel
			// 
			this->timeLabel->AutoSize = true;
			this->timeLabel->Location = System::Drawing::Point(16, 65);
			this->timeLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->timeLabel->Name = L"timeLabel";
			this->timeLabel->Size = System::Drawing::Size(43, 17);
			this->timeLabel->TabIndex = 3;
			this->timeLabel->Text = L"Czas:";
			// 
			// runGroup
			// 
			this->runGroup->Controls->Add(this->runButton);
			this->runGroup->Controls->Add(this->timeLabel);
			this->runGroup->Location = System::Drawing::Point(321, 107);
			this->runGroup->Name = L"runGroup";
			this->runGroup->Size = System::Drawing::Size(200, 98);
			this->runGroup->TabIndex = 17;
			this->runGroup->TabStop = false;
			this->runGroup->Text = L"Stworz";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->ClientSize = System::Drawing::Size(534, 218);
			this->Controls->Add(this->runGroup);
			this->Controls->Add(this->imageGroup);
			this->Controls->Add(this->libGroup);
			this->Controls->Add(this->threadsGroup);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"Anaglify";
			this->threadsGroup->ResumeLayout(false);
			this->threadsGroup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->threadsNumericUpDown))->EndInit();
			this->libGroup->ResumeLayout(false);
			this->libGroup->PerformLayout();
			this->imageGroup->ResumeLayout(false);
			this->imageGroup->PerformLayout();
			this->runGroup->ResumeLayout(false);
			this->runGroup->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void runButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (leftTextBox->Text == "" || rightTextBox->Text == "") { MessageBox::Show("There is no Filename!"); }
		else {

			if (LeftBMP->readBMP(msclr::interop::marshal_as<string>(leftTextBox->Text).c_str()) == "ok" && RightBMP->readBMP(msclr::interop::marshal_as<string>(rightTextBox->Text).c_str())) {

				int numberOfThreads = Decimal::ToInt32(threadsNumericUpDown->Value);
				auto start = high_resolution_clock::now();

				LeftBMP->result = new BYTE[LeftBMP->size];
				
				for (int s = 0; s < LeftBMP->size; s++) {
					LeftBMP->result[s] = 0;
				}

				/*for (int s = 0; s < LeftBMP->size; s++) {
					LeftBMP->result[s] = LeftBMP->BMPData[s] ^ RightBMP->BMPData[s];
				}*/

				Generic::List<Task^>^ listOfThreads = gcnew Generic::List<Task^>();

				int l = (LeftBMP->height * LeftBMP->width) / numberOfThreads;
				int s = 0;


				for (int i = 0; i < numberOfThreads; i++) {
					
					Tuple<bool, BMP^, BMP^, int, int>^ param;
					
					if (i == numberOfThreads - 1) {
						int d = l + ((LeftBMP->height * LeftBMP->width) % numberOfThreads);
						param = gcnew Tuple<bool, BMP^, BMP^, int, int>(cppRadioButton->Checked, LeftBMP, RightBMP, s, d * 3);
					}
					else {
						param = gcnew Tuple<bool, BMP^, BMP^, int, int>(cppRadioButton->Checked, LeftBMP, RightBMP, s, l * 3);
					}

					listOfThreads->Add(Task::Factory->StartNew((Action<Object^>^)(gcnew Action<Object^>(libHandler, &LibraryHandler::createAnaglyph)), param));
					s += l * 3;

				}
				Task::WaitAll(listOfThreads->ToArray());

				//for (int s = 0; s < LeftBMP->height * LeftBMP->width; s += 3) {
				//	LeftBMP->result[s + 0] = 0;// RightBMP->BMPData[s + 0];
				//	LeftBMP->result[s + 1] = RightBMP->BMPData[s + 1];
				//	LeftBMP->result[s + 2] = 0;//LeftBMPData[s + 2];
				//}

				


				LeftBMP->writeBMP();
				auto stop = high_resolution_clock::now();
				duration<double, milli> duration = stop - start;
				timeLabel->Text = gcnew String(("Czas: " + to_string(duration.count()) + " ms").c_str());
				/*ofstream file;
				file.open("czas.txt", std::ios::app);
				file << numberOfThreads;
				file << "\n	" + to_string(duration.count()) + "\n";
				file.close();*/

			}
			else MessageBox::Show("Cannot open image!");

		}
	}

	private: System::Void ChooseL_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ fileDialog = gcnew OpenFileDialog();
		fileDialog->Filter = "bmp files(*.bmp)|*.bmp";

		if (fileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			leftTextBox->Text = fileDialog->FileName;
		}
		else MessageBox::Show("Dialog window was cancelled or sth went wrong!");
	}

	private: System::Void ChooseR_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ fileDialog = gcnew OpenFileDialog();
		fileDialog->Filter = "bmp files(*.bmp)|*.bmp";

		if (fileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			rightTextBox->Text = fileDialog->FileName;
		}
		else MessageBox::Show("Dialog window was cancelled or sth went wrong!");
	}


};
}

