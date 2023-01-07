#pragma once
#include "NewCharacter.h"
#include "Game.h"

namespace СourseWorkС {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using IO::File;

	/// <summary>
	/// Сводка для Main_Menu
	/// </summary>
	public ref class Main_Menu : public System::Windows::Forms::Form
	{
	public:
		Main_Menu(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			if (File::Exists("save.save") == true) {
				TextStartButtonSet();
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Main_Menu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ GameStartButton;
	protected:
	private: System::Windows::Forms::Button^ ExitButton;
	private: System::Windows::Forms::Button^ AboutGameButton;
	private: System::Windows::Forms::Button^ SaveDeleteButton;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main_Menu::typeid));
			this->GameStartButton = (gcnew System::Windows::Forms::Button());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			this->AboutGameButton = (gcnew System::Windows::Forms::Button());
			this->SaveDeleteButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// GameStartButton
			// 
			this->GameStartButton->BackColor = System::Drawing::Color::Goldenrod;
			this->GameStartButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->GameStartButton->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GameStartButton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->GameStartButton->Location = System::Drawing::Point(276, 134);
			this->GameStartButton->Name = L"GameStartButton";
			this->GameStartButton->Size = System::Drawing::Size(171, 53);
			this->GameStartButton->TabIndex = 15;
			this->GameStartButton->Text = L"Начать игру";
			this->GameStartButton->UseVisualStyleBackColor = false;
			this->GameStartButton->Click += gcnew System::EventHandler(this, &Main_Menu::GameStartButton_Click);
			// 
			// ExitButton
			// 
			this->ExitButton->BackColor = System::Drawing::Color::Goldenrod;
			this->ExitButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ExitButton->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ExitButton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->ExitButton->Location = System::Drawing::Point(276, 375);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(171, 53);
			this->ExitButton->TabIndex = 16;
			this->ExitButton->Text = L"Выход";
			this->ExitButton->UseVisualStyleBackColor = false;
			this->ExitButton->Click += gcnew System::EventHandler(this, &Main_Menu::ExitButton_Click);
			// 
			// AboutGameButton
			// 
			this->AboutGameButton->BackColor = System::Drawing::Color::Goldenrod;
			this->AboutGameButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->AboutGameButton->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AboutGameButton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->AboutGameButton->Location = System::Drawing::Point(276, 298);
			this->AboutGameButton->Name = L"AboutGameButton";
			this->AboutGameButton->Size = System::Drawing::Size(171, 53);
			this->AboutGameButton->TabIndex = 17;
			this->AboutGameButton->Text = L"Об игре";
			this->AboutGameButton->UseVisualStyleBackColor = false;
			this->AboutGameButton->Click += gcnew System::EventHandler(this, &Main_Menu::AboutGameButton_Click);
			// 
			// SaveDeleteButton
			// 
			this->SaveDeleteButton->BackColor = System::Drawing::Color::Goldenrod;
			this->SaveDeleteButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->SaveDeleteButton->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SaveDeleteButton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->SaveDeleteButton->Location = System::Drawing::Point(276, 219);
			this->SaveDeleteButton->Name = L"SaveDeleteButton";
			this->SaveDeleteButton->Size = System::Drawing::Size(171, 53);
			this->SaveDeleteButton->TabIndex = 18;
			this->SaveDeleteButton->Text = L"Удалить сохранение";
			this->SaveDeleteButton->UseVisualStyleBackColor = false;
			this->SaveDeleteButton->Click += gcnew System::EventHandler(this, &Main_Menu::SaveDeleteButton_Click);
			// 
			// Main_Menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(755, 525);
			this->Controls->Add(this->SaveDeleteButton);
			this->Controls->Add(this->AboutGameButton);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->GameStartButton);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(771, 564);
			this->MinimumSize = System::Drawing::Size(771, 564);
			this->Name = L"Main_Menu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Главное меню";
			this->Resize += gcnew System::EventHandler(this, &Main_Menu::Main_Menu_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void TextStartButtonSet();
private: System::Void ExitButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void AboutGameButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void SaveDeleteButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void GameStartButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Main_Menu_Resize(System::Object^ sender, System::EventArgs^ e);
};
}
