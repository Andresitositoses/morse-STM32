# morse-STM32

La librería implementada permite generar mensajes en código Morse a partir de cadenas de texto en placas de desarrollo STM32. Para ello, simplemente se alterna la señal de un *GPIO* y se provocan una serie de retardos que se corresponden con puntos y rayas (elementos del código Morse).

# Utilización de la librería

Toda la configuración de esta librería se encuentra en el fichero **morse.h**, donde aparecen parámetros de configuración que permiten establecer el pin *GPIO*, así como los distintos retardos en la señal. El usuario únicamente deberá llamar a la función *morse*, pasando como parámetro el mensaje a comunicar por el dispositivo. Por otro lado, es importante incluir la librería de abstracción del *hardware* de la placa STM32 que se esté utilizando. En mi caso requería de la capa *HAL* de la placa de desarrollo STM32L432KC.

A modo de ejemplo, en el fichero *main.c* se encuentra el código de ejecución de la placa de desarrollo STM32L432KC, donde se realiza una llamada a la función *morse* con el mensaje "sos" pasado como parámetro.

```
int main(void) {
  HAL_Init();
  
  ...
  
  /* Infinite loop */ 
	/* USER CODE BEGIN WHILE */ 
	while (1) { 
		/* USER CODE END WHILE */ 
 
		/* USER CODE BEGIN 3 */ 
    
		morse("sos"); 
    
		HAL_Delay(5000); 
	} 
	/* USER CODE END 3 */
}
```

Finalmente, teniendo conectada la placa a nuestro ordenador, bastará con compilar y generar el código desde STM32CubeIDE.

**\*Nota:\*** Solamente se considerarán letras en minúsculas y sin tildes.

Vídeo de ejemplo: https://youtu.be/74bjN73hgNo
