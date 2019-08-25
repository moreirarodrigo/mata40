#include <stdio.h>
#include <stdbool.h>

struct data {
	int dia;
	int mes;
	int ano;
};

struct periodo {
    struct data data_inicio;
    struct data data_fim;
    int numero_dia;
};

bool checkData(struct data d);

int main() {

	struct data	d;

	printf("\t\tDatas\n\t\t=====");

    printf("\n\nForneca uma data no formato:\n\tDia = ");
    scanf("%d", &d.dia);

	printf("\n\n\tMes = ");
	scanf("%d", &d.mes);

	printf("\n\n\tAno = ");
	scanf("%d", &d.ano);

	if(checkData(d)){
        printf("\n\nData valida");
	}else{
	    printf("\n\nData invalida");
	}

	printf("\n\n\nA data fornecida foi: %d/%d/%d\n", d.dia, d.mes, d.ano);

	return 0;
}


bool checkData(struct data d){
  if((d.dia >= 1 && d.dia <= 30) && (d.mes >= 1 && d.mes <= 12) && (d.ano >= 1900 && d.ano <= 2100)){
    return true;
  }else{
    return false;
  }
}
// Implementar depois a comparação de datas
//void compararData(struct data d1,struct data d2){
//  int dia = 0;
//  int mes = 0;
//  int ano = 0;
//  if(d1.dia > d2.dia){
//    dia = d1.dia - d2.dia;
//  }else{
//    dia = d2.dia - d1.dia;
//  }
//  if(d1.mes > d2.mes){
//    mes = d1.mes - d2.mes;
//  }else{
//    mes = d2.mes - d1.mes;
//  }
//  if(d1.ano > d2.ano){
//    ano = d1.ano - d2.ano;
//  }else{
//    ano = d2.ano - d1.ano;
//  }
//  printf("\nA diferença entre %d/%d/%d e %d/%d/%d é de %d dia(s) %d mes(es) e %d ano(s)", d1.dia, d1.mes, d1.ano, d2.dia, d2.mes, d2.ano, dia, mes, ano);
//}
