int limite, numero2, suma_numeros_amigos = 0, suma_divisores_num2;
  

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  suma_numeros_amigos=0;
  Serial.println("Ingrese un numero limite: ");
  while (!Serial.available()) {
    // Espero a que se ingrese un número por el monitor serial
  }
  limite = Serial.parseInt(); // Leo el número ingresado

  for (int numero1 = 220; numero1 < limite; numero1++) {
    numero2 = SumaDeDivisores(numero1);
    suma_divisores_num2 = SumaDeDivisores(numero2);
    if (suma_divisores_num2 == numero1 && numero1 != numero2) {
      suma_numeros_amigos += numero1;
    }
  }
  if (suma_numeros_amigos == 0) {
    Serial.println("No hay numeros amigos menores al numero ingresado");
  } else {
    Serial.print("La suma de los numeros amigos menores que ");
    Serial.print(limite);
    Serial.print(" es ");
    Serial.println(suma_numeros_amigos);
  }
}

int SumaDeDivisores(int numero) {
  int suma = 0;
  for (int i = 1; i <= numero / 2; i++) {
    if (numero % i == 0) {
      suma += i;
    }
  }
  return suma;
}
