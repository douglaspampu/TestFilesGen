#include "regex.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

Regex::Regex(string re)
{
    regex = re;

    srand (time(NULL));

}

Regex::~Regex()
{

}

string Regex::cria_automato()
{
    string pilha;
    vector<string> pilha_strings;

    vector<operacao*> pilha_operacoes;

    string subExpressao = "";
    string resultado;

    int j;
    int tam_regex;
    string::size_type pos;

    int tamanho;

    int operacao_or = 0;

    int parentizacao = 0;

    tam_regex = regex.size();

    pilha_strings.push_back("");

    for (int i = 0; i < tam_regex; i++)
    {
        set *new_set = new set();
        operacao *op = new operacao();
        operador_string *new_string = new operador_string();
        operacao_ponto *new_ponto = new operacao_ponto();

        switch(regex[i])
        {
            case ']':
                subExpressao = get_subexpressions(pilha, '[');

                pos = pilha.find(subExpressao);
                j = subExpressao.size();

                new_set->set_operacao(subExpressao);
                op->put_set(new_set);

                pilha_operacoes.push_back(op);

                pilha.replace(pos, j+1,pilha_strings.back());

                subExpressao = "";

                parentizacao++;

                break;

            case ')':
                subExpressao = get_subexpressions(pilha, '(');

                pos = pilha.find(subExpressao);
                j = subExpressao.size();

                if(pilha_operacoes.empty() || !subExpressao.empty())
                {
                    new_string->set_string(subExpressao);

                    op->put_expressao(new_string);

                    pilha_operacoes.push_back(op);
                }

                else if(pilha_operacoes.back()->verifica_conteudo() != 3)
                {
                    new_string->set_string(pilha_operacoes.back()->get_expressao());

                    pilha_operacoes.pop_back();

                    op->put_expressao(new_string);
                    pilha_operacoes.push_back(op);
                }
                else
                {
                    new_string->set_string(subExpressao);

                    op->put_expressao(new_string);

                    pilha_operacoes.push_back(op);
                }

                if(operacao_or == 1)
                {
                    pilha_operacoes.pop_back();

                    operacao_or = 0;
                }


                if(parentizacao > 1)
                {
                    subExpressao = "";
                    while (parentizacao > 0)
                    {
                        subExpressao = pilha_operacoes.back()->get_expressao() + subExpressao;

                        pilha_operacoes.pop_back();

                        parentizacao--;
                    }


                    new_string->set_string(subExpressao);

                    op->put_expressao(new_string);

                    pilha_operacoes.push_back(op);
                }

                subExpressao = "";
                pilha.replace(pos, 1,"");
                break;

            case '}':
                subExpressao = get_subexpressions(pilha, '{');

                pos = pilha.find(subExpressao);
                j = subExpressao.size();

                tamanho = cria_operacao_size(subExpressao);

                resultado = "";

                for (int x = 0; x < tamanho+1; x++)
                {
                    resultado += pilha_operacoes.back()->get_expressao();
                }

                pilha_operacoes.pop_back();

                new_string->set_string(resultado);
                op->put_expressao(new_string);
                pilha_operacoes.push_back(op);


                pilha.replace(pos - 1, j+1,"");
                subExpressao = "";
                break;

            case '*':
                subExpressao = get_operacao(pilha);

                pos = pilha.find(subExpressao);
                j = subExpressao.size();

                tamanho = cria_operacao_asterisco();

                resultado = "";

                for (int x = 0; x < tamanho; x++)
                {
                    resultado += pilha_operacoes.back()->get_expressao();
                }
                pilha_operacoes.pop_back();

                new_string->set_string(resultado);
                op->put_expressao(new_string);
                pilha_operacoes.push_back(op);

                pilha.erase(pos, j+1);

                subExpressao = "";
                break;

            case '+':
                subExpressao = get_operacao(pilha);

                pos = pilha.find(subExpressao);
                j = subExpressao.size();

                tamanho = cria_operacao_asterisco();

                for (int x = 0; x < tamanho; x++)
                {
                    resultado += pilha_operacoes.back()->get_expressao();
                }

                new_string->set_string(resultado);
                op->put_expressao(new_string);
                pilha_operacoes.push_back(op);
                pilha.erase(pos, j+1);

                subExpressao = "";
                break;

            case '|':
                if(pilha_operacoes.empty())
                {
                    subExpressao = get_operacao(pilha);

                    pos = pilha.find(subExpressao);
                    j = subExpressao.size();

                    new_string->set_string(subExpressao);

                    op->put_expressao(new_string);

                    pilha_operacoes.push_back(op);

                    pilha.erase(pos, j+1);
                }

                if(operacao_or == 0)
                {
                    operacao_or = rand() % 2;

                    if(operacao_or == 0)
                    {
                        pilha_operacoes.pop_back();
                    }

                }
                else
                {
                    pilha_operacoes.pop_back();
                }

                subExpressao = "";
                break;

            case '[':
            case '(':
                if(i > 0)
                {
                    subExpressao = get_strings (pilha);

                    pos = pilha.find(subExpressao);
                    j = subExpressao.size();

                    new_string->set_string(subExpressao);

                    op->put_expressao(new_string);

                    pilha_operacoes.push_back(op);

                    pilha.replace(pos, j+1,pilha_strings.back());

                    subExpressao = "";
                }

                if(regex[i] == '(')
                {
                    parentizacao = 1;
                }

                break;

            case '.':

                subExpressao = char(rand() % 256);

                op->put_ponto();
                pilha_operacoes.push_back(op);

                subExpressao = "";
                break;

            default:
                pilha += regex[i];
                break;
        }

    }

    resultado = "";

    for (int c = 0; c < pilha_operacoes.size(); c++)
        resultado += pilha_operacoes[c]->get_expressao();

    cout << "String gerada: "<<resultado<<endl;

    return resultado;
}

string Regex::get_subexpressions(string _pilha, char token)
{
    int j;
    string subExpressao = "";

    j = _pilha.size() - 1;
    while(_pilha[j] != token && j >= 0)
    {
        subExpressao = _pilha[j] + subExpressao;
        j--;
    }

    return subExpressao;
}

string Regex::get_operacao(string _pilha)
{
    int j;
    string subExpressao = "";

    j = _pilha.size() - 1;
    while((_pilha[j] != '[' && _pilha[j] != '(' /*&& _pilha[j] != '|'*/) && j >= 0)
    {
        subExpressao = _pilha[j] + subExpressao;
        j--;
    }

    return subExpressao;
}

string Regex::get_strings (string _pilha)
{
    int j;
    string subExpressao = "";

    j = _pilha.size() - 1;

    while((_pilha[j] != ']' && _pilha[j] != ')') && j >= 0)
    {
        subExpressao = _pilha[j] + subExpressao;
        j--;
    }

    return subExpressao;
}

int Regex::cria_operacao_asterisco()
{
    int result = 0;
    int fim;

    fim = rand() % 2;

    while(fim==0)
    {
        result = result + 1;

        fim = rand() % 2;
    }

    return result;
}

string Regex::cria_operacao_mais(string _operacao)
{
    string result = _operacao;
    int fim;

    fim = rand() % 2;

    while(fim==0)
    {
        result = result + _operacao;

        fim = rand() % 2;
    }

    return result;
}


string Regex::cria_operacao_set(string _operacao)
{
    //[inicio do range - fim do range]

    string inicio_do_range;
    string fim_do_range;

    string retorno;

    bool inicio_fim = false;
    bool conjunto_negado = false;

    for(int i = 0; i < _operacao.size(); i++)
    {
        switch (_operacao[i])
        {
            case '[':

                break;
            case ']':

                break;
            case ' ':

                break;
            case '-':
                inicio_fim = true;
                break;
            case '^':
                conjunto_negado = true;
                break;
            default:
                if(!inicio_fim)
                    inicio_do_range += _operacao[i];
                else
                    fim_do_range += _operacao[i];
                break;
        }
    }

    if(inicio_fim)
    {
        int inicio = int(inicio_do_range[0]);
        int fim = int(fim_do_range[0]);

        int range = fim - inicio;

        range = rand() % range;

        retorno = char(range+inicio);
    }
    else
    {
        if (conjunto_negado)
        {
            int char_in_set;
            bool char_escolhido = false;

            while(char_escolhido == false)
            {
                char_in_set = rand() % 256;
                char_escolhido = true;
                for (int i = 0; i < inicio_do_range.size(); i++)
                {
                    if(char_escolhido == int(inicio_do_range[i]))
                        char_escolhido = false;
                }
            }

            retorno = char(char_in_set);
        }
        else
        {
            int range = inicio_do_range.size();

            range = rand() % range;

            retorno = inicio_do_range[range];
        }
    }

    return retorno;
}

int Regex::cria_operacao_size(string _operacao)
{
    bool min_max = false;
    int min, max;
    string aux_min, aux_max;

    for (int i = 0; i < _operacao.size(); i++)
    {
        switch(_operacao[i])
        {
            case '{':

                break;
            case '}':
                break;
            case ' ':
                break;
            case ',':
                min_max = true;
                break;
            default:
                if(!min_max)
                    aux_min += _operacao[i];
                else
                    aux_max += _operacao[i];
                break;
        }
    }

    min = atoi(aux_min.c_str());
    max = atoi(aux_max.c_str());

    if(min_max)
    {
        int range = max - min;
        range = rand() % range;

        return range;

        //for (int i = 0; i < range + min; i++)
            //result = result + _expressao;
    }
    else
    {
        //for (int i = 0; i < min - 1; i++)
            //result = result + _expressao;
        return min - 1;
    }

    //return result;
}
