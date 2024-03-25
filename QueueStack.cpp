#include<iostream>
#include<list>
#include<ctime>
#include <chrono>




//------------------stackMass------------

const int array_size = 100;
template <typename T>
struct stack_mass {
    T* hop; 
    T mass[array_size];
    int counter_of_elm = 0;


    void add_element(T elm)
    {

        //переполнение стека
        if (counter_of_elm == 0)
        {
            mass[0] = elm;
            hop = &mass[0]; 
            counter_of_elm++;
        }
        else
        {
            if (counter_of_elm <= array_size)
            {
                hop++;  //добовляем элемент 
                *hop = elm;
                counter_of_elm++;
            }
            else
            {
                std::cout << "error  переполнение стека \n";
            }
        }
    }
     T get_element()
     {
         if (counter_of_elm == 0)
         {
             std::cout << "there is nothing in stack \n";
             return -1; 
         }
         else
         {
             if (counter_of_elm == 1)
             {

                 hop = nullptr;
                 counter_of_elm--;
                 return mass[0];
             }
             else
             {
                 T elm = *hop;
                 hop--;
                 counter_of_elm--;
                 return elm;
             }
         }
     }

};


//-------------------------queueMass---------------------


template <typename T>
struct queue_mass {
    T* first;
    T* last;
    T mass[array_size];
    int counter_of_elm = 0;

    void queue_element(T elm)
    {

        //переполнение очереди
        if (counter_of_elm == 0)
        {
            mass[0] = elm;
            *last = mass[0];
            counter_of_elm++;
        }
        else
        {
            if (counter_of_elm <= array_size)
            {
                last++;  //добовляем элемент 
                last = elm;
                counter_of_elm++;
            }
            else
            {
                std::cout << "error  переполнение очереди. \n";
            }
        }
    }
    T get_element()
    {
        if (counter_of_elm == 0)
        {
            std::cout << "there is nothing in  \n";
            return -1;
        }
        else
        {
            if (counter_of_elm == 1)
            {

                first = nullptr;
                counter_of_elm--;
                return mass[0];
            }
            else
            {
                T elm = *first;
                first++;
                counter_of_elm--;
                return elm;
            }
        }
    }

};


//------------------queueList----------------------


template <typename S>
struct queue_list {
    S* first;
    int count_el = 0;
    std::list<S> newList;

    void add_el(S el) {
        if (count_el == 0) {
            newList.push_back(el);
            count_el++;
            first = &newList.front();
        }
        else
        {
            if (count_el <= maxSize)
            {
                newList.push_back(el);
                count_el++;
            }
            else
            {
                std::cout << "очередь переполнена\n";
            }
        }
    }

    S get_element() {
        if (count_el == 0)
        {
            std::cout << "очередь пуста\n";
            return -1;
        }
        else
        {
            if (count_el == 1)
            {
                first = nullptr;
                count_el--;
                return newList.front();
            }
            else
            {
                S el = *first;
                newList.pop_front();
                first = &newList.front();
                count_el--;
                return el;
            }
        }
    }

};



//-------------stackList-----------

template<typename M>
struct stack_list
{
    std::list<M> newList;
    M* hop;
    int count_el = 0;

    void add_el(M el) {
        if (count_el < maxSize) {
            newList.push_back(el);
            count_el++;
            hop = &newList.back();
        }
        else
        {
            std::cout << "стек переполнен\n";
        }
    }

    M get_element() {
        if (count_el == 0)
        {
            std::cout << "стек пуст!\n";
            return -1;
        }
        else
        {
            if (count_el == 1)
            {
                hop = nullptr;
                count_el--;
                return newList.back();
            }
            else
            {
                M el = *hop;
                newList.pop_back();
                hop = &newList.back();
                count_el--;
                return el;
            }
        }
    }
};



int main(){

    unsigned long long start_time = clock();
    setlocale(LC_ALL, "");
    stack_mass<int>stack_arr;
    queue_mass<int>queue_arr;
    //stack_list<int>stack_list;
    //queue_list<int>queue_list;

    stack_arr.add_element(4);
    queue_arr.get_element();
    std::cout << stack_arr.get_element();
    std::cout << queue_arr.get_element();
    //std::cout << stack_list.add_el();
    //std::cout << queue_list.add_el();



//    setlocale(LC_ALL, "RU");
//
//    //QUEUE ARR
//    std::cout << "queue arr\n" << std::endl;
//
//    queue_mass<int> queue_arr;
//
//    auto startQuArr = std::chrono::high_resolution_clock::now();
//
//    for (int i = 0; i < maxSize; i++) {
//        queue_arr.get_element(i);
//    }
//    for (int j = 0; j < maxSize; j++) {
//        std::cout << queue_arr.get_element() << std::endl;
//    }
//
//    auto endQuArr = std::chrono::high_resolution_clock::now();
//    std::chrono::duration<double> duration = endQuArr - startQuArr;
//
//    std::cout << "Время выполнения программы: " << duration.count() << " секунд" << std::endl;
//   
//
//
//    return 0;
//}
