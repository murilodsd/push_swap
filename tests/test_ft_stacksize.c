#include "minunit.h"
#include "pushswap.h"

t_stack_ref *stack_ref;

void test_setup(void) {
    stack_ref = ft_stacknewref('a');
}

void test_teardown(void) {
    ft_stackfree(&stack_ref);
}

MU_TEST(test_check_stacksize) {
    // Adicione alguns elementos à pilha
    ft_stackpush(stack_ref, ft_stacknewnode(1));
    ft_stackpush(stack_ref, ft_stacknewnode(2));
    ft_stackpush(stack_ref, ft_stacknewnode(3));

    // Verifique se a função ft_stacksize retorna o tamanho correto
    mu_assert_int_eq(3, ft_stacksize(stack_ref));
}

MU_TEST(test_check_stacksize_empty) {
    // Adicione alguns elementos à pilha

    // Verifique se a função ft_stacksize retorna o tamanho correto
    mu_assert(0 == ft_stacksize(stack_ref),"Lista vazia deveria ter tamanho zero");
}

MU_TEST_SUITE(test_suite) {
    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
    MU_RUN_TEST(test_check_stacksize);
    MU_RUN_TEST(test_check_stacksize_empty);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	stack_top_print(stack_ref);
	return minunit_status;
}