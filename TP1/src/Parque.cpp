#include "Parque.h"
#include <vector>

using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli) : lotacao(lot), numMaximoClientes(nMaxCli) {
	vagas = lot;
}

unsigned int ParqueEstacionamento::getNumLugares() const {
	return lotacao;
}

bool ParqueEstacionamento::adicionaCliente(const string& nome) {
	if (clientes.size() < numMaximoClientes) {
		InfoCartao cliente;
		cliente.nome = nome;
		cliente.presente = false;
		clientes.push_back(cliente);
		return true;
	} else {
		return false;
	}
}

int ParqueEstacionamento::posicaoCliente(const string& nome) const {
	for (size_t i = 0; i < clientes.size(); i++) {
		if (clientes[i].nome == nome) {
			return i;
		}
	}

	return -1;
}

bool ParqueEstacionamento::entrar(const string& nome) {
	int index = posicaoCliente(nome);
	if (index == -1) {
		return false;
	}

	InfoCartao* cliente = &clientes[index];
	if (cliente->presente || vagas == 0) {
		return false;
	}

	cliente->presente = true;
	vagas--;

	return true;

}

bool ParqueEstacionamento::retiraCliente(const string& nome) {
	int index = posicaoCliente(nome);
	if (index == -1) {
		return false;
	}

	InfoCartao* cliente = &clientes[index];
	if (cliente->presente) {
		return false;
	}

	clientes.erase(clientes.begin()+index);

	return true;
}

bool ParqueEstacionamento::sair(const string& nome) {
	int index = posicaoCliente(nome);
		if (index == -1) {
			return false;
		}

		InfoCartao* cliente = &clientes[index];
		if (!cliente->presente) {
			return false;
		}

		cliente->presente = false;
		vagas++;

		return true;
}

unsigned int ParqueEstacionamento::getNumMaximoClientes() const {
	return numMaximoClientes;
}

unsigned int ParqueEstacionamento::getNumLugaresOcupados() const {
	return lotacao - vagas;
}

unsigned int ParqueEstacionamento::getNumClientesAtuais() const {
	return clientes.size();
}
