// Nama: Nathan Praja Kusuma
// RPM Motor akan menyesuaikan dengan input yang diberikan pada serial monitor

#define pinMotorA 4   // set pin 4 sebagai pinMotorA digital
#define pinMotorB 3   // set pin 3 sebagai pinMotorB PWM
int nilaiAnalog;      // declare variabel nilaiAnalog untuk menampung nilai int 
               

void setup()
{
  pinMode(pinMotorA, OUTPUT); // set mode pinMotorA sbg output
  pinMode(pinMotorB, OUTPUT); // set mode pinMotorB sbg output
  Serial.begin(9600);         // inisialisasi serial 
  nilaiAnalog = 0;            // set nilaiAnalog = 0;
}

void loop()
{
  // mengecek ketersediaan data pada serial
  if (Serial.available() > 0) {     
    nilaiAnalog = Serial.parseInt();  // jika terdapat data, maka akan disimpan dalam nilaiAnalog
    Serial.println(nilaiAnalog);    // print data nilaiAnalog agar dapat dilihat di monitor
    analogWrite(pinMotorB, nilaiAnalog);  // set data pada nilaiAnalog sebagai parameter pinMotorB (PWM). Untuk RPM tinggi = 0, RPM rendah/mati = 255
  }
  digitalWrite(pinMotorA, HIGH);  // set pinMotorA (digital) ke HIGH
}
