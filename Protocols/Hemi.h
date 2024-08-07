/*
 * Hemi.h
 *
 */

#ifndef PROTOCOLS_HEMI_H_
#define PROTOCOLS_HEMI_H_

#include "Semi.h"
#include "HemiMatrixPrep.h"

/**
 * Matrix multiplication optimized with semi-homomorphic encryption
 */
template<class T>
class Hemi : public T::BasicProtocol
{
    map<array<int, 3>, typename T::MatrixPrep*> matrix_preps;
    DataPositions matrix_usage;

    MatrixMC<T> mc;

public:
    Hemi(Player& P) :
            T::BasicProtocol(P)
    {
    }
    ~Hemi();

    typename T::MatrixPrep& get_matrix_prep(const array<int, 3>& dimensions,
            SubProcessor<T>& processor);

    bool use_plain_matmul(const array<int, 3> dimensions,
            SubProcessor<T>& processor);

    ShareMatrix<T> matrix_multiply(const ShareMatrix<T>& A, const ShareMatrix<T>& B,
            SubProcessor<T>& processor);

    void matmulsm(SubProcessor<T>& processor, MemoryPart<T>& source,
            const Instruction& instruction);
    void conv2ds(SubProcessor<T>& processor, const Instruction& instruction);
};

#endif /* PROTOCOLS_HEMI_H_ */
