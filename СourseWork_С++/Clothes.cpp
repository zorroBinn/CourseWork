#include "Clothes.h"

Clothes::Clothes()
{
    this->Body = "Ìàéêà";
    this->Pants = "Òðóñû";
    this->Shoes = "Òàïêè";
    this->ClothesStatus = 100;
    this->AutoSewUp = false;
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
    if (this->Pants != "Áðþêè") {
        this->ClothesStatus -= 7;
    }
    else {
        this->ClothesStatus -= 3;
    }
    if (this->ClothesStatus < 0) {
        this->ClothesStatus = 0;
    }
}

void Clothes::BuySuit()
{
    this->Body = "Ïèäæàê";
    this->Pants = "Áðþêè";
    this->Shoes = "Òóôëè";
    this->ClothesStatus = 100;
}

bool Clothes::GetAutoSewUp()
{
    return this->AutoSewUp;
}

void Clothes::SetAutoSewUp(bool argument)
{
    this->AutoSewUp = argument;
    if (this->AutoSewUp == true) {
        this->ClothesStatus = 100;
    }
}
