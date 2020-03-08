/*
 * Compile with the following command:
 *    gcc hello_world.c -o hello
 *
 * There should now be an executable in your directory called "hello" which you
 * should be able to run using ./hello.
 *
 * If you leave off the "-o hello" there will be an executable called "a.out"
 * which you can run the same way.
 *
 * Now try printing numbers and other things!
 * http://www.cplusplus.com/reference/clibrary/cstdio/printf/
 */
#include <time.h>
#include <stdio.h>

int main () {

    char* c_time_string;
    time_t current_time;
    current_time = time(NULL);

    /* Convert to local time format. */
    c_time_string = ctime(&current_time);

    printf("Current time is %s", c_time_string);
  printf ("Hello world!\n");
  return 0;
}
