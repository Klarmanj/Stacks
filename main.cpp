#include <iostream>
#include <assert.h>

using namespace std;



template<class Type>
class StackADT {
public:
    virtual void initializeStack() = 0;
    virtual bool isEmptyStack() const = 0;
    virtual bool isFullStack() const = 0;
    virtual void push(const Type& newItem) = 0;
    virtual Type top() const = 0;
    virtual void pop() = 0;
};

template<class Type>
class stackType: public StackADT<Type>{
public:
    const stackType<Type>& operator=(const stackType<Type>&);
    void initializeStack();
    bool isEmptyStack() const;
    bool isFullStack() const;
    void push(const Type&);
    Type top() const;
    void pop();
    stackType(int stackSize = 100);
    stackType(const stackType<Type>& otherStack);
    ~stackType();

private:
    int maxStackSize;
    int stackTop;
    Type *list;

    void copyStack(const stackType<Type>& otherStack);
};

template<class Type>
void stackType<Type>::initializeStack() {
    stackTop = 0;
}
template<class Type>
bool stackType<Type>::isEmptyStack() const {
    return (stackTop == 0);
}
template<class Type>
bool stackType<Type>::isFullStack() const {
    return (stackTop == maxStackSize);
}
template<class Type>
void stackType<Type>::push(const Type &newItem) {
    if(!isFullStack()){
        list[stackTop] = newItem;

        stackTop++;
    }
    else{
        cout << "Cannot add to a full stack" << endl;
    }
}
template<class Type>
Type stackType<Type>::top() const {
    assert(stackTop != 0);

    return list[stackTop - 1];
}
template<class Type>
void stackType<Type>::pop() {
    if(!isEmptyStack()){
        stackTop--;
    }
    else{
        cout << "Cannot remove from an empty list." << endl;
    }
}
template<class Type>
void stackType<Type>::copyStack(const stackType<Type> &otherStack) {
    delete [] list;
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;

    list = new Type[maxStackSize];

    for(int j = 0; j < stackTop; j++){
        list[j] = otherStack.list[j];
    }
}
template<class Type>
stackType<Type>::stackType(int stackSize) {

    if(stackSize <= 0){
        cout << "Size of the array to hold the stack must be positive." << endl;
        cout << "Creating an array of size 100." <<endl;

        maxStackSize = 100;
    }
    else{
        maxStackSize = stackSize;

        stackTop = 0;
        list = new Type[maxStackSize];
    }
}
template<class Type>
stackType<Type>::~stackType<Type>() {
    delete [] list;
}
template<class Type>
stackType<Type>::stackType(const stackType<Type> &otherStack) {
    list = nullptr;

    copyStack(otherStack);
}
template<class Type>
const stackType<Type> & stackType<Type>::operator=(const stackType<Type> &otherStack) {
    if(this != &otherStack){
        copyStack(otherStack);
    }
    return *this;
}


void testCopyConstructor(stackType<int> otherStack);

int main() {
    stackType<int> stack(50);
    stackType<int> copyStack(50);
    stackType<int> dummyStack(100);

    stack.initializeStack();
    stack.push(85);
    stack.push(28);
    stack.push(56);
    copyStack = stack;

    cout << "The elements of copyStack: ";
    while (!copyStack.isEmptyStack()){
        cout << copyStack.top() << " ";
        copyStack.pop();
    }
    cout << endl;
    copyStack = stack;
    testCopyConstructor(stack);

    if(!stack.isEmptyStack()){
        cout << "The original stack is not empty." << endl
        << "The top element of the original stack: "
        << copyStack.top() << endl;
    }

    dummyStack = stack;

    cout << "The elements of dummyStack: ";
    while(!dummyStack.isEmptyStack()){
        cout << dummyStack.top() << " ";
        dummyStack.pop();
    }
    cout << endl;



    return 0;
}

void testCopyConstructor(stackType<int> otherStack){
    if(!otherStack.isEmptyStack()){
        cout << "otherStack is not empty." << endl
        << "The top element of otherStack: "
        << otherStack.top() << endl;
    }
}