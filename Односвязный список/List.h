#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Person
{
    string name;
    int age;
};

class List
{
private:

    struct Node
    {
        Person m_data;
        Node* m_next;

        Node(const Person& data)
        {
            m_data = data;
            m_next = nullptr;
        }
    };

    Node* m_head;
    unsigned int m_size;

public:

    List();
    List(const List& list);
    ~List();

    List& operator=(const List& right);

    unsigned int GetSize() const;

    void Add(const Person& data);
    void Insert(const Person& data, int index);
    void RemoveAt(int index);

    void Print() const;

private:

    void Assign(const List& list);
    void RemoveHead();
    void RemoveAll();
};
