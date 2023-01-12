#include "FoodEating.h"

//Конструктор без параметров
FoodEating::FoodEating()
{
    this->AutoEating = false;
    this->SatietyStatus = 100;
}

//Геттер показателя автоматического питания
bool FoodEating::GetAutoEating()
{
    return this->AutoEating;
}

//Сеттер показателя автоматического питания
void FoodEating::SetAutoEating(bool argument)
{
    this->AutoEating = argument;
    if (this->AutoEating == true) {
        this->SatietyStatus = 100;
    }
}

//Геттер статуса сытости
Int32 FoodEating::GetSatietyStatus()
{
    return this->SatietyStatus;
}

//Сеттер статуса сытости
void FoodEating::SetSatietyStatus(Int32 argument)
{
    this->SatietyStatus = argument;
}

//Метод "Поднять статус сытости"
void FoodEating::UpSatietyStatus(Int32 argument)
{
    this->SatietyStatus += argument;
    if (this->SatietyStatus > 100) {
        this->SatietyStatus = 100;
    }
}

//Метод "Уменьшить статус сытости"
void FoodEating::DownSatietyStatus()
{
    this->SatietyStatus -= 10;
    if (this->SatietyStatus < 0) {
        this->SatietyStatus = 0;
    }
}
