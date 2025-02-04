# Semáforo com Raspberry Pi Pico W

## Descrição
Este projeto implementa um semáforo utilizando um microcontrolador Raspberry Pi Pico W. O semáforo muda de estado a cada 3 segundos seguindo a sequência:
- **Verde** -> **Amarelo** -> **Vermelho** -> **Verde**

A mudança de estado é realizada utilizando a função `add_repeating_timer_ms()` do Pico SDK.

## Requisitos
Para realizar a simulação e execução deste projeto, são necessários os seguintes componentes:
- Microcontrolador **Raspberry Pi Pico W**
- **3 LEDs** (Vermelho, Amarelo e Verde)
- **3 Resistores de 330 Ω**
- Ambiente de desenvolvimento **VS Code** com **Pico SDK**
- Simulador **Wokwi** integrado ao VS Code
- Ferramenta Educacional **BitDogLab**

## Configuração do Hardware
Os LEDs estão conectados aos seguintes pinos GPIO:
- **Vermelho**: GPIO 11
- **Amarelo**: GPIO 12
- **Verde**: GPIO 13

Cada LED deve ser conectado em série com um resistor de 330 Ω para limitar a corrente.

## Instalação e Execução
### Clonando o Repositório
```sh
git clone 
cd 
```

### Compilando o Código
1. Instale o **Pico SDK** e configure o ambiente.
2. Certifique-se de que o Raspberry Pi Pico SDK está corretamente instalado e configurado no seu ambiente de desenvolvimento.
3. Compile e carregue o código no microcontrolador.:
4. Conectar a placa BitDogLab ao seu computador.
5. Enviar o arquivo ws2812.uf2 gerado para a placa.

### Executando no Wokwi
1. Abra o **Wokwi** e carregue o código.
2. Configure os pinos conforme a descrição acima.
3. Execute a simulação.

## Estrutura do Código
O programa segue a lógica de alteração dos LEDs dentro da função `altera_semaforo()`, que é acionada pelo temporizador periódico. A função `main()` inicializa os pinos, configura o temporizador e mantém o loop principal do programa.

## Testes e Validação
- Testes foram realizados no **Wokwi** para garantir a correta transição dos LEDs.
- A ferramenta **BitDogLab** foi utilizada para validar o funcionamento com um LED RGB (GPIOs 11, 12 e 13).
- A execução do código foi monitorada via porta serial para verificar mensagens de depuração.

---
*Este projeto faz parte das atividades acadêmicas para aprendizagem de microcontroladores utilizando o Raspberry Pi Pico W.*

