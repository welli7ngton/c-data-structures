#include "suite_runner.h"
#include "../test_helpers.h"
#include <stdio.h>

void run(func tests[], int amount_of_tests, char suite_name[]) {

  printf("\nRunning tests for %s ...\n", suite_name);
  printf("\n---------------------------------------------\n");

  for (int i = 0; i < amount_of_tests; i++) {
    tests[i]();
  }
  printf(GREEN "\nAll tests passed!\n" RESET);
  printf("\n---------------------------------------------\n");
}

void teste1() { printf("Executando teste 1\n"); }

void teste2() { printf("Executando teste 2\n"); }

void teste3() { printf("Executando teste 3\n"); }
