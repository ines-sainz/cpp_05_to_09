/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:42:16 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/10 15:42:20 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750

/**
 * @brief Main function demonstrating the use of the Array template class.
 * 
 * Creates an Array of integers and a mirror array, fills them with random
 * values, then tests copy construction and assignment within a scope.
 * Verifies that copied values match the original, and tests out-of-bounds
 * access with exception handling. Finally, reassigns random values and cleans
 * up allocated memory.
 * 
 * @param argc Argument count (unused).
 * @param argv Argument vector (unused).
 * @return int Returns 0 on success, or 1 if a value mismatch is detected.
 */
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "test[0]: " << test[0] << std::endl;
        std::cout << "tmp[0]: " << tmp[0] << std::endl;
        test[0] = 2;
        std::cout << "2test[0]: " << test[0] << std::endl;
        std::cout << "2tmp[0]: " << tmp[0] << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << numbers[i] << " ";
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "\n";
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
