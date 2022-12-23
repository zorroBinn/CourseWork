#include "Game.h"

System::Void СourseWorkС::Game::персонажToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->groupBoxworker->Visible = false;
	this->groupBoxfood->Visible = false;
	this->groupBoxclothes->Visible = false;
	this->groupBoxmd->Visible = false;
	this->groupBoxrealty->Visible = false;
	this->groupBoxhuman->Visible = true;
	this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
}

System::Void СourseWorkС::Game::здоровьеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->groupBoxhuman->Visible = false;
	this->groupBoxfood->Visible = false;
	this->groupBoxworker->Visible = false;
	this->groupBoxclothes->Visible = false;
	this->groupBoxrealty->Visible = false;
	this->groupBoxmd->Visible = true;
}

System::Void СourseWorkС::Game::имуществоToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->groupBoxhuman->Visible = false;
	this->groupBoxfood->Visible = false;
	this->groupBoxworker->Visible = false;
	this->groupBoxmd->Visible = false;
	this->groupBoxclothes->Visible = false;
	this->groupBoxrealty->Visible = true;
}

System::Void СourseWorkС::Game::работаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->groupBoxhuman->Visible = false;
	this->groupBoxfood->Visible = false;
	this->groupBoxclothes->Visible = false;
	this->groupBoxmd->Visible = false;
	this->groupBoxrealty->Visible = false;
	this->groupBoxworker->Visible = true;
}

System::Void СourseWorkС::Game::одеждаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->groupBoxhuman->Visible = false;
	this->groupBoxfood->Visible = false;
	this->groupBoxworker->Visible = false;
	this->groupBoxmd->Visible = false;
	this->groupBoxrealty->Visible = false;
	this->groupBoxclothes->Visible = true;
}

System::Void СourseWorkС::Game::checkBoxhouse_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->checkBoxhouse->Checked == true) {
		this->comboBoxrealtyhouse->Visible = true;
		this->buybutton->Visible = true;
		this->checkBoxcar->Checked = false;
		this->comboBoxrealtycar->Visible = false;
	}
	else if (this->checkBoxhouse->Checked == false && this->checkBoxcar->Checked == true) {
		this->comboBoxrealtyhouse->Visible = false;
	}
	else {
		this->buybutton->Visible = false;
		this->comboBoxrealtycar->Visible = false;
	}
}

System::Void СourseWorkС::Game::checkBoxcar_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->checkBoxcar->Checked == true) {
		this->buybutton->Visible = true;
		this->checkBoxhouse->Checked = false;
		this->comboBoxrealtyhouse->Visible = false;
		this->comboBoxrealtycar->Visible = true;
	}
	else if (this->checkBoxcar->Checked == false && this->checkBoxhouse->Checked == true) {
		this->comboBoxrealtycar->Visible = false;
	}
	else {
		this->buybutton->Visible = false;
		this->comboBoxrealtycar->Visible = false;
	}
}

System::Void СourseWorkС::Game::Game_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	System::Windows::Forms::DialogResult result = MessageBox::Show("Вы уврены, что хотите выйти?", "Внимание!", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
	if (result == System::Windows::Forms::DialogResult::Yes) {
		if (worker->GetAge() != 0) {
			try
			{
				StreamWriter^ f = gcnew StreamWriter("save.txt", false);
				f->WriteLine(worker->GetName());
				f->WriteLine(worker->GetSex());
				f->WriteLine(worker->GetAge());
				f->WriteLine(worker->GetMoneybalance());
				f->WriteLine(medcard->GetWeight());
				f->WriteLine(medcard->GetHeight());
				f->WriteLine(medcard->GetHealthStatus());
				if (medcard->GetInfinityHealth() == true) {
					f->WriteLine(1);
				}
				else {
					f->WriteLine(0);
				}
				f->WriteLine(worker->GetNamework());
				f->WriteLine(worker->GetPayment());
				f->WriteLine(clothes->GetBody());
				f->WriteLine(clothes->GetPants());
				f->WriteLine(clothes->GetShoes());
				f->WriteLine(clothes->GetClothesStatus());
				if (clothes->GetAutoSewUp() == true) {
					f->WriteLine(1);
				}
				else {
					f->WriteLine(0);
				}
				f->WriteLine(realty->GetHousing());
				f->WriteLine(realty->GetVehicle());
				f->WriteLine(worker->GetLevel());
				f->WriteLine(food->GetSatietyStatus());
				if (food->GetAutoEating() == true) {
					f->WriteLine(1);
				}
				else {
					f->WriteLine(0);
				}
				f->Close();
			}
			catch (Exception^)
			{
				MessageBox::Show("Не удалось провести сохранение!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			
		}
		this->Owner->WindowState = FormWindowState::Normal;
		this->Owner->ShowInTaskbar = true;
		return;
	}
	else {
		e->Cancel = true;
	}
}

System::Void СourseWorkС::Game::buysuitbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (worker->GetMoneybalance() >= 1000) {
		clothes->BuySuit();
		clothes->SetClothesStatus(100);
		this->dataGridViewclothes->Rows[0]->Cells[1]->Value = clothes->GetBody();
		this->dataGridViewclothes->Rows[1]->Cells[1]->Value = clothes->GetPants();
		this->dataGridViewclothes->Rows[2]->Cells[1]->Value = clothes->GetShoes();
		this->dataGridViewclothes->Rows[3]->Cells[1]->Value = clothes->GetClothesStatus();
		this->buysuitbutton->Visible = false;
		worker->ChangeMoney(-1000);
		this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
		this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
	}
	else {
		MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void СourseWorkС::Game::buttonsewup_Click(System::Object^ sender, System::EventArgs^ e)
{
	if ((worker->GetMoneybalance() >= 5 && clothes->GetPants() != "Брюки") || (worker->GetMoneybalance() >= 10 && clothes->GetPants() == "Брюки")) {
		if (clothes->GetClothesStatus() < 100) {
			clothes->SewUpClothes();
			this->dataGridViewclothes->Rows[3]->Cells[1]->Value = clothes->GetClothesStatus();
			if (clothes->GetPants() != "Брюки") {
				worker->ChangeMoney(-5);
			}
			else {
				worker->ChangeMoney(-10);
			}
			this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
			this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
		}
		else {
			MessageBox::Show("Одежда как новенькая!", "Зачем?", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	else {
		MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void СourseWorkС::Game::workingbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (medcard->GetHealthStatus() > 0 && clothes->GetClothesStatus() > 0 && food->GetSatietyStatus() > 0) {
		worker->ChangeMoney(worker->GetPayment());
		this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
		this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
		if (clothes->GetAutoSewUp() != true) {
			clothes->TearClothes();
			this->dataGridViewclothes->Rows[3]->Cells[1]->Value = clothes->GetClothesStatus();
		}
		else {
			worker->ChangeMoney(-1);
			this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
			this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
		}
		if (medcard->GetInfinityHealth() != true) {
			medcard->DownStatus();
			this->infohealthpercent->Text = Convert::ToString(medcard->GetHealthStatus());
			this->health->Text = Convert::ToString(medcard->GetHealthStatus());
		}
		else {
			worker->ChangeMoney(-2);
			this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
			this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
		}
		if (food->GetAutoEating() != true) {
			food->DownSatietyStatus();
			this->infosatietypercent->Text = Convert::ToString(food->GetSatietyStatus());
			this->satiety->Text = Convert::ToString(food->GetSatietyStatus());
		}
		else {
			worker->ChangeMoney(-3);
			this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
			this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
		}
		if (worker->GetMoneybalance() > 100000000 && worker->GetLevel() < 4) {
			if (worker->GetNamework() != "Магнат") {
				MessageBox::Show("С повышением!", "Ура!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			worker->SetNamework("Магнат");
			worker->SetPayment(900000);
			worker->LevelUp();
			this->Namework->Text = worker->GetNamework();
			this->payment->Text = Convert::ToString(worker->GetPayment());
		}
		if (worker->GetMoneybalance() > 10000000 && worker->GetLevel() < 3) {
			if (worker->GetNamework() != "Бизнесмен") {
				MessageBox::Show("С повышением!", "Ура!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			worker->SetNamework("Бизнесмен");
			worker->SetPayment(185000);
			worker->LevelUp();
			this->Namework->Text = worker->GetNamework();
			this->payment->Text = Convert::ToString(worker->GetPayment());
		}
		if (worker->GetMoneybalance() > 1000000 && worker->GetLevel() < 2) {
			if (worker->GetNamework() != "Глава отдела") {
				MessageBox::Show("С повышением!", "Ура!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			worker->SetNamework("Глава отдела");
			worker->SetPayment(70000);
			worker->LevelUp();
			this->Namework->Text = worker->GetNamework();
			this->payment->Text = Convert::ToString(worker->GetPayment());
		}
		if (worker->GetMoneybalance() > 100000 && worker->GetLevel() < 1) {
			if (worker->GetNamework() != "Кассир") {
				MessageBox::Show("С повышением!", "Ура!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			worker->SetNamework("Кассир");
			worker->SetPayment(13000);
			worker->LevelUp();
			this->Namework->Text = worker->GetNamework();
			this->payment->Text = Convert::ToString(worker->GetPayment());
		}
	}
	else {
		MessageBox::Show("Сейчас вы не можете работать!\nПроверьте состояние здоровья,\n состояние одежды или сытость", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void СourseWorkС::Game::healthbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (worker->GetMoneybalance() >= 10) {
		if (medcard->GetHealthStatus() < 100) {
			medcard->UpStatus();
			worker->ChangeMoney(-10);
			this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
			this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
			this->infohealthpercent->Text = Convert::ToString(medcard->GetHealthStatus());
			this->health->Text = Convert::ToString(medcard->GetHealthStatus());
		}
		else {
			MessageBox::Show("Вы как огурчик!", "Зачем ? ", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	else {
		MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void СourseWorkС::Game::buybutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->checkBoxhouse->Checked == true) {
		if (this->comboBoxrealtyhouse->Text == "Квартира(3 000 000)") {
			if (worker->GetMoneybalance() >= 3000000) {
				realty->SetHousing(this->comboBoxrealtyhouse->Text);
				worker->ChangeMoney(-3000000);
				this->realtyhouse->Text = realty->GetHousing();
				this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
				this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
			}
			else {
				MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		if (this->comboBoxrealtyhouse->Text == "Коттедж(7 000 000)") {
			if (worker->GetMoneybalance() >= 7000000) {
				realty->SetHousing(this->comboBoxrealtyhouse->Text);
				worker->ChangeMoney(-7000000);
				this->realtyhouse->Text = realty->GetHousing();
				this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
				this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
			}
			else {
				MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		if (this->comboBoxrealtyhouse->Text == "Вилла(20 000 000)") {
			if (worker->GetMoneybalance() >= 20000000) {
				realty->SetHousing(this->comboBoxrealtyhouse->Text);
				worker->ChangeMoney(-20000000);
				this->realtyhouse->Text = realty->GetHousing();
				this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
				this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
			}
			else {
				MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
	}
	else {
		if (this->comboBoxrealtycar->Text == "Мотоцикл(200 000)") {
			if (worker->GetMoneybalance() >= 200000) {
				realty->SetVehicle(this->comboBoxrealtycar->Text);
				worker->ChangeMoney(-200000);
				this->realtycar->Text = realty->GetVehicle();
				this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
				this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
			}
			else {
				MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		if (this->comboBoxrealtycar->Text == "Автомобиль(600 000)") {
			if (worker->GetMoneybalance() >= 600000) {
				realty->SetVehicle(this->comboBoxrealtycar->Text);
				worker->ChangeMoney(-600000);
				this->realtycar->Text = realty->GetVehicle();
				this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
				this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
			}
			else {
				MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		if (this->comboBoxrealtycar->Text == "Ламба(9 000 000)") {
			if (worker->GetMoneybalance() >= 9000000) {
				realty->SetVehicle(this->comboBoxrealtycar->Text);
				worker->ChangeMoney(-9000000);
				this->realtycar->Text = realty->GetVehicle();
				this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
				this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
			}
			else {
				MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
	}
}

System::Void СourseWorkС::Game::DataInitialization()
{
	if (File::Exists("save.txt") == true) {
		try
		{
			StreamReader^ f = File::OpenText("save.txt");
			worker->SetName(f->ReadLine());
			worker->SetSex(f->ReadLine());
			worker->SetAge(Convert::ToInt32(f->ReadLine()));
			worker->SetMoneyBalance(Convert::ToInt32(f->ReadLine()));
			medcard->SetWeight(Convert::ToInt32(f->ReadLine()));
			medcard->SetHeight(Convert::ToInt32(f->ReadLine()));
			medcard->SetHealthStatus(Convert::ToInt32(f->ReadLine()));
			if (f->ReadLine() == "0") {
				medcard->SetInfinityHealth(false);
			}
			else {
				medcard->SetInfinityHealth(true);
			}
			worker->SetNamework(f->ReadLine());
			worker->SetPayment(Convert::ToInt32(f->ReadLine()));
			clothes->SetBody(f->ReadLine());
			clothes->SetPants(f->ReadLine());
			clothes->SetShoes(f->ReadLine());
			clothes->SetClothesStatus(Convert::ToInt32(f->ReadLine()));
			if (f->ReadLine() == "0") {
				clothes->SetAutoSewUp(false);
			}
			else {
				clothes->SetAutoSewUp(true);
			}
			realty->SetHousing(f->ReadLine());
			realty->SetVehicle(f->ReadLine());
			worker->SetLevel(Convert::ToInt32(f->ReadLine()));
			food->SetSatietyStatus(Convert::ToInt32(f->ReadLine()));
			if (f->ReadLine() == "0") {
				food->SetAutoEating(false);
			}
			else {
				food->SetAutoEating(true);
			}
			f->Close();

			if (clothes->GetPants() == "Брюки") {
				this->buttonsewup->Text = "Починить одежду(10$)";
			}
			this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
			this->infoname->Text = worker->GetName();
			this->infohealthpercent->Text = Convert::ToString(medcard->GetHealthStatus());
			this->infosatietypercent->Text = Convert::ToString(food->GetSatietyStatus());
			this->dataGridViewclothes->Rows->Add();
			this->dataGridViewclothes->Rows->Add();
			this->dataGridViewclothes->Rows->Add();
			this->dataGridViewclothes->Rows->Add();
			this->dataGridViewclothes->Rows[0]->Cells[0]->Value = L"Верх";
			this->dataGridViewclothes->Rows[1]->Cells[0]->Value = L"Штаны";
			this->dataGridViewclothes->Rows[2]->Cells[0]->Value = L"Обувь";
			this->dataGridViewclothes->Rows[3]->Cells[0]->Value = L"Состояние одежды";
			this->dataGridViewclothes->Rows[0]->Cells[1]->Value = clothes->GetBody();
			this->dataGridViewclothes->Rows[1]->Cells[1]->Value = clothes->GetPants();
			this->dataGridViewclothes->Rows[2]->Cells[1]->Value = clothes->GetShoes();
			this->dataGridViewclothes->Rows[3]->Cells[1]->Value = clothes->GetClothesStatus();
			this->humanname->Text = worker->GetName();
			this->humansex->Text = worker->GetSex();
			this->humanage->Text = Convert::ToString(worker->GetAge());
			if (clothes->GetShoes() == "Туфли") {
				this->buysuitbutton->Visible = false;
			}
			this->mdname->Text = worker->GetName();
			this->mdweight->Text = Convert::ToString(medcard->GetWeight());
			this->mdheight->Text = Convert::ToString(medcard->GetHeight());
			this->health->Text = Convert::ToString(medcard->GetHealthStatus());
			this->satiety->Text = Convert::ToString(food->GetSatietyStatus());
			this->realtyhouse->Text = realty->GetHousing();
			this->realtycar->Text = realty->GetVehicle();
			this->workername->Text = worker->GetName();
			this->Namework->Text = worker->GetNamework();
			this->payment->Text = Convert::ToString(worker->GetPayment());
			Double IMT = (medcard->GetWeight() + 0.0) / (medcard->GetHeight() * medcard->GetHeight() / 10000);
			this->imt->Text = Convert::ToString(IMT);
			if (IMT < 18.5) {
				this->imtcomment->Text = "Ниже нормы";
			}
			else if (IMT > 26.0) {
				this->imtcomment->Text = "Выше нормы";
			}
			else {
				this->imtcomment->Text = "Норма";
			}
			
		}
		catch (Exception^)
		{
			MessageBox::Show("Не удалость загрузить сохранение!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->Close();
		}
	}
}

System::Void СourseWorkС::Game::boostersbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->groupBoxboosters->Visible == false) {
		this->groupBoxboosters->Visible = true;
	}
	else {
		this->groupBoxboosters->Visible = false;
	}
}

System::Void СourseWorkС::Game::едаtoolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->groupBoxfood->Visible = true;
	this->groupBoxrealty->Visible = false;
	this->groupBoxhuman->Visible = false;
	this->groupBoxworker->Visible = false;
	this->groupBoxmd->Visible = false;
	this->groupBoxclothes->Visible = false;
}

System::Void СourseWorkС::Game::onefoodbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (worker->GetMoneybalance() >= 5) {
		food->UpSatietyStatus(10);
		this->infosatietypercent->Text = Convert::ToString(food->GetSatietyStatus());
		this->satiety->Text = Convert::ToString(food->GetSatietyStatus());
		worker->ChangeMoney(-5);
		this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
		this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
	}
	else {
		MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void СourseWorkС::Game::twofoodbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (worker->GetMoneybalance() >= 20) {
		food->UpSatietyStatus(25);
		this->infosatietypercent->Text = Convert::ToString(food->GetSatietyStatus());
		this->satiety->Text = Convert::ToString(food->GetSatietyStatus());
		worker->ChangeMoney(-20);
		this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
		this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
	}
	else {
		MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void СourseWorkС::Game::threebutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (worker->GetMoneybalance() >= 100) {
		food->UpSatietyStatus(100);
		this->infosatietypercent->Text = Convert::ToString(food->GetSatietyStatus());
		this->satiety->Text = Convert::ToString(food->GetSatietyStatus());
		worker->ChangeMoney(-100);
		this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
		this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
	}
	else {
		MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}
