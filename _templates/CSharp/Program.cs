using System;
// Exibe uma mensagem inicial, lê um número inteiro digitado pelo usuário e mostra o valor informado.

class Program
{
  static void Main()
  {
    Console.WriteLine("Olá, mundo! Exemplo em C++ executado com sucesso, e com acentuação.");
    Console.Write("Valor: ");
    int valor = int.Parse(Console.ReadLine()!);
    Console.WriteLine($"Valor lido: {valor}");
  }
}
