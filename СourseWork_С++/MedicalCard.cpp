#include "MedicalCard.h"

MedicalCard::MedicalCard()
{
    this->Weight = 50;
    this->Height = 170;
    this->HealthStatus = 100;
}

Int32 MedicalCard::GetWeight()
{
    return this->Weight;
}

void MedicalCard::SetWeight(Int32 weight)
{
    this->Weight = weight;
}

Int32 MedicalCard::GetHeight()
{
    return this->Height;
}

void MedicalCard::SetHeight(Int32 height)
{

    this->Height = height;
}

Int32 MedicalCard::GetHealthStatus()
{
    return this->HealthStatus;
}

void MedicalCard::DownStatus()
{
    if (this->HealthStatus > 0) {
        this->HealthStatus -= 5;
        if (this->HealthStatus < 0) {
            this->HealthStatus = 0;
        }
    }
}

void MedicalCard::UpStatus()
{
    if (this->HealthStatus < 100) {
        this->HealthStatus += 30;
        if (this->HealthStatus > 100) {
            this->HealthStatus = 100;
        }
    }
}