# Hardware-Implementation-of-Quantum-Fourier-Transform
A quantum method called the Quantum Fourier Transform (QFT) applies a Fourier transform to a quantum state. It is an essential component of quantum computing and finds use in processes like signal processing, quantum simulation, and cryptography. 

The Fourier transform occurs in different versions throughout classical computing, in areas
ranging from signal processing to data compression to complexity theory. The quantum Fourier
transform is the quantum implementation of the discrete Fourier transform over the amplitudes
of wavefunction. It is a part of many quantum algorithms, like Shor’s algorithm and quantum
phase estimation.
The quantum Fourier transform can be performed efficiently on a quantum computer with a
decomposition into the product of simpler unitary matrices. The discrete Fourier transform on
2^n amplitudes can be implemented as a quantum circuit consisting of only O(2^n) Hadamard
gates and controlled phase shift gates, where n is the number of qubits
The quantum Fourier transform acts on a quantum state vector (a quantum register), and the
classical Fourier transform acts on a vector. Both types of vectors can be written as lists of
complex numbers. In the quantum case it is a sequence of probability amplitudes for all the
possible outcomes upon measurement (called basis states, or eigenstates). Because
measurement collapses the quantum state to a single basis state, not every task that uses the
classical Fourier transform can take advantage of the quantum Fourier transform's exponential
speedup.

#### Note: Additional Information can be found in the ProjectReport.Pdf
