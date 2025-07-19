// Max-Heap Implementation
class MaxHeap {
  private:
  int size;
  vector<int> arr;

  public:
  MaxHeap() {
    size = 0;
    arr.push_back(-1); 
  }

  void insert(int num) {
    size++;
    arr.push_back(num);
    int index = size;

    while (index > 1) {
      int parent = index / 2;

      if (arr[parent] < arr[index]) {
        swap(arr[parent], arr[index]);
        index = parent;
      } else {
        return;
      }
    }
  }

  void Delete() {
    if (size == 0)
      return;

    swap(arr[1], arr[size]);
    size--;
    arr.pop_back();

    int index = 1;
    while (index <= size) {
      int left = 2 * index;
      int right = 2 * index + 1;
      int largest = index;

      if (left <= size && arr[left] > arr[largest]) {
        largest = left;
      }
      if (right <= size && arr[right] > arr[largest]) {
        largest = right;
      }
      if (largest != index) {
        swap(arr[index], arr[largest]);
        index = largest;
      } else {
        break;
      }
    }
  }
};

// Min-Heap Implementation
class MinHeap {
  private:
  int size;
  vector<int> arr;

  public:
  MinHeap() {
    size = 0;
    arr.push_back(INT_MAX);
  }

  void insert(int num) {
    size++;
    arr.push_back(num);
    int index = size;

    while (index > 1) {
      int parent = index / 2;

      if (arr[parent] > arr[index]) {
        swap(arr[parent], arr[index]);
        index = parent;
      } else {
        return;
      }
    }
  }

  void Delete() {
    if (size == 0)
      return;

    swap(arr[1], arr[size]);
    size--;
    arr.pop_back();

    int index = 1;
    while (index <= size) {
      int left = 2 * index;
      int right = 2 * index + 1;
      int smallest = index;

      if (left <= size && arr[left] < arr[smallest]) {
        smallest = left;
      }
      if (right <= size && arr[right] < arr[smallest]) {
        smallest = right;
      }
      if (smallest != index) {
        swap(arr[index], arr[smallest]);
        index = smallest;
      } else {
        break;
      }
    }
  }
};

// Heapify Alogorithm
void Heapify(vector<int> &arr, int &size, int index) {
  int left = 2 * index;
  int right = 2 * index + 1;
  int largest = index;

  if(left <= size && arr[left] > arr[largest]) {
    largest = left;
  }
  if(right <= size && arr[right] > arr[largest]) {
    largest = right;
  }

  if(largest != index) {
    swap(arr[largest], arr[index]);
    Heapify(arr, size, largest);
  }
} 

// Build Heap
void BuildHeap(vector<int> &arr) {
  int size = arr.size() - 1;
  for(int i = size / 2; i > 0; i--) {
    Heapify(arr, size, i);
  }
}

// Heap Sort 
void HeapSort(vector<int> &arr) {
  BuildHeap(arr);

  int size = arr.size();
  for(int i = size; i >= 1; i--) {
    swap(arr[1], arr[i]);
    Heapify(arr, i, 1);
  }
}