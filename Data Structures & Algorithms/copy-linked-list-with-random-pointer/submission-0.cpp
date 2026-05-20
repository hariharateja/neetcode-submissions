class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        Node dummy(0);
        Node* temp = head;

        vector<int> vc;

        // map original node -> copied node
        map<Node*,Node*> mp;

        // store values + move temp
        while(temp){
            vc.push_back(temp->val);
            temp = temp->next;
        }

        Node* nhead = &dummy;
        temp = &dummy;

        Node* original = head;

        // create copied nodes
        for(int num : vc){
            Node* new_node = new Node(num);

            temp->next = new_node;

            // map original node to copied node
            mp[original] = new_node;

            temp = temp->next;
            original = original->next;
        }

        Node* temp1 = head;
        Node* temp2 = nhead->next;

        while(temp1 && temp2){

            // set random safely
            if(temp1->random){
                temp2->random = mp[temp1->random];
            }
            else{
                temp2->random = nullptr;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return nhead->next;
    }
};