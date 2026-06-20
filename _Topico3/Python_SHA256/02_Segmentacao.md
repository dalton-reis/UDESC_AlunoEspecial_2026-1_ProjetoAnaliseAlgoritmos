# Segmentação

Este material aborda a **segmentação de imagens**, definida como a etapa fundamental do processamento digital que isola objetos de interesse para facilitar a **análise e o reconhecimento** de padrões. O conteúdo explica que segmentar consiste em **simplificar a imagem**, removendo ruídos e detalhes irrelevantes para gerar uma representação focada em regiões homogêneas, essencial para aplicações em robótica e inspeção industrial. Para estruturar esse processo, o texto detalha metodologias variadas, desde a detecção de **descontinuidades**, como bordas e pontos, até a identificação de **similaridades** por meio de técnicas como a **limiarização** (*thresholding*), o crescimento de regiões e a clusterização. Entre os algoritmos de destaque, são explorados o **K-Means**, pela sua simplicidade em organizar dados de forma não supervisionada, e o **Mean Shift**, que identifica zonas de maior densidade para delimitar bacias de atração e segmentar cenários complexos.

**Slides:** [02_Segmentacao.pdf](./02_Segmentacao.pdf)

---

## Segmentação de Imagens

A **segmentação de imagens** é uma das tarefas mais críticas e desafiadoras no processo de análise de imagens digitais. Seu objetivo principal é a **simplificação**, particionando a imagem em regiões homogêneas que correspondam a objetos de interesse ou estruturas significativas.

O resultado ideal é uma “caricatura” da realidade, onde detalhes desnecessários e ruídos são removidos, preservando apenas a informação semântica necessária para etapas posteriores, como o reconhecimento de padrões.

### Fundamentos e Metodologia

A segmentação situa-se entre o pré-processamento (filtragem) e a extraçãa de características no fluxo de trabalho de processamento de imagens.

O sucesso da análise depende diretamente da qualidade da segmentação.

Os algoritmos de segmentação são geralmente classificados em duas categorias baseadas em propriedades de intensidade:

- **Descontinuidades:** busca por mudanças bruscas nos níveis de cinza, como pontos isolados, linhas e bordas.
- **Similaridades:** agrupamento de pixels que compartilham características comuns.

### Principais Famílias de Técnicas

As abordagens mais utilizadas incluem:

- Limiarização (*Thresholding*)
- Segmentação por Regiões
- Clusterização (*Clustering*)
- Métodos Morfológicos (*Watershed*)
- Métodos Baseados em Grafos
- Métodos Baseados em Formas
- Redes Neurais Convolucionais

### Aplicações Práticas

- Controle de qualidade
- Inspeção automatizada de peças
- Robótica
- Medicina
- Reconhecimento de padrões

---

## Limiarização Global

A **limiarização global** é uma técnica fundamental de segmentação de imagens baseada na utilização de um único valor de corte (**limiar** $T$) para toda a imagem.

### Funcionamento e Lógica Matemática

A operação é classificada como homogênea, pois o novo valor de cada pixel depende apenas de sua intensidade original:

- Se $f(x,y) > T$, o pixel pertence ao objeto.
- Caso contrário, pertence ao fundo.

O resultado é uma imagem binária que separa **foreground** e **background**.

### Métodos de Seleção de Limiar

- Limiar Fixo
- Média ou Mediana
- Técnica de Quantil
- Algoritmo Isodata
- Método de Otsu

### Requisitos e Limitações

Para que funcione adequadamente, o histograma deve idealmente ser **bimodal**.

Principais limitações:

- Iluminação irregular
- Gradientes de iluminação
- Sobreposição entre intensidades do objeto e fundo

Nestes casos, recomenda-se limiarização local ou adaptativa.

---

## Segmentação por Regiões

A **segmentação por regiões** opera no domínio do espaço, utilizando relações de vizinhança e propriedades locais para agrupar pixels homogêneos.

Ela foi desenvolvida para superar limitações de métodos puramente baseados em intensidade.

### Premissas Matemáticas

Uma segmentação válida deve satisfazer:

- União total das regiões forma a imagem completa.
- Regiões não podem se sobrepor.
- Cada região deve satisfazer um predicado lógico de homogeneidade.
- A união de regiões vizinhas deve invalidar o predicado.

### Crescimento de Regiões (*Region Growing*)

O processo inicia com pixels sementes.

A partir deles:

- pixels vizinhos similares são agregados;
- utiliza-se critérios como:
  - intensidade;
  - cor;
  - textura;
  - estatísticas locais.

#### Desvantagens

- Dependência das sementes.
- Dependência da propriedade escolhida.

### Divisão e Fusão (*Split and Merge*)

A imagem é subdividida sucessivamente em quadrantes (*quadtree*) enquanto o predicado de homogeneidade for falso.

Depois:

- regiões vizinhas homogêneas são fundidas.

### Rotulagem de Regiões

Após segmentar:

- cada componente conectado recebe um rótulo único;
- podem ser extraídas estatísticas geométricas.

#### Estatísticas

- Área
- Centroide
- Bounding Box
- Momentos

### Aplicações

- Medicina
- Robótica
- Controle de qualidade
- Detecção de microcalcificações

---

## Clustering

A clusterização consiste em agrupar elementos similares entre si e diferentes dos pertencentes a outros grupos.

### Tipos de Clustering

- **Divisivo (Divisive):**
  - inicia com um único cluster;
  - realiza divisões sucessivas.

- **Aglomerativo (Agglomerative):**
  - inicia com cada pixel separado;
  - realiza fusões sucessivas.

### Medidas de Similaridade

A segmentação depende de uma medida de similaridade, normalmente:

- distância euclidiana;
- cor;
- textura;
- proximidade espacial.

### Dendrograma

Em clustering hierárquico, o dendrograma representa:

- a sequência de uniões;
- o nível de similaridade entre grupos.

Uniões baixas representam grupos semelhantes.
Uniões altas representam grupos menos semelhantes.

---

## Algoritmo K-Means

O **K-Means** é uma técnica clássica de aprendizagem não supervisionada para agrupamento de dados e segmentação de imagens.

### Funcionamento do Algoritmo

O algoritmo segue etapas iterativas:

1. Selecionar $k$ centróides iniciais.
2. Associar cada ponto ao centróide mais próximo.
3. Recalcular os centróides.
4. Repetir até convergência.

### Fundamentos Matemáticos

#### Distância Euclidiana

A similaridade normalmente é medida por distância euclidiana.

#### Centroide

O novo centróide é dado pela média:

$$
c_j = \frac{1}{|C_j|} \sum_{x_i \in C_j} x_i
$$

### Problemas e Limitações

- Dependência de boa inicialização.
- Necessidade de definir previamente o número de clusters ($k$).
- Sensibilidade a ruídos e *outliers*.

### Aplicações

- Segmentação por cor
- Quantização de cores
- Agrupamento de padrões

---

## Técnica Mean Shift

A técnica **Mean Shift** é um método robusto de clusterização baseado na busca por regiões de maior densidade.

Diferente do K-Means:

- não requer número prévio de clusters;
- é uma técnica não-paramétrica.

### Conceitos Fundamentais

- **Modos:** regiões de máxima densidade.
- **Bacias de atração:** conjuntos de pontos que convergem ao mesmo modo.
- **Vetor Mean Shift:** direção de maior crescimento de densidade.

### Funcionamento do Algoritmo

Para cada ponto:

1. Centraliza-se uma janela.
2. Calcula-se a média local.
3. Desloca-se a janela.
4. Repete-se até convergência.

### Vantagens

- Não requer definir $k$.
- Boa robustez.
- Excelente qualidade visual.
- Funciona bem em imagens complexas.

### Aplicações

- Segmentação baseada em cor
- Segmentação de cenas naturais
- Análise de espaço de características

---

## Morfologia e Watershed

O algoritmo **Watershed** interpreta a imagem como um relevo topográfico.

### Funcionamento

- mínimos locais representam bacias;
- o algoritmo “inunda” essas regiões;
- fronteiras entre bacias formam as linhas de segmentação.

### Problema de Super-segmentação

Ruídos criam muitos mínimos locais.

Isso gera:

- excesso de regiões;
- fragmentação exagerada.

### Soluções

Aplicar suavização antes da segmentação:

- filtro Gaussiano;
- filtro da Mediana.

---

## ⏭ [Unidade 3)](../Unidade3/README.md "Unidade 3")
