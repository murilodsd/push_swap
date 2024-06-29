#include "minunit.h"
#include "pushswap.h"

t_stack_ref *stack_ref;

void test_setup(void) {
	//o que sera rodado depois de cada teste
}

void test_teardown(void) {
	//o que será rodado após cada teste;
}

//Fazemos um MU_TEST para cada teste em geral.
//Se colocarmos mais de um teste dentro do MU_TEST, no caso de falha, os seguintes nao serao executados
//O parametro deve ser um nome que remeta ao teste realizado
MU_TEST(test_1_saida_deve_ser_null) {
	//ARRANGE (CONFIGURAÇÃO DO AMBIENTE DE TESTE) obs: dependendo pode estar no setup
	int expected;
	int result;

	//ACT (AÇÃO A SER TESTADA)
	
	
	//ASSERT (VERIFICAR SE RESULTADO É O ESPERADO)
	mu_assert_int_eq(expected,result);//compara dois inteiros
	mu_check("resultado esperado"=="resultado real");//recebe uma comparacao
	mu_assert("resultado esperado"=="resultado real","msg de erro");//recebe uma comparacao e exibe uma msg no caso de falha
}

//Macro que rodara nosso testes
//Primeiro configuramos as funcoes a rodarem ao inicio e final de cada teste
//Depois usamos a macro MU_RUN_TEST para rodar cada teste criado repassando seu nome
MU_TEST_SUITE(test_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
	MU_RUN_TEST(test_1);
	MU_RUN_TEST(test_2);
}

//Na nossa main rodamos a suite e o report.
int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return minunit_status;
}

/*
mu_check(condition): will pass if the condition is evaluated to true, otherwise it will show the condition as the error message

mu_fail(message): will fail and show the message

mu_assert(condition, message): will pass if the condition is true, otherwise it will show the failed condition and the message

mu_assert_int_eq(expected, result): it will pass if the two numbers are equal or show their values as the error message

mu_assert_double_eq(expected, result): it will pass if the two values are almost equal or show their values as the error message. The value of MINUNIT_EPSILON sets the threshold to determine if the values are close enough.
*/