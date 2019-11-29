O que foi feito:

Tipos de dados necessários, leitura do arquivo de especificação e geração da imagem PPM.
Desenho de retas.
Desenho de polígonos.
Modularzação do programa.
Implementação de apenas um extra (GitHub).
Documentação no código.

O que não foi feito:

Comando Open.
Desenho de círculo.
Desenho do retângulo
Preenchimento de figuras.



O que seria feito diferente:

Acho que poderiamos ter organizado o código desde o início, ter feito o código desde o início usando uma estrutura auxiliar para armazenar a imagem antes de salvar. Como não foi feito desde o ínicio, acabou complicado demais refazer todo o código para salvar em outra estrutura sem ser o arquivo final da imagem.

No main, colocamos pra salvar apenas na struct e caso tivesse mais de um comando igual, sempre salva apenas o que estava no ultimo comando, poderiamos ter colocado um vetor de struct para salvar mais de um comando.

Integrantes da dupla: Bruna Gecyele e Denis Rodrigo

Atividades Bruna:

Todo o arquivo main.c, circle.h, circle.c,image.h,image.c,color.h,color.c, line.h, line.c (função processa_linha), rect.c,rect.h, polygon.h.


Atividades Denis:
Todo o arquivo polygon.c, line.c(função void line()).



