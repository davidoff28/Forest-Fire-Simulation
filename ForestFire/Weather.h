#ifndef WEATHER_H
#define WEATHER_H

/// <summary>
/// The type of weather. CLEAR, SUNNY and RAINING.
/// </summary>
enum WeatherType
{
	CLEAR = 0,
	SUNNY = 1,
	RAINING = 2
};

/// <summary>
/// Controls the effect of the weather type. Weather type affects the burn chance of Cells.
/// </summary>
class Weather
{
public:
	/// <summary>
	/// Constructs a Weather object. The weather type is set to CLEAR.
	/// </summary>
	Weather(void);

	/// <summary>
	/// Constructs a Weather with a weather type.
	/// </summary>
	/// <param name="weatherType">The type of weather.</param>
	Weather(const WeatherType& weatherType);

	/// <summary>
	/// Returns the weather type of this Weather.
	/// </summary>
	/// <returns>The weather type.</returns>
	WeatherType GetWeatherType(void) const;

	/// <summary>
	/// Returns the weather type by its index of this Weather.
	/// </summary>
	/// <param name="index">The weather index.</param>
	/// <returns>The weather type.</returns>
	WeatherType GetWeatherType(const int index) const;

	/// <summary>
	/// Sets the weather type for this Weather.
	/// </summary>
	/// <param name="weatherType">The weather type.</param>
	void SetWeathertype(const WeatherType& weatherType);

	/// <summary>
	/// Returns the burn chance of the weather type.
	/// </summary>
	/// <returns>The burn chance of the weather type.</returns>
	float WeatherEffect(void);

private:
	WeatherType weatherType;
	float burnChance;
};

#endif