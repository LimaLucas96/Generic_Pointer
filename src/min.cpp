#include "../include/graal.h"
namespace graal{

	//questao 1
	const void *min(const void *first,const void *last,size_t size,compare cmp){

		const byte *it=static_cast<const byte *>(first);

		const byte *smalltest = it;

		while(it != last){
			if(cmp(it,smalltest)){
				smalltest=it;
			}
			it+=size;
		}

		return smalltest;
	}
	
	//questao 2	
	void reverse(void *first,void *last,size_t size){

		byte *f=static_cast<byte *>(first);
		byte *l=static_cast<byte *>(last);
		byte *temp[size];
		l-=size;

		while (f<l){
			std::memcpy(temp,f,size);
			std::memcpy(f,l,size);
			std::memcpy(l,temp,size);

			f+=size;
			l-=size;
		}
	}

	//questao 3
	void *copy(const void *first,const void *last, void *d_first,size_t size){
	
		const byte *f=static_cast<const byte *>(first);
		 byte *df=static_cast< byte *>(d_first);

		while (f<last){
			std::memcpy(df,f,size);
			df+=size;
			f+=size;
		}

		return df;
	}

	//questao 4
	void *clone(const void *first,const void *last, size_t size){
		//tamanho do vetor
		const byte *f=static_cast<const byte *>(first);
		const byte *l=static_cast<const byte *>(last);
		int num=(l-f);

		byte *vet=new byte[num];
		byte *temp=vet;
		while(f<last){
			std::memcpy(vet,f,size);
			f+=size;
			vet+=size;
		}

		return temp;
	}

	//questao 5
	const void *find_if(const void *first,const void *last, size_t size, Predicate p){
		const byte *f=static_cast<const byte *>(first);

		while(f<last){
			if(p(f)){
				return f;
			}

			f+=size;
		}

		return last;
	}

	//questao 6
	const void *find(const void *first,const void *last, size_t size,const void *value, Equal eq){
		const byte *f=static_cast<const byte *>(first);
		const byte *v=static_cast<const byte *>(value);

		while (f<last){
			if(eq(f,v)){
				return f;
			}

			f+=size;
		}

		return last;
	}


	//questao 7
	bool all_of(const void *first,const void *last, size_t size, Predicate p){
		const byte *f=static_cast<const byte *>(first);

		while (f<last){
			if(p(f)==false){
				return false;
			}
			f+=size;
		}
		return true;
	}

	//questao 7
	bool any_of(const void *first,const void *last, size_t size, Predicate p){
		const byte *f=static_cast<const byte *>(first);

		while (f<last){
			if(p(f)){
				return true;
			}

			f+=size;
		}

		return false;
	}

	//questao 7
	bool none_of(const void *first,const void *last, size_t size, Predicate p){
		const byte *f=static_cast<const byte *>(first);

		while (f<last){
			if(p(f)){
				return false;
			}
			f+=size;
		}

		return true;
	}

	//questao 8
	bool equal(const void *first1,const void *last1,const void *first2, size_t size,Equal eq){
		const byte *f1=static_cast<const byte *>(first1);
		const byte *f2=static_cast<const byte *>(first2);

		const byte *f=f1;
		const byte *ff=f2;
		const byte *l=static_cast<const byte *>(last1);

		while(f2<(ff+(l-f))){
			if(eq(f2,f1)==false){
				return false;
			}

			f1+=size;
			f2+=size;
		}

		return true;
	}

	//questao 8
	bool equal(const void *first1,const void *last1,const void *first2,const void *last2, size_t size, Equal eq){
		const byte *f1=static_cast<const byte *>(first1);
		const byte *f2=static_cast<const byte *>(first2);

		while(f1<last1 && f2<last2){
			if(eq(f1,f2)==false){
				return false;
			}

			f1+=size;
			f2+=size;
		}

		return true;
	}

	//questao 9
	void *unique(void *first,void *last,size_t size,Equal eq){
		byte *f=static_cast<byte *>(first);
		byte *aux=f;
		bool test=false;

		for (f;f<last;f+=size){
			test=false;
			for (byte *j=static_cast<byte *>(first);j<f;j+=size){
				if(eq(f,j)){
					test=true;
				}
			}

			if(test == false){
				std::memcpy(aux,f,size);
				aux+=size;
			}
		}

		return aux;
	}

	//questao 10
	void *partition(void *first,void *last,size_t size, Predicate p){
		byte *f=static_cast< byte *>(first);
		byte *slow=f;
		byte *temp[size];

		while (f<last){
			if(p(f)){
				std::memcpy(temp,slow,size);
				std::memcpy(slow,f,size);
				std::memcpy(f,temp,size);
				slow+=size;
			}

			f+=size;
		}

		return slow;
	}

	//questao 11
	void qsort(void *first, size_t num, size_t size, compare cmp){
		byte *f1=static_cast< byte *>(first);
		byte *temp[size];

		for(byte *f=static_cast<byte *>(first); f < f1+((num-1)*size); f+=size){

			for(byte *includeS=f; includeS < f1+(num*size); includeS+=size){
				
				if(cmp(includeS,f)){

					std::memcpy(temp,f,size);
					std::memcpy(f,includeS,size);
					std::memcpy(includeS,temp,size);

				}
			}
		}
	}
}





