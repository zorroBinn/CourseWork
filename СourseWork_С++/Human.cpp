#include "Human.h"


Human::Human()
{
    this->Age = 0;
    this->Name = "test";
    this->Moneybalance = 1000;
    this->Sex = "test";
    this->Level = 0;
}

Int32 Human::GetAge()
{
    return this->Age;
}

void Human::SetAge(Int32 age)
{
    this->Age = age;
}

Int32 Human::GetMoneybalance()
{
    return this->Moneybalance;
}

void Human::SetMoneyBalance(Int32 moneybalance)
{
    this->Moneybalance = moneybalance;
}

String^ Human::GetName()
{
    return this->Name;
}

void Human::SetName(String^ name)
{
    this->Name = name;
}

String^ Human::GetSex()
{
    return this->Sex;
}

void Human::SetSex(String^ sex)
{
    this->Sex = sex;
}

Int32 Human::GetLevel()
{
    return this->Level;
}

void Human::SetLevel(Int32 level)
{
    this->Level = level;
}

void Human::LevelUp()
{
    this->Level++;
}

void Human::ChangeMoney(Int32 money)
{
    this->Moneybalance += money;
}
