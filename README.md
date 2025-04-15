<p align="left"><h1 align="left">push_swap</h1></p>
<p align="left">
	<img src="https://img.shields.io/github/license/nabuchholz/ft_push_swap?style=default&logo=opensourceinitiative&logoColor=white&color=0b96a2" alt="license">
	<img src="https://img.shields.io/github/last-commit/nabuchholz/ft_push_swap?style=default&logo=git&logoColor=white&color=0b96a2" alt="last-commit">
	<img src="https://img.shields.io/github/languages/top/nabuchholz/ft_push_swap?style=default&color=0b96a2" alt="repo-top-language">
	<img src="https://img.shields.io/github/languages/count/nabuchholz/ft_push_swap?style=default&color=0b96a2" alt="repo-language-count">
</p>
<p align="left">
	<!-- opção padrão, sem badges de dependência. -->
</p>
<br>

## 🔗 Índice

- [📍 Visão Geral](#-visão-geral)
- [📁 Estrutura do Projeto](#-estrutura-do-projeto)
- [🚀 Começando](#-começando)
  - [☑️ Pré-requisitos](#-pré-requisitos)
  - [⚙️ Instalação](#-instalação)
  - [🤖 Uso](#-uso)
- [🧮 Algoritmos](#-algoritmos)
- [🛠️ Operações](#️-operações)
- [📊 Desempenho](#-desempenho)
- [📝 Norminette](#-norminette)
- [🙌 Agradecimentos](#-agradecimentos)

## 📍 Visão Geral

push_swap é um projeto da 42 School focado na ordenação de dados usando duas pilhas com um conjunto limitado de operações. O objetivo é implementar algoritmos de ordenação eficientes que usem o mínimo de operações para organizar uma lista aleatória de números inteiros em ordem crescente.

## 📁 Estrutura do Projeto

```sh
.
├── includes/         # Arquivos de cabeçalho
│   └── pushSwap.h    # Cabeçalho principal
├── libft/            # Biblioteca customizada (submódulo)
│   └── printf/       # Implementação do Printf
├── src/              # Código-fonte
│   ├── parse_args.c
│   ├── push_operations.c
│   ├── push_swap.c
│   ├── radix_sort.c
│   ├── rotate_operations.c
│   ├── rotate_reverse_operations.c
│   ├── sort_hundred.c
│   ├── sort_stack.c
│   ├── swap_operations.c
│   ├── utils.c
│   └── validation.c
├── Makefile
└── README.md
```

## 🚀 Começando

### ☑️ Pré-requisitos

Antes de começar com o push_swap, certifique-se de que seu ambiente atende aos seguintes requisitos:

- **Linguagem de Programação:** C
- **Compilador:** gcc ou clang
- **Sistema de Build:** Make
- **Git:** Para clonar o repositório e submódulos

### ⚙️ Instalação

1. Clone o repositório push_swap com submódulos:
```sh
❯ git clone --recurse-submodules https://github.com/nbuchhol/push_swap.git
```

2. Navegue até o diretório do projeto:
```sh
❯ cd push_swap
```

3. Compile o projeto:
```sh
❯ make
```

### 🤖 Uso

Execute o push_swap com uma lista de inteiros como argumentos:

```sh
❯ ./push_swap 4 67 3 87 23
```

Você também pode fornecer números como uma string:
```sh
❯ ./push_swap "4 67 3 87 23"
```

O programa exibirá a sequência de operações necessárias para ordenar os números em ordem crescente.

## 🧮 Algoritmos

O programa utiliza diferentes algoritmos de ordenação dependendo do tamanho da entrada:

- **2 números**: Troca simples se necessário
- **3 números**: Algoritmo otimizado específico para 3 números
- **4-5 números**: Algoritmo que extrai os menores valores para a pilha B, ordena os números restantes e os empurra de volta
- **Até 100 números**: Algoritmo de ordenação por chunks que divide os valores em 5 grupos e os move estrategicamente entre as pilhas
- **Acima de 100 números**: Algoritmo Radix Sort adaptado e otimizado para duas pilhas

## 🛠️ Operações

As operações disponíveis para manipulação das pilhas são:

- `sa`: Troca os dois elementos do topo da pilha A
- `sb`: Troca os dois elementos do topo da pilha B
- `ss`: `sa` e `sb` simultaneamente
- `pa`: Empurra o elemento do topo da pilha B para a pilha A
- `pb`: Empurra o elemento do topo da pilha A para a pilha B
- `ra`: Rotaciona a pilha A para cima (o primeiro elemento se torna o último)
- `rb`: Rotaciona a pilha B para cima (o primeiro elemento se torna o último)
- `rr`: `ra` e `rb` simultaneamente
- `rra`: Rotaciona a pilha A para baixo (o último elemento se torna o primeiro)
- `rrb`: Rotaciona a pilha B para baixo (o último elemento se torna o primeiro)
- `rrr`: `rra` e `rrb` simultaneamente

## 📊 Desempenho

- Para 3 números: máximo de 2 operações
- Para 5 números: máximo de 10 operações
- Para 100 números: aproximadamente 750 operações
- Para 500 números: aproximadamente 6864 operações

## 📝 Norminette

Este projeto está em conformidade com a Norma da 42, que inclui:
- Máximo de 25 linhas por função
- Apenas loops `while` são permitidos
- Cada função realiza apenas uma tarefa
- Variáveis são declaradas no início das funções
- Máximo de 5 funções por arquivo

## 🙌 Agradecimentos

- Colegas da 42 por discussões e insights sobre otimização de algoritmos, em especial [Fernando](https://github.com/fernandoruanb) pelos incontáveis testes, [Luis](https://github.com/luizpanigassi) pelo apoio moral ao pragmatísmo.

---

<p align="center">
  Feito com 💜 por nyx
</p>
