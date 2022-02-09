#pragma once

namespace Table {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Table
	/// </summary>
	public ref class Table : public System::Windows::Forms::Form
	{
	public:
		Table(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Table()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ exportToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exportToTxtFileToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->exportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportToTxtFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exportToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 1, 0, 1);
			this->menuStrip1->Size = System::Drawing::Size(751, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// exportToolStripMenuItem
			// 
			this->exportToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exportToTxtFileToolStripMenuItem });
			this->exportToolStripMenuItem->Name = L"exportToolStripMenuItem";
			this->exportToolStripMenuItem->Size = System::Drawing::Size(53, 22);
			this->exportToolStripMenuItem->Text = L"Export";
			// 
			// exportToTxtFileToolStripMenuItem
			// 
			this->exportToTxtFileToolStripMenuItem->Name = L"exportToTxtFileToolStripMenuItem";
			this->exportToTxtFileToolStripMenuItem->Size = System::Drawing::Size(164, 22);
			this->exportToTxtFileToolStripMenuItem->Text = L"Export to text file";
			this->exportToTxtFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Table::exportToTxtFileToolStripMenuItem_Click);
			// 
			// Table
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(751, 325);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Table";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Fragmentation Statistics";
			this->Load += gcnew System::EventHandler(this, &Table::Table_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		String^ saveFileName = "";



	private: System::Void exportToTxtFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
		//EXPORT
	{
		SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;

		saveFileDialog1->FileName = "result.txt";
		saveFileDialog1->Filter = "Text files (*.txt)|*.txt";
		saveFileDialog1->Title = "Save to text file";
		saveFileDialog1->RestoreDirectory = true;

		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			saveFileName = saveFileDialog1->FileName;

			if (System::IO::File::Exists(saveFileName) == false)
			{
				System::IO::File::Create(saveFileName)->Close();
			}

			System::IO::StreamWriter^ swSaveFile = gcnew System::IO::StreamWriter(saveFileName);
			System::IO::StreamReader^ srFragment = gcnew System::IO::StreamReader("fragment.txt");
			System::IO::StreamReader^ srSubFragm = gcnew System::IO::StreamReader("subfragm.txt");
			String^ line = "";

			line = srFragment->ReadLine();
			swSaveFile->WriteLine(line);

			line = srSubFragm->ReadLine();

			while (line != "" && line != nullptr)
			{
				swSaveFile->WriteLine(line);
				line = srSubFragm->ReadLine();
			}

			swSaveFile->Close();
			srFragment->Close();
			srSubFragm->Close();
		}
	}

	private: System::Void Table_Load(System::Object^ sender, System::EventArgs^ e)
		//CREATE A TABLE
	{
		System::IO::StreamReader^ srBuffer = gcnew System::IO::StreamReader("buffer.txt");

		int numCols = System::Convert::ToInt32(srBuffer->ReadLine());
		int numRows = System::Convert::ToInt32(srBuffer->ReadLine());
		int statistica = System::Convert::ToInt32(srBuffer->ReadLine());

		srBuffer->Close();

		int vSize = Math::Round(300 * 1.0 / (numRows + 1));
		int hSize = Math::Round(700 * 1.0 / (numCols + 1));

		TableLayoutPanel^ table = gcnew TableLayoutPanel;

		table->Location = System::Drawing::Point(0, 24);
		table->Size = System::Drawing::Size(750, 300);
		table->BackColor = Color::LightBlue;
		table->ColumnCount = numCols + 1;
		table->RowCount = numRows + 1;
		table->CellBorderStyle = TableLayoutPanelCellBorderStyle::Inset;
		table->BorderStyle = BorderStyle::FixedSingle;

		Label^ label1 = gcnew Label;
		label1->Text = L"Fragment Name";
		label1->TextAlign = ContentAlignment::MiddleCenter;
		label1->Size = System::Drawing::Size(hSize, vSize);

		table->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent));
		table->Controls->Add(label1, 0, 0);

		//Заполнение колонок
		int k = 1;//счетчик колонок
		//MEAN
		if ((statistica & 1) == 1)
		{
			Label^ label2 = gcnew Label;
			label2->Text = L"Mean";
			label2->TextAlign = ContentAlignment::MiddleCenter;
			label2->Size = System::Drawing::Size(hSize, vSize);
			table->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent));
			table->Controls->Add(label2, k, 0);
			k++;
		}

		//MIN
		if ((statistica & 2) == 2)
		{
			Label^ label3 = gcnew Label;
			label3->Text = L"Min";
			label3->TextAlign = ContentAlignment::MiddleCenter;
			label3->Size = System::Drawing::Size(hSize, vSize);
			table->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent));
			table->Controls->Add(label3, k, 0);
			k++;
		}

		//MAX
		if ((statistica & 4) == 4)
		{
			Label^ label4 = gcnew Label;
			label4->Text = L"Max";
			label4->TextAlign = ContentAlignment::MiddleCenter;
			label4->Size = System::Drawing::Size(hSize, vSize);
			table->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent));
			table->Controls->Add(label4, k, 0);
			k++;
		}

		//SKO
		if ((statistica & 8) == 8)
		{
			Label^ label5 = gcnew Label;
			label5->Text = L"Std.Err.";
			label5->TextAlign = ContentAlignment::MiddleCenter;
			label5->Size = System::Drawing::Size(hSize, vSize);
			table->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent));
			table->Controls->Add(label5, k, 0);
			k++;
		}

		//Linear
		if ((statistica & 16) == 16)
		{
			Label^ label6 = gcnew Label;
			label6->Text = L"a";
			label6->TextAlign = ContentAlignment::MiddleCenter;
			label6->Size = System::Drawing::Size(hSize, vSize);
			table->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent));
			table->Controls->Add(label6, k, 0);
			k++;

			Label^ label7 = gcnew Label;
			label7->Text = L"b";
			label7->TextAlign = ContentAlignment::MiddleCenter;
			label7->Size = System::Drawing::Size(hSize, vSize);
			table->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent));
			table->Controls->Add(label7, k, 0);
		}

		//Заполнение рядов
		System::IO::StreamReader^ srSubfragm = gcnew System::IO::StreamReader("subfragm.txt");

		String^ line = "";

		array<Label^>^ labels = gcnew array<Label^>(numRows * (numCols + 1));

		for (int i = 1; i < numRows + 1; i++)
		{
			line = srSubfragm->ReadLine();
			for (int j = 0; j < numCols + 1; j++)
			{
				labels[i + j - 1] = gcnew Label;
				labels[i + j - 1]->Text = line->Substring(j * 10, 10);
				labels[i + j - 1]->TextAlign = ContentAlignment::MiddleCenter;
				labels[i + j - 1]->Size = System::Drawing::Size(hSize, vSize);
				table->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent));
				table->Controls->Add(labels[i + j - 1], j, i);
			}

		}

		srSubfragm->Close();
		Controls->Add(table);
	}
	};
}
