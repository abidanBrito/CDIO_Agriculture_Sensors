/*  ------------------------------------------------------------------------
    AUTHOR:         Abidan Brito Clavijo
    FILE:           TemperatureSensor.h
    DATE:           02/01/2020
    STATE:          DONE
    FUNCTIONALITY:  Temperature sensor class definition.
    ------------------------------------------------------------------------
    NOTICE: (C) Copyright 2019 by Abidan Brito Clavijo. All rights reserved.
    ------------------------------------------------------------------------ */

#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#ifndef ADCAPI_H
#define ADCAPI_H
#include <Adafruit_ADS1015.h>
#endif

// ---------------------------------------------------
// Temperature sensor class definition.
// ---------------------------------------------------
class TemperatureSensor {
private:
    Adafruit_ADS1115 * adcAddress;
    unsigned int outputPin;
    double slope;
    double dTemp;
    double yIntercept;

// MEMBER FUNCTIONS - DECLARATIONS
private:
    int16_t readADC() const;                                // Return ADC reading.
    double voltageToTemperature(double voltage,
                                double slope,
                                double dTemp,
                                double yIntercept) const;   // Return voltage value from ADC reading.
    double mapFloatingPoint(int16_t adcReading,
                            double newlowerBound,
                            double newUpperBound) const;    // Floating-point compliant "map()".
public:
    TemperatureSensor(Adafruit_ADS1115 * adcAddress,
                      unsigned int outputPin,
                      double slope,
                      double dTemp,
                      double yIntercept);   // Default constructor.
    double getTemperature() const;          // Return temperature (º C).
    void printCalibrationReading() const;   // Print voltage value for calibration.
};

#endif
