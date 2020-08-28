#include <iostream>
#include <string>
#include <exception>

#define trace true

using namespace std;

namespace ericawithlove208 { namespace cxxSamples { namespace sort {

void topMerge(int*, int*, int, int = 0);
void combine(int*, int*, int*, int, int); 

void usage();
void printArray(int*, int);

void topMerge(int* input, int* output, int inputSize, int outputSize) {
  if (inputSize == 1) {
    #ifdef trace
      cout << "\ntopMerge (base case) " << endl;
      printArray(input, inputSize);
    #endif
    output[0] = input[0];
    return;
  }

  int middle = inputSize / 2;

  #ifdef trace
    cout << "\ntopMerge" << endl;
    cout << "input left ";
    printArray(input, middle);

    cout << "middle " << middle << " [" << input[middle] << "]" << endl;

    cout << "input right ";
    printArray(input + middle, inputSize - middle);

    cout << "output ";
    printArray(output, outputSize);
  #endif

  topMerge(input, output, middle, outputSize);
  topMerge(input + middle, output, inputSize - middle); 

  combine(input, input + middle, output, middle, inputSize - middle);
}

void combine(int* left, int* right, int* output, int leftSize, int rightSize) {
  int leftIndex = 0;
  int rightIndex = 0;
  int outputIndex = 0;

  while (outputIndex < (leftSize + rightSize)) {
    if ((leftIndex < leftSize) && ((left[leftIndex] <= right[rightIndex]) || (rightIndex >= rightSize))) {
      output[outputIndex] = left[leftIndex];
      outputIndex++;
      leftIndex++;

      continue;
    }

    if ((rightIndex < rightSize) && ((right[rightIndex] <= left[leftIndex]) || (leftIndex >= leftSize))) {
      output[outputIndex] = right[rightIndex];
      outputIndex++;
      rightIndex++;

      continue;
    }
  }

  for (int x = 0; x < (leftSize + rightSize); x++) {
    if (x < leftSize) {
      left[x] = output[x];

      continue;
    }

    right[x - leftSize] = output[x];
  }
}

void printArray(int* array, int size) {
  cout << "size: " << size << " [";

  for (int x = 0; x < size; x++) {
    cout << array[x];

    if ((x + 1) < size) {
      cout << " ";
    }
  }

  cout << "]" << endl;
}

void usage() {
  cout << "mergesort 1 2 3 4 5 6 7 8 9 10" << endl;
}

} } }

using namespace ericawithlove208::cxxSamples::sort;

int main(int argc, const char** argv) {
  if (argc < 2) {
    usage();
    return 0;
  }

  int inputSize = argc - 1;
  int* input = new int[inputSize];

  for (int x = 1; x < argc; x++) {
    const char* str = argv[x];

    try {
      int num = stoi(str);
      input[x - 1] = num;

    } catch (exception e) {
      cout << "could not parse int: " << str << endl;
      return -1;
    }
  }

  int* org = new int[inputSize];

  for (int x = 0; x < inputSize; x++) {
    org[x] = input[x];
  }

  int* output = new int[inputSize]();

  topMerge(input, output, inputSize);

  cout << "\ninput ";
  printArray(org, inputSize);

  cout << "sorted ";
  printArray(output, inputSize);
}
