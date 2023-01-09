#include "Game.h"

System::Void СourseWorkС::Game::DataInitialization()
{
	if (File::Exists("save.save") == true) {
		try
		{
			StreamReader^ f = File::OpenText("save.save");
			worker->SetName(f->ReadLine());
			worker->SetSex(f->ReadLine());
			worker->SetAge(Convert::ToInt32(f->ReadLine()));
			worker->SetMoneyBalance(Convert::ToInt32(f->ReadLine()));
			worker->GetMedCard()->SetWeight(Convert::ToInt32(f->ReadLine()));
			worker->GetMedCard()->SetHeight(Convert::ToInt32(f->ReadLine()));
			worker->GetMedCard()->SetHealthStatus(Convert::ToInt32(f->ReadLine()));
			if (f->ReadLine() == "0") {
				worker->GetMedCard()->SetInfinityHealth(false);
			}
			else {
				worker->GetMedCard()->SetInfinityHealth(true);
				this->autohealthbutton->BackColor = System::Drawing::Color::LimeGreen;
			}
			worker->SetNamework(f->ReadLine());
			worker->SetPayment(Convert::ToInt32(f->ReadLine()));
			worker->GetClothes()->SetBody(f->ReadLine());
			worker->GetClothes()->SetPants(f->ReadLine());
			worker->GetClothes()->SetShoes(f->ReadLine());
			worker->GetClothes()->SetClothesStatus(Convert::ToInt32(f->ReadLine()));
			if (f->ReadLine() == "0") {
				worker->GetClothes()->SetAutoSewUp(false);
			}
			else {
				worker->GetClothes()->SetAutoSewUp(true);
				this->autosewupbutton->BackColor = System::Drawing::Color::LimeGreen;
			}
			worker->GetRealty()->SetHousing(f->ReadLine());
			worker->GetRealty()->SetVehicle(f->ReadLine());
			worker->SetLevel(Convert::ToInt32(f->ReadLine()));
			worker->GetFood()->SetSatietyStatus(Convert::ToInt32(f->ReadLine()));
			if (f->ReadLine() == "0") {
				worker->GetFood()->SetAutoEating(false);
			}
			else {
				worker->GetFood()->SetAutoEating(true);
				this->autoeatbutton->BackColor = System::Drawing::Color::LimeGreen;
			}
			Day = Convert::ToInt32(f->ReadLine());
			f->Close();

			SatietyUpdating();
			MoneyBalanceUpdating();
			HealthUpdating();
			if (worker->GetClothes()->GetPants() == "Брюки") {
				this->buttonsewup->Text = "Починить одежду(10$)";
			}
			this->infoname->Text = worker->GetName();
			this->infoday->Text = Convert::ToString(Day);
			this->dataGridViewclothes->Rows->Add();
			this->dataGridViewclothes->Rows->Add();
			this->dataGridViewclothes->Rows->Add();
			this->dataGridViewclothes->Rows->Add();
			this->dataGridViewclothes->Rows[0]->Cells[0]->Value = L"Верх";
			this->dataGridViewclothes->Rows[1]->Cells[0]->Value = L"Штаны";
			this->dataGridViewclothes->Rows[2]->Cells[0]->Value = L"Обувь";
			this->dataGridViewclothes->Rows[3]->Cells[0]->Value = L"Состояние одежды";
			this->dataGridViewclothes->Rows[0]->Cells[1]->Value = worker->GetClothes()->GetBody();
			this->dataGridViewclothes->Rows[1]->Cells[1]->Value = worker->GetClothes()->GetPants();
			this->dataGridViewclothes->Rows[2]->Cells[1]->Value = worker->GetClothes()->GetShoes();
			this->dataGridViewclothes->Rows[3]->Cells[1]->Value = worker->GetClothes()->GetClothesStatus();
			this->humanname->Text = worker->GetName();
			this->humansex->Text = worker->GetSex();
			this->humanage->Text = Convert::ToString(worker->GetAge());
			if (worker->GetClothes()->GetShoes() == "Туфли") {
				this->buysuitbutton->Visible = false;
			}
			this->mdname->Text = worker->GetName();
			this->mdweight->Text = Convert::ToString(worker->GetMedCard()->GetWeight());
			this->mdheight->Text = Convert::ToString(worker->GetMedCard()->GetHeight());
			Double IMT = (worker->GetMedCard()->GetWeight() + 0.0) / (worker->GetMedCard()->GetHeight() * worker->GetMedCard()->GetHeight() / 10000);
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
			this->realtyhouse->Text = worker->GetRealty()->GetHousing();
			RealtyInitialization();
			this->realtycar->Text = worker->GetRealty()->GetVehicle();
			this->workername->Text = worker->GetName();
			this->Namework->Text = worker->GetNamework();
			this->payment->Text = Convert::ToString(worker->GetPayment());
		}
		catch (Exception^)
		{
			MessageBox::Show("Не удалость загрузить сохранение!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			if (File::Exists("save.save") == true) {
				File::Delete("save.save");
			}
			this->Owner->WindowState = FormWindowState::Normal;
			this->Owner->ShowInTaskbar = true;
			this->Close();
		}
	}
}

System::Void СourseWorkС::Game::RealtyInitialization()
{
	if (worker->GetRealty()->GetHousing() == "Квартира") {
		this->comboBoxrealtyhouse->Items->Clear();
		this->comboBoxrealtyhouse->Items->AddRange(gcnew cli::array< System::Object^  >(2) {
			L"Коттедж (120 000$)", L"Вилла (350 000$)"
		});
	}
	if (worker->GetRealty()->GetHousing() == "Коттедж") {
		this->comboBoxrealtyhouse->Items->Clear();
		this->comboBoxrealtyhouse->Items->AddRange(gcnew cli::array< System::Object^  >(2) {
			L"Квартира (50 000$)", L"Вилла (350 000$)"
		});
	}
	if (worker->GetRealty()->GetHousing() == "Вилла") {
		this->comboBoxrealtyhouse->Items->Clear();
		this->comboBoxrealtyhouse->Items->AddRange(gcnew cli::array< System::Object^  >(2) {
			L"Квартира (50 000$)", L"Коттедж (120 000$)"
		});
	}
	if (worker->GetRealty()->GetVehicle() == "Мотоцикл") {
		this->comboBoxrealtycar->Items->Clear();
		this->comboBoxrealtycar->Items->AddRange(gcnew cli::array< System::Object^  >(2) {
			L"Автомобиль (10 000$)", L"Спорткар (150 000$)"
		});
	}
	if (worker->GetRealty()->GetVehicle() == "Автомобиль") {
		this->comboBoxrealtycar->Items->Clear();
		this->comboBoxrealtycar->Items->AddRange(gcnew cli::array< System::Object^  >(2) {
			L"Мотоцикл (3 500$)", L"Спорткар (150 000$)"
		});
	}
	if (worker->GetRealty()->GetVehicle() == "Спорткар") {
		this->comboBoxrealtycar->Items->Clear();
		this->comboBoxrealtycar->Items->AddRange(gcnew cli::array< System::Object^  >(2) {
			L"Мотоцикл (3 500$)", L"Автомобиль (10 000$)"
		});
	}
}

System::Void СourseWorkС::Game::DayUpdating()
{
	this->Day++;
	this->infoday->Text = Convert::ToString(Day);
	if (Day >= 365 && Day % 365 == 0) {
		if (worker->GetLevel() == 0) {
			MessageBox::Show("Сегодня ваш день рождения!\nПримите в подарок эту скромную сумму:\n+1 000$", "Поздравляем!", MessageBoxButtons::OK, MessageBoxIcon::None);
			worker->ChangeMoney(1000);
		}
		else if (worker->GetLevel() == 1) {
			MessageBox::Show("Сегодня ваш день рождения!\nПримите в подарок эту скромную сумму:\n+5 000$", "Поздравляем!", MessageBoxButtons::OK, MessageBoxIcon::None);
			worker->ChangeMoney(5000);
		}
		else if (worker->GetLevel() == 2) {
			MessageBox::Show("Сегодня ваш день рождения!\nПримите в подарок эту скромную сумму:\n+10 000$", "Поздравляем!", MessageBoxButtons::OK, MessageBoxIcon::None);
			worker->ChangeMoney(10000);
		}
		else {
			MessageBox::Show("Сегодня ваш день рождения!\nПримите в подарок эту скромную сумму:\n+25 000$", "Поздравляем!", MessageBoxButtons::OK, MessageBoxIcon::None);
			worker->ChangeMoney(25000);
		}
		MoneyBalanceUpdating();
		worker->SetAge(worker->GetAge()+1);
		this->humanage->Text = Convert::ToString(worker->GetAge());
	}
}

System::Void СourseWorkС::Game::MoneyBalanceUpdating()
{
	this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
	this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
}

System::Void СourseWorkС::Game::SatietyUpdating()
{
	this->infosatietypercent->Text = Convert::ToString(worker->GetFood()->GetSatietyStatus());
	this->satiety->Text = Convert::ToString(worker->GetFood()->GetSatietyStatus());
}

System::Void СourseWorkС::Game::HealthUpdating()
{
	this->infohealthpercent->Text = Convert::ToString(worker->GetMedCard()->GetHealthStatus());
	this->health->Text = Convert::ToString(worker->GetMedCard()->GetHealthStatus());
}

System::Void СourseWorkС::Game::LevelUp()
{
	if (worker->GetMoneybalance() > 1000000 && worker->GetLevel() < 7) {
		MessageBox::Show("С повышением!", "Ура!", MessageBoxButtons::OK, MessageBoxIcon::Information);
		worker->SetNamework("Магнат");
		worker->SetPayment(10000);
		UpdatingLevelUp();
	}
	if (worker->GetMoneybalance() > 500000 && worker->GetLevel() < 6) {
		MessageBox::Show("С повышением!", "Ура!", MessageBoxButtons::OK, MessageBoxIcon::Information);
		worker->SetNamework("Глава франшизы");
		worker->SetPayment(2000);
		UpdatingLevelUp();
	}
	if (worker->GetMoneybalance() > 100000 && worker->GetLevel() < 5) {
		MessageBox::Show("С повышением!", "Ура!", MessageBoxButtons::OK, MessageBoxIcon::Information);
		worker->SetNamework("Бизнесмен");
		worker->SetPayment(600);
		UpdatingLevelUp();
	}
	if (worker->GetMoneybalance() > 50000 && worker->GetLevel() < 4) {
		MessageBox::Show("С повышением!", "Ура!", MessageBoxButtons::OK, MessageBoxIcon::Information);
		worker->SetNamework("Директор магазина");
		worker->SetPayment(250);
		UpdatingLevelUp();
	}
	if (worker->GetMoneybalance() > 10000 && worker->GetLevel() < 3) {
		MessageBox::Show("С повышением!", "Ура!", MessageBoxButtons::OK, MessageBoxIcon::Information);
		worker->SetNamework("Заведующий");
		worker->SetPayment(120);
		UpdatingLevelUp();
	}
	if (worker->GetMoneybalance() > 5000 && worker->GetLevel() < 2) {
		MessageBox::Show("С повышением!", "Ура!", MessageBoxButtons::OK, MessageBoxIcon::Information);
		worker->SetNamework("Глава отдела");
		worker->SetPayment(40);
		UpdatingLevelUp();
	}
	if (worker->GetMoneybalance() > 1000 && worker->GetLevel() < 1) {
		MessageBox::Show("С повышением!", "Ура!", MessageBoxButtons::OK, MessageBoxIcon::Information);
		worker->SetNamework("Кассир");
		worker->SetPayment(15);
		UpdatingLevelUp();
	}
}

System::Void СourseWorkС::Game::UpdatingLevelUp()
{
	worker->LevelUp();
	this->Namework->Text = worker->GetNamework();
	this->payment->Text = Convert::ToString(worker->GetPayment());
}

System::Void СourseWorkС::Game::GameSave()
{
	try
	{
		StreamWriter^ f = gcnew StreamWriter("save.save", false);
		f->WriteLine(worker->GetName());
		f->WriteLine(worker->GetSex());
		f->WriteLine(worker->GetAge());
		f->WriteLine(worker->GetMoneybalance());
		f->WriteLine(worker->GetMedCard()->GetWeight());
		f->WriteLine(worker->GetMedCard()->GetHeight());
		f->WriteLine(worker->GetMedCard()->GetHealthStatus());
		if (worker->GetMedCard()->GetInfinityHealth() == true) {
			f->WriteLine(1);
		}
		else {
			f->WriteLine(0);
		}
		f->WriteLine(worker->GetNamework());
		f->WriteLine(worker->GetPayment());
		f->WriteLine(worker->GetClothes()->GetBody());
		f->WriteLine(worker->GetClothes()->GetPants());
		f->WriteLine(worker->GetClothes()->GetShoes());
		f->WriteLine(worker->GetClothes()->GetClothesStatus());
		if (worker->GetClothes()->GetAutoSewUp() == true) {
			f->WriteLine(1);
		}
		else {
			f->WriteLine(0);
		}
		f->WriteLine(worker->GetRealty()->GetHousing());
		f->WriteLine(worker->GetRealty()->GetVehicle());
		f->WriteLine(worker->GetLevel());
		f->WriteLine(worker->GetFood()->GetSatietyStatus());
		if (worker->GetFood()->GetAutoEating() == true) {
			f->WriteLine(1);
		}
		else {
			f->WriteLine(0);
		}
		f->WriteLine(Day);
		f->Close();
	}
	catch (Exception^)
	{
		MessageBox::Show("Не удалось провести сохранение!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

System::Void СourseWorkС::Game::GameLoss()
{
	bool lossrate = false;
	while (lossrate == false) {
		if (worker->GetClothes()->GetClothesStatus() == 0 && worker->GetClothes()->GetPants() == "Брюки" && worker->GetMoneybalance() < 10) {
			MessageBox::Show("Ваш костюм износился и вам не хватает денег его починить!\nБыла возвращена старая одежда.", "Ой!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			worker->GetClothes()->SetRegularClothes();
			this->dataGridViewclothes->Rows[0]->Cells[1]->Value = worker->GetClothes()->GetBody();
			this->dataGridViewclothes->Rows[1]->Cells[1]->Value = worker->GetClothes()->GetPants();
			this->dataGridViewclothes->Rows[2]->Cells[1]->Value = worker->GetClothes()->GetShoes();
			this->dataGridViewclothes->Rows[3]->Cells[1]->Value = worker->GetClothes()->GetClothesStatus();
			this->buysuitbutton->Visible = true;
		}
		if (worker->GetClothes()->GetClothesStatus() == 0 && worker->GetClothes()->GetPants() != "Брюки" && worker->GetMoneybalance() < 5) {
			lossrate = true;
			MessageBox::Show("Игра окончена!\nПричины проигрыша: невозможность починить одежду", "Очень жаль...", MessageBoxButtons::OK, MessageBoxIcon::Information);
			break;
		}
		if (worker->GetFood()->GetSatietyStatus() == 0 && worker->GetMoneybalance() < 5) {
			lossrate = true;
			MessageBox::Show("Игра окончена!\nПричины проигрыша: невозможность утолить голод", "Очень жаль...", MessageBoxButtons::OK, MessageBoxIcon::Information);
			break;
		}
		if (worker->GetMedCard()->GetHealthStatus() == 0 && worker->GetMoneybalance() < 10) {
			lossrate = true;
			MessageBox::Show("Игра окончена!\nПричины проигрыша: невозможность лечения", "Очень жаль...", MessageBoxButtons::OK, MessageBoxIcon::Information);
			break;
		}
		break;
	}
	if (lossrate == true) {
		MessageBox::Show("Результат:\nДостигнутый день: " + Day, "Игра окончена", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

System::Void СourseWorkС::Game::персонажToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->groupBoxworker->Visible = false;
	this->groupBoxfood->Visible = false;
	this->groupBoxclothes->Visible = false;
	this->groupBoxmd->Visible = false;
	this->groupBoxrealty->Visible = false;
	this->groupBoxhuman->Visible = true;
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

System::Void СourseWorkС::Game::едаtoolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->groupBoxfood->Visible = true;
	this->groupBoxrealty->Visible = false;
	this->groupBoxhuman->Visible = false;
	this->groupBoxworker->Visible = false;
	this->groupBoxmd->Visible = false;
	this->groupBoxclothes->Visible = false;
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
			GameSave();
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
	if (worker->GetMoneybalance() >= 5000) {
		worker->GetClothes()->BuySuit();
		this->dataGridViewclothes->Rows[0]->Cells[1]->Value = worker->GetClothes()->GetBody();
		this->dataGridViewclothes->Rows[1]->Cells[1]->Value = worker->GetClothes()->GetPants();
		this->dataGridViewclothes->Rows[2]->Cells[1]->Value = worker->GetClothes()->GetShoes();
		this->dataGridViewclothes->Rows[3]->Cells[1]->Value = worker->GetClothes()->GetClothesStatus();
		this->buysuitbutton->Visible = false;
		worker->ChangeMoney(-5000);
		MoneyBalanceUpdating();
		GameLoss();
	}
	else {
		MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void СourseWorkС::Game::buttonsewup_Click(System::Object^ sender, System::EventArgs^ e)
{
	if ((worker->GetMoneybalance() >= 5 && worker->GetClothes()->GetPants() != "Брюки") || (worker->GetMoneybalance() >= 10 && worker->GetClothes()->GetPants() == "Брюки")) {
		if (worker->GetClothes()->GetClothesStatus() < 100) {
			worker->GetClothes()->SewUpClothes();
			this->dataGridViewclothes->Rows[3]->Cells[1]->Value = worker->GetClothes()->GetClothesStatus();
			if (worker->GetClothes()->GetPants() != "Брюки") {
				worker->ChangeMoney(-5);
			}
			else {
				worker->ChangeMoney(-10);
			}
			MoneyBalanceUpdating();
			GameLoss();
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
	GameLoss();
	if (worker->GetMedCard()->GetHealthStatus() > 0 && worker->GetClothes()->GetClothesStatus() > 0 && worker->GetFood()->GetSatietyStatus() > 0) {
		worker->ChangeMoney(worker->GetPayment());
		MoneyBalanceUpdating();
		DayUpdating();
		if (worker->GetClothes()->GetAutoSewUp() != true) {
			worker->GetClothes()->TearClothes();
			this->dataGridViewclothes->Rows[3]->Cells[1]->Value = worker->GetClothes()->GetClothesStatus();
		}
		if (worker->GetMedCard()->GetInfinityHealth() != true) {
			worker->GetMedCard()->DownStatus();
			HealthUpdating();
		}
		if (worker->GetFood()->GetAutoEating() != true) {
			worker->GetFood()->DownSatietyStatus();
			SatietyUpdating();
		}
		LevelUp();
	}
	else {
		MessageBox::Show("Сейчас вы не можете работать!\nПроверьте состояние здоровья,\n состояние одежды или сытость", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void СourseWorkС::Game::healthbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (worker->GetMoneybalance() >= 10) {
		if (worker->GetMedCard()->GetHealthStatus() < 100) {
			worker->GetMedCard()->UpStatus();
			worker->ChangeMoney(-10);
			MoneyBalanceUpdating();
			HealthUpdating();
			GameLoss();
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
		if (this->comboBoxrealtyhouse->Text == "Квартира (50 000$)") {
			if (worker->GetMoneybalance() >= 50000) {
				worker->GetRealty()->SetHousing("Квартира");
				worker->ChangeMoney(-50000);
				this->comboBoxrealtyhouse->Items->Clear();
				this->comboBoxrealtyhouse->Items->AddRange(gcnew cli::array< System::Object^  >(2) {
					L"Коттедж (120 000$)", L"Вилла (350 000$)"
				});
				this->realtyhouse->Text = worker->GetRealty()->GetHousing();
				MoneyBalanceUpdating();
				DayUpdating();
			}
			else {
				MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		if (this->comboBoxrealtyhouse->Text == "Коттедж (120 000$)") {
			if (worker->GetMoneybalance() >= 120000) {
				worker->GetRealty()->SetHousing("Коттедж");
				worker->ChangeMoney(-120000);
				this->comboBoxrealtyhouse->Items->Clear();
				this->comboBoxrealtyhouse->Items->AddRange(gcnew cli::array< System::Object^  >(2) {
					L"Квартира (50 000$)", L"Вилла (350 000$)"
				});
				this->realtyhouse->Text = worker->GetRealty()->GetHousing();
				MoneyBalanceUpdating();
				DayUpdating();
			}
			else {
				MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		if (this->comboBoxrealtyhouse->Text == "Вилла (350 000$)") {
			if (worker->GetMoneybalance() >= 350000) {
				worker->GetRealty()->SetHousing("Вилла");
				worker->ChangeMoney(-350000);
				this->comboBoxrealtyhouse->Items->Clear();
				this->comboBoxrealtyhouse->Items->AddRange(gcnew cli::array< System::Object^  >(2) {
					L"Квартира (50 000$)", L"Коттедж (120 000$)"
				});
				this->realtyhouse->Text = worker->GetRealty()->GetHousing();
				MoneyBalanceUpdating();
				DayUpdating();
			}
			else {
				MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
	}
	else {
		if (this->comboBoxrealtycar->Text == "Мотоцикл (3 500$)") {
			if (worker->GetMoneybalance() >= 3500) {
				worker->GetRealty()->SetVehicle("Мотоцикл");
				worker->ChangeMoney(-3500);
				this->comboBoxrealtycar->Items->Clear();
				this->comboBoxrealtycar->Items->AddRange(gcnew cli::array< System::Object^  >(2) {
					L"Автомобиль (10 000$)", L"Спорткар (150 000$)"
				});
				this->realtycar->Text = worker->GetRealty()->GetVehicle();
				MoneyBalanceUpdating();
				DayUpdating();
			}
			else {
				MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		if (this->comboBoxrealtycar->Text == "Автомобиль (10 000$)") {
			if (worker->GetMoneybalance() >= 10000) {
				worker->GetRealty()->SetVehicle("Автомобиль");
				worker->ChangeMoney(-10000);
				this->comboBoxrealtycar->Items->Clear();
				this->comboBoxrealtycar->Items->AddRange(gcnew cli::array< System::Object^  >(2) {
					L"Мотоцикл (3 500$)", L"Спорткар (150 000$)"
				});
				this->realtycar->Text = worker->GetRealty()->GetVehicle();
				MoneyBalanceUpdating();
				DayUpdating();
			}
			else {
				MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		if (this->comboBoxrealtycar->Text == "Спорткар (150 000$)") {
			if (worker->GetMoneybalance() >= 150000) {
				worker->GetRealty()->SetVehicle("Спорткар");
				worker->ChangeMoney(-150000);
				this->comboBoxrealtycar->Items->Clear();
				this->comboBoxrealtycar->Items->AddRange(gcnew cli::array< System::Object^  >(2) {
					L"Мотоцикл (3 500$)", L"Автомобиль (10 000$)"
				});
				this->realtycar->Text = worker->GetRealty()->GetVehicle();
				MoneyBalanceUpdating();
				DayUpdating();
			}
			else {
				MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
	}
	GameLoss();
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

System::Void СourseWorkС::Game::onefoodbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (worker->GetMoneybalance() >= 5) {
		if (worker->GetFood()->GetSatietyStatus() < 100) {
			worker->GetFood()->UpSatietyStatus(10);
			SatietyUpdating();
			worker->ChangeMoney(-5);
			MoneyBalanceUpdating();
			GameLoss();
		}
		else {
			MessageBox::Show("Вы абсолютно сытый!", "Зачем?", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	else {
		MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void СourseWorkС::Game::twofoodbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (worker->GetMoneybalance() >= 20) {
		if (worker->GetFood()->GetSatietyStatus() < 100) {
			worker->GetFood()->UpSatietyStatus(25);
			SatietyUpdating();
			worker->ChangeMoney(-20);
			MoneyBalanceUpdating();
			GameLoss();
		}
		else {
			MessageBox::Show("Вы абсолютно сытый!", "Зачем?", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	else {
		MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void СourseWorkС::Game::threebutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (worker->GetMoneybalance() >= 100) {
		if(worker->GetFood()->GetSatietyStatus() < 100) {
			worker->GetFood()->UpSatietyStatus(100);
			SatietyUpdating();
			worker->ChangeMoney(-100);
			MoneyBalanceUpdating();
			GameLoss();
		}
		else {
			MessageBox::Show("Вы абсолютно сытый!", "Зачем?", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	else {
		MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void СourseWorkС::Game::autoeatbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (worker->GetFood()->GetAutoEating() == false) {
		if (worker->GetMoneybalance() >= 50000) {
			System::Windows::Forms::DialogResult result = MessageBox::Show("Автоматическое восполнение сытости позволяет вам больше не беспокоиться о кормлении своего персонажа. Это действие нельзя будет отменить!", "Хотите приобрести антиголод?", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
			if (result == System::Windows::Forms::DialogResult::Yes) {
				this->autoeatbutton->BackColor = System::Drawing::Color::LimeGreen;
				worker->GetFood()->SetAutoEating(true);
				worker->ChangeMoney(-50000);
				SatietyUpdating();
				MoneyBalanceUpdating();
				GameLoss();
			}
		}
		else {
			MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
}

System::Void СourseWorkС::Game::autosewupbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (worker->GetClothes()->GetAutoSewUp() == false) {
		if (worker->GetMoneybalance() >= 100000) {
			System::Windows::Forms::DialogResult result = MessageBox::Show("Автоматическое починка одежды позволяет вам больше не беспокоиться о состоянии одежды своего персонажа. Это действие нельзя будет отменить!", "Хотите приобрести автопочинку одежды?", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
			if (result == System::Windows::Forms::DialogResult::Yes) {
				this->autosewupbutton->BackColor = System::Drawing::Color::LimeGreen;
				worker->GetClothes()->SetAutoSewUp(true);
				this->dataGridViewclothes->Rows[3]->Cells[1]->Value = worker->GetClothes()->GetClothesStatus();
				worker->ChangeMoney(-100000);
				MoneyBalanceUpdating();
				GameLoss();
			}
		}
		else {
			MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
}

System::Void СourseWorkС::Game::autohealthbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (worker->GetMedCard()->GetInfinityHealth() == false) {
		if (worker->GetMoneybalance() >= 150000) {
			System::Windows::Forms::DialogResult result = MessageBox::Show("Автоматическое лечение позволяет вам больше не беспокоиться о состоянии здоровья своего персонажа. Это действие нельзя будет отменить!", "Хотите приобрести автолечение?", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
			if (result == System::Windows::Forms::DialogResult::Yes) {
				this->autohealthbutton->BackColor = System::Drawing::Color::LimeGreen;
				worker->GetMedCard()->SetInfinityHealth(true);
				worker->ChangeMoney(-150000);
				MoneyBalanceUpdating();
				HealthUpdating();
				GameLoss();
			}
		}
		else {
			MessageBox::Show("Недостаточко денег!", "Упс!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
}
