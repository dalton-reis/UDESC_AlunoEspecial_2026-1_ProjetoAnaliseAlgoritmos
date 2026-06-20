# Dicionário

O dicionário exato do Termo não é oficialmente publicado em um arquivo único facilmente acessível, mas há bastante informação pública sobre ele.
O criador do jogo, Fernando Serboncini, informou que o jogo utiliza aproximadamente 18 mil palavras de 5 letras em português. Essa base foi montada a partir de:

- dicionários de sistemas operacionais;
- textos jurídicos;
- redes sociais;
- outras listas de palavras em português;

e depois refinada para remover:

- nomes próprios;
- palavras muito obscuras;
- regionalismos extremos;
- palavrões;
- algumas conjugações verbais.  

Há também projetos no GitHub que tentam reconstruir ou usar essa lista:

- andersonmdcanteli/termo — usa uma base com mais de 245 mil palavras para - análises estatísticas do jogo. 
- GabrielMenoni/term.ooo-solver — solucionador para o jogo. 
- jlcvp/termo-solver — outro solver para Term.ooo. 

Um dos scripts antigos usados para “descobrir” a palavra do dia referenciava um JSON chamado termooo-wordsv2.json, contendo a lista de respostas diárias. 
Na prática, o jogo trabalha com:

uma lista de palavras válidas para aceitar tentativas;
uma lista menor de palavras possíveis como resposta diária.

Exemplos de palavras válidas:

- TERMO
- FESTA
- MAMÃE
- TURMA
- NUVEM

Características importantes:

- palavras têm 5 letras;
- acentos são tratados automaticamente;
- “Ç” é diferente de “C”;
- letras repetidas podem aparecer. 
