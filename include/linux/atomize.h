/*
 * atomize.h	Definitions of routines for processes atomization
 *
 * Authors:	Rodrigo Siqueira
 */

#ifndef _ATOMIZE_H
#define _ATOMIZE_H

#ifdef CONFIG_ATOMIZE

#include <linux/kobject.h>

/*
 * @pid PID from processes that required atomization
 */
struct particle
{
	struct kobject kobj;
	int id;
	unsigned long pid;
};

/*
 * First initialization of atomize system
 */
extern void atomize_init(void);

#endif //CONFIG_ATOMIZE
#endif
