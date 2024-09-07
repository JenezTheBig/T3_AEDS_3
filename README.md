# Trabalho Prático 3 de AEDS3

## Algoritmos de Correspondência de Padrões

### OBJETIVO
- Verificar a correspondência exata de padrões em uma sequência de caracteres utilizando os algoritmos **Boyer-Moore** e **Knuth-Morris-Pratt**.
- **Tema**: Implementação e comparação de dois algoritmos clássicos de busca de padrões em cadeias de caracteres.
- **Base Teórica**: Algoritmos de busca de padrões otimizados para diferentes cenários, como textos longos ou padrões com repetições.

### Mecânica do Algoritmo
- **Boyer-Moore**: Utiliza as heurísticas de mau caractere e bom sufixo para evitar comparações desnecessárias, permitindo saltos eficientes ao longo do texto durante a busca.
- **Knuth-Morris-Pratt (KMP)**: Baseado no pré-processamento do padrão, constrói uma tabela de prefixo que otimiza a busca, evitando retrocessos e repetição de comparações.

### Estratégias de Implementação
- **Boyer-Moore**: Implementado com duas heurísticas principais para otimizar a busca e reduzir o número de comparações necessárias.
- **KMP**: Utiliza uma tabela de prefixo gerada durante o pré-processamento do padrão para garantir uma busca eficiente e sem redundância.
