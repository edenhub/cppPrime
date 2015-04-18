#include <iostream>
//decare the class,for pre use the class
template<class Type> class Queue;
//decare the function,for pre use the function
template<class T> std::ostream& operator<<(std::ostream& ,const Queue<T>&);

template<class Type>
class QueueItem{
    //identify the template for the class
    friend class Queue<Type>;
    //identifiy the template for the function
    friend std::ostream& operator<< <Type>(std::ostream&,const Queue<Type>&);

    QueueItem(const Type& t):item(t),next(0){}

private:
    Type item;
    QueueItem* next;
};

template<class Type>
class Queue{
    Queue():head(0),tail(0){}

    template<class It> 
    Queue(It beg,It end):head(beg),tail(end){
        copy_elems(beg,end);
    }

    Queue(const Queue& q):head(0),tail(0){
        copy_elems(q);
    }

    Queue& operator=(const Queue&);
    ~Queue(){
        destroy();
    }

    Type& front(){
        return head->item;
    }
    const Type& front() const{
        return head->item;
    }
    void push(const Type&);
    void pop();
    bool empty() const{
        return head==0;
    }

    template<class Iter> void assgin(Iter,Iter);

private:
    QueueItem<Type> *head;
    QueueItem<Type> *tail;

    void destroy();
    void copy_elems(const Queue&);
    template<class Iter> void copy_elems(Iter,Iter);
};

template<class Type> void Queue<Type>::push(const Type& e){
    
}

template<class Type> void Queue<Type>::pop(){}

template<class Type> template<class Iter>
void Queue<Type>::copy_elems(Iter beg,Iter end){

}

template<class Type> template<class Iter>
void Queue<Type>::assgin(Iter beg,Iter end){

}

int main(){
    return 0;
}