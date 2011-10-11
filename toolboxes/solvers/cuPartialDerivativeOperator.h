#pragma once

#include "partialDerivativeOperator.h"
#include "cuNDArray.h"

template <class REAL, class T, unsigned int D> class EXPORTSOLVERS cuPartialDerivativeOperator : public partialDerivativeOperator< REAL, D, cuNDArray<T> >
{
  
public:
  
  cuPartialDerivativeOperator( unsigned int dimension ) : partialDerivativeOperator< REAL, D, cuNDArray<T> >( dimension ) {}
  virtual ~cuPartialDerivativeOperator() {}
      
  virtual int compute_partial_derivative( typename intd<D>::Type stride, cuNDArray<T> *in, cuNDArray<T> *out, bool accumulate );  

  virtual int compute_second_order_partial_derivative( typename intd<D>::Type forwards_stride, typename intd<D>::Type adjoint_stride, 
						       cuNDArray<T> *in, cuNDArray<T> *out, bool accumulate );  
};