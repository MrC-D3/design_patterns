#include <unordered_map>
#include <vector>
#include <list>


using namespace std;


class LRUCache
{
  public:
    struct Node
    {
        Node(int key, int value)
        : m_key{key}, m_value{value}
        {}

        int m_key;
        int m_value;
    };

    LRUCache(int capacity)
    : m_capacity{capacity}
    {}

    int get(int key) 
    {
        // Problems in having a COPY of the iterator?
        auto it = m_memory.find(key);
        if (it == m_memory.end())
        {
            return -1;
        }

        // Present, so now check if it isn't already the link head.
        auto node_it = it->second;
        if (m_nodes.begin() != node_it)
        {
            m_nodes.splice(m_nodes.begin(), m_nodes, node_it);
            m_memory[key] = m_nodes.begin();
        }

        return m_nodes.begin()->m_value;
    }
    
    void put(int key, int value) 
    {
        auto it = m_memory.find(key);
        if (it == m_memory.end())
        {
            if (m_memory.size() == m_capacity)
            {
                m_memory.erase(m_memory.find(m_nodes.rbegin()->m_key));
                m_nodes.pop_back();
            }
            m_nodes.emplace_front(key, value);
            m_memory.try_emplace(key, m_nodes.begin());

            return;
        }

        // Here to update an existing Node: first the value...
        auto node_it = it->second;
        node_it->m_value = value;
        // ... then the link head, if not already the head.
        if (m_nodes.begin() != node_it)
        {
            m_nodes.splice(m_nodes.begin(), m_nodes, node_it);
            m_memory[key] = m_nodes.begin();
        }
    }

  private:
    int m_capacity;
    list<Node> m_nodes;
    unordered_map<int, list<Node>::iterator> m_memory;
};


class LRUCache_v1
{
  public:
    struct Node
    {
        Node(int key, int value, int parent_key, int child_key)
        : m_key{key}, m_value{value}, m_parent_key{parent_key}, m_child_key{child_key}
        {}

        int m_key;
        int m_value;
        int m_parent_key;
        int m_child_key;
    };

    LRUCache(int capacity)
    : m_capacity{capacity}, m_head_key{-1}, m_tail_key{-1}
    {}

    int get(int key) 
    {
        // Problems in having a COPY of the iterator?
        auto it = m_memory.find(key);
        if (it == m_memory.end())
        {
            return -1;
        }

        // Present, so now check if it isn't already the link head.
        auto& node = it->second;
        if (m_head_key != key)
        {
            // Update double link parent-child.
            // Opeator[] creates a Node if doesn't exist, so it expects a 
            //  default c'tor and - if there isn't - it doesn't compile.
            m_memory.at(node.m_parent_key).m_child_key = node.m_child_key;
            if (node.m_child_key != -1)
            {
                m_memory.at(node.m_child_key).m_parent_key = node.m_parent_key;
            }
            else
            {
                // Means node is link tail.
                m_tail_key = node.m_parent_key;
            }
            node.m_parent_key = -1;
            // Update link head.
            m_memory.at(m_head_key).m_parent_key = key;
            node.m_child_key = m_head_key;
            m_head_key = key;
        }

        return node.m_value;
    }
    
    void put(int key, int value) 
    {
        auto it = m_memory.find(key);
        if (it == m_memory.end())
        {
            auto it = m_memory.try_emplace(key, key, value, -1, -1);
            auto& new_node = it.first->second;

            // Update list head.
            if (m_head_key == -1)
            {
                // Here onyl if Node #1.
                m_head_key = key;
            }
            else
            {
                new_node.m_child_key = m_head_key;
                m_memory.at(m_head_key).m_parent_key = key;
                m_head_key = key;
            }
            // Update list tail.
            if (m_tail_key == -1)
            {
                // Here only on Node #1.
                m_tail_key = key;
            }
            else if (m_memory.at(m_tail_key).m_parent_key == -1)
            {
                // Here only on Node #2.
                // I think I never get here.
                m_memory.at(m_tail_key).m_parent_key = key;
            }
            
            if (m_memory.size() > m_capacity)
            {
                // From Node m_last to Node map.
                auto key_to_delete = m_tail_key;
                m_tail_key = m_memory.at(m_tail_key).m_parent_key;
                m_memory.at(m_tail_key).m_child_key = -1;
                m_memory.erase(m_memory.find(key_to_delete));
            }

            return;
        }

        // Here to update an existing Node: first the value...
        auto& node = it->second;
        node.m_value = value;
        // ... then the link head, if not already the head.
        if (m_head_key != key)
        {
            // Not the head, so you're sure there's a parent...
            m_memory.at(node.m_parent_key).m_child_key = node.m_child_key;
            // ... but still don't know about the child.
            if (node.m_child_key != -1)
            {
                m_memory.at(node.m_child_key).m_parent_key = node.m_parent_key;
            }
            else
            {
                // Means node is link tail.
                m_tail_key = node.m_parent_key;
            }

            m_memory.at(m_head_key).m_parent_key = key;
            node.m_child_key = m_head_key;
            m_head_key = key;

            node.m_parent_key = -1;
        }
    }

  private:
    // STD guarantees that pointers to elements in an (unordered_)map don't 
    //  change after rehashing, so you can store directly pointers.
    unordered_map<int, Node> m_memory;
    int m_capacity;
    int m_head_key;
    int m_tail_key;
};
