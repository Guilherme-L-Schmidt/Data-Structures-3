#include <stdio.h>
#include <stdlib.h>
#include "registros.h"

/**
 * @brief calcula o tamanho do lixo ao final do registro
 * @param reg registro cujo tamanho do lixo deve ser calculado
 * @return tamanho do lixo
 */
int calcula_lixo(registro reg) {
    return (TAM_REG - (1 + 5*4 + reg.tamanhoTecnologiaOrigem + reg.tamanhoTecnologiaDestino));
}

/**
 * @brief escreve o registro fornecido na posicao corrente no arquivo dado
 * @param arquivo arquivo onde sera escrito o registro
 * @param reg registro a ser escrito no arquivo
 */
void escrever_registro(FILE* arquivo, registro reg) {
    // calcula tamanho do lixo e o cria
    int tam_lixo = calcula_lixo(reg);
    char* lixo = (char *)malloc(tam_lixo * sizeof(char));
    for(int i = 0; i < tam_lixo; i++)
        lixo[i] = '$';

    // escrita do registro no binário
    fwrite(&reg.removido, sizeof(char), 1, arquivo);
    fwrite(&reg.grupo, sizeof(int), 1, arquivo);
    fwrite(&reg.popularidade, sizeof(int), 1, arquivo);
    fwrite(&reg.peso, sizeof(int), 1, arquivo);
    fwrite(&reg.tamanhoTecnologiaOrigem, sizeof(int), 1, arquivo);
    fwrite(reg.nomeTecnologiaOrigem, sizeof(char), reg.tamanhoTecnologiaOrigem, arquivo);
    fwrite(&reg.tamanhoTecnologiaDestino, sizeof(int), 1, arquivo);
    fwrite(reg.nomeTecnologiaDestino, sizeof(char), reg.tamanhoTecnologiaDestino, arquivo);
    fwrite(lixo, sizeof(char), tam_lixo, arquivo);

    // libera o lixo
    free(lixo);
}

/**
 * @brief le um registro no arquivo fornecido a partir da posicao corrente e o armazena em reg
 * @param arquivo arquivo a ser lido (binario)
 * @param reg registro no qual sera armazenado o registro lido
 * @return 1, quando encontrar fim do arquivo, ou 0, quando le com sucesso
 */
int ler_registro(FILE* arquivo, registro* reg) {
    // leitura do registro
    if(fread(&(reg->removido), sizeof(char), 1, arquivo) == 0) {
        // retorno com fim do arquivo
        return 1;
    }
    // leitura dos dados, com alocacao de strings quando necessario
    fread(&(reg->grupo), sizeof(int), 1, arquivo);
    fread(&(reg->popularidade), sizeof(int), 1, arquivo);
    fread(&(reg->peso), sizeof(int), 1, arquivo);
    fread(&(reg->tamanhoTecnologiaOrigem), sizeof(int), 1, arquivo);
    reg->nomeTecnologiaOrigem = malloc(reg->tamanhoTecnologiaOrigem * sizeof(char));
    fread(reg->nomeTecnologiaOrigem, sizeof(char), reg->tamanhoTecnologiaOrigem, arquivo);
    fread(&(reg->tamanhoTecnologiaDestino), sizeof(int), 1, arquivo);
    reg->nomeTecnologiaDestino = malloc(reg->tamanhoTecnologiaDestino * sizeof(char));
    fread(reg->nomeTecnologiaDestino, sizeof(char), reg->tamanhoTecnologiaDestino, arquivo);

    // calcula tamanho do lixo e o pula
    fseek(arquivo, calcula_lixo(*reg), SEEK_CUR);
    
    // retorno com sucesso
    return 0;
}

/**
 * @brief escreve o cabecalho fornecido na posicao corrente no arquivo dado (binario)
 * @param arquivo arquivo no qual sera escrito o cabecalho
 * @param cabecalho cabecalho a ser escrito no arquivo
 */
void escrever_header(FILE* arquivo, header cabecalho) {
    // escreve os dados contidos no registro de cabecalho
    fwrite(&cabecalho.status, sizeof(char), 1, arquivo);
    fwrite(&cabecalho.proxRRN, sizeof(int), 1, arquivo);
    fwrite(&cabecalho.nroTecnologias, sizeof(int), 1, arquivo);
    fwrite(&cabecalho.nroParesTecnologias, sizeof(int), 1, arquivo);    
}
