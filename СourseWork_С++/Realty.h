#pragma once
using System::String;
using System::Int32;

ref class Realty
{
	String^ Housing;
	String^ Vehicle;

public:
	Realty();
	String^ GetHousing();
	void SetHousing(String^ housing);
	String^ GetVehicle();
	void SetVehicle(String^ vehicle);
};

