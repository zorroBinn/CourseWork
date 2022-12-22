#include "FoodEating.h"

FoodEating::FoodEating()
{
    this->AutoEating = false;
    this->SatietyStatus = 100;
}

bool FoodEating::GetAutoEating()
{
    return this->AutoEating;
}

void FoodEating::SetAutoEating(bool argument)
{
    this->AutoEating = argument;
}

Int32 FoodEating::GetSatietyStatus()
{
    return this->SatietyStatus;
}

void FoodEating::UpSatietyStatus(Int32 argument)
{
    this->SatietyStatus += argument;
    if (this->SatietyStatus > 100) {
        this->SatietyStatus = 100;
    }
}

void FoodEating::DownSatietyStatus()
{
    this->SatietyStatus -= 10;
    if (this->SatietyStatus < 0) {
        this->SatietyStatus = 0;
    }
}
