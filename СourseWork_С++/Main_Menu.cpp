#include "Main_Menu.h"
#include "Game.h"

System::Void �ourseWork�::Main_Menu::ExitButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
}

System::Void �ourseWork�::Main_Menu::AboutGameButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("����� ���������� � ���� <<Life simulator>>!\n����� ��� ��������� ������ ���� �� ������������ �� �����������������!\n������� ������, ������������ � �����.\n������ ������� �� ����� ��������� � ������� ������������!\n�����!", "�� ����", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void �ourseWork�::Main_Menu::SaveDeleteButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (File::Exists("save.txt") == true) {
        try
        {
            System::Windows::Forms::DialogResult result = MessageBox::Show("�� ������, ��� ������ ������� ���� ����������?", "��������!", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
            if (result == System::Windows::Forms::DialogResult::Yes) {
                File::Delete("save.txt");
                MessageBox::Show("���������� �������", "", MessageBoxButtons::OK, MessageBoxIcon::Information);
                this->GameStartButton->Text = "������ ����";
            }
        }
        catch (Exception^)
        {
            MessageBox::Show("������ �������� �����!", "��������!", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    else {
        MessageBox::Show("���������� ���!", "", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
}

System::Void �ourseWork�::Main_Menu::GameStartButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (this->GameStartButton->Text == "������ ����") {
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

System::Void �ourseWork�::Main_Menu::Main_Menu_Resize(System::Object^ sender, System::EventArgs^ e)
{
    if (File::Exists("save.txt") == true) {
        this->GameStartButton->Text = "������";
    }
}

