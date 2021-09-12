Pet Project, 只是練習而已

### Experimental C++20 Usage

由於現在CMake對C++20的支援還很孱弱, 抓不到Module Partition
直接開Visual Studion的來弄

### Thought

不支援 Partition
例如
``` cpp
export module small:iterator:pointer_wrapper;
```

原本只要提供一個header file(其他header file可以隱藏), 和一個library..
現在如果要做類似的事, 所有的ifc都要提供
