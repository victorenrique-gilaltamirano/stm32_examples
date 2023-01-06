# STM32 Templates

This templates are based on the book "stm32 Microcontroller - Programming and Development" located in [here](https://drive.google.com/file/d/1WbbreLDAR6WvoAmFCadmCWHDoyuoGC_S/view?usp=sharing).


## Note for Timer configuration
Quick guide on how to define values for Preescaler and Counter Period:

1. Let's suppose the clock cycle = 48MHz.
2. We want to bring this clock into the ms units.
3. 48000000ticks is 1s
4. 48000ticks is 1ms, therefore, Preescaler value = 48000.
5. Counter Period = 1000.
6. Timer will be clicking every second, which means everytime it reaches counto of 1000.
7. For setting a Timer to tick every 200ms (for example), then Counter Period = 200, and so on.
