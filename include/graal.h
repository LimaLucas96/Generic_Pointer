#ifndef GRAAL_H
#define GRAAL_H

#include <cstring>//memcpy

using compare=bool (*)(const void *,const void *);

//using Compare=int (*)( const void *a, const void *b );

using byte = char;

using Predicate = bool (*)(const void *);

using Equal=bool (*)(const void *,const void*);

namespace graal{
	const void *min(const void *first,const void *last,size_t size,compare cmp);

	void reverse(void *first,void *last,size_t size);

	void *copy(const void *first,const void *last, void *d_first,size_t size);

	void *clone(const void *first,const void *last, size_t size);

	const void *find_if(const void *first,const void *last, size_t size, Predicate p);

	const void *find(const void *first,const void *last, size_t size,const void *value, Equal eq);

	bool all_of(const void *first,const void *last, size_t size, Predicate p);

	bool any_of(const void *first,const void *last, size_t size, Predicate p);

	bool none_of(const void *first,const void *last, size_t size, Predicate p);

	bool equal(const void *first1,const void *last1,const void *first2, size_t size,Equal eq);

	bool equal(const void *first1,const void *last1,const void *first2,const void *last2, size_t size, Equal eq);

	void *unique(void *first,void *last,size_t size,Equal eq);

	void *partition(void *first,void *last,size_t size, Predicate p);

	void qsort(void *first, size_t num, size_t size, compare cmp);
	
}

#endif