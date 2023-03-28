#include <stdio.h>

#include "linked_list/ops.h"

int main(void) {
    LinkedList list = new_list();
    const int nums[] = {1, 1, 4, 5, 1, 4, 1, 9, 1, 9, 8, 1, 0};
    for (int i = 0; i < sizeof(nums) / sizeof(int); i++) {
        if (push_tail(&list, &nums[i])) {
            return -1;
        }
    }

    const Node * head = list.head;
    while(head) {
        printf("%d ", head->item);
        head = head->next;
    }

}
