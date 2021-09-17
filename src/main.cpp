#include <assert.h>
#include <iostream>
#include "../includes/meteo.h"

int main() {
    Meteo meteo1;
    assert(meteo1.getTemperature() == 0 && meteo1.getPressure() == 0 && meteo1.getWindSpeed() == 0 \
         && meteo1.getWindDirection() == "");
         
    Meteo meteo2(38, 780, 15, "North");
    assert(meteo2.getTemperature() == 38 && meteo2.getPressure() == 780 && meteo2.getWindSpeed() == 15 \
         && meteo2.getWindDirection() == "North");

    Meteo meteo3 = meteo2;
    assert(meteo3.getTemperature() == 38 && meteo3.getPressure() == 780 && meteo3.getWindSpeed() == 15 \
         && meteo3.getWindDirection() == "North");
    
    meteo2.setTemperature(40);
    meteo2.setPressure(800);
    meteo2.setWindSpeed(25);
    meteo2.setWindDirection("East");
    assert(meteo2.getTemperature() == 40 && meteo2.getPressure() == 800 && meteo2.getWindSpeed() == 25 \
         && meteo2.getWindDirection() == "East");
    
}