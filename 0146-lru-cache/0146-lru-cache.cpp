class LRUCache {
    struct Node {
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int key, int value) {
            this->key = key;
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
    };

    unordered_map<int, Node*> mp;
    int currSize;
    int capacity;
    Node* head;
    Node* tail;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        currSize = 0;
        head = nullptr;
        tail = nullptr;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        if (node != tail) {
            if (node == head) {
                head = head->next;
            } else {
                node->prev->next = node->next;
            }

            node->next->prev = node->prev;

            node->prev = tail;
            node->next = nullptr;
            tail->next = node;
            tail = node;
        }

        return node->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;

            if (node != tail) {
                if (node == head) {
                    head = head->next;
                } else {
                    node->prev->next = node->next;
                }

                node->next->prev = node->prev;

                node->prev = tail;
                node->next = nullptr;
                tail->next = node;
                tail = node;
            }

            return;
        }

        if (currSize == capacity) {
            mp.erase(head->key);

            if (head->next == nullptr) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
                head->prev = nullptr;
            }

            currSize--;
        }

        Node* node = new Node(key, value);

        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }

        mp[key] = node;
        currSize++;
    }
};