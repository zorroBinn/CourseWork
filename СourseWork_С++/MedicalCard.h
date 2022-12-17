#pragma once
using System::Int32;

ref class MedicalCard
{
private:
	Int32 Weight;
	Int32 Height;
	Int32 HealthStatus;

public:
	MedicalCard();
	Int32 GetWeight();
	void SetWeight(Int32 weight);
	Int32 GetHeight();
	void SetHeight(Int32 height);
	Int32 GetHealthStatus();
	void DownStatus();
	void UpStatus();
};

