#pragma once
using System::Int32;

ref class MedicalCard
{
private:
	bool InfinityHealth;
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
	void SetHealthStatus(Int32 status);
	void DownStatus();
	void UpStatus();
	bool GetInfinityHealth();
	void SetInfinityHealth(bool argument);
};

