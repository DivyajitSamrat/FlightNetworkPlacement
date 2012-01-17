#include <iostream>
#include <string>

using namespace std;

struct node { //structure to create the stack

    unsigned int info;
    struct node *next;

};

struct stack { //defining the stack

    struct node *base;

    stack() {

        base = NULL;
    }
};

int top(struct stack &s) { //reading the top-most element of the stack

    if(s.base != NULL)
        return s.base->info;
    else return -1;
}

bool empty(struct stack &s) { //checking whether the stack is empty

    if(s.base == NULL)  return true;
    else                return false;
}

void pop(struct stack &s) { //pop functionality of the stack

    if(s.base == NULL)
        return;

    cout << s.base->info << " ";
    struct node *temp = s.base->next;
    delete s.base;
    s.base = temp;
}

void push(struct stack &s, unsigned int i) { //push() function as required in the problem

    if(i - top(s) != 1 && i != 0 && s.base != NULL)
        return;

    struct node *temp = new struct node;
    temp->info = i;
    temp->next = s.base;
    s.base = temp;
}

void natpush(struct stack &s, unsigned int i) { //the natural push() function. it is not required in the problem

    struct node *temp = new struct node;
    temp->info = i;
    temp->next = s.base;
    s.base = temp;
}

void print(struct stack &s) { //

    struct stack buff;

    while(!empty(s)) {

        natpush(buff, top(s));
        pop(s);
    }

    cout << endl;

    while(!empty(buff)) {

        cout << top(buff) << " ";
        push(s, top(buff));
        pop(buff);
    }

    cout << endl;
}

bool isvalid(string sqc) { //checking the validity of the sequence entered by the user

    unsigned int i, len = sqc.length();

    for(i = 1; i < len; ++i)
        if(sqc[i - 1] - sqc[i] != 1 && sqc[i] < sqc[i - 1])
            return false;

    return true;
}

int main() {

    struct stack s;
    string seq;
    cout << "\n Enter the string of digits (0-9) to be validated : ";
    cin >> seq;
    if( isvalid(seq) )
        cout << "\n This is a valid pattern and can be achieved using PUSH-POP.\n";
    else
        cout << "\n Invalid pattern. \n";

    return 0;
}
