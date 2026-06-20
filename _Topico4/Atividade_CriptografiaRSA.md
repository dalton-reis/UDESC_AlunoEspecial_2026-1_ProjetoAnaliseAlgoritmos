# Criptografia RSA — exercícios resolvidos

## Exercício 1

Dados:

\[
p=17,\quad q=41
\]

Calculando \(n\):

\[
n=pq=17\cdot 41=697
\]

Calculando a função totiente de Euler:

\[
\varphi(n)=(p-1)(q-1)=16\cdot 40=640
\]

Um expoente público \(e\) é válido se:

\[
\gcd(e,\varphi(n))=1
\]

Testando \(e_1=32\):

\[
\gcd(32,640)=32
\]

Logo:

\[
e_1=32
\]

não é válido.

Testando \(e_2=49\):

\[
\gcd(49,640)=1
\]

Logo:

\[
e_2=49
\]

é válido.

Agora calculamos a chave privada \(d\), tal que:

\[
49d \equiv 1 \pmod{640}
\]

O inverso modular de \(49\) módulo \(640\) é:

\[
d=209
\]

Portanto:

\[
\boxed{e=49}
\]

\[
\boxed{d=209}
\]

Chave pública:

\[
\boxed{(e,n)=(49,697)}
\]

Chave privada:

\[
\boxed{(d,n)=(209,697)}
\]

---

## Exercício 2.1

Dados:

\[
p=3,\quad q=11,\quad e=7,\quad m=5
\]

Calculando \(n\):

\[
n=3\cdot 11=33
\]

Calculando \(\varphi(n)\):

\[
\varphi(n)=(3-1)(11-1)=2\cdot 10=20
\]

Calculando \(d\):

\[
7d \equiv 1 \pmod{20}
\]

\[
d=3
\]

### Criptografia

A fórmula da criptografia RSA é:

\[
c=m^e \bmod n
\]

Substituindo os valores:

\[
c=5^7 \bmod 33
\]

\[
c=14
\]

### Descriptografia

A fórmula da descriptografia RSA é:

\[
m=c^d \bmod n
\]

Substituindo os valores:

\[
m=14^3 \bmod 33
\]

\[
m=5
\]

Resultado:

\[
\boxed{c=14}
\]

\[
\boxed{m=5}
\]

---

## Exercício 2.2

Dados:

\[
p=5,\quad q=11,\quad e=3,\quad m=9
\]

Calculando \(n\):

\[
n=5\cdot 11=55
\]

Calculando \(\varphi(n)\):

\[
\varphi(n)=(5-1)(11-1)=4\cdot 10=40
\]

Calculando \(d\):

\[
3d \equiv 1 \pmod{40}
\]

\[
d=27
\]

### Criptografia

A fórmula da criptografia RSA é:

\[
c=m^e \bmod n
\]

Substituindo os valores:

\[
c=9^3 \bmod 55
\]

\[
c=14
\]

### Descriptografia

A fórmula da descriptografia RSA é:

\[
m=c^d \bmod n
\]

Substituindo os valores:

\[
m=14^{27} \bmod 55
\]

\[
m=9
\]

Resultado:

\[
\boxed{c=14}
\]

\[
\boxed{m=9}
\]
