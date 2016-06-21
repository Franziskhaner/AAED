#ifndef COLA_ENLA_H
#define COLA_ENLA_H
#include <cassert>

template <typename T> class Cola {
    public:
        Cola(); // constructor
        Cola(const Cola<T>& p); // ctor. de copia
        Cola<T>& operator =(const Cola<T>& p); // asignación de colas
        bool vacia() const;
        const T& frente() const;
        void pop();
        void push(const T& x);
        ~Cola(); // destructor
    private:
        struct nodo {
            T elto;
            nodo* sig;
            nodo(const T& e, nodo* p = 0): elto(e), sig(p) {}
        };
        nodo *inicio, *fin; // extremos de la cola
        void copiar(const Cola<T>& c);
};

// Método privado
template <typename T>
void Cola<T>::copiar(const Cola<T>& c)
{
    if (c.inicio) { // c no está vacía
        // Copiar el primer elto.
        inicio = fin = new nodo(c.inicio->elto);
        // Copiar el resto de elementos hasta el final de la cola.
        for (nodo *q = c.inicio->sig; q; q = q->sig) {
            fin->sig = new nodo(q->elto);
            fin = fin->sig;
        }
    }
}

template <typename T>
inline Cola<T>::Cola() : inicio(0), fin(0) {}

template <typename T>
inline Cola<T>::Cola(const Cola<T>& c) : inicio(0), fin(0)
{
    copiar(c);
}

template <typename T>
inline Cola<T>& Cola<T>::operator =(const Cola<T>& c)
{
    if (this != &c) { // evitar autoasignación
        this->~Cola(); // vaciar la cola actual
        copiar(c);
}
    return *this;
}

template <typename T>
inline bool Cola<T>::vacia() const
{
    return (inicio == 0);
}

template <typename T>
inline const T& Cola<T>::frente() const
{
    assert(!vacia());
    return inicio->elto;
}

template <typename T>
inline void Cola<T>::pop()
{
    assert(!vacia());
    nodo* q = inicio;
    inicio = q->sig;
    if (!inicio) fin = 0;
    delete q;
}

template <typename T>
inline void Cola<T>::push(const T& x)
{
    nodo* q = new nodo(x);
    if (inicio == 0) // cola vacía
        inicio = fin = q;
    else
        fin = fin->sig = q;
}

// Destructor: vacía la cola
template <typename T>
Cola<T>::~Cola()
{
    nodo* q;
    while (inicio) {
        q = inicio->sig;
        delete inicio;
        inicio = q;
    }
    fin = 0;
}
#endif // COLA_ENLA_H
