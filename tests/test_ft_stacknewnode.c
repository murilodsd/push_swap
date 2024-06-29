/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_stacknewnode.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 09:20:29 by mde-souz          #+#    #+#             */
/*   Updated: 2024/06/29 23:44:49 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "pushswap.h"

MU_TEST(test_newnode_notnull) //Se colocarmos mais de um teste aqui e um deles falhar, os seguintes não serão executados
{
    int		nbr = 5;
    t_stack	*node;
    
    node = ft_stacknewnode(nbr);
    mu_assert(node != NULL, "node should not be NULL");
	free(node);
}

MU_TEST(test_node_value)
{
    //ARRANGE (CONFIGURAÇÃO DO AMBIENTE DE TESTE)
    int		nbr = 5;
    t_stack	*node;
    
    //ACT (AÇÃO A SER TESTADA)
    node = ft_stacknewnode(nbr);
    
    //ASSERT (VERIFICAR SE RESULTADO É O ESPERADO)
    mu_assert_int_eq(5, node->nbr);	
    free(node);
}

MU_TEST(test_node_previous)
{
    //ARRANGE (CONFIGURAÇÃO DO AMBIENTE DE TESTE)
    int		nbr = 5;
    t_stack	*node;
    
    //ACT (AÇÃO A SER TESTADA)
    node = ft_stacknewnode(nbr);
    
    //ASSERT (VERIFICAR SE RESULTADO É O ESPERADO)
    mu_assert(node->previous != NULL, "previous node should be NULL for a new node");
	
    free(node);
}
MU_TEST(test_node_next)
{
    //ARRANGE (CONFIGURAÇÃO DO AMBIENTE DE TESTE)
    int		nbr = 5;
    t_stack	*node;
    
    //ACT (AÇÃO A SER TESTADA)
    node = ft_stacknewnode(nbr);
    
    //ASSERT (VERIFICAR SE RESULTADO É O ESPERADO)
    mu_assert_int_eq((int) NULL, (int)node->next);
	
    free(node);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_newnode_notnull);
    MU_RUN_TEST(test_node_previous);
    MU_RUN_TEST(test_node_next);
}



int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return minunit_status;
}