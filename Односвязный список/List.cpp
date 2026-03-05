#include "List.h"

List::List() : m_head(nullptr), m_size(0U)
{
}

List::List(const List& list) : m_head(nullptr), m_size(0U)
{
    Assign(list);
}

List::~List()
{
    RemoveAll();
}

List& List::operator=(const List& right)
{
    if (this != &right)
    {
        Assign(right);
    }

    return *this;
}

unsigned int List::GetSize() const
{
    return m_size;
}

void List::Add(const Person& data)
{
    Node* newNode = new Node(data);

    if (m_head == nullptr)
    {
        m_head = newNode;
    }
    else
    {
        Node* temp = m_head;

        while (temp->m_next != nullptr)
        {
            temp = temp->m_next;
        }

        temp->m_next = newNode;
    }

    ++m_size;
}

void List::Insert(const Person& data, int index)
{
    if (index < 0 || index > m_size)
        return;

    Node* newNode = new Node(data);

    if (index == 0)
    {
        newNode->m_next = m_head;
        m_head = newNode;
    }
    else
    {
        Node* temp = m_head;

        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->m_next;
        }

        newNode->m_next = temp->m_next;
        temp->m_next = newNode;
    }

    ++m_size;
}

void List::RemoveAt(int index)
{
    if (index < 0 || index >= m_size)
        return;

    if (index == 0)
    {
        RemoveHead();
        return;
    }

    Node* temp = m_head;

    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->m_next;
    }

    Node* nodeToDelete = temp->m_next;
    temp->m_next = nodeToDelete->m_next;

    delete nodeToDelete;

    --m_size;
}

void List::Assign(const List& list)
{
    RemoveAll();

    Node* node = list.m_head;

    while (node != nullptr)
    {
        Add(node->m_data);
        node = node->m_next;
    }
}

void List::Print() const
{
    Node* temp = m_head;

    while (temp != nullptr)
    {
        cout << temp->m_data.name << " "
             << temp->m_data.age << endl;

        temp = temp->m_next;
    }

    cout << endl;
}

void List::RemoveHead()
{
    if (m_head != nullptr)
    {
        Node* node = m_head;
        m_head = m_head->m_next;

        delete node;
        --m_size;
    }
}

void List::RemoveAll()
{
    while (m_head != nullptr)
    {
        RemoveHead();
    }
}
