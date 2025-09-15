// ["MyCircularQueue","enQueue","enQueue","enQueue","enQueue","deQueue","deQueue","isEmpty","isEmpty","Rear","Rear","deQueue"]
// [[8],                [3],        [9],    [5],        [0],    [],         [],     [],         [],     [],     [],     []]
// [null,               true,       true,   true,       true,   true,       true,   false,      false,  0,      0,      true]
class MyCircularQueue 
{
  public:
    MyCircularQueue(int k) 
    : m_capacity{k}
    {
        m_array = new int[m_capacity];
        m_head = 0;
        m_tail = 0;
        m_size = 0;
    }

    ~MyCircularQueue() 
    {
        delete[] m_array;
    }
    
    bool enQueue(int value) 
    {
        if (isFull())
        {
            return false;
        }

        m_array[m_tail] = value;
        m_tail = (m_tail + 1) % m_capacity;
        m_size += 1;
        return true;
    }
    
    // From head.
    bool deQueue() 
    {
        if (isEmpty())
        {
            return false;
        }

        m_head = (m_head + 1) % m_capacity;
        m_size -= 1;

        return true;
    }
    
    int Front() 
    {
        if (isEmpty())
        {
            return -1;
        }
        return m_array[m_head];
    }
    
    int Rear() 
    {
        if (isEmpty())
        {
            return -1;
        }

        auto tmp = m_tail - 1;
        if (tmp < 0)
        {
            tmp = m_capacity - 1;
        }
        return m_array[tmp];
    }
    
    bool isEmpty() 
    {
        return (m_size == 0);
    }
    
    bool isFull() 
    {
        return (m_size == m_capacity);
    }

  private:
    int m_capacity;
    int* m_array;
    int m_tail;
    int m_head;
    int m_size;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

 int main()
 {
    MyCircularQueue queue{3};

    return 0;
 }