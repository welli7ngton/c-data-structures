# Estruturas de Dados em C

Bem-vindo ao repositório **Estruturas de Dados em C**! Este projeto tem como objetivo implementar TADs (Tipos Abstratos de Dados) que representam diversas estruturas de dados, junto com uma suíte de testes para validar seu funcionamento.

## Sumário
- [Lista Sequencial Estática](#1-lista-sequencial-estatica)
- [Lista Dinamicamente Encadeada](#2-lista-dinamicamente-encadeada)
  
## Estrutura do Projeto
- **src/**: Contém os TADs das estruturas de dados implementados.
  - Exemplo atual: `sequential_list/` (lista sequencial estática).
- **test/**: Código dedicado para testes unitários e validações dos TADs.
- **Makefile**: Automatiza a compilação dos testes, facilitando o desenvolvimento e a manutenção.

## Funcionalidades Implementadas

### 1. Lista Sequencial Estática
- Arquivo fonte: [sequential_list.c](./src/sequential_list/sequential_list.c)
- Cabeçalho: [sequential_list.h](./src/sequential_list/sequential_list.h)
- Testes: [test/sequential_list.c](./test/sequential_list.c)
- **Descrição**: Uma lista estática que armazena elementos em um array fixo, permitindo operações básicas como inserção no final, inicio, organizada (sorted), remoção por index, remoção por dado, busca por index e busca por dado. Estou usando uma estrutura de dados personalizada simulando o cadastro de um aluno para ter um dado dinâmico para trabalhar.

### 2. Lista Dinamicamente Encadeada
- Arquivo fonte: [dinamic_list.c](./src/dinamic_list/dinamic_list.c)
- Cabeçalho: [dinamic_list.h](./src/dinamic_list/dinamic_list.h)
- Testes: [test/dinamic_list.c](./test/dinamic_list.c)
- **Descrição**: Uma lista dinamicamente encadeada armazena elementos em nós, onde cada nó contém um valor e um ponteiro para o próximo. Isso permite inserção e remoção eficientes de elementos, sem necessidade de realocar memória. Estou usando essa estrutura para simular o cadastro dinâmico de alunos, facilitando a adição e remoção de registros sem um tamanho fixo de lista.

## Como Usar

### Pré-requisitos
- Compilador GCC instalado.
- Make instalado.

### Compilação dos Testes
1. Escolha o arquivo a ser testado, definindo o parâmetro `TEST`. Por exemplo:
    ```bash
    make TEST=sequential_list
    ```

2. Execute o programa gerado:
    ```bash
    ./sequential_list.test
    ```

3. Para limpar os executáveis:
    ```bash
    make clean
    ```

