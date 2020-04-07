#include <stdio.h>

int
main ()
{
    unsigned int R_bar;    /* "reset" control input--active low     */
    unsigned int S_bar;    /* "set" control--active low             */
    unsigned int Q_init;   /* initial value of Q output             */
    unsigned int P;        /* output value P                        */
    unsigned int Q_final;  /* output value of Q for stability check */

    /* Print a header for the list of stable states. */
    printf ("Stable states include the following:\n\n");
    printf (" R_bar S_bar | Q P\n");
    printf ("-------------+-----\n");

    /* Loop over all combinations of inputs. */
    for (R_bar = 0; 2 > R_bar; R_bar = R_bar + 1) {
        for (S_bar = 0; 2 > S_bar; S_bar = S_bar + 1) {

            /* Loop over all possible initial values of Q. */
            for (Q_init = 0; 2 > Q_init; Q_init = Q_init + 1) {
                
                /* Calculate output values. */
                P       = ((R_bar & Q_init) & 1);
                Q_final = ((S_bar & P     ) & 1);

                /* Check for stability. */
                if (Q_init == Q_final) {
                    printf ("   %d     %d   | %d %d\n",
                            R_bar, S_bar, Q_init, P);
                }
            }
        }
    }

    return 0;
}

