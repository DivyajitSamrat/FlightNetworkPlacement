#include <iostream>

using namespace std;

struct node { //structure for creating the cicular array

    unsigned int pos;
    struct node *next;
};

struct node *start;

void build(int size) { //building the circular array

    int i;
    struct node *end;
    start = new struct node;

    start->pos = 1;

    struct node *current = start;
    for(i = 2; i <= size; ++i) {

        struct node *newnode = new struct node;
        newnode->pos = i;
        current->next = newnode;
        current = newnode;
    }

    end = current;
    end->next = start;
}

void print() { // to print the elements of the circular array

    struct node *current = start;

    do {

        cout << current->pos << " ";
        current = current->next;

    } while(current != start);

    cout << endl;
}

struct node *kill(struct node *_start, unsigned int incr) { // killing (removing) the required element from the circular array

    unsigned int i;
    struct node *prev, *trash, *j;

    trash = _start;

    j = _start->next;
    while (j->next != trash)
        j = j->next;
    prev = j;

    if(prev == trash)
        return NULL;

    for(i = 1; i < incr; ++i) {

        //cout << prev->pos << " " << trash->pos << endl;
        prev = prev->next;
        trash = trash->next;
    }

    prev->next = trash->next;

    if(start == trash) start = trash->next;

    delete trash;

    return prev->next;
}

void keep_killing(unsigned int M, unsigned int N) { //reaching the final element of the circular array, finding the winner of the game

    build(M);
    struct node *current = start;
    do {

        current = kill(current, N);
    } while(current != NULL);
}

int main() {

    unsigned int M, N;

    cout << "\n Enter the value of the total number of KIDS (M) : ";
    cin >> M ;
    cout << "\n Enter the value of the random number (N) : ";
    cin >> N;
    cout <<"\n The winner of the game is position number ";
    keep_killing(M, N);

    print();

    return 0;
}
