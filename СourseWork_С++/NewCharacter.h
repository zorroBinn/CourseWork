#pragma once

namespace СourseWorkС {

	//using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Сводка для NewCharacter
	/// </summary>
	public ref class NewCharacter : public System::Windows::Forms::Form //Форма создания персонажа
	{
	public:
		NewCharacter(void)
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
		~NewCharacter()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ createbutton;
	protected:

	protected:
	private: System::Windows::Forms::Label^ labelname;
	private: System::Windows::Forms::TextBox^ textBoxname;

	private: System::Windows::Forms::Label^ labelsex;
	private: System::Windows::Forms::Label^ labelage;

	private: System::Windows::Forms::Label^ labelweight;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownweight;
	private: System::Windows::Forms::Label^ labelheight;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownheight;
	private: System::Windows::Forms::CheckBox^ checkBoxman;
	private: System::Windows::Forms::CheckBox^ checkBoxwoman;
	private: System::Windows::Forms::ComboBox^ comboBoxage;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(NewCharacter::typeid));
			this->createbutton = (gcnew System::Windows::Forms::Button());
			this->labelname = (gcnew System::Windows::Forms::Label());
			this->textBoxname = (gcnew System::Windows::Forms::TextBox());
			this->labelsex = (gcnew System::Windows::Forms::Label());
			this->labelage = (gcnew System::Windows::Forms::Label());
			this->labelweight = (gcnew System::Windows::Forms::Label());
			this->numericUpDownweight = (gcnew System::Windows::Forms::NumericUpDown());
			this->labelheight = (gcnew System::Windows::Forms::Label());
			this->numericUpDownheight = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBoxman = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxwoman = (gcnew System::Windows::Forms::CheckBox());
			this->comboBoxage = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownweight))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownheight))->BeginInit();
			this->SuspendLayout();
			// 
			// createbutton
			// 
			this->createbutton->BackColor = System::Drawing::Color::Goldenrod;
			this->createbutton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->createbutton->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->createbutton->ForeColor = System::Drawing::SystemColors::ControlText;
			this->createbutton->Location = System::Drawing::Point(286, 404);
			this->createbutton->Name = L"createbutton";
			this->createbutton->Size = System::Drawing::Size(156, 45);
			this->createbutton->TabIndex = 0;
			this->createbutton->Text = L"Создать персонажа";
			this->createbutton->UseVisualStyleBackColor = false;
			this->createbutton->Click += gcnew System::EventHandler(this, &NewCharacter::createbutton_Click);
			// 
			// labelname
			// 
			this->labelname->AutoSize = true;
			this->labelname->BackColor = System::Drawing::SystemColors::Info;
			this->labelname->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelname->Location = System::Drawing::Point(58, 91);
			this->labelname->Name = L"labelname";
			this->labelname->Size = System::Drawing::Size(52, 24);
			this->labelname->TabIndex = 1;
			this->labelname->Text = L"Имя:";
			// 
			// textBoxname
			// 
			this->textBoxname->BackColor = System::Drawing::Color::Cornsilk;
			this->textBoxname->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxname->Location = System::Drawing::Point(116, 86);
			this->textBoxname->MaxLength = 20;
			this->textBoxname->Name = L"textBoxname";
			this->textBoxname->Size = System::Drawing::Size(169, 29);
			this->textBoxname->TabIndex = 2;
			this->textBoxname->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxname->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &NewCharacter::textBoxname_KeyPress);
			// 
			// labelsex
			// 
			this->labelsex->AutoSize = true;
			this->labelsex->BackColor = System::Drawing::SystemColors::Info;
			this->labelsex->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelsex->Location = System::Drawing::Point(58, 159);
			this->labelsex->Name = L"labelsex";
			this->labelsex->Size = System::Drawing::Size(45, 24);
			this->labelsex->TabIndex = 4;
			this->labelsex->Text = L"Пол:";
			// 
			// labelage
			// 
			this->labelage->AutoSize = true;
			this->labelage->BackColor = System::Drawing::SystemColors::Info;
			this->labelage->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelage->Location = System::Drawing::Point(58, 221);
			this->labelage->Name = L"labelage";
			this->labelage->Size = System::Drawing::Size(82, 24);
			this->labelage->TabIndex = 5;
			this->labelage->Text = L"Возраст:";
			// 
			// labelweight
			// 
			this->labelweight->AutoSize = true;
			this->labelweight->BackColor = System::Drawing::SystemColors::Info;
			this->labelweight->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelweight->Location = System::Drawing::Point(370, 91);
			this->labelweight->Name = L"labelweight";
			this->labelweight->Size = System::Drawing::Size(46, 24);
			this->labelweight->TabIndex = 7;
			this->labelweight->Text = L"Вес:";
			// 
			// numericUpDownweight
			// 
			this->numericUpDownweight->BackColor = System::Drawing::Color::Cornsilk;
			this->numericUpDownweight->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->numericUpDownweight->Location = System::Drawing::Point(422, 91);
			this->numericUpDownweight->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 300, 0, 0, 0 });
			this->numericUpDownweight->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->numericUpDownweight->Name = L"numericUpDownweight";
			this->numericUpDownweight->Size = System::Drawing::Size(120, 26);
			this->numericUpDownweight->TabIndex = 8;
			this->numericUpDownweight->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->numericUpDownweight->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 75, 0, 0, 0 });
			// 
			// labelheight
			// 
			this->labelheight->AutoSize = true;
			this->labelheight->BackColor = System::Drawing::SystemColors::Info;
			this->labelheight->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelheight->Location = System::Drawing::Point(370, 159);
			this->labelheight->Name = L"labelheight";
			this->labelheight->Size = System::Drawing::Size(52, 24);
			this->labelheight->TabIndex = 9;
			this->labelheight->Text = L"Рост:";
			// 
			// numericUpDownheight
			// 
			this->numericUpDownheight->BackColor = System::Drawing::Color::Cornsilk;
			this->numericUpDownheight->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->numericUpDownheight->Location = System::Drawing::Point(422, 159);
			this->numericUpDownheight->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 240, 0, 0, 0 });
			this->numericUpDownheight->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 150, 0, 0, 0 });
			this->numericUpDownheight->Name = L"numericUpDownheight";
			this->numericUpDownheight->Size = System::Drawing::Size(120, 26);
			this->numericUpDownheight->TabIndex = 10;
			this->numericUpDownheight->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->numericUpDownheight->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 180, 0, 0, 0 });
			// 
			// checkBoxman
			// 
			this->checkBoxman->AutoSize = true;
			this->checkBoxman->BackColor = System::Drawing::Color::Cornsilk;
			this->checkBoxman->Cursor = System::Windows::Forms::Cursors::Hand;
			this->checkBoxman->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBoxman->Location = System::Drawing::Point(116, 158);
			this->checkBoxman->Name = L"checkBoxman";
			this->checkBoxman->Size = System::Drawing::Size(42, 25);
			this->checkBoxman->TabIndex = 11;
			this->checkBoxman->Text = L"M";
			this->checkBoxman->UseVisualStyleBackColor = false;
			this->checkBoxman->CheckedChanged += gcnew System::EventHandler(this, &NewCharacter::checkBoxman_CheckedChanged);
			// 
			// checkBoxwoman
			// 
			this->checkBoxwoman->AutoSize = true;
			this->checkBoxwoman->BackColor = System::Drawing::Color::Cornsilk;
			this->checkBoxwoman->Cursor = System::Windows::Forms::Cursors::Hand;
			this->checkBoxwoman->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBoxwoman->Location = System::Drawing::Point(174, 158);
			this->checkBoxwoman->Name = L"checkBoxwoman";
			this->checkBoxwoman->Size = System::Drawing::Size(42, 25);
			this->checkBoxwoman->TabIndex = 12;
			this->checkBoxwoman->Text = L"Ж";
			this->checkBoxwoman->UseVisualStyleBackColor = false;
			this->checkBoxwoman->CheckedChanged += gcnew System::EventHandler(this, &NewCharacter::checkBoxwoman_CheckedChanged);
			// 
			// comboBoxage
			// 
			this->comboBoxage->BackColor = System::Drawing::Color::Cornsilk;
			this->comboBoxage->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBoxage->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxage->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBoxage->FormattingEnabled = true;
			this->comboBoxage->Items->AddRange(gcnew cli::array< System::Object^  >(33) {
				L"18", L"19", L"20", L"21", L"22", L"23", L"24",
					L"25", L"26", L"27", L"28", L"29", L"30", L"31", L"32", L"33", L"34", L"35", L"36", L"37", L"38", L"39", L"40", L"41", L"42",
					L"43", L"44", L"45", L"46", L"47", L"48", L"49", L"50"
			});
			this->comboBoxage->Location = System::Drawing::Point(148, 221);
			this->comboBoxage->MaxDropDownItems = 6;
			this->comboBoxage->MaxLength = 2;
			this->comboBoxage->Name = L"comboBoxage";
			this->comboBoxage->Size = System::Drawing::Size(68, 28);
			this->comboBoxage->TabIndex = 13;
			// 
			// NewCharacter
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(755, 525);
			this->Controls->Add(this->comboBoxage);
			this->Controls->Add(this->checkBoxwoman);
			this->Controls->Add(this->checkBoxman);
			this->Controls->Add(this->numericUpDownheight);
			this->Controls->Add(this->labelheight);
			this->Controls->Add(this->numericUpDownweight);
			this->Controls->Add(this->labelweight);
			this->Controls->Add(this->labelage);
			this->Controls->Add(this->labelsex);
			this->Controls->Add(this->textBoxname);
			this->Controls->Add(this->labelname);
			this->Controls->Add(this->createbutton);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(771, 564);
			this->MinimumSize = System::Drawing::Size(771, 564);
			this->Name = L"NewCharacter";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Создание нового персонажа";
			this->TopMost = true;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &NewCharacter::NewCharacter_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownweight))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownheight))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void checkBoxman_CheckedChanged(System::Object^ sender, System::EventArgs^ e); //Выбор пола (М) по флажку
private: System::Void checkBoxwoman_CheckedChanged(System::Object^ sender, System::EventArgs^ e); //Выбор пола (Ж) по флажку
private: System::Void createbutton_Click(System::Object^ sender, System::EventArgs^ e); //Формирование файла сохранения по кнопке
private: System::Void NewCharacter_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
private: System::Void textBoxname_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e); //Защита на ввод в текстовом поле имени персонажа
};
}
