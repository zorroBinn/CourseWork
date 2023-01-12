#include "MedicalCard.h"

//Конструктор без параметров
MedicalCard::MedicalCard()
{
    this->Weight = 50;
    this->Height = 170;
    this->HealthStatus = 100;
    this->InfinityHealth = false;
}

//Геттер веса
Int32 MedicalCard::GetWeight()
{
    return this->Weight;
}

//Сеттер веса
void MedicalCard::SetWeight(Int32 weight)
{
    this->Weight = weight;
}

//Геттер роста
Int32 MedicalCard::GetHeight()
{
    return this->Height;
}

//Сеттер роста
void MedicalCard::SetHeight(Int32 height)
{
    this->Height = height;
}

//Геттер статуса здоровья
Int32 MedicalCard::GetHealthStatus()
{
    return this->HealthStatus;
}

//Сеттер статуса здоровья
void MedicalCard::SetHealthStatus(Int32 status)
{
    this->HealthStatus = status;
}

//Метод "Уменьшить статус здоровья"
void MedicalCard::DownStatus()
{
    if (this->HealthStatus > 0) {
        this->HealthStatus -= 5;
        if (this->HealthStatus < 0) {
            this->HealthStatus = 0;
        }
    }
}

//Метод "Поднять статус здоровья"
void MedicalCard::UpStatus()
{
    if (this->HealthStatus < 100) {
        this->HealthStatus += 35;
        if (this->HealthStatus > 100) {
            this->HealthStatus = 100;
        }
    }
}

//Геттер показателя бесконечного здоровья (автолечения)
bool MedicalCard::GetInfinityHealth()
{
    return this->InfinityHealth;
}

//Сеттер показателя бесконечного здоровья (автолечения)
void MedicalCard::SetInfinityHealth(bool argument)
{
    this->InfinityHealth = argument;
    if (this->InfinityHealth == true) {
        this->HealthStatus = 100;
    }
}
