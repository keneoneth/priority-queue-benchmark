#ifndef PAIRING_HEAP_PRIQUEUE
#define PAIRING_HEAP_PRIQUEUE

#include <cassert>
#include <stack>

template <typename T>
struct heap_node {
    const T key;
    heap_node<T> * left_child = nullptr;
    heap_node<T> * next_sibling = nullptr;

    heap_node(const T key) : key(key)  {}

    void add_child(heap_node<T> *& node) {
        if (left_child!=nullptr){
            std::swap(node->next_sibling,left_child);
            std::swap(left_child,node);
        } else {
            std::swap(left_child,node);
        }
    }
};

template <typename T>
struct two_pass_ret {
    heap_node<T> * merge_node;
    heap_node<T> * new_node;
    two_pass_ret(heap_node<T> * merge_node,heap_node<T> * new_node) : merge_node(merge_node),new_node(new_node) {}
};


template <typename T>
class pairing_heap_priqueue {

private:
    typedef T key_type;
    heap_node<key_type> * root = nullptr;
    size_t total_num = 0;


    heap_node<T> * insert(heap_node<T> * node, const T key){
        auto * node_ptr = new heap_node(key);
        return merge(node, node_ptr);
    }

    inline heap_node<T> * & merge(heap_node<T> *&A, heap_node<T> *&B) {
 
        // If any of the two-nodes is None
        // then return the not None node
        if(A == nullptr)
            return B;
        if(B == nullptr)
            return A;

        // To maintain the min heap condition compare
        // the nodes and node with minimum value become
        // parent of the other node
        if(A->key < B->key) {
            A->add_child(B);
            return A;
        }
        
        B->add_child(A);
        return B;
    }

    heap_node<T> * erase(heap_node<T> * & node) {
        
        heap_node<T> * cur_node = node->left_child;
        heap_node<T> * merge_node = nullptr;

        while(true) {
            if(cur_node == nullptr || cur_node->next_sibling == nullptr)
                break;
            
            cur_node = two_pass_merge(merge_node,cur_node);
        }

        
        delete node; // remove node
        return merge(cur_node,merge_node); // return node
    }

    inline heap_node<T> * two_pass_merge(heap_node<T> *& merge_node, heap_node<T> *& node) {

        auto B = node->next_sibling;
        auto new_node = node->next_sibling->next_sibling;

        node->next_sibling->next_sibling = nullptr;
        node->next_sibling = nullptr;
        
        merge_node = merge(merge_node,merge(node, B));
        return new_node;
    }
        

public:
    
    size_t size(void) const {
        return total_num;
    }

    bool empty(void) const {
        return total_num == 0;
    } 

    void push(const key_type key) {
        root = insert(root,key);
        total_num++;
    }

    void pop(void) {
        assert(!empty());
        root = erase(root);
        total_num--;
    }

    const T& top(void) const {
        assert(!empty());
        return root->key;
    }

};


#endif //PAIRING_HEAP_PRIQUEUE