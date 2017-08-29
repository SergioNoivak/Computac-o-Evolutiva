# Computac-o-Evolutiva
 Disciplina cursada em 2017 onde, por meio de experimentos, simulamos processos genéticos e evolutivos
 
 # algoritmo da roleta e selecao(ESTRATÉGIA 1+1)
 No código algoritmo_da_roleta_e_selecao_natural.cpp simulamos o processo evolutivo da seguinte forma:<br>
 <u> Precisamos encontrar um máximo para a função</u> x*sin(10*PI*x)+5; (funcao que chamamos de fitness)<br>
 <br>
i-) cria-se um vetor(populacao).<br>
ii-)preenche todas as posicoes com numeros aleatorios no intervalo [0,4].<br>
iii-) Faz o <b>fitness</b>, o seja, aplica uma funcão, que retoorna um numero maior se o individuo está mais apto.<br>
iv-)calcula <b>soma das aptidoes</b>.<br>
v-)Passamos a soma das aptidões para a funcao de selecao, que será como uma roleta, onde os individuos mais aptos <br>
serão selecionados(isso se faz necessario pois os individuos com maior aptidão serão os individuos com maiores chances de ser escolhidos).<br>Essa funcao retorna um indice, que é o indice do elemento escolhido.
vi-)ao ser escolhido, esse elemento sofre uma mutacao. <b> mutacao </b> é uma perturbação que no nosso caso somar um numero aleatório<br>
entre -0.5 e +0.5.<br>
iix-)Se o individuo(mutado) for mais apto ele assume a posicao do anterior.<br>
ix-)Senao o individuo eh descartado e o antigo toma o seu lugar<br>
o processo foi simulado para 400 geracoes.




           


 

