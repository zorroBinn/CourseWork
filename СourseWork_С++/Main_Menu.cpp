#include "Main_Menu.h"
#include "Game.h"

System::Void СourseWorkС::Main_Menu::ExitButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
}

System::Void СourseWorkС::Main_Menu::AboutGameButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Добро пожаловать в игру <<Life simulator>>!\nЗдесь вам предстоит пройти путь от безработного до мультимиллиардера!\nПокупка одежды, недвижимости и машин.\nВсегда следите за своим здоровьем и другими показателями!\nУдачи!", "Об игре", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void СourseWorkС::Main_Menu::SaveDeleteButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (File::Exists("save.txt") == true) {
        try
        {
            System::Windows::Forms::DialogResult result = MessageBox::Show("Вы уврены, что хотите удалить файл сохранения?", "Внимание!", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
            if (result == System::Windows::Forms::DialogResult::Yes) {
                File::Delete("save.txt");
                MessageBox::Show("Сохранение удалено", "", MessageBoxButtons::OK, MessageBoxIcon::Information);
                this->GameStartButton->Text = "Начать игру";
            }
        }
        catch (Exception^)
        {
            MessageBox::Show("Ошибка удаления файла!", "Внимание!", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    else {
        MessageBox::Show("Сохранений нет!", "", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
}

System::Void СourseWorkС::Main_Menu::GameStartButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (this->GameStartButton->Text == "Начать игру") {
        NewCharacter^ newcharacter = gcnew NewCharacter();
        newcharacter->Owner = this;
        this->WindowState = FormWindowState::Minimized;
        this->ShowInTaskbar = false;
        newcharacter->Show();
    }
    else {
        Game^ game = gcnew Game();
        game->Owner = this;
        this->WindowState = FormWindowState::Minimized;
        this->ShowInTaskbar = false;
        game->Show();
    }
}

System::Void СourseWorkС::Main_Menu::Main_Menu_Resize(System::Object^ sender, System::EventArgs^ e)
{
    if (File::Exists("save.txt") == true) {
        this->GameStartButton->Text = "Играть";
    }
}

