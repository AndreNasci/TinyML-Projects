# TinyML - Fan Motion Detection 

## Proposta 
Criar um modelo de *machine learning* para o *deploy* em um dispositivo embarcado, capaz de classificar dados de vibração provenientes de um ventilador. O propósito é inferir se ele está desligado ou ligado, com alta ou baixa potência e com o modo *swing* ligado ou desligado. A ideia é que a intensidade das vibrações podem ser passadas pela carcaça do ventilador até a placa e, assim, ser feita a leitura.

## Setup
A placa de desenvolvimento utilizada foi um **Arduino Nano 33 BLE Sense**. Ela foi fixada ao ventilador, sobre a carcaça do motor, por meio de fita adesiva. Isso foi feito de forma que sempre estivesse em contato direto com a estrutura do ventilador e uma abetura foi feita para que o LED RGB ficasse à mostra para fácil identificação.

## Data Collection
Após conectar o dispositivo ao Edge Impulse, foram coletados dados nas seguintes categorias:

1. OFF - ventilador desligado.
2. LOW - ventilador ligado na potência baixa.
3. LOW - SWING - ventilador ligado na potência baixa com modo swing ativo.
4. HIGH - ventilador ligado na potência máxima.
5. HIGH - SWING - ventilador ligado na potência máxima com modo swing ativo.
  
Foram coletadas 14 amostras de 5 segundos para cada classe, com frequência de 100 Hz, utilizando o sensor inercial. Dessas amostras, 77% foram usadas pra treino de modelo e 23% para teste.

## Impulse design
O modelo foi treinado com auxílio da plataforma EdgeImpulse. Foram usadas as recomendações do EdgeImpulse nessa sessão. Janelas de amostras de 2 segundos, window increase de 200ms, frequência de 100 Hz e zero-padding ativado. Como bloco processador foi usado o “Spectral Analysis”, e foram utilizados apenas os eixos relacionados ao acelerômetro do sensor inercial. Por fim, o modelo escolhido foi um modelo classificador recomendado pela plataforma.

## Feature extraction
Optou-se por usar o “Autotune parameters” do EI para calcular os parâmetros necessários para o filtro e para a FFT. A FFT resultante é de tamanho 32. 
Esse processo permitiu a redução da quantidade de *features* de 600 para 60. De acordo com a ferramenta “Feature Explorer”, que permite visualizar graficamente os dados, o conjunto apresentou boa diferenciabilidade, o que é algo positivo para o treinamento. 

## Classifier
O modelo foi criado seguindo as recomendações e arquitetura que o próprio EI forneceu, com 30 épocas, learning rate de 0,0005 e duas camadas internas, com 20 e 10 neurônios  respectivamente. A acurácia e a perda obtida pós treinamento foi de 88,4% e 0,31, respectivamente.

## Testing
Como esperado, os testes do modelo resultaram em uma acurácia inferior, de 84,38%. Além disso, no teste com os dados de teste é possível notar uma significativa confusão entre os modos HIGH e HIGH-SWING e uma leve confusão entre os estados LOW e LOW-SWING. Essa mesma dificuldade pode ser notada nos testes de bancada, como demonstrado no vídeo demo ao final do arquivo. Também é possível notar essa confusão do modelo no "Feature Explorer" dos dados de teste, no qual nota-se certa sobreposição, principalmente dos dados “HIGH-SWING - incorrect” sobre os dados “HIGH” e vice-versa.

## Post-processing
Após a conclusão do modelo, foi incluída uma funcionalidade ao código para que a placa exibisse o estado das inferências realizadas. Para isso, foi usado o LED RGB do Arduino e a seguinte referência de cores:

- Amarelo = OFF
- Verde = LOW
- Rosa = LOW com SWING
- Vermelho - HIGH
- Azul = HIGH com SWING

## Vídeo demonstrativo:
Um video com o modelo sendo testado pode ser conferido no *link* abaixo (YouTube):
https://youtu.be/p1Ws7zBVe-Y
