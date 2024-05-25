#ifndef __FILTER_H__
#define __FILTER_H__

#define FILTER_MAX_SIZE 16

typedef struct filter {
  vuint16 a[FILTER_MAX_SIZE];
  vuint8 ai;
  vuint8 an;
  vuint32 as;
} filter_t;

extern void filter_init( vuint16 v, filter_t *f, vuint8 n );
extern vuint16 filter_calc( vuint16 v, filter_t *f, vuint8 n );

#endif
