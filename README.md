# SoC estimation of LiFePo4

In this project, we need to estimate the SoC(State of Charge) of 4 [LiFePo4 batteries](https://robu.in/product/orange-ifr18650-1500mah-lifepo4-battery/?gclid=CjwKCAiAlrSPBhBaEiwAuLSDUPGNGajKmz2qf9B3RZyCmFzpsHOVYuG1YtfwBlMRtC95PU2fWeGWNxoCoFoQAvD_BwE) in series.

Battery Banks form the power sources for the ‘uninterrupted power supplies (UPS)’, electrical vehicles and many more applications. Many of the modern battery banks are made up of LiFePO4 batteries cells. The operation of these battery banks are managed by ‘battery Management Systems (BMS)’. One of the main functions of the BMS systems is controlling the charger operations, for which the SoC must be known in ‘real time’.   

The SoC is a parameter giving the amount of the charge on the battery (or Cell) expressed as a fraction (or %) of the full battery capacity.


For this purpose, it is required to perform the measurement of terminal voltages of all the batteries, string current and compute the SoC with suitable computing platform. The computations are performed on Atemga328P.



