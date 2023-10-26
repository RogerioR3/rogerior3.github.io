#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t c1;
    pid_t c2 = 0;

    c1 = fork(); /* fork numero 1 */
				/* fork numero 1: Cria um processo filho C1 */
    if(c1 == 0)
        c2 = fork(); /* fork numero 2 */
					/* fork numero 2: Cria um processo filho C2, apenas se estivermos no processo C1 */
    fork(); /* fork numero 3 */
			/* fork numero 3: Cria um processo filho, independente do processo atual */
    if(c2 > 0)
        fork(); /* fork numero 4 */
				/* fork numero 4: Cria um processo filho, apenas se estivermos no processo C2 */

    return 0;
}