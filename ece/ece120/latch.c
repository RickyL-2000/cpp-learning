/*									tab:8
 *
 * latch.c - find stable states for an R-bar/S-bar latch
 *
 * "Copyright (c) 2017 by Steven S. Lumetta."
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement is
 * hereby granted, provided that the above copyright notice and the following
 * two paragraphs appear in all copies of this software.
 * 
 * IN NO EVENT SHALL THE AUTHOR OR THE UNIVERSITY OF ILLINOIS BE LIABLE TO 
 * ANY PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL 
 * DAMAGES ARISING OUT  OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, 
 * EVEN IF THE AUTHOR AND/OR THE UNIVERSITY OF ILLINOIS HAS BEEN ADVISED 
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * THE AUTHOR AND THE UNIVERSITY OF ILLINOIS SPECIFICALLY DISCLAIM ANY 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE 
 * PROVIDED HEREUNDER IS ON AN "AS IS" BASIS, AND NEITHER THE AUTHOR NOR
 * THE UNIVERSITY OF ILLINOIS HAS ANY OBLIGATION TO PROVIDE MAINTENANCE, 
 * SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
 *
 * Author:	    Steve Lumetta
 * Version:	    1
 * Creation Date:   13 February 2017
 * Filename:	    latch.c
 * History:
 *	SL	1	13 February 2017
 *		First written.
 */

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
                P       = ((~(R_bar & Q_init)) & 1);
                Q_final = ((~(S_bar & P     )) & 1);

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

