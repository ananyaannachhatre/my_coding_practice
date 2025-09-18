class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        // Step 1: Insert copied nodes right after the original nodes
        Node* current = head;
        while (current) {
            Node* copy = new Node(current->val);
            copy->next = current->next;
            current->next = copy;
            current = copy->next;
        }
        
        // Step 2: Assign random pointers for the copied nodes
        current = head;
        while (current) {
            if (current->random) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }
        
        // Step 3: Separate the interleaved list into original and copied
        Node* original = head;
        Node* copyHead = head->next;
        Node* copy = copyHead;
        
        while (original) {
            original->next = original->next->next;
            if (copy->next) {
                copy->next = copy->next->next;
            }
            original = original->next;
            copy = copy->next;
        }
        
        return copyHead;
    }
};
