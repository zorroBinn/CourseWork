#include "NewCharacter.h"
using System::Char;

//Выбор пола (М) по флажку
System::Void СourseWorkС::NewCharacter::checkBoxman_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->checkBoxman->Checked == true)
		this->checkBoxwoman->Checked = false;
}

//Выбор пола (Ж) по флажку
System::Void СourseWorkС::NewCharacter::checkBoxwoman_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->checkBoxwoman->Checked == true)
		this->checkBoxman->Checked = false;
}

//Формирование файла сохранения по кнопке
System::Void СourseWorkС::NewCharacter::createbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->textBoxname->Text == "" || (this->checkBoxman->Checked == false && this->checkBoxwoman->Checked == false) || this->comboBoxage->Text == "" || this->numericUpDownheight->Text == "" || this->numericUpDownweight->Text == "") {
		MessageBox::Show("Не все поля заполнены!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else {
		try
		{
			StreamWriter^ f = gcnew StreamWriter("save.save", false);
			//
			//В файле sava.save построчно хранится информация от персонаже
			//
			f->WriteLine(this->textBoxname->Text); //Имя
			//Пол
			if (this->checkBoxman->Checked == true) {
				f->WriteLine("М");
			}
			else {
				f->WriteLine("Ж");
			}
			f->WriteLine(this->comboBoxage->Text); //Возраст
			f->WriteLine(100); //Balance
			f->WriteLine(this->numericUpDownweight->Text); //Вес
			f->WriteLine(this->numericUpDownheight->Text); //Рост
			f->WriteLine(100); //HealthStatus
			f->WriteLine(0); //InfinityHealth
			f->WriteLine("Раздача листовок"); //Наименование работы
			f->WriteLine(10); //Payment
			f->WriteLine("Кофта"); //Верх одежды
			f->WriteLine("Джинсы"); //Штаны
			f->WriteLine("Кроссовки"); //Обувь
			f->WriteLine(100); //ClothesStatus
			f->WriteLine(0); //AutoSewUp
			f->WriteLine("Гараж"); //Недвижимость
			f->WriteLine("Велик"); //Транспортное средство
			f->WriteLine(0); //Level
			f->WriteLine(100); //SatietyStatus
			f->WriteLine(0); //AutoEating
			f->WriteLine(1); //Day
			f->Close();
			MessageBox::Show("Персонаж создан!", "Готово!", MessageBoxButtons::OK, MessageBoxIcon::None);
			this->Close();
		}
		catch (FileNotFoundException^)
		{
			MessageBox::Show("Ошибка создания", "Ой!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

//Возврат в форму главного меню при закрытии данной формы
System::Void СourseWorkС::NewCharacter::NewCharacter_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	this->Owner->WindowState = FormWindowState::Normal;
	this->Owner->ShowInTaskbar = true;
}

//Защита на ввод в текстовом поле имени персонажа
System::Void СourseWorkС::NewCharacter::textBoxname_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	Char ch = e->KeyChar;
	if (ch.IsLetter(ch) || ch.IsControl(ch)) {
		return;
	}
	else {
		e->Handled = true;
	}
}
