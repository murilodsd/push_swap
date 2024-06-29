#include "minunit.h"
#include "pushswap.h"

MU_TEST(test_ft_stackfree) {
    t_stack_ref *stack_ref = ft_stacknewref('a');

    // Adicione alguns elementos à pilha
    ft_stackpush(stack_ref, ft_stacknewnode(1));
    ft_stackpush(stack_ref, ft_stacknewnode(2));
    ft_stackpush(stack_ref, ft_stacknewnode(3));

    // Libere a memória
    ft_stackfree(&stack_ref);

    // Verifique se stack_ref é agora NULL
    mu_assert(stack_ref == NULL,"ponteiro deveria apontar para null");
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test_ft_stackfree);
}

int main(int argc, char const *argv[])
{
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return minunit_status;
}
