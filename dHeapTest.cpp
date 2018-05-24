#include "dHeap.h"
#include <iostream>
#include <cassert>
#include <random>

const int SIZE = 1000;

int * generateRandomNumbers();

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    int * randomNumbers = generateRandomNumbers();

    std::cout << "STARTING TEST:\n-------------------------------\n";
    /* Constructor */
    dHeap<int> h1(2);
    dHeap<int> h2(3);
    dHeap<int> h3(4);
    dHeap<int> h4(8);
    dHeap<int> h5(16);

    /* Testing PUSH */
    std::cout << "Testing push: ";
    for (int i = 0; i < SIZE; i++)
    {
        h1.push(randomNumbers[i]);
        h2.push(randomNumbers[i]);
        h3.push(randomNumbers[i]);
        h4.push(randomNumbers[i]);
        h5.push(randomNumbers[i]);
    }
    std::cout << "Ok.\n";

    /* Using copy constructor */
    dHeap<int> copy1(h1);
    dHeap<int> copy2(h2);
    dHeap<int> copy3(h3);
    dHeap<int> copy4(h4);
    dHeap<int> copy5(h5);

    /* Testing SIZE */
    std::cout << "Testing size: ";
    assert(h1.size() == SIZE);
    assert(h2.size() == SIZE);
    assert(h3.size() == SIZE);
    assert(h4.size() == SIZE);
    assert(h5.size() == SIZE);
    std::cout << "Ok.\n";

    /* Testing d-value */
    std::cout << "Testing dValue: ";
    assert(h1.getdValue() == 2);
    assert(h2.getdValue() == 3);
    assert(h3.getdValue() == 4);
    assert(h4.getdValue() == 8);
    assert(h5.getdValue() == 16);
    std::cout << "Ok,\n";

    /* Testing PEEK and POP */
    std::cout << "Testing peek and pop: ";
    for (int i = 0; i < SIZE; i++)
    {
        assert(h1.peek() == h1.pop());
        assert(h2.peek() == h2.pop());
        assert(h3.peek() == h3.pop());
        assert(h4.peek() == h4.pop());
        assert(h5.peek() == h5.pop());
    }
    // Should now be empty

    /* Re-testing size: */
    std::cout << "Re-testing size: ";
    assert(h1.size() == 0);
    assert(h2.size() == 0);
    assert(h3.size() == 0);
    assert(h4.size() == 0);
    assert(h5.size() == 0);
    std::cout << "Ok.\n";

    /* Testing assignment operator */
    std::cout << "Testing assignment operator: ";
    h1 = copy1;
    h2 = copy2;
    h3 = copy3;
    h4 = copy4;
    h5 = copy5;
    // Basically running the same test-suite:
    assert(h1.size() == SIZE);
    assert(h2.size() == SIZE);
    assert(h3.size() == SIZE);
    assert(h4.size() == SIZE);
    assert(h5.size() == SIZE);
    assert(h1.getdValue() == 2);
    assert(h2.getdValue() == 3);
    assert(h3.getdValue() == 4);
    assert(h4.getdValue() == 8);
    assert(h5.getdValue() == 16);
    for (int i = 0; i < SIZE; i++)
    {
        assert(h1.peek() == h1.pop());
        assert(h2.peek() == h2.pop());
        assert(h3.peek() == h3.pop());
        assert(h4.peek() == h4.pop());
        assert(h5.peek() == h5.pop());
    }
    std::cout << "Ok.\n";


    /* Testing copy constructor */
    std::cout << "Testing copy constructor: ";
    // Basically running the same test-suite
    assert(copy1.size() == SIZE);
    assert(copy2.size() == SIZE);
    assert(copy3.size() == SIZE);
    assert(copy4.size() == SIZE);
    assert(copy5.size() == SIZE);
    assert(copy1.getdValue() == 2);
    assert(copy2.getdValue() == 3);
    assert(copy3.getdValue() == 4);
    assert(copy4.getdValue() == 8);
    assert(copy5.getdValue() == 16);
    for (int i = 0; i < SIZE; i++)
    {
        assert(copy1.peek() == copy1.pop());
        assert(copy2.peek() == copy2.pop());
        assert(copy3.peek() == copy3.pop());
        assert(copy4.peek() == copy4.pop());
        assert(copy5.peek() == copy5.pop());
    }
    std::cout << "Ok.\n";

    std::cout << "Reaching end of test. Your implementation passed the test. Congratulations!\n";

    delete [] randomNumbers;
    return 0;
}

int * generateRandomNumbers()
{
    std::random_device rd;
    std::uniform_int_distribution<int> uniformDistribution(0, SIZE * 2);

    int * randomNumbers = new int[SIZE];
    for (int i = 0; i < SIZE; i++)
        randomNumbers[i] = uniformDistribution(rd);

    return randomNumbers;
}
