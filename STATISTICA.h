#pragma once

#include "TABLE.h"

namespace Statistics {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class Statistics : public System::Windows::Forms::Form
	{
	public:
		Statistics(void)
		{
			InitializeComponent();


		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Statistics()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;


	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openDataToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ closeDataToolStripMenuItem;


	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::CheckBox^ checkBox5;
	private: System::Windows::Forms::CheckBox^ checkBox6;

	private: System::Windows::Forms::ToolTip^ toolTip1;


	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(102, 44);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(106, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Statistics::textBox1_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(140, 129);
			this->textBox4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(68, 20);
			this->textBox4->TabIndex = 5;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Statistics::textBox4_TextChanged);
			// 
			// button1
			// 
			this->button1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button1->Location = System::Drawing::Point(190, 350);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(117, 36);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Calculate";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Statistics::button1_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(16, 90);
			this->checkBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(139, 17);
			this->checkBox1->TabIndex = 7;
			this->checkBox1->Text = L"Additional fragmentation";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Statistics::checkBox1_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 47);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(54, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Threshold";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 170);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Statistics:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 133);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(102, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Subfragment length:";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 1, 0, 1);
			this->menuStrip1->Size = System::Drawing::Size(326, 24);
			this->menuStrip1->TabIndex = 13;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openDataToolStripMenuItem,
					this->closeDataToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 22);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openDataToolStripMenuItem
			// 
			this->openDataToolStripMenuItem->Name = L"openDataToolStripMenuItem";
			this->openDataToolStripMenuItem->Size = System::Drawing::Size(130, 22);
			this->openDataToolStripMenuItem->Text = L"Open Data";
			this->openDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &Statistics::openDataToolStripMenuItem_Click);
			// 
			// closeDataToolStripMenuItem
			// 
			this->closeDataToolStripMenuItem->Name = L"closeDataToolStripMenuItem";
			this->closeDataToolStripMenuItem->Size = System::Drawing::Size(130, 22);
			this->closeDataToolStripMenuItem->Text = L"Close Data";
			this->closeDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &Statistics::closeDataToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Statistics::openFileDialog1_FileOk);
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileName = L"openFileDialog2";
			this->openFileDialog2->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Statistics::openFileDialog2_FileOk);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 275);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(21, 13);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Fit:";
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(16, 205);
			this->checkBox2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(53, 17);
			this->checkBox2->TabIndex = 15;
			this->checkBox2->Text = L"Mean";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Statistics::checkBox2_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(16, 237);
			this->checkBox3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(63, 17);
			this->checkBox3->TabIndex = 16;
			this->checkBox3->Text = L"Std. err.";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &Statistics::checkBox3_CheckedChanged);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(131, 205);
			this->checkBox4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(43, 17);
			this->checkBox4->TabIndex = 17;
			this->checkBox4->Text = L"Min";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &Statistics::checkBox4_CheckedChanged);
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(131, 237);
			this->checkBox5->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(46, 17);
			this->checkBox5->TabIndex = 18;
			this->checkBox5->Text = L"Max";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &Statistics::checkBox5_CheckedChanged);
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Location = System::Drawing::Point(16, 311);
			this->checkBox6->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(55, 17);
			this->checkBox6->TabIndex = 19;
			this->checkBox6->Text = L"Linear";
			this->checkBox6->UseVisualStyleBackColor = true;
			this->checkBox6->CheckedChanged += gcnew System::EventHandler(this, &Statistics::checkBox6_CheckedChanged);
			// 
			// Statistics
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(326, 394);
			this->Controls->Add(this->checkBox6);
			this->Controls->Add(this->checkBox5);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"Statistics";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Fragmentation Statistics";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		int splitNumber = 1;
		int isAdditional = 0;
		int statistica = 0;
		int numberOfWords = 0;
		int numRows = 0;
		int numCols = 0;
		double threshold = 0;

		String^ output = "";
		String^ openFileName = "data.txt";
		String^ nameCol = "";
		String^ emptyCol = gcnew String(' ', 10);
		String^ fileBufferName = "buffer.txt";


	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
		//THRESHOLD
	{
		if (textBox1->Text == "")
			threshold = 0;
		else
			threshold = System::Convert::ToDouble(textBox1->Text);
	}

	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		//ADDITIONAL FRAGMENTATION
	{
		if (checkBox1->Checked == false)
		{
			textBox4->ReadOnly = true;
			splitNumber = numberOfWords;
			isAdditional = 0;
		}
		else if (checkBox1->Checked == true)
		{
			textBox4->ReadOnly = false;
			isAdditional = 1;

			if (textBox4->Text == "")
				splitNumber = numberOfWords;
			else
				splitNumber = System::Convert::ToInt32(textBox4->Text);

		}
	}

	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (checkBox1->Checked == true)
		{
			if (textBox4->Text == "")
				splitNumber = numberOfWords;
			else
				splitNumber = System::Convert::ToInt32(textBox4->Text);
		}
		else
			splitNumber = numberOfWords;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
		//CALCULATE
	{
		if (isAdditional == 0)
			numRows = 1;
		else
			numRows = System::Math::Ceiling((numberOfWords * 1.0) / splitNumber);//считаем количество строк

		System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(fileBufferName);

		sw->WriteLine(System::Convert::ToString(numCols));
		sw->WriteLine(System::Convert::ToString(numRows));
		sw->WriteLine(System::Convert::ToString(statistica));
		sw->WriteLine(nameCol);
		sw->WriteLine(openFileName);
		sw->WriteLine(System::Convert::ToString(threshold));
		sw->WriteLine(System::Convert::ToString(splitNumber));
		sw->WriteLine(System::Convert::ToString(isAdditional));

		sw->Close();


		try
		{
			auto process = Process::Start("Statcalc_rel.exe");
			process->WaitForExit();
		}
		catch (Win32Exception^ e)
		{
			MessageBox::Show(e->Message, "Oops", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
			Application::Exit();
		}


		Table::Table^ form_Table = gcnew Table::Table;
		form_Table->ShowDialog();

		checkBox2->Checked = false;
		checkBox3->Checked = false;
		checkBox4->Checked = false;
		checkBox5->Checked = false;
		checkBox6->Checked = false;

		numCols = 0;
	}


	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
	{

	}

	private: System::Void openDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
		//OPEN FILE
	{

		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

		openFileDialog1->FileName = "data.txt";
		openFileDialog1->Filter = "Text files (*.txt)|*.txt";
		openFileDialog1->Title = "Open text file";
		openFileDialog1->RestoreDirectory = true;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			openFileName = openFileDialog1->FileName;

			//перенос данных
			System::IO::StreamReader^ srSafeName = gcnew System::IO::StreamReader(openFileName);
			System::IO::StreamWriter^ swSafeName = gcnew System::IO::StreamWriter("Safe.txt");

			String^ move = srSafeName->ReadToEnd();

			swSafeName->Write(move);

			srSafeName->Close();
			swSafeName->Close();

			System::IO::StreamReader^ srName = gcnew System::IO::StreamReader(openFileName);
			nameCol = srName->ReadLine();
			String^ line = "";

			line = srName->ReadLine();

			//считаем количество элементов
			while (line != "" && line != nullptr && line != " ")
			{
				numberOfWords++;
				line = srName->ReadLine();
			}

			srName->Close();

			textBox1->ReadOnly = false;
			textBox4->ReadOnly = true;
		}

	}

	private: System::Void openFileDialog2_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
	{

	}

	private: System::Void closeDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		textBox1->ReadOnly = true;
		textBox4->ReadOnly = true;
	}

	private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		//MEAN
	{
		if (checkBox2->Checked == false)
		{
			statistica = statistica & 0b11110;
			numCols--;
		}
		else
		{
			statistica = statistica | 0b00001;
			numCols++;
		}
	}

	private: System::Void checkBox3_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		//STD. ERR.
	{
		if (checkBox3->Checked == false)
		{
			statistica = statistica & 0b10111;
			numCols--;
		}
		else
		{
			statistica = statistica | 0b01000;
			numCols++;
		}
	}

	private: System::Void checkBox4_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		//MIN
	{
		if (checkBox4->Checked == false)
		{
			statistica = statistica & 0b11101;
			numCols--;
		}
		else
		{
			statistica = statistica | 0b00010;
			numCols++;
		}
	}

	private: System::Void checkBox5_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		//MAX
	{
		if (checkBox5->Checked == false)
		{
			statistica = statistica & 0b11011;
			numCols--;
		}
		else
		{
			statistica = statistica | 0b00100;
			numCols++;
		}
	}

	private: System::Void checkBox6_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
		//LINEAR
	{
		if (checkBox6->Checked == false)
		{
			statistica = statistica & 0b01111;
			numCols -= 2;
		}
		else
		{
			statistica = statistica | 0b10000;
			numCols += 2;
		}
	}

	};
}
