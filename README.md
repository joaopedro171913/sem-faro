Esses são os codigo que eu utilizei para poder simular o meu semáforo. o arquivo "samaforo.cpp" é o meu código que eu ultilizei para fazer o semáforo, o arquivo "avr-gpio.cpp"
o motivo desse arquivo é porque eu criei ele como  função de uma biblioteca, e essa biblioteca tem como função de (atribuir a saída do registrador dos pinos e também poder fazer
a parte do desligamento dos leds, a função "gpio-setmode" ele faz a função de saída, "gpio-write" e esse faz a função dos desligamentos dos leds. o motivo de eu fazer isso foi
por motivos de facilitar o código e fazer com que o código não fique muito grande. Nesses dois arquivos que eu coloquei, "semaforo fredi.pzw" esse é o codigo rodando no PICsimLab-Arduino-UNO
e a o arquivo "semáforofredi.hex" é o código convertido em hexadecimal. Fazendo funcionar o semáforo funcionar...
