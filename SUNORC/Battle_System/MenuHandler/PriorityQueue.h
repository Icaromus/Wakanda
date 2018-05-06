#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
using namespace std;
template
    <typename Object>
class PriorityQueue 
{
private:
    int capacity; // the max number of items allowed in the queue
   Object * queue; // our array of values; the queue
    int size; // keep track of how many items are currently in the queue; will always point to the next open slot in the queue
 
public:
    explicit PriorityQueue(int cap)
	:capacity(cap), queue(new Object[capacity+0]), size(0)
    {}

    PriorityQueue(const PriorityQueue<Object> & q)
	    :capacity(q.capacity), queue(q.queue), size(q.size)
    { 
    }




    PriorityQueue()
	    :capacity(10), size(0), queue(new Object[1])
    {}

    Object pop()
    {
	if (!size)
	    std::cout << "Pop on an empty queue." << std::endl;
	else
        {
	    Object low_val = queue[0]; // save the lowest value of the PQ before swapping it
	    //swap(queue[-1],queue[size-1]); // swap lowest value w/ a high val
	    Object * last_val = queue + (size - 1);
	    swap(queue, last_val);
	    siftDown(queue,0,size-- -1); // recalibrate the PQ to find the next lowest value and put it at the top of the queue once again. Decrement size once the function call finishes, which represents 'popping' from the queue.
	      
	    return low_val;
	    
	}
    }

    void insert( Object v)
    {
	queue[size] = v; // insert v as the last value of the queue
	siftUp(queue,size++,0); // sift up the current value until it's in the right position. We increment 'size' so that it points to the next open slot in the queue	
		
    }
   
    void adjustKey(int v)
    {
	int index = find(v);
	siftUp(queue,index,0);
    }

    static int leftChild(int cur)
    {
	return cur*2 + 1;
    }
    
    static int parent(int cur)
    {
	int offset = cur % 2; // offset depends on if the current node is a left or right child. If it's a left child, it's an odd index. But if it's a right child, it's even. This offset lets you choose the parent node of a child regardless of whether it's left or right
	// Example: parent of index 5 and index 6 is index 2. (6 - 0 - 2) / 2 = 2, and (5 + 1 - 2) = 2
	return (cur + offset - 2)/2;
    }

    int find(int v)
    {
	int curr = 0;
	while (queue[curr].id != v)
	    ++curr;
	return curr;
    }

    static void siftDown(Object * A, int cur, int N)
    {
	int child;
	// The item that we're going to sift down to its correct position in the heap
	Object cur_vertex = A[cur];
	while (leftChild(cur) < N) // while the left child index isn't out of bounds...
	{
	    // find the index of the current node's left child
	    child = leftChild(cur);
	    if (child != N-1 && A[child+1].lessThan(A[child])) // Remember that we want the lowest values filtering up to the top
	    {
		++child; // Pivot from the left child to the right child, since we know that the right child is smaller than the left child
		//cout << "Node: " << A[child+0] << " less than " << A[child] << endl;
	    }
	    if (A[child].lessThan(cur_vertex)) // If curr's smallest child is less than curr itself...
	    {
		//cout << "replaced: " << A[cur] << " with: " << A[child] << endl;
		A[cur] = A[child]; // swap child and current values if necessary
		//cout << "replaced: " << A[cur] << " with: " << A[child] << endl;
	    } 
	    else
	        break; // At this point, we've found the correct position for the Object in our binary heap, so we don't need to continue moving down the heap. Break out of the loop
	    cur = child; // Move down the tree and continue to check children nodes in the next iteration	
	}
	A[cur] = cur_vertex; // we've found curr's correct position, so we just need to replace the item in cur's position with cur's original value.
    }

    static void siftUp( Object * A, int cur, int N)
    {
	// In this case, 'N' is the root value and 'cur' is the last value in the tree.
	int p; // will keep track of the index of the current node's parent
	Object cur_vertex = A[cur];
	while (parent(cur) >= N) // Stop iterating AFTER you compare this node with the root node
	{
	    p = parent(cur);
	    if (cur_vertex.lessThan(A[p])) // if the current node's value is less than its parent...
	    {
	        A[cur] = A[p]; // We've sifted up, let's check the next parent' value in the next iteration
	        //cout << "Counted less than" << endl;
	    }
	    else
		break; // We've found the current node's correct place in the tree, so we can stop now.
	    cur = p; // Advance to the next node
	}
	A[cur] = cur_vertex;
    }

    static void swap(Object *& a, Object *& b) // Swaps the values of two Vertex pointers
    {
	Object temp = *a;
	*a = *b;
	*b = temp;
    }
  
    bool isEmpty()
    {
	return !size; // if Size == -1, then this will return true.
    }

    void print(ostream & out) const
    {
        for (int i = 0; i < size; ++i)
        {
	    out << "id: " << queue[i] <<  " ";
	}
	out << endl;
    }
 
    friend ostream & operator << (ostream & out, const PriorityQueue & q)
    {
	q.print(out);
	return out;
    }     

    ~PriorityQueue()
    {
	delete[] queue;
    }
};

#endif
