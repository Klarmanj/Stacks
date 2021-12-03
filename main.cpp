#include <iostream>
#include <assert.h>
#include <iomanip>
#include<fstream>

using namespace std;

template<class Type>
struct nodeType{
    Type info;
    nodeType<Type> *link;
};


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
class linkedStackType: public StackADT<Type>{
public:
    const linkedStackType<Type>& operator=(const linkedStackType<Type>&);
    bool isEmptyStack() const;
    bool isFullStack() const;
    void initializeStack();
    void push(const Type&);
    Type top() const;
    void pop();
    linkedStackType();
    linkedStackType(const linkedStackType<Type>&);
    ~linkedStackType();

private:
    nodeType<Type> *stackTop;
    void copyStack(const linkedStackType<Type>&);
};

template<class Type>
void stackType<Type>::initializeStack(){
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

template<class Type>
linkedStackType<Type>::linkedStackType() {
    stackTop = nullptr;
}
template<class Type>
bool linkedStackType<Type>::isEmptyStack() const{
    return (stackTop == nullptr);
}
template<class Type>
bool linkedStackType<Type>::isFullStack() const {
    return false;
}
template<class Type>
void linkedStackType<Type>::initializeStack() {
    nodeType<Type> *temp;

    while(stackTop != nullptr){
        temp = stackTop;
        stackTop = stackTop->link;
        delete temp;
    }
}
template<class Type>
void linkedStackType<Type>::push(const Type &newElement) {
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;

    newNode->info = newElement;
    newNode->link = stackTop;
    stackTop = newNode;
}
template<class Type>
Type linkedStackType<Type>::top() const {

    assert(stackTop != nullptr);
    return stackTop->info;
}
template<class Type>
void linkedStackType<Type>::pop() {
    nodeType<Type> *temp;

    if(stackTop != nullptr){
        temp = stackTop;
        stackTop = stackTop->link;
        delete temp;
    }
}
template<class Type>
void linkedStackType<Type>::copyStack(const linkedStackType<Type> &otherStack) {
    nodeType<Type> *newNode, *current, *last;
    if(stackTop != nullptr){
        initializeStack();
    }
    if(otherStack.stackTop == nullptr){
        stackTop = nullptr;
    }
    else{
        current = otherStack.stackTop;
        stackTop = new nodeType<Type>;
        stackTop->info = current->info;
        stackTop->link = nullptr;

        last = stackTop;
        current = current->link;

        while(current != nullptr){
            newNode = new nodeType<Type>;

            newNode->info = current->info;
            newNode->link = nullptr;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}
template<class Type>
linkedStackType<Type>::linkedStackType(const linkedStackType<Type> &otherStack) {
    stackTop = nullptr;
    copyStack(otherStack);
}
template<class Type>
linkedStackType<Type>::~linkedStackType<Type>() {
    initializeStack();
}
template<class Type>
const linkedStackType<Type>& linkedStackType<Type>::operator=(const linkedStackType<Type> &otherStack) {
    if(this != &otherStack){
        copyStack(otherStack);
    }
    return *this;
}

void evaluateOpr(ofstream& outF, stackType<double>& stack, char& ch, bool& isExpOk){
    double op1, op2;

    if(stack.isEmptyStack()){
        outF << "(Not enough operands)";
        isExpOk = false;
    }
    else{
        op2 = stack.top();
        stack.pop();
        if(stack.isEmptyStack()){
            outF << "(Not enough operands)";
            isExpOk = false;
        }
        else{
            op1 = stack.top();
            stack.pop();

            switch (ch) {
                case '+':
                    stack.push(op1 + op2);
                    break;
                case '-':
                    stack.push(op1 - op2);
                    break;
                case '*':
                    stack.push(op1 * op2);
                    break;
                case '/':
                    if(op2 != 0) {
                        stack.push(op1 / op2);
                    }
                    else{
                        outF << "(Division by 0)";
                        isExpOk = false;
                    }
                    break;
                default:
                    outF << "(Illegal Operator)";
                    isExpOk = false;
            }
        }
    }
}


void evaluateExpression(ifstream& inF, ofstream& outF, stackType<double>& stack, char& ch, bool& isExpOk){
    double num;

    while(ch != '='){
        switch (ch) {
            case '#':
                inF >> num;
                outF << num << " ";
                if(!stack.isFullStack()){
                    stack.push(num);
                }
                else{
                    cout << "Stack overflow. Program terminates!" <<endl;
                    exit(0);
                }
                break;
            default:
                evaluateOpr(outF, stack, ch, isExpOk);
        }
        if(isExpOk){
            inF >> ch;
            outF << ch;

            if(ch != '#'){
                outF << " ";
            }
            else{
                discardExp(inF, outF, ch);
            }
        }
    }
}




//void testCopyConstructor(stackType<int> otherStack);
//void testCopy(linkedStackType<int> OStack);

void evaluateExpression(ifstream& inF, ofstream& outF, stackType<double>& stack, char& ch, bool& isExpOk);
void evaluateOpr(ofstream& outF, stackType<double>& stack, char& ch, bool& isExpOk);
void discardExp(ifstream& inF, ofstream& outF, char& ch);
void printResult(ofstream& outF, stackType<double> stack, bool isExpOk);

int main() {




    //Commented out previous code to make testing easier for the calculator.
//    linkedStackType<int> stack;
//    linkedStackType<int> otherStack;
//    linkedStackType<int> newStack;
//
//    stack.push(28);
//    stack.push(94);
//    stack.push(37);
//
//    newStack = stack;
//    cout << "After the assignment operator, newStack: " << endl;
//
//    while(!newStack.isEmptyStack()){
//        cout << newStack.top() << endl;
//        newStack.pop();
//    }
//
//    otherStack = stack;
//    cout << "Testing the copy constructor." << endl;
//
//    testCopy(otherStack);
//
//    cout << "After testing the copy constructor, otherStack: " << endl;
//
//    while(!otherStack.isEmptyStack()){
//        cout << otherStack.top() << endl;
//        otherStack.pop();
//    }








//Commented out previous test code for stackType to make life easier when testing linkedStackType.

//    stackType<int> stack(50);
//    stackType<int> copyStack(50);
//    stackType<int> dummyStack(100);
//
//    stack.initializeStack();
//    stack.push(85);
//    stack.push(28);
//    stack.push(56);
//    copyStack = stack;
//
//    cout << "The elements of copyStack: ";
//    while (!copyStack.isEmptyStack()){
//        cout << copyStack.top() << " ";
//        copyStack.pop();
//    }
//    cout << endl;
//    copyStack = stack;
//    testCopyConstructor(stack);
//
//    if(!stack.isEmptyStack()){
//        cout << "The original stack is not empty." << endl
//        << "The top element of the original stack: "
//        << copyStack.top() << endl;
//    }
//
//    dummyStack = stack;
//
//    cout << "The elements of dummyStack: ";
//    while(!dummyStack.isEmptyStack()){
//        cout << dummyStack.top() << " ";
//        dummyStack.pop();
//    }
//    cout << endl;



    return 0;
}

void testCopyConstructor(stackType<int> otherStack){
    if(!otherStack.isEmptyStack()){
        cout << "otherStack is not empty." << endl
        << "The top element of otherStack: "
        << otherStack.top() << endl;
    }
}

void testCopy(linkedStackType<int> OStack){
    cout << "Stack in the function testCopy: " << endl;

    while(!OStack.isEmptyStack()){
        cout << OStack.top() << endl;
        OStack.pop();
    }
}