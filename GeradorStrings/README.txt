README

A ideia desse código é gerar strings aleatórias com base em expressões regulares;
Exemplos:

	([1-9][0-9][2-9][0-9]{7}): 1147154568
	([1-9][0-9][2-9][0-9]{7}): 3536525718
	([1-9][0-9][2-9][0-9]{7}): 2260277070


GeradorStrings
	Classes:
		Operacao: Container das classes Operador_string e Set
		Operador_string: Armazena uma string estática
		Regex: Cria strings aleatórias baseadas em expressões regulares
		Set: armazena operações [ string ] como [1-9], [abc] e [^abc]
		
Operações suportadas
	
	[A-Z]: Escolhe um caractere entre um range minimo e um máximo.
	*: Repete zero ou mais vezes uma expressão
	+: Repete uma ou mais vezes uma expressão.
	(expressão): delimita uma expressao
	{3}: Define um número de vezes pra repetir a última expressão.
	|: operação de OR, escolhe entre 2 ou mais expressões.