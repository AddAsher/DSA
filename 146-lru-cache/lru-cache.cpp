struct Node {
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    unordered_map<int, Node*> map;
    Node* head;
    Node* tail;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;        
    }
    
    int get(int key) {
        if(map.count(key)>0){
            moveToFront(map[key]);
            return map[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.count(key)>0){
            map[key]->value=value;
            moveToFront(map[key]);
        }
        else {
            Node* newNode = new Node(key,value);
            map[key] = newNode;
            addToFront(newNode);
            if(map.size()>capacity){
                Node* temp = tail->prev;
                temp->prev->next = tail;
                tail->prev = temp->prev;
                map.erase(temp->key);
                delete temp;
            }
        }
    }

    void moveToFront(Node* node){
        Node* prev = node->prev;
        prev->next = node->next;
        node->next->prev = prev;
        addToFront(node);
    }

    void addToFront(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */