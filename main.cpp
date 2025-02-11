#include <iostream>
#include "UnqPtrTests.h"
#include "ShrdPtrTests.h"

#include "DynamicArrayTests.h"

int main() {
    std::cout << "UnqPtr tests:\n";

    test_create_and_dereference();
    test_move_ptr();
    test_array_support();
    test_release();
    test_reset();
    test_is_free();
    std::cout << "\n";

    std::cout << "ShrdPtr tests:\n";
    test_empty_shared_ptr();
    test_shared_ptr_with_object();
    test_shared_ptr_copy();
    test_shared_ptr_move();
    test_shared_ptr_reset();
    test_shared_ptr_use_count();
    test_shared_ptr_dereference();
    std::cout << "\n";



    std::cout << "DynamicArray tests:\n";
    test_empty_array();
    test_array_with_size();
    test_array_with_elements();
    test_get_method();
    test_set_method();
    test_index_operator();
    test_resize();
    test_exceptions();



    return 0;
}
