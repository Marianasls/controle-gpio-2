# controle-gpio-2

# Controle de GPIOs com a Ferramenta BitDogLab

Este projeto consiste no controle de pinos GPIO do microcontrolador RP2040 integrado na ferramenta educacional *BitDogLab* (versão 6.3), utilizando a interface serial UART e programação em linguagem C com o *Pico SDK*. Foram desenvolvidas rotinas para o acionamento de LEDs RGB e buzzer, conforme especificações da tarefa.

## Índice
- [Descrição do Projeto](#descrição-do-projeto)
- [Requisitos](#requisitos)
- [Configuração do Ambiente](#configuração-do-ambiente)
- [Funcionalidades](#funcionalidades)
- [Como Utilizar](#como-utilizar)
- [Estrutura do Repositório](#estrutura-do-repositório)
- [Contribuição](#contribuição)

---

## Descrição do Projeto
O objetivo do projeto é demonstrar o uso prático de GPIOs através da ferramenta *BitDogLab* e realizar a comunicação com o microcontrolador RP2040 utilizando comandos enviados via interface serial UART. Os periféricos controlados incluem:
- *LED RGB* (pinos GPIO 11, 12 e 13);
- *Buzzer* (pino GPIO 21).

As funcionalidades permitem acionar os LEDs com diferentes cores e estados, além de ativar o buzzer por um intervalo de tempo programado.

---

## Requisitos
Para a execução deste projeto, são necessários:
1. *Ferramenta educacional BitDogLab (versão 6.3);*
2. *Cabo micro-USB para USB-A;*
3. *Computador pessoal;*
4. *Software PuTTY* ou equivalente para emulação de terminal serial;
5. *VS Code* com o *Pico SDK* configurado;
6. *Simulador Wokwi* integrado ao VS Code;
7. *GitHub* para versionamento de código.

---

## Configuração do Ambiente
1. Instale o *VS Code* e configure o *Pico SDK* seguindo a [documentação oficial](https://github.com/raspberrypi/pico-sdk).
2. Baixe e configure o simulador *Wokwi*.
3. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/seu-repositorio.git
   cd seu-repositorio

---

## Funcionalidades

As principais rotinas implementadas no projeto são:

1. *Ligar LED Verde (GPIO 11)* – Desliga os demais LEDs.
2. *Ligar LED Azul (GPIO 12)* – Desliga os demais LEDs.
3. *Ligar LED Vermelho (GPIO 13)* – Desliga os demais LEDs.
4. *Ligar os três LEDs (luz branca)* – Todos os LEDs acendem simultaneamente.
5. *Desligar todos os LEDs.*
6. *Acionar o buzzer por 2 segundos.*
7. *Sair do modo de execução e habilitar o modo de gravação via software (opcional).*

---

## Como Utilizar

1. Conecte a ferramenta *BitDogLab* ao computador via cabo micro-USB.
2. Compile o código utilizando o *VS Code*:
   ```bash
   cmake ..
   make
3. *Envie os binários para o microcontrolador.*
4. *Estabeleça a comunicação UART usando o PuTTY:*
   - Configure a porta serial correspondente;
   - Taxa de transmissão: *115200 baud*.
5. *Envie os seguintes comandos para testar as funcionalidades:*
   - LED VERDE – Liga o LED verde.
   - LED AZUL – Liga o LED azul.
   - LED VERMELHO – Liga o LED vermelho.
   - LED BRANCO – Liga todos os LEDs.
   - DESLIGAR – Desliga todos os LEDs.
   - BUZZER – Ativa o buzzer por 2 segundos.
   - SAIR – Reinicia o sistema para gravação.

---

## Estrutura do Repositório

controle-gpio-2/
├── .vscode/               # Configurações do Visual Studio Code
├── .gitignore             # Arquivo de configuração para exclusões no Git
├── CMakeLists.txt         # Arquivo de configuração para o CMake
├── README.md              # Documentação principal do projeto
├── controle-gpio-2.c      # Código-fonte principal do projeto
├── pico_sdk_import.cmake  # Configuração para o uso do SDK do Pico

---

## Contribuição

Para contribuir:

1. Faça um fork do repositório.
2. Crie um branch com a sua funcionalidade:
   ```bash
   git checkout -b minha-funcionalidade
3. *Realize commits descritivos e frequentes.*

4. *Abra um pull request.*
