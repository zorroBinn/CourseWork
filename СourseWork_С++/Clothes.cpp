#include "Clothes.h"

Clothes::Clothes()
{
    this->Body = "Майка";
    this->Pants = "Трусы";
    this->Shoes = "Тапки";
    this->ClothesStatus = 100;
}

Clothes::Clothes(String^ Body, String^ Pants, String^ Shoes)
{
    this->Body = Body;
    this->Pants = Pants;
    this->Shoes = Shoes;
    this->ClothesStatus = 100;
}

String^ Clothes::GetBody()
{
    return this->Body;
}

void Clothes::SetBody(String^ body)
{
    this->Body = body;
}

String^ Clothes::GetPants()
{
    return this->Pants;
}

void Clothes::SetPants(String^ pants)
{
    this->Pants = pants;
}

String^ Clothes::GetShoes()
{
    return this->Shoes;
}

void Clothes::SetShoes(String^ shoes)
{
    this->Shoes = shoes;
}

Int32 Clothes::GetClothesStatus()
{
    return this->ClothesStatus;
}

void Clothes::SetClothesStatus(Int32 status)
{
    this->ClothesStatus = status;
}

void Clothes::SewUpClothes()
{
    if (this->ClothesStatus < 100) {
        this->ClothesStatus += 15;
        if (this->ClothesStatus > 100) {
            this->ClothesStatus = 100;
        }
    }
}

void Clothes::TearClothes()
{
    if (this->ClothesStatus > 0) {
        this->ClothesStatus -= 7;
        if (this->ClothesStatus < 0) {
            this->ClothesStatus = 0;
        }
    }
}

void Clothes::BuySuit()
{
    this->Body = "Пиджак";
    this->Pants = "Брюки";
    this->Shoes = "Туфли";
    this->ClothesStatus = 100;
}
