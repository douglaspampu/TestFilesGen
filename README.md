# TestFilesGen
README

A ideia desse cÃ³digo Ã© gerar strings aleatÃ³rias com base em expressÃµes regulares;
Exemplos:

	([1-9][0-9][2-9][0-9]{7}): 1147154568
	([1-9][0-9][2-9][0-9]{7}): 3536525718
	([1-9][0-9][2-9][0-9]{7}): 2260277070


GeradorStrings
	Classes:
		Operacao: Container das classes Operador_string e Set
		Operador_string: Armazena uma string estÃ¡tica
		Regex: Cria strings aleatÃ³rias baseadas em expressÃµes regulares
		Set: armazena operaÃ§Ãµes [ string ] como [1-9], [abc] e [^abc]
		
OperaÃ§Ãµes suportadas
	
	[A-Z]: Escolhe um caractere entre um range minimo e um mÃ¡ximo.
	*: Repete zero ou mais vezes uma expressÃ£o
	+: Repete uma ou mais vezes uma expressÃ£o.
	(expressÃ£o): delimita uma expressao
	{3}: Define um nÃºmero de vezes pra repetir a Ãºltima expressÃ£o.
	|: operaÃ§Ã£o de OR, escolhe entre 2 ou mais expressÃµes.
