/* this file handles logging.
 * logging should only be done if DEBUG is not 0 */
#ifndef __ENG_LOG_H
#define __ENG_LOG_H

#include <stdio.h>
#include "strings.h"
#include "error.h"

#define LOG_LINE_SIZE	1000

/* logs l using format string fmt */
#define log(l,fmt) (__appendlog((void *)l, fmt))
void __appendlog(void *l, char *fmt);

int clearfile(char *fname);

#endif
