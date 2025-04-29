#include <stdio.h>

float converte_celsus(float temperatura){
    float temp_convertida = ((temperatura - 32) * 5) / 9; 
    return temp_convertida;
}

int main(){
    float temperatura;
    printf("Entre com a temperatura em Fahrenheit: ");
    scanf("%f", &temperatura);
    
    float r_converte_celsus = converte_celsus(temperatura);
    printf("Temperatura em Celsius: %.2f\n", r_converte_celsus);

    return 0;
}
