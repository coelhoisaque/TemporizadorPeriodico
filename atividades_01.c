#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos pinos dos LEDs
#define VERMELHO 11
#define AMARELO 12
#define VERDE 13

volatile uint8_t estado = 0; // Controla os estados do semáforo

// Função de callback do temporizador
bool altera_semaforo(struct repeating_timer *t) {
    // Desliga todos os LEDs primeiro
    gpio_put(VERMELHO, 0);
    gpio_put(AMARELO, 0);
    gpio_put(VERDE, 0);

    // Lógica de transição de estados
    switch(estado) {
        case 0:    // Verde -> Amarelo
            gpio_put(AMARELO, 1);
            estado = 1;
            break;
            
        case 1:    // Amarelo -> Vermelho
            gpio_put(VERMELHO, 1);
            estado = 2;
            break;
            
        case 2:    // Vermelho -> Verde
            gpio_put(VERDE, 1);
            estado = 0;
            break;
    }
    return true; // Mantém o temporizador ativo
}

int main() {
    stdio_init_all();
    
    // Configuração dos pinos
    gpio_init(VERMELHO);
    gpio_init(AMARELO);
    gpio_init(VERDE);
    
    gpio_set_dir(VERMELHO, GPIO_OUT);
    gpio_set_dir(AMARELO, GPIO_OUT);
    gpio_set_dir(VERDE, GPIO_OUT);

    // Estado inicial: Verde ligado
    gpio_put(VERDE, 1);
    
    // Configura temporizador periódico de 3000ms (3 segundos)
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, altera_semaforo, NULL, &timer);

    while(1) {
        tight_loop_contents(); // Reduz consumo de energia
    }
}