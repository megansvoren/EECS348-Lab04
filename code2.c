#include <stdio.h>
void categorize_temperature(float temp)
{
    if (temp < 0)
    {
        printf("\nTemperature category: Freezing\nWeather advisory: Stay indoors");
    }
    else if (temp < 10)
    {
        printf("\nTemperature category: Cold\nWeather advisory: Wear a jacket");
    }
    else if (temp < 25)
    {
        printf("\nTemperature category: Comfortable\nWeather advisory: You should feel comfortable");
    }
    else if (temp < 35)
    {
        printf("\nTemperature category: Hot\nWeather advisory: Wear light clothing");
    }
    else
    {
        printf("\nTemperature category: Extreme Heat\nWeather advisory: Stay indoors");
    }
}

float celsius_to_fahrenheit(float temp)
{
    float newTemp = (9.0 / 5.0) * temp + 32.0;
    return newTemp;
}

float celsius_to_kelvin(float temp)
{
    float newTemp = temp + 273.15;
    return newTemp;
}

float fahrenheit_to_celsius(float temp)
{
    float newTemp = (5.0 / 9.0) * (temp - 32.0);
    return newTemp;
}

float fahrenheit_to_kelvin(float temp)
{
    float newTemp = (temp - 32.0) * (5.0 / 9.0) + 273.15;
    return newTemp;
}

float kelvin_to_celsius(float temp)
{
    float newTemp = temp - 273.15;
    return newTemp;
}

float kelvin_to_fahrenheit(float temp)
{
    float newTemp = (temp - 273.15) * (9.0 / 5.0) + 32.0;
    return newTemp;
}



int main()
{
    float temp;
    float newTemp;
    int inputTempScale;
    int conversionTempScale;

    while (1)
    {
        printf("\nEnter the temperature: ");
        scanf("%f", &temp);
        printf("\nChoose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &inputTempScale);
        if (inputTempScale == 3 && temp < 0)
        {
            printf("\nKelvin temperature cannot be below 0. Try again. ");
            continue;
        }
        printf("\nConvert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &conversionTempScale);
        if (inputTempScale == conversionTempScale)
        {
            printf("\nCannot convert from %d to %d. Try again.", inputTempScale, conversionTempScale);
            continue;
        }
        else if (conversionTempScale < 1 || conversionTempScale > 3)
        {
            printf("\nInvalid conversion choice. Try again.");
            continue;
        }
        break;
    }
    if (inputTempScale == 1)
        {
            if (conversionTempScale == 2)
            {
                newTemp = celsius_to_fahrenheit(temp);
            }
            else if (conversionTempScale == 3)
            {
                newTemp = celsius_to_kelvin(temp);
            }
            printf("\nConverted temperature: %f", newTemp);
            categorize_temperature(temp);
        }
        else if (inputTempScale == 2)
        {
            if (conversionTempScale == 1)
            {
                newTemp = fahrenheit_to_celsius(temp);
            }
            else if (conversionTempScale == 3)
            {
                newTemp = fahrenheit_to_kelvin(temp);
            }
            printf("\nConverted temperature: %f", newTemp);
            categorize_temperature(fahrenheit_to_celsius(temp));
        }
        else if (inputTempScale == 3)
        {
            if (conversionTempScale == 1)
            {
                newTemp = kelvin_to_celsius(temp);
            }
            else if (conversionTempScale == 2)
            {
                newTemp = kelvin_to_fahrenheit(temp);
            }
            printf("\nConverted temperature: %f", newTemp);
            categorize_temperature(kelvin_to_celsius(temp));
        }
}