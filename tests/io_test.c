
#include "nx_application.h"
#include "nx_io.h"
#include "nx_test.h"

#include <stdlib.h>

/******************************************************************************************/
void test_io_init(void *data)
{
    struct nx_file *f;
    f = nx_fopen("test_file.txt", "w", 0);
    nx_test_assert(f != 0);
    
    int magic_nr = 7;
    int result = nx_fwrite(f, "Greek symbols: Λ ξ Σ, åäö, magic number: %i", magic_nr);
    nx_test_assert(result > 0);
    
    nx_fclose(f);
}

/******************************************************************************************/
void test_printf(void *data)
{
    nx_printf("Testing unicode printf: åäö, 水 火 風, Λ ξ Σ \n");
}

nx_test tests[] = {
    &test_io_init,
    &test_printf
};

/******************************************************************************************/
int main(int argc, char** argv)
{
    nx_init(NX_INIT_CORE);
    atexit(&nx_shutdown);
    
    nx_test_run(tests);
    return 0;
}
