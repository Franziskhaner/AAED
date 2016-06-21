#ifndef PILA_ENLA_H
#define PILA_ENLA_H
#include <cassert>

template <typename T>
class Pila {
public:
    Pila(); // constructor
    Pila(const Pila<T>& p); // ctor. de copia
    Pila<T>& operator =(const Pila<T>& p); // asignación
    bool vacia() const;
    const T& tope() const;
    void pop();
    void push(const T& x);
    ~Pila(); // destructor
private:
    struct nodo {
        T elto;
        nodo* sig;
        nodo(const T& e, nodo* p = 0): elto(e), sig(p) {}
    };
    nodo* tope_;
    void copiar(const Pila<T>& p);
};

template <typename T>
inline Pila<T>::Pila() : tope_(0) {}

template <typename T>
Pila<T>::Pila(const Pila<T>& p) : tope_(0)
{
    copiar(p);
}

template <typename T>
Pila<T>& Pila<T>::operator =(const Pila<T>& p)
{
    if (this != &p) { // evitar autoasignación
    this->~Pila(); // vaciar la pila actual
    copiar(p);
    }
    return *this;
}

template <typename T>
inline bool Pila<T>::vacia() const
{ return (!tope_); }

template <typename T>
inline const T& Pila<T>::tope() const
{
    assert(!vacia());
    return tope_->elto;
}

template <typename T>
inline void Pila<T>::pop()
{
    assert(!vacia());
    nodo* q = tope_;
    tope_ = q->sig;
    delete q;
}

template <typename T>
inline void Pila<T>::push(const T& x)
{
    tope_ = new nodo(x, tope_);
}
    // Destructor: vacía la pila
template <typename T>
Pila<T>::~Pila()
{
    nodo* q;
    while (tope_) {
        q = tope_->sig;
        delete tope_;
        tope_ = q;
    }
}
// Método privado
template <typename T>
void Pila<T>::copiar(const Pila<T>& p)
{
    if (!p.vacia()) {
        tope_ = new nodo(p.tope()); // copiar el primer elto
        // Copiar el resto de elementos hasta el fondo de la pila.
        nodo* q = tope_; // recorre la pila destino
        nodo* r = p.tope_->sig; // recorre la pila origen
        while (r) {
            q->sig = new nodo(r->elto);
            q = q->sig;
            r = r->sig;
        }
    }
}
#endif // PILA_ENLA_H
