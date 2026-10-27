#ifndef DEQUE_H
#define DEQUE_H

typedef struct deque Deque;

void freeDeque(Deque* list);
Deque* getLast(Deque* list);
Deque* get(Deque* list, int value);
int isEmpty(Deque* list);
Deque* delete(Deque* list, int value);
void showReverseDeque(Deque* list);
void showDeque(Deque* list);
Deque* addInOrder(Deque* list, int value);
Deque* add(Deque* list, int value);
Deque* newDeque();

#endif