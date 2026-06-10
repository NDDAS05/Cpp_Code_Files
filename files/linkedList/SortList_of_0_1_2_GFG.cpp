/* Node is defined as
class Node {
	public:
	int data;
	Node* next;
	
	Node(int x) {
		data = x;
		next = nullptr;
	}
};
*/
class Solution {
	public:
	Node* segregate(Node* head) {
		// code here
		Node* zeroHead = nullptr, *zeroTail = nullptr;
		Node* oneHead = nullptr, *oneTail = nullptr;
		Node* twoHead = nullptr, *twoTail = nullptr;
		
		while (head != nullptr) {
			if (head->data == 0) {
				if (zeroTail == nullptr) {
					zeroHead = head;
					zeroTail = head;
					head = head->next;
					zeroTail->next = nullptr;
				}
				else {
					zeroTail->next = head;
					zeroTail = head;
					head = head->next;
					zeroTail->next = nullptr;
				}
			}
			
			else if (head->data == 1) {
				if (oneTail == nullptr) {
					oneHead = head;
					oneTail = head;
					head = head->next;
					oneTail->next = nullptr;
				}
				else {
					oneTail->next = head;
					oneTail = head;
					head = head->next;
					oneTail->next = nullptr;
				}
			}
			else {
				if (twoTail == nullptr) {
					twoHead = head;
					twoTail = head;
					head = head->next;
					twoTail->next = nullptr;
				}
				else {
					twoTail->next = head;
					twoTail = head;
					head = head->next;
					twoTail->next = nullptr;
				}
			}
			
		}
		// Now we also need to check 0,1,2 which nodes exist then assign
		
		// zero exists then connect to oneHead
		// Doesn't then skip to oneHead
		if(zeroHead) zeroTail->next = oneHead;
		
		
		// One head exists connect oneTail to twoHead
		// Doesn't? Then if zeroTail exists connect that to 2 skipping 1
		if(oneHead) oneTail->next = twoHead;
		else{
		    if(zeroHead) zeroTail->next = twoHead;
		}
		
		// If zero head exists return it
		if(zeroHead) return zeroHead;
		else if(oneHead) return oneHead;
		else return twoHead;
	}
};
