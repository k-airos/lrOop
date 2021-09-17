#ifndef METEO_H
#define METEO_H

#include <string>

class Meteo{
private:
    int temperature;
    int pressure;
    int windSpeed;
    std::string windDirection;
public:
    Meteo();

    Meteo(int temperature, int pressure, int windSpeed, std::string windDirection);

    Meteo(const Meteo &meteo);

    int getTemperature() const {
        return temperature;
    }

    int getPressure() {
        return pressure;
    }

    int getWindSpeed() {
        return windSpeed;
    }

    std::string getWindDirection() {
        return windDirection;
    }

    void setTemperature(int temperature);
    void setPressure(int pressure);
    void setWindSpeed(int windSpeed);
    void setWindDirection(std::string windDirection);
};


#endif  

