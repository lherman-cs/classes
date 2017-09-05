#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node();
    Node(double coef, int exp);
    ~Node();

    Node* getNext();
    double getCoef();
    int getExp();
    void setCoef(double coef);
    void setExp(int exp);
    void setNext(Node*);

private:
    double coef;
    int exp;
    Node* next;
};

#endif
