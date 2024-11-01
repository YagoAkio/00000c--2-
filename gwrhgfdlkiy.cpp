#include "TADFILACP"
#include "TADFILAP"

void FilaC_com_FilaP(TdFilaP &P,TdFilaC &C){
	for(int i=0;i<C.fim;i++){
		inserirFP(P,retirarC(C));
	}
	for(int i=0;i<P.fim;i++);
	{
		inserirFC(C,retirar(P));
	}
}
