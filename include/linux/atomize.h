/*
 * We got inspiration from the atomic model for this concept. In a few
 * words: we view a process as an atom and each one can be divided into
 * small particles, which in turn can be classified based on different
 * criteria. Additionally, there is a bunch of properties related to
 * atoms. Our processes can be divided into many different particles,
 * each one with a different purpose.
 *
 * atomize.h	Definitions of routines for processes atomization
 *
 * Authors:	Rodrigo Siqueira
 */

#ifndef _ATOMIZE_H
#define _ATOMIZE_H

#ifdef CONFIG_ATOMIZE

#include <linux/kobject.h>

enum ATOMIZE_OPERATIONS {
	TRANSMUTATION = 0,
	DESTROY,
};

/*
 * Atom is a representation of process characteristics
 *
 * @particles Map particle id with the corresponding data structure
 * @atomize_lock Lock to access control for add and remove idr
 */
struct atom {
	struct idr particles;
	spinlock_t atomize_lock;
};

/*
 * @id Unique identification into the atom
 * @composition Particles can be classified according to composition, our
 *		process too
 */
struct particle {
	struct kobject kobj;
	int id;
	struct task_struct *composition;
};

/*
 * Initial setup atomization elements
 */
void atomize_init(void);

/*
 * In atomic theory, nuclear transmutation converts one element into
 * another similar, but not equal. Here we have a similar behaviour
 * related to process, since transmutation works like a snapshot into
 * the processes and copy it in specific state.
 *
 * @return On caller processes return the particle id, on the copy
 *	element it returns -1
 */
int transmutation(void);

/*
 * Destroy particle
 */
int destroy(int id);

#endif //CONFIG_ATOMIZE
#endif
