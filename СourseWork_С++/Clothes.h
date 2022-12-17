#pragma once
using System::String;
using System::Int32;

ref class Clothes
{
private:
	String^ Body;
	String^ Pants;
	String^ Shoes;
	Int32 ClothesStatus;

public:
	Clothes();
	Clothes(String^ Body, String^ Pants, String^ Shoes);
	String^ GetBody();
	void SetBody(String^ body);
	String^ GetPants();
	void SetPants(String^ pants);
	String^ GetShoes();
	void SetShoes(String^ shoes);
	Int32 GetClothesStatus();
	void SetClothesStatus(Int32 status);
	void SewUpClothes();
	void TearClothes();
	void BuySuit();
};

