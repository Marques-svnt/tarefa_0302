# Projeto: Interface de Comunicação Serial com RP2040

## Descrição
Este projeto utiliza a placa BitDogLab baseada no microcontrolador RP2040 para demonstrar a comunicação serial e manipulação de componentes periféricos. Ele explora técnicas de controle de LEDs, interação com botões com debounce por software e utiliza os protocolos UART e I2C para integração de dispositivos.

---

## Funcionalidades

### Tarefa 1: Exibição de Caracteres via UART
- **Entrada de Dados pelo Serial Monitor:**
  - Cada caractere digitado é exibido no display SSD1306.
  - Números entre `0` e `9` ativam padrões específicos na matriz de LEDs WS2812.

### Tarefa 2: Interação com Botões
- **Botão A:**
  - Alterna o estado do LED RGB verde (ligado/desligado).
  - Exibe uma mensagem informativa no display SSD1306.
  - Envia uma mensagem descritiva ao Serial Monitor.
- **Botão B:**
  - Alterna o estado do LED RGB azul (ligado/desligado).
  - Exibe uma mensagem informativa no display SSD1306.
  - Envia uma mensagem descritiva ao Serial Monitor.

---

## Requisitos

- Placa BitDogLab com microcontrolador RP2040
- Matriz de LEDs WS2812
- LED RGB
- Display SSD1306
- Botões A e B conectados aos GPIOs configurados
- Ambiente de desenvolvimento configurado com Pico SDK
- VS Code com suporte para Raspberry Pi Pico

---

## Configuração

### Mapeamento de GPIOs

| Componente    | GPIO |
|---------------|------|
| Matriz WS2812 | GPIO 7 |
| LED RGB       | GPIOs 11, 12, 13 |
| Botão A      | GPIO 5  |
| Botão B      | GPIO 6  |
| Display SSD1306 | GPIOs 14, 15 |

---

## Compilação e Execução

1. Certifique-se de que o SDK do RP2040 está configurado no seu ambiente.
2. Compile o programa utilizando a extensão **Raspberry Pi Pico Project** no VS Code:
   - Abra o projeto no VS Code.
   - Navegue até a extensão do **Raspberry Pi Pico Project** e clique em **Compile Project**.
3. Coloque a placa em modo boot cell e copie o arquivo `main.uf2`, que está na pasta build, para o microcontrolador conectado via USB.

---

## Emulação com Wokwi

Para testar o programa sem hardware físico, você pode utilizar o **Wokwi** para emulação no VS Code:

1. Instale a extensão **Wokwi for VS Code**.
2. Inicie a emulação:
   - Configure os componentes conforme a especificação das atividades.
3. Teste o funcionamento do programa diretamente no ambiente emulado.

---

## Demonstração no YouTube

Confira a demonstração completa deste projeto no YouTube: [Demonstração do Projeto]()

---

## Colaboradores

- [Gabriel Marques](https://github.com/Marques-svnt)

---

## Licença

Este projeto está licenciado sob a [MIT License](LICENSE).

