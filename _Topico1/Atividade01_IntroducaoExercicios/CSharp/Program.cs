using System;
using System.Security.Cryptography.X509Certificates;

class Program
{
  static int LerInteiro()
  {
    int numeroInt = 0;
    do
    {
      if (!int.TryParse(Console.ReadLine(), out numeroInt))
        Console.WriteLine("Valor inválido! Digite um número inteiro.");
      else
        return numeroInt;
    } while (true);
  }

  static int LerInteiroPositivo()
  {
    int numeroIntPos = 0;
    do
    {
      if (!int.TryParse(Console.ReadLine(), out numeroIntPos) || numeroIntPos <= 0)
        Console.WriteLine("Valor inválido! Digite um número inteiro positivo.");
      else
        return numeroIntPos;
    } while (true);
  }

  static void AntesSequencia()
  {
    Console.Write("Informe a qtd. de valores (n) menor que 1.000.000: ");
    int n = LerInteiroPositivo();
        
    Console.Write("Informe o valor a buscar (m): ");
    int m = LerInteiro();

    int contador = 0; // contador de ocorrências de `m` em `n`.

    Console.WriteLine("Informe os " + n + " valores de (n) ____");
    int x = 0;
    for (int i = 0; i < n; i++)
    {
      x = LerInteiro();
      if (x == m)
        contador++;
    }
    Console.WriteLine("O valor (m) apareceu " + contador + " vezes em (n).");    
  }
  
  static void DepoisSequencia()
  {
    Console.Write("Informe a qtd. de valores (n) menor que 1.000.000: ");
    int n = LerInteiroPositivo();
    
    Console.WriteLine("Informe os " + n + " valores de (n) ____");
    int[] vetorN = new int[n];
    for (int i = 0; i < n; i++)
    {
        vetorN[i] = LerInteiro();
    }

    Console.Write("Informe o valor a buscar (m): ");
    int m = LerInteiro();

    int contador = 0; // contador de ocorrências de `m` em `n`.

    for (int i = 0; i < n; i++)
    {
      if (vetorN[i] == m)
        contador++;
    }
    Console.WriteLine("O valor (m) apareceu " + contador + " vezes em (n).");    
  }

  static void Main()
  {
    AntesSequencia();
    DepoisSequencia();
  }
}
