#include "Weather.h"

#pragma region Constructors
Weather::Weather(void)
{
	weatherType = CLEAR;
}

Weather::Weather(const WeatherType& weatherType)
{
	this->weatherType = weatherType;
}
#pragma endregion Constructors

#pragma region Public Methods
WeatherType Weather::GetWeatherType(void) const
{
	return weatherType;
}

WeatherType Weather::GetWeatherType(const int index) const
{
	WeatherType type;
	if (index < 0 || index > 2 || index == 0) type = CLEAR;
	else if (index == 1) type = SUNNY;
	else if (index == 2) type = RAINING;
	return type;
}

void Weather::SetWeathertype(const WeatherType& weatherType)
{
	this->weatherType = weatherType;
}

float Weather::WeatherEffect(void)
{
	if (weatherType == CLEAR)	burnChance = 0.5f;
	else if (weatherType == SUNNY)	burnChance = 0.75f;
	else if (weatherType == RAINING)	burnChance = 0.25f;
	return burnChance;
}
#pragma endregion Public Methods