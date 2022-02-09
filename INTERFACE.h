#pragma once

namespace Interface {

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
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();


		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openDataToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ closeDataToolStripMenuItem;


	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog2;
	private: System::Windows::Forms::CheckBox^ checkBox2;
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
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
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
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(109, 151);
			this->textBox3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(199, 20);
			this->textBox3->TabIndex = 4;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(132, 272);
			this->textBox4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(68, 20);
			this->textBox4->TabIndex = 5;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(190, 340);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(117, 46);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Make fragment";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(16, 241);
			this->checkBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(139, 17);
			this->checkBox1->TabIndex = 7;
			this->checkBox1->Text = L"Additional fragmentation";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
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
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(16, 97);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Fragment name root";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 155);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(87, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Output file name:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 279);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(102, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Subfragment length:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(149, 96);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(51, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"FRAGM1";
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
			this->openDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openDataToolStripMenuItem_Click);
			// 
			// closeDataToolStripMenuItem
			// 
			this->closeDataToolStripMenuItem->Name = L"closeDataToolStripMenuItem";
			this->closeDataToolStripMenuItem->Size = System::Drawing::Size(130, 22);
			this->closeDataToolStripMenuItem->Text = L"Close Data";
			this->closeDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::closeDataToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileName = L"openFileDialog2";
			this->openFileDialog2->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog2_FileOk);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(16, 311);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(118, 17);
			this->checkBox2->TabIndex = 14;
			this->checkBox2->Text = L"Advansed fragment";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox2_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(326, 394);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Threshold Fragmentation";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		int numColumn = 0;
		int splitNumber = 1;
		int isAdvansed = 0;
		int isAdditional = 0;
		int offset = 0;
		int numberOfWords = 0;
		double threshold = 0;
		bool hasFile = false;
		String^ output = "";
		String^ openFileName = "data.txt";
		String^ filePath = "";
		String^ nameCol = "";
		String^ emptyCol = gcnew String(' ', 10);
		String^ fileBufferName = "buffer.txt";
		String^ safeFileName = "Safe.txt";


	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (textBox1->Text == "")
			threshold = 0;
		else
			threshold = System::Convert::ToDouble(textBox1->Text);
	}

	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		output = textBox3->Text;
	}

	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
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

			if (textBox4->Text == "")
				splitNumber = numberOfWords;
			else
				splitNumber = System::Convert::ToInt32(textBox4->Text);

			isAdditional = 1;
		}
	}

	private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (checkBox2->Checked == false)
		{
			isAdvansed = 0;;
		}
		else if (checkBox1->Checked == true)
		{
			isAdvansed = 1;
		}
	}

	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (checkBox1->Checked)
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
	{
		//если в файле результата содержатьс€ данные
		if (System::IO::File::Exists(output) == false)
		{
			System::IO::File::Create(output)->Close();
		}

		System::IO::StreamReader^ srFirstLine = gcnew System::IO::StreamReader(output);
		String^ firstLine = "";

		firstLine = srFirstLine->ReadLine();

		if (numColumn == 0 && firstLine != nullptr && firstLine != " ")
		{
			String^ secondLine = srFirstLine->ReadLine();
			String^ subString = "";

			bool inSpaces = true;
			int numWords = 0;
			int i = 0;

			if (secondLine->Length != 0)
				subString = secondLine->Substring(i, 1);

			i++;

			while (i != secondLine->Length - 1)
			{
				if (subString == " ")
				{
					inSpaces = true;
				}
				else if (inSpaces)
				{
					numWords++;
					inSpaces = false;
				}

				subString = secondLine->Substring(i, 1);
				++i;
			}

			numColumn = numWords;
		}
		srFirstLine->Close();

		offset = numColumn;

		int splitOffset = System::Math::Ceiling((numberOfWords * 1.0) / splitNumber);

		if (checkBox1->Checked == true && checkBox2->Checked == false)
			numColumn += splitOffset;
		else if (checkBox1->Checked == true && checkBox2->Checked == true)
			numColumn += 3 * splitOffset;
		else if (checkBox1->Checked == false && checkBox2->Checked == true)
			numColumn += 3;
		else
			numColumn += 1;

		if (checkBox2->Checked)
			isAdvansed = 1;
		else
			isAdvansed = 0;

		System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(fileBufferName);

		sw->WriteLine("Safe.txt");
		sw->WriteLine(System::Convert::ToString(threshold));
		sw->WriteLine(output);
		sw->WriteLine(isAdditional);
		sw->WriteLine(System::Convert::ToString(splitNumber));
		sw->WriteLine(nameCol);
		sw->WriteLine(System::Convert::ToString(isAdvansed));
		sw->WriteLine(System::Convert::ToString(offset));

		sw->Close();

		try
		{
			auto process = Process::Start("Parser_rel.exe");
			process->WaitForExit();
		}
		catch (Win32Exception^ e)
		{
			MessageBox::Show(e->Message, "Oops", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
			Application::Exit();
		}

		System::IO::StreamReader^ srFragm = gcnew System::IO::StreamReader("fragment.txt");

		if (System::IO::File::Exists(output) == false)
		{
			System::IO::File::Create(output)->Close();
		}

		System::IO::StreamReader^ srOut = gcnew System::IO::StreamReader(output);
		System::IO::StreamWriter^ swBuffer = gcnew System::IO::StreamWriter("subfragm.txt");

		String^ lineFragm;
		String^ lineOut;
		String^ lineBuffer;

		lineOut = srOut->ReadLine();
		lineFragm = srFragm->ReadLine();

		while ((lineOut != "" || lineFragm != "") && (lineOut != nullptr || lineFragm != nullptr))
		{
			if (lineOut != nullptr && lineFragm != nullptr && lineOut != "" && lineFragm != "")
			{
				while (lineOut->Length < offset * 10)
					lineOut += emptyCol;

				lineOut = lineOut + lineFragm;
				swBuffer->WriteLine(lineOut);
			}
			else if (lineOut == nullptr || lineOut == "")
			{
				lineOut = "";
				for (int i = 0; i < offset; i++)
				{
					lineOut += emptyCol;
				}

				lineOut = lineOut + lineFragm;
				swBuffer->WriteLine(lineOut);
			}
			else if (lineFragm == nullptr || lineFragm == "")
			{
				lineOut = lineOut + emptyCol;
				swBuffer->WriteLine(lineOut);
			}

			lineOut = srOut->ReadLine();
			lineFragm = srFragm->ReadLine();
		}

		srFragm->Close();
		srOut->Close();
		swBuffer->Close();

		System::IO::StreamReader^ srExchange = gcnew System::IO::StreamReader("subfragm.txt");
		System::IO::StreamWriter^ swExchange = gcnew System::IO::StreamWriter(output);

		String^ exchange = srExchange->ReadToEnd();
		swExchange->Write(exchange);

		srExchange->Close();
		swExchange->Close();
	}

	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
	{

	}

	private: System::Void openDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
		//OPEN DATA FILE
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

			label5->Text = nameCol;

			srName->Close();

			textBox1->ReadOnly = false;
			textBox3->ReadOnly = false;
			textBox4->ReadOnly = true;
		}

	}

	private: System::Void openFileDialog2_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
	{

	}

	private: System::Void closeDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		textBox1->ReadOnly = true;
		textBox3->ReadOnly = true;
		textBox4->ReadOnly = true;
	}
	};
}
