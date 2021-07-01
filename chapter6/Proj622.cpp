/*
 * Proj622.cpp
 *
 *  Created on: 2015-1-8
 *      Author: basstal
 */
void exchangePtr(void *,void *);
void exchangePtr(void *a,void *b){
	void *tmp;
	tmp=a;
	a=b;
	b=tmp;
}





