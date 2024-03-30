/*
**    Função : Número de Carmichael
**    Autor : Aderbal Ferreira da Silva Filho
**    Data  : 28/03/2024
**    Observações:
*/

#include <stdbool.h>
#include <stdio.h>

int mdc(int a, int b) {
  int temp;
  while (b != 0) {
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

bool sao_coprimos(int a, int b) {
  return mdc(a, b) == 1;
}

bool eh_numero_carmichael(int n) {
  if (n <= 2) {
    return false; 
  }

  for (int a = 2; a < n; ++a) {
    if (sao_coprimos(a, n)) {
      int res = 1;
      int exp = n - 1;
      int base = a;

      while (exp > 0) {
        if (exp % 2 == 1) {
          res = (res * base) % n;
        }
        base = (base * base) % n;
        exp /= 2;
      }

      if (res != 1) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  int numero;
  printf("Digite um número inteiro positivo: ");
  scanf("%d", &numero);
  if (eh_numero_carmichael(numero)) {
    printf("%d é um número de Carmichael.\n", numero);
  } else {
    printf("%d não é um número de Carmichael.\n", numero);
  }
  return 0;
}
