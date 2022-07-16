## push_swap

<img width="403" alt="image" src="https://user-images.githubusercontent.com/81334995/179250784-b24718ed-c5d9-4784-b9c3-b97f82d3ac73.png">

### organizando as ideias:

###### síntese:
- o programa recebev uma pilha de números inteiros aleatórios que deve ser organizada em ordem crescente.
- recebemos a pilha A com esses números aleatórios e temos também a disposíção uma pilha vazia B.
- devemos usar os 11 movimentos descritos em **tipos de movimento** na sequência mais precisa possível.

###### regras para a pilha recebida:
- os elementos devem ser números inteiros, portanto podem ser positivos ou negativos.
- a pilha recebida não pode possuir números repetidos.
- o número deve estar dentro do intervalo padrão de um **int** (-2,147,483,648 ~ 2,147,483,647).
- o programa deve retornar os movimentos usados para organizar a pilha A em ordem crescente separados por uma quebra de linha.

###### tipos de movimento:
- **swap** -> inverte os dois elementos do topo de uma fila (sa sb ss)*.
- **push** -> coloca o elemento do topo de uma fila no topo da outra  (pa pb).
- **rotate** -> desloca todos os elementos de uma fila para cima, com o primeiro se tornando o último (ra rb rr).
- **reverse rotate** -> desloca todos os elementos de uma fila para baixo, com o último se tornando o primeiro (rra rrb rrr).
- 
```
sa = swap a, sb = swap b, ss = sa + sb
pa = push a, pb = push b
ra = rotate a, rb = rotate b, rr = ra + rb
rra = reverse rotate a, rrb = reverse rotate b, rrr = rra + rrb
```


