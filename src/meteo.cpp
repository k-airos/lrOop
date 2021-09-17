#include "../includes/meteo.h"


Meteo::Meteo() {
    this->temperature = 0;
    this->pressure = 0;
    this->windSpeed = 0;
    this->windDirection = "";
}

Meteo::Meteo(int newTemperature, int newPressure, int newWindSpeed, std::string newWindDirection) {
    this->temperature = newTemperature;
    this->pressure = newPressure;
    this->windSpeed = newWindSpeed;
    this->windDirection = newWindDirection;
}

Meteo::Meteo(const Meteo &meteo) {
    temperature = meteo.temperature;
    pressure = meteo.pressure;
    windSpeed = meteo.windSpeed;
    windDirection = meteo.windDirection;
}

void Meteo::setTemperature(int temperature) {
    this->temperature = temperature;
}

void Meteo::setPressure(int pressure) {
    this->pressure = pressure;
}

void Meteo::setWindSpeed(int windSpeed) {
    this->windSpeed = windSpeed;
}

 void Meteo::setWindDirection(std::string windDirection) {
     this->windDirection = windDirection;
 }