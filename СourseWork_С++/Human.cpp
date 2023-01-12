#include "Human.h"

//Конструктор без параметров
Human::Human()
{
    this->Age = 0;
    this->Name = "test";
    this->Moneybalance = 100;
    this->Sex = "test";
    this->Level = 0;
    this->MedCard = gcnew MedicalCard();
    this->realty = gcnew Realty();
    this->clothes = gcnew Clothes();
    this->food = gcnew FoodEating();
}

//Геттер возраста
Int32 Human::GetAge()
{
    return this->Age;
}

//Сеттер возраста
void Human::SetAge(Int32 age)
{
    this->Age = age;
}

//Геттер баланса
Int32 Human::GetMoneybalance()
{
    return this->Moneybalance;
}

//Сеттер баланса
void Human::SetMoneyBalance(Int32 moneybalance)
{
    this->Moneybalance = moneybalance;
}

//Геттер имени
String^ Human::GetName()
{
    return this->Name;
}

//Сеттер имени
void Human::SetName(String^ name)
{
    this->Name = name;
}

//Геттер пола
String^ Human::GetSex()
{
    return this->Sex;
}

//Сеттер пола
void Human::SetSex(String^ sex)
{
    this->Sex = sex;
}

//Геттер уровня
Int32 Human::GetLevel()
{
    return this->Level;
}

//Сеттер уровня
void Human::SetLevel(Int32 level)
{
    this->Level = level;
}

//Метод "Повышение уровня"
void Human::LevelUp()
{
    this->Level++;
}

//Метод "Изменить баланс денег"
void Human::ChangeMoney(Int32 money)
{
    this->Moneybalance += money;
    if (this->Moneybalance < 0) {
        this->Moneybalance = 0;
    }
}

//Геттер медицинской карты
MedicalCard^ Human::GetMedCard()
{
    return this->MedCard;
}

//Геттер имущества
Realty^ Human::GetRealty()
{
    return this->realty;
}

//Геттер одежды
Clothes^ Human::GetClothes()
{
    return this->clothes;
}

//Геттер питания
FoodEating^ Human::GetFood()
{
    return this->food;
}
