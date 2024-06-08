#include "arduinoFFT.h"
 
#define SAMPLES 256             
#define SAMPLING_FREQUENCY 1000 
arduinoFFT FFT = arduinoFFT();
unsigned int samplingPeriod;
unsigned long microseconds;
double vReal[SAMPLES];
double vImag[SAMPLES];
 
void setup() {
    Serial.begin(115200);
    samplingPeriod = round(1000000*(1.0/SAMPLING_FREQUENCY));
}
 
void loop() {
    for(int i=0; i<SAMPLES; i++)
    {
        microseconds = micros();  
        vReal[i] = analogRead(2);
        vImag[i] = 0;     
        while(micros() < (microseconds + samplingPeriod)){
        }
    }
 
    FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
    FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
    FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);
    double peak = FFT.MajorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);
    //Serial.println(peak);     //Print out what frequency is the most dominant.
    for(int i=0; i<(SAMPLES/2); i++)
    {
        /*View all these three lines in serial terminal to see which frequencies has which amplitudes*/  
        //Serial.print((i * 1.0 * SAMPLING_FREQUENCY) / SAMPLES, 1);
        //Serial.print(" ");
        /*View only this line in serial plotter to visualize the bins*/
        Serial.println(vReal[i], 1);    
    }
    delay(1000);       
}
