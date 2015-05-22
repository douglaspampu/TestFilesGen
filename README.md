# TestFilesGen
README

A ideia desse codigo é gerar strings aleatorias com base em expressoes regulares;
Exemplos:

	([1-9][0-9][2-9][0-9]{7}): 1147154568
	([1-9][0-9][2-9][0-9]{7}): 3536525718
	([1-9][0-9][2-9][0-9]{7}): 2260277070


GeradorStrings
	Classes:
		Operacao: Container das classes Operador_string e Set
		Operador_string: Armazena uma string estatica
		Regex: Cria strings aleatorias baseadas em expressoes regulares
		Set: armazena operacoes [ string ] como [1-9], [abc] e [^abc]
		
Operacoes suportadas
	
	[A-Z]: Escolhe um caractere entre um range minimo e um maximo.
	*: Repete zero ou mais vezes uma expressao
	+: Repete uma ou mais vezes uma expressao.
	(expressao): delimita uma expressao
	{3}: Define um nÃºmero de vezes pra repetir a ultima expressao.
	|: operacao de OR, escolhe entre 2 ou mais expressoes.
	.: retorna qualquer caractere da tabela ascii
