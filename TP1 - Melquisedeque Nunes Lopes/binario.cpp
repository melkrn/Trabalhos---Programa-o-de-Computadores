unsigned short bitsAltos(unsigned short numero) {
	numero = numero >> 8;
	return numero;
}

unsigned short bitsBaixos(unsigned short numero) {
	numero = numero << 8;
	numero = numero >> 8;
	return numero;
}

unsigned short orBinario(unsigned short numero1, unsigned short numero2) {
	return numero1 | numero2;
}

unsigned short andBinario(unsigned short numero1, unsigned short numero2) {
	return numero1 & numero2;
}

bool testarBit(unsigned short numero, unsigned short posicaoBit) {
	//Realiza um AND entre o número e a máscara
	return andBinario(numero, 1 << posicaoBit);
}

unsigned short desligarBit(unsigned short numero, unsigned short posicaoBit) {
	//Realiza um AND entre o número e o inverso da máscara
	return numero & (~(1 << posicaoBit));
}

unsigned short ligarBit(unsigned short numero, unsigned short posicaoBit) {
	//Realiza um OR entre o número e a máscara
	return numero | (1 << posicaoBit);
}