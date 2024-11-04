const byte npulse = 12; // número de pulsos para cargar el capacitor antes de cada medición

const byte pin_pulse = A0; // PIN Analógico carga el capacitor con pulsos
const byte pin_cap = A1; // PIN Analógico que mide la carga del capacitor
const byte pin_LED = 12; // LED indicando cuando detecta el metal

void setup()
{
    pinMode(pin_pulse, OUTPUT);
    digitalWrite(pin_pulse, LOW);
    pinMode(pin_cap, INPUT);
    pinMode(pin_LED, OUTPUT);
    digitalWrite(pin_LED, LOW);
}

const int nmeas = 256; // measurements to take
long int sumsum = 0; // running sum of 64 sums
long int skip = 0; // number of skipped sums
long int diff = 0; // difference between sum and avgsum
long int flash_period = 0; // period (in ms)
long unsigned int prev_flash = 0; // time stamp of previous flash

void loop()
{
    int minval = 2000;

    // realiza la medición
    for (int imeas = 0; imeas < nmeas + 2; imeas++) {
        // reseteando y condensando
        digitalWrite(pin_cap, OUTPUT);
        digitalWrite(pin_cap, LOW);
        delayMicroseconds(20);
        pinMode(pin_cap, INPUT);
        digitalWrite(pin_pulse, HIGH);
        delayMicroseconds(20);
        digitalWrite(pin_pulse, LOW);
        delayMicroseconds(1);
        int t = micros();
        while (digitalRead(pin_cap) == LOW) {
            if ((micros() - t) > minval) break;
        }
        int val = micros() - t;
        if (imeas >= 2) {
            sumsum += val;
            if (val < minval) minval = val;
        }
    }

    // calcula la diferencia
    long int avgsum = sumsum / nmeas;
    diff = avgsum - minval;

    // parpadea el LED si detecta metal
    if (diff > 100) {
        digitalWrite(pin_LED, HIGH);
        flash_period = 100;
    } else {
        digitalWrite(pin_LED, LOW);
        flash_period = 1000;
    }

    // espera antes de la siguiente medición
    delay(flash_period);
}
