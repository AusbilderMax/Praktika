#include <stdio.h>

/** Fehler fehlendes #include <stdio.h>:
    4 |     printf("Hallo, Philipp!\n");
      |     ^~~~~~
hallo.c:1:1: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
  +++ |+#include <stdio.h>
    1 | 
hallo.c:4:5: warning: incompatible implicit declaration of built-in function ‘printf’ [-Wbuiltin-declaration-mismatch]
    4 |     printf("Hallo, Philipp!\n");
      |     ^~~~~~
hallo.c:4:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
*/

int main(void) {
    printf("Hallo, Philipp!\n");

/** Fehler falsches printf:
hallo.c: In function ‘main’:
hallo.c:16:5: error: implicit declaration of function ‘frintf’; did you mean ‘printf’? [-Wimplicit-function-declaration]
   16 |     frintf("Hallo, Philipp!\n");
      |     ^~~~~~
      |     printf
*/

    return 0;

/** Fehler fehlendes Semikolon:
hallo.c: In function ‘main’:
hallo.c:17:13: error: expected ‘;’ before ‘}’ token
   17 |     return 0
      |             ^
      |             ;
   18 | }
      | ~    
*/

}