#include "Realty.h"

//Конструктор без параметров
Realty::Realty()
{
    this->Housing = "Гараж";
    this->Vehicle = "Велик";
}

//Геттер недвижимости
String^ Realty::GetHousing()
{
    return this->Housing;
}

//Сеттер недвижимости
void Realty::SetHousing(String^ housing)
{
    this->Housing = housing;
}

//Геттер транспортного средства
String^ Realty::GetVehicle()
{
    return this->Vehicle;
}

//Сеттер транспортного средства
void Realty::SetVehicle(String^ vehicle)
{
    this->Vehicle = vehicle;
}
