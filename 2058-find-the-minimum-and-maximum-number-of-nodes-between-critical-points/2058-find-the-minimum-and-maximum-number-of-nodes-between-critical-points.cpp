class Solution {
public:
vector<int> nodesBetweenCriticalPoints(ListNode* head) {

    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        return {-1, -1};
    }

    int first = -1;
    int last = -1;
    int prevCritical = -1;

    int minDist = INT_MAX;
    int index = 1;

    ListNode* prev = head;
    ListNode* curr = head->next;

    while (curr != nullptr && curr->next != nullptr) {

        bool isCritical =
            (curr->val > prev->val && curr->val > curr->next->val) ||
            (curr->val < prev->val && curr->val < curr->next->val);

        if (isCritical) {

            if (first == -1) {
                first = index;
            }

            if (prevCritical != -1) {
                minDist = min(minDist, index - prevCritical);
            }

            prevCritical = index;
            last = index;
        }

        prev = curr;
        curr = curr->next;
        index++;
    }

    if (first == last) {
        return {-1, -1};
    }

    return {minDist, last - first};
}


};
