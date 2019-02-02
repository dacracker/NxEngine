
#include "nx_application.h"
#include "nx_test.h"

/******************************************************************************************/
void test_init(void *data)
{
    nx_init(NX_INIT_CORE);
}

/******************************************************************************************/
void test_shutdown(void *data)
{
    nx_shutdown();
}

nx_test tests[] = {
    &test_init,
    &test_shutdown
};

/******************************************************************************************/
int main(int argc, char** argv)
{
    nx_test_run(tests);
    return 0;
}
