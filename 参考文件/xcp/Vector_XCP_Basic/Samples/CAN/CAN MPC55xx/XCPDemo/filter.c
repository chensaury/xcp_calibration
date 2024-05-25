
#include "project.h"

#include "filter.h"


void filter_init( vuint16 v, struct filter *f, vuint8 n ) {

  register vuint8 i;

  if (n>FILTER_MAX_SIZE) n = FILTER_MAX_SIZE;

  f->ai = 0;
  f->as = n*v;
  f->an = n;
  for (i=0;i<FILTER_MAX_SIZE;i++) f->a[i] = v;
}
   
vuint16 filter_calc( vuint16 v, struct filter *f, vuint8 n ) {
                
  register vuint8 i;
  
  if (n==0||n>FILTER_MAX_SIZE) return v;
  if (n!=f->an) filter_init(v,f,n); // Reinitialize, if n changed
  
  i = f->ai;
  f->as -= f->a[i];
  f->as += v;
  f->a[i] = v;
  if (++i>=n) i = 0;
  f->ai = i;
  return (vuint16)(f->as/n);
}
