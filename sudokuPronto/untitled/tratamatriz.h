#ifndef TRATAMATRIZ_H
#define TRATAMATRIZ_H


class trataMatriz{
protected:
    int linha;
    int coluna;
public:
    trataMatriz();
    void setDados();
    virtual bool verificaSePode() = 0;
};

#endif // TRATAMATRIZ_H
